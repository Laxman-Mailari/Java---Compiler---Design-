%{
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include "header.h"
	void yyerror(const char *);

	FILE *yyin;
	int yylex();
	extern int line;
	FILE *opt;
	FILE *opt2;

	/* ----- this structure is for evaluating common sub expression ---*/
	typedef struct Node2{
		char *str1;
		char *opr1;
		char *str2;
		char *opr2;
		char *str3;
		struct Node2 *next;
	}node2;
	node2 *head2 = NULL;
	void add_strs2(char *s1,char *op1,char *s2,char *op2,char *s3);
	char* find_exp(char *s1,char *s2,char *s3);

	/* ---- it is for symbol table ------*/
	typedef struct symbol_table_node
	{
		char name[30];
		int data;
	}NODE;

	NODE table[100];
	int top = -1;
	
	void add_update(char*,int);		//evaluate expression and store it in the table
	int getVal(char*);		//get the data from symbol table
	int calculate(char*,int,int);
	void Display();

	/* -- storing the equivalent id's in the file --- */
	node *head=NULL;
	void add_strs(char *op,char *s1,char *s2);
%}
%union{
    	int number;
    	char *string;
}
%token <number> T_NUM
%token <string> T_ID 
%type  <string> Operator

%token T_LOR T_LAND T_DEQL T_NEQL T_COLON T_SUB T_ADD T_MUL T_DIV T_LT T_GT T_EQL T_GOTO T_IF

%%
start:
	STATEMENTS	{ Display();}
	;

STATEMENTS:
	STATEMENT
	| STATEMENT STATEMENTS	
	;
STATEMENT:
	T_ID T_EQL T_ID Operator T_ID {
		//printf("both ids :%d\n",getVal($5));
		//char* temp=$4->value.str;
		char *t=find_exp($3,$4,$5);
		
		if(strlen(t)!=0){
			/* ----- whenever the expression is repeated  i just don't print that expression ----*/

			add_strs("=",t,$1);
		}
		else{
			add_strs2($1,"=",$3,$4,$5);
			if(strcmp($4,"<")==0 || strcmp($4,">")==0 || strcmp($4,"<=")==0 || strcmp($4,">=")==0)
					fprintf(opt,"%s = %s %s %s\n",$1,$3,$4,$5);
			else if(getVal($5)==-1 && getVal($3)==-1)
				fprintf(opt,"%s = %s %s %s\n",$1,$3,$4,$5);
			else if(getVal($5)!= -1){
				if(getVal($3)==-1){
					//printf("inside both ids printing\n");
					fprintf(opt,"%s = %s %s %d\n",$1,$3,$4,getVal($5));
					
				}
				else{
					//printf("inside both ids adding\n");
					add_update($1,calculate($4,getVal($3),getVal($5)));
				}
					
			}
			else if(getVal($3)!= -1){
				fprintf(opt,"%s = %d %s %s\n",$1,getVal($3),$4,$5);
			}
		}
		
		
	}
	|	T_ID T_EQL T_ID Operator T_NUM {
			if(strcmp($4,"<")==0 || strcmp($4,">")==0 || strcmp($4,"<=")==0 || strcmp($4,">=")==0)
				fprintf(opt,"%s = %s %s %d\n",$1,$3,$4,$5);
			else if(getVal($3) != -1){
				add_update($1,calculate($4,getVal($3),$5));
			}
			else
				fprintf(opt,"%s = %s %s %d\n",$1,$3,$4,$5);

	}
	|	T_ID T_EQL T_NUM Operator T_ID {
			if(strcmp($4,"<")==0 || strcmp($4,">")==0 || strcmp($4,"<=")==0 || strcmp($4,">=")==0)
				fprintf(opt,"%s = %d %s %s\n",$1,$3,$4,$5);
			else if(getVal($5) != -1){
				add_update($1,calculate($4,$3,getVal($5)));
			}
			else
				fprintf(opt,"%s = %d %s %s\n",$1,$3,$4,$5);
}
	|	T_ID T_EQL T_NUM Operator T_NUM {
			add_update($1,calculate($4,$3,$5));
	}
	|	T_ID T_EQL T_NUM 	{ 	add_update($1,$3);	}
	|	T_ID T_EQL T_ID 	{
			if(getVal($3)!= -1){
				add_update($1,getVal($3));
			}
			else
			 	add_strs("=",$1,$3);
	}
    |   T_IF T_ID T_GOTO T_ID    { fprintf(opt,"if %s goto %s\n",$2,$4);}
    |   T_GOTO T_ID     {fprintf(opt,"goto %s\n",$2);}
    |   T_ID T_COLON    {fprintf(opt,"%s:\n",$1);}

	;

Operator:
T_ADD	{$$="+";} | T_SUB {$$="-";} | T_MUL {$$="*";} | T_DIV {$$="/";} | T_EQL {$$="=";} | T_LT {$$="<";} | T_GT {$$=">";}
	;

%%

void add_strs(char *op,char *s1,char *s2){
	node *temp;
	temp = (node*)malloc(sizeof(node));
	temp->opr=op;
	temp->str1=s1;
	temp->str2=s2;

	if(head == NULL){
		temp->next=NULL;
		head=temp;
		return;
	}
	temp->next=head;
	head=temp;
}


int main(){
	opt = fopen("Optimised.txt", "w");
	opt2 = fopen("temp_var.txt", "w");
	if(opt==NULL)
		printf("ICG not found\n");

	yyin = fopen("icg.txt","r");
	if(!yyparse())
		printf("Optimised ICG Generated\n");

	return 1;
}

void yyerror(const char *msg)
{

	printf("\n");
	printf("ERROR\n");
	printf("Parsing Unsuccesful\n");
	printf("Error at line %d\n\n",line);

}

void add_update(char* name,int value)
{
	if(top==-1){
		top++;
		strcpy(table[top].name,name);
		table[top].data=value;
		return;
	}
	for(int i = top;i>=0;i--){
		if(strcmp(table[i].name,name)==0){
			table[i].data=value;
			return;
		}
	}

	top++;
	strcpy(table[top].name,name);
	table[top].data=value;
}

int  getVal(char *name){
	for(int i = top;i>=0;i--){
		if(strcmp(table[i].name,name)==0){
			return table[i].data;
		}
	}
	return -1;
}
void Display(){
	printf("\tname\tvalue\n");
	for(int i = top;i>=0;i--){
		printf("\t%s\t%d\n",table[i].name,table[i].data);
	}

	node *temp;
	temp=head;
	while(temp!=NULL){
		//printf("%s %s\n",temp->str1,temp->str2);
		fprintf(opt2,"%s %s\n",temp->str1,temp->str2);
		temp=temp->next;
	}

	
}

int calculate(char* opr,int oper1,int oper2){
	char* result;
	result = (char*)malloc(sizeof(char)*30);
	int res;
	if(strcmp(opr,"+")==0)
		res = oper1 + oper2;
	if(strcmp(opr,"-")==0)
		res = oper1 - oper2;
	if(strcmp(opr,"*")==0)
		res = oper1 * oper2;
	if(strcmp(opr,"/")==0)
		res = oper1 / oper2;
	if(strcmp(opr,">")==0)
		res = oper1 > oper2;
	if(strcmp(opr,"<")==0)
		res = oper1 < oper2;
	if(strcmp(opr,"==")==0)
		res = oper1 == oper2;
	if(strcmp(opr,"!=")==0)
		res = oper1 != oper2;
	if(strcmp(opr,"&&")==0)
		res = oper1 && oper2;
	if(strcmp(opr,"||")==0)
		res = oper1 || oper2;

	return res;
}


void add_strs2(char *s1,char *op1,char *s2,char *op2,char *s3){
	node2 *temp;
	temp = (node2*)malloc(sizeof(node2));
	temp->str1=s1;
	temp->opr1=op1;
	temp->str2=s2;
	temp->opr2=op2;
	temp->str3=s3;

	if(head2 == NULL){
		temp->next=NULL;
		head2=temp;
		return;
	}
	temp->next=head2;
	head2=temp;
}

char* find_exp(char *s1,char *s2,char *s3){
	node2 *temp;
	temp=head2;
	while(temp!=NULL){
		if(strcmp(temp->str2,s1) == 0 && strcmp(temp->opr2,s2) == 0 && strcmp(temp->str3,s3) == 0)
			return temp->str1;

		temp=temp->next;
	}
	return "";

}