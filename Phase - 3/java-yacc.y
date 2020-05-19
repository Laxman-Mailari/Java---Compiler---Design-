%{
#include<limits.h>
#include <stdarg.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "header.h"

#include "comp.c"
//#include "graph.c"

int yylex(void);
void yyerror(char *);
extern int line  ;


nodeType *con(int value);
nodeType *id(char *i);
nodeType *opr(int oper, int nops, ...);
void freeNode(nodeType *p);


%}

%union {
    int iValue;                 /* integer value */
    char *sIndex;                /* symbol table index */
    nodeType *nPtr;             /* node pointer */
};
%token <iValue> T_NUM  
%token <sIndex> T_ID
%type  <nPtr> E T F STATEMENT STATEMENTS VAR_DEC  MethodDec HANDLE BOOL



%token  T_IMPORT T_CLASS
%token  T_PUBLIC T_PRIVATE T_PROTECTED
%token  T_STATIC T_VOID T_MAIN T_NEW T_RETURN T_BREAK
%token  T_BOOL T_SHORT T_BYTE T_CHAR T_INT T_FLOAT T_LONG T_DOUBLE  T_STRVAL


%token T_LOR T_LAND T_NOT
%token  T_STR_ARG T_STR T_STDOUT
%token  T_IF T_ELSE T_WHILE T_FOR T_DO
%token  T_TRUE T_FALSE

%token  T_U_INCR T_U_DECR T_OFB T_CFB
%token	T_S_PLUSEQ T_S_MINUSEQ T_S_MULTEQ T_S_DIVEQ T_S_DIV
%nonassoc  T_S_EQ
%left   T_S_PLUS T_S_MINUS T_S_MULT T_ S_DIV
%right  T_GEQ T_LEQ T_LE T_GE T_ASSG T_NE



%%
CompilationStart:
	ImportDec CompilationStart
	|Class_def  { exit(0); }
	;

ImportDec:
	T_IMPORT  T_ID'.'T_ID'.' T_S_MULT ';' 
	;
Class_def:
  Modifier T_CLASS T_ID open ClassBody close 
;
ClassBody:
  GlobVarDec ClassBody
  | MethodDec ClassBody   { ex($1);freeNode($1); /*--------- calling ex function od comp.c ------*/}
  |
  ;
GlobVarDec:
	Modifier VAR_DEC
	;
MethodDec:
  Modifier T_VOID T_MAIN '('T_STR_ARG ')' HANDLE  {$$ = $7;}
  | Modifier TYPE T_ID '(' Params ')' HANDLE  {$$ = $7;}
	| Modifier T_VOID T_ID '('Params ')' HANDLE {$$ = $7;}
	;

Params:
	ParamList
	;

ParamList:
	TYPE T_ID
	|TYPE T_ID',' Params
	|
	;

Modifier:
  T_PUBLIC Modifier1
  | Modifier1
  ;
Modifier1:
  T_STATIC Modifier1
  |
  ;

TYPE:
    T_BOOL  
    | T_CHAR 
    | T_SHORT 
    | T_INT   
    | T_FLOAT  ;

STATEMENTS:
  STATEMENT { $$ = $1; }
  | STATEMENTS STATEMENT { $$ = opr(';', 2, $1, $2); }
  ;

STATEMENT:
  T_ID T_ASSG E ';'     { $$ = opr('=', 2, id($1), $3); }
  | VAR_DEC             { $$ = $1;}
  | T_IF '(' BOOL ')' HANDLE                { $$ = opr(T_IF, 2, $3, $5); }
  | T_IF '(' BOOL ')' HANDLE T_ELSE HANDLE  { $$ = opr(T_IF, 3, $3, $5, $7); }
  | T_WHILE '(' BOOL ')' HANDLE             { $$ = opr(T_WHILE, 2, $3, $5); }
;



VAR_DEC:
 TYPE T_ID T_ASSG E ';' {  $$ = opr('=', 2, id($2), $4); } 
  | TYPE T_ID ';' { $$ = id($2);} 
  ;



/*
DecIdenList:
	','T_ID T_ASSG E DecIdenList {  $$ = opr('=', 2, id($2), $4); }
    | ','T_ID DecIdenList { $$ = id($2);}

	;
 */ 



E: E T_S_PLUS T   { $$ = opr('+', 2, $1, $3);}
  | E T_S_MINUS T { $$ = opr('-', 2, $1, $3);}
  | T             {$$ = $1;}
  ;

T: T T_S_MULT F   { $$ = opr('*', 2, $1, $3);}
  | T T_S_DIV F   { $$ = opr('/', 2, $1, $3);}
  | F             {$$ = $1;}
  ;

F: T_ID       {$$=id($1);}
  | T_NUM     {$$=con($1);}
  | '(' E ')' {$$ = $2;}
;

BOOL:
  E T_LOR E     { $$ = opr(T_LOR, 2, $1, $3);}
  | E T_LAND E  { $$ = opr(T_LAND, 2, $1, $3);}
  | E T_GE E    { $$ = opr('>', 2, $1, $3);}
  | E T_LE E    { $$ = opr('<', 2, $1, $3);}
  | E T_GEQ E   { $$ = opr(T_GEQ, 2, $1, $3);}
  | E T_LEQ E   { $$ = opr(T_LEQ, 2, $1, $3);}
  | E T_NE E    { $$ = opr(T_NE, 2, $1, $3);}
  | E T_S_EQ E  { $$ = opr(T_S_EQ, 2, $1, $3);}
  ;
  
open:
  T_OFB 
  ;

close:
  T_CFB 
  ;

HANDLE:
  open STATEMENTS close  {$$ = $2;}
  ;

%%

nodeType *con(int value) {
    nodeType *p;

    //printf("adding oprator\n");
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    p->type = typeCon;
    p->con.value = value;

    return p;
}

nodeType *id(char *i) {
    nodeType *p;
    //printf("adding oprator\n");
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    p->type = typeId;
    p->id.str = i;

    return p;
}

nodeType *opr(int oper, int nops, ...) {
    //printf("adding oprator\n");
    va_list ap;
    nodeType *p;
    int i;

    if ((p = malloc(sizeof(nodeType) + (nops-1) * sizeof(nodeType *))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeOpr;
    p->opr.oper = oper;
    p->opr.nops = nops;
    va_start(ap, nops);
    for (i = 0; i < nops; i++)
        p->opr.op[i] = va_arg(ap, nodeType*);
    va_end(ap);
    return p;
}

void freeNode(nodeType *p) {
    int i;

    if (!p) return;
    if (p->type == typeOpr) {
        for (i = 0; i < p->opr.nops; i++)
            freeNode(p->opr.op[i]);
    }
    free (p);
}

void yyerror(char *s) {
    fprintf(stdout, "%s\n", s);
}

int main(void) {
    yyparse();
    return 0;
}


