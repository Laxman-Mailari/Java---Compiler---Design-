%{
#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*---- linked list for symbol table -----*/

struct list{
  	char name[30];
  	char type[40];
  	int s;
    union Value {
        int val;
        char* vale;
        float valu;
    }value;
    struct list * next;
};
/* ----- writing data to the parent($$) ----- */

typedef struct Node{
      union Value2 {
        int val2;
        float f_val2;
        char* vale2;
    }value2;
}node;

/*------- keep track of the scope -------- */

struct Stack { 
    int top; 
    unsigned capacity; 
    int* array; 
};

struct Stack* createStack() ;
int isEmpty(struct Stack* stack);
void push(struct Stack* stack, int item);
int pop(struct Stack* stack);
int peek(struct Stack* stack); 

typedef struct list d_list;
d_list* head=NULL;
int scope;
int yylex(void);
void yyerror(char *);

int fill(char* name,int value,char* type,int scope);
int  fill_str(char* name,char* value,char* type,int scope);
int  fill_float(char* name,float value,char* type,int scope);
int find_val(char *id);
void display();
int update(char* id,int value,int scope);
int temp_scope=0;
int scope;
struct Stack* stack_arr;
extern int line  ;
int res=0;

node* data(int value);
node* fdata(float value);
node* StrValue(char value[20]);

%}


%union{
    	int number;
      float fnumber;
    	char *string;
      struct Node *block;
}

%token <number> T_NUM 
%token <fnumber> T_FNUM  
%type  <block> E T F  



%token  T_IMPORT T_CLASS
%token  T_PUBLIC T_PRIVATE T_PROTECTED
%token  T_STATIC T_VOID T_MAIN T_NEW T_RETURN T_BREAK
%token <string> T_BOOL T_SHORT T_BYTE T_CHAR T_INT T_FLOAT T_LONG T_DOUBLE T_ID T_STRVAL
%type  <string> TYPE

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
	|Class_def
	;

ImportDec:
	T_IMPORT  T_ID'.'T_ID'.' T_S_MULT ';' {/*printf("matched\n");*/}
	;
Class_def:
  Modifier T_CLASS T_ID open ClassBody close {display();}
;
ClassBody:
  GlobVarDec ClassBody
  | MethodDec ClassBody
  |
  ;
GlobVarDec:
	Modifier VAR_DEC
	;
MethodDec:
  Modifier T_VOID T_MAIN '('T_STR_ARG')'HANDLE
  | Modifier TYPE T_ID'(' Params ')'HANDLE
	| Modifier T_VOID T_ID'('Params ')'HANDLE
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
    T_BOOL {$$="boolean";} | T_BYTE {$$="byte";} | T_CHAR {$$="char";} | T_SHORT {$$="short";} | T_INT {$$="int";} | T_LONG {$$="long";} | T_FLOAT {$$="float";} | T_DOUBLE {$$="double";} ;

STATEMENTS:
  STATEMENT
  | STATEMENTS STATEMENT
  ;

STATEMENT:
  T_ID T_ASSG E ';' {
              //printf("Assigned\n");
              node *tem = $3;
              int v1=tem->value2.val2;
              int i = update($1,v1,scope); //updating symbol table
              
            }
  | VAR_DEC
  | T_IF '(' BOOL ')' HANDLE
  | T_IF '(' BOOL ')' open STATEMENTS close T_ELSE open STATEMENTS close  
  | T_WHILE '(' BOOL ')' HANDLE
;



VAR_DEC:
 TYPE T_ID  T_ASSG E  {
            
            //printf("%s\n",$1);
            int i;
            if(strcmp($1,"int")==0){
              i=fill($2,$4->value2.val2,$1,scope); //adding symbol table
            }
            else if(strcmp($1,"char")==0){
              //printf("%s\n",$4->value2.vale2);
              i=fill_str($2,$4->value2.vale2,$1,scope);
            }
            else if(strcmp($1,"float")==0){
              
              i=fill_float($2,$4->value2.f_val2,$1,scope);
            }
            //$$ = data(i);
          } DecIdenList ';'
  | TYPE T_ID {
              //printf("declaration\n");
              int i=fill($2,0,$1,scope);
              //$$ = data(i);
            } DecIdenList ';'
  ;

DecIdenList:
	','T_ID T_ASSG E DecIdenList {
            int i;
            i=fill($2,$4->value2.val2,"int",scope);

            }
    | ','T_ID DecIdenList {
            int i;
            i=fill($2,0,"int",scope);
            }
    |
	;

E: E T_S_PLUS T {
    int v1=$1->value2.val2;
    int v2=$3->value2.val2;
    int res = v1+v2;
    $$ = data(res);
}
  | E T_S_MINUS T {
      int v1=$1->value2.val2;
      int v2=$3->value2.val2;
      int res = v1-v2;
      $$ = data(res);
  }
  | T {$$ = $1;}
  ;

T: T T_S_MULT F {
            int v1=$1->value2.val2;
            int v2=$3->value2.val2;
            int res = v1*v2;
            $$ = data(res);
             }
  | T T_S_DIV F {
      int v1=$1->value2.val2;
      int v2=$3->value2.val2;
      int res = v1/v2;
      $$ = data(res);
      }
  | F {$$ = $1;}
  ;

F: T_ID  {
      //printf("getting value\n");
      int d=find_val($1); //get the value from sym_table
      $$=data(d);
    }
  | T_NUM {$$=data($1);}
  | T_STRVAL {$$=StrValue($1);}
  | T_FNUM {$$ = fdata($1); }
;

BOOL:
  E T_LOR E 
  | E T_LAND E
  | E T_GE E
  | E T_LE E
  | E T_GEQ E
  | E T_LEQ E
  | E T_NE E
  | E T_S_EQ E
  ;
  
open:
  T_OFB {temp_scope++;push(stack_arr,temp_scope);scope=peek(stack_arr);}
  ;

close:
  T_CFB {pop(stack_arr);scope=peek(stack_arr);}
  ;

HANDLE:
  open STATEMENTS close ;

%%


/*------------ data to send back to the $$ -------------*/

node* data(int value){
    node* p;
    p =malloc(sizeof(node));
    p->value2.val2=value;
    return p;
}
node* fdata(float value){
    node* p;
    p =malloc(sizeof(node));
    p->value2.f_val2=value;
    return p;
}

node* StrValue(char* value){
  //printf("string in fun:%s\n",value);
    node* p;
    p =malloc(sizeof(node));
    p->value2.vale2=value;
    return p;
}


/* -----------------  symbol table  --------------- */

int update(char*name,int value,int scope){
  d_list *node=head;
  while(node!=NULL){
    if(strcmp(name,node->name)==0){
      node->s=scope;
      node->value.val=value;
      return 1; 
    }
    node=node->next;
  }  
  yyerror("variable not declared");
  return 0;
  exit(1);
}

int  fill(char* name,int value,char* type,int scope){
  d_list *temp=head;
  while(temp!=NULL){
    if(strcmp(name,temp->name)==0){
      if(temp->s != scope){
        temp=temp->next;
        continue;
      }  
      yyerror("variable already declared");
      exit(1);
      return  -1;
    }
    temp=temp->next;
  }
  //create new node
  d_list* newnode=(d_list*)malloc(sizeof(d_list));
  strcpy(newnode->name,name);
  strcpy(newnode->type,type);     
  newnode->value.val=value;
  newnode->s=scope;
  newnode->next=head;
  head=newnode;  
  return 1;
}

//str storing
int  fill_str(char* name,char* value,char* type,int scope){
  d_list *temp=head;
  while(temp!=NULL){
    if(strcmp(name,temp->name) == 0){
      yyerror("variable already declared");
      //exit(1);
      return  -1;
    }
    temp=temp->next;
  }
  d_list* newnode=(d_list*) malloc(sizeof(d_list));
  strcpy(newnode->name,name);
  strcpy(newnode->type,type);
  //printf("copying..%s\n",value);
  
  newnode->value.vale=value;
  newnode->s=scope;
  newnode->next=head;
  head=newnode; 
  return 1;
}

int  fill_float(char* name,float value,char* type,int scope){
  d_list *temp=head;
  while(temp!=NULL){
    if(strcmp(name,temp->name) == 0){
      yyerror("variable already declared");
      //exit(1);
      return  -1;
    }
    temp=temp->next;
  }
  d_list* newnode=(d_list*) malloc(sizeof(d_list));
  strcpy(newnode->name,name);
  strcpy(newnode->type,type);
  //printf("copying..%s\n",value);
  
  newnode->value.valu=value;
  newnode->s=scope;
  newnode->next=head;
  head=newnode; 
  return 1;
}


int find_val(char *id){
  d_list* temp;
  temp=head;
  if(head==NULL){
    yyerror("Variable Not declared");
    return -1;
    exit(1);
  }
  while(temp!=NULL){
    if(strcmp(id,temp->name)==0)
      return temp->value.val;
    temp=temp->next;
  }
  yyerror("Variable Not declared");
  return -1;
  exit(1); 
}

/* ------- scope of the variable --------- */

struct Stack* createStack() { 
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); 
    stack->capacity = 100; 
    stack->top = -1; 
    stack->array = (int*)malloc(stack->capacity * sizeof(int)); 
    return stack; 
}

int isEmpty(struct Stack* stack) { 
    return stack->top == -1; 
} 

void push(struct Stack* stack, int item) { 
    if (stack->top == (stack->capacity)-1) 
        return; 
    stack->array[++stack->top] = item; 
    //printf("%d pushed to stack\n", item); 
}

int pop(struct Stack* stack) { 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top--]; 
}

int peek(struct Stack* stack) { 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top]; 
}

/* ------------- Display the symbol table ---------- */

void display(){
  d_list* node;
  node=head;
  printf("------------------- HASH TABLE ------------------\n\n");
  printf("\tType\tName\tValue\t\tScope\n");
  while(node!=NULL){
      if(strcmp(node->type,"int")==0){
        printf("\t%s\t%s\t%d\t\t%d\n",node->type,node->name,node->value.val,node->s);
      }
      else if(strcmp(node->type,"char")==0){
        printf("\t%s\t%s\t%s\t\t%d\n",node->type,node->name,node->value.vale,node->s);
      }
      else if(strcmp(node->type,"float")==0){
        printf("\t%s\t%s\t%f\t%d\n",node->type,node->name,node->value.valu,node->s);
      }
      node=node->next;
  }
  printf("\n");
}

void yyerror(char *s) {
fprintf(stderr, "%d : %s\n", line,s);
}

/* ------- main function --------- */

int main()
{
  stack_arr = createStack();
  yyparse();

  return 0;
}



