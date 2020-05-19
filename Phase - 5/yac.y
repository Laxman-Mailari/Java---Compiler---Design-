%{
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>

    /* ------- keep track of t_var and r_var equivalent ------- */
    typedef struct Node{
		char *opr;
		char *str1;
		char *str2;
		struct Node *next;
    }node; 
	void yyerror(const char *);

    /* table of register holding the value */
    typedef struct symbol_table_node
	{
		char name[30];
		int data;
	}NODE;

	NODE table[100];
	int top = -1;

    void add_update(char*,int); //update the new register value
	char*  getVar(int); //get the register which is storing int parameter int(number)

    /* ----------- the efficient use of registers ------------*/
    typedef struct register_table
    {
        char *Rname;
        int Rstatus;
        struct register_table *next;
    }REGISTERS;

    REGISTERS *Rhead = NULL;

    void changeStatus(char *str);
    char* temp_register();

	FILE *yyin;
	int yylex();
	extern int line;
	FILE *opt2;
	FILE *fp;

    int find_str(char *str);
    char* newTemp();
    void display();
    void add_strs(char *op,char *s1,char *s2);

    char *data,*if_opr;
    int tn = 1;
    node *head=NULL;

    
%}
%union{
    	int number;
    	char *string;
}
%token <number> T_NUM
%token <string> T_ID 
%type  <string> Operator

%token T_LOR T_LAND T_DEQL T_NEQL T_COLON T_SUB T_ADD T_MUL T_DIV T_LT T_GT T_EQL T_GOTO T_IF T_LE T_GE

%%
start:
	STATEMENTS	    
	;

STATEMENTS:
	STATEMENT
	| STATEMENT STATEMENTS	
	;
STATEMENT:
	T_ID T_EQL T_ID Operator T_ID {
        //printf("hello world\n");
        char *r1,*r2;
        if(find_str($3))
            r1 = data;
        else {
            r1 = temp_register();
            add_strs("=",r1,$3);
            fprintf(opt2,"LD %s %s\n",r1,$3);
        }
        if(find_str($5))
            r2 = data;
        else {
            r2 = temp_register();
            add_strs("=",r2,$5);
            fprintf(opt2,"LD %s %s\n",r2,$5);
        }

        char *r3 = temp_register();
        if(strcmp($4,"+") == 0){
            fprintf(opt2,"ADD %s %s %s\n",r3,r1,r2);
            fprintf(opt2,"STR %s %s\n",$1,r3);
            changeStatus(r3);
        } 
        else if(strcmp($4,"-") == 0){
            fprintf(opt2,"SUB %s %s %s\n",r3,r1,r2);
            fprintf(opt2,"STR %s %s\n",$1,r3);
            changeStatus(r3);
        }
        else if(strcmp($4,"*") == 0){
            fprintf(opt2,"MUL %s %s %s\n",r3,r1,r2);
            fprintf(opt2,"STR %s %s\n",$1,r3);
            changeStatus(r3);
        }
        else if(strcmp($4,"/") == 0){
            fprintf(opt2,"DIV %s %s %s\n",r3,r1,r2);
            fprintf(opt2,"STR %s %s\n",$1,r3);
            changeStatus(r3);
        }
        else if(strcmp($4,"<") == 0){
            if_opr = "<";
            fprintf(opt2,"SUB %s %s %s\n",r3,r1,r2);
            add_strs("=",$1,r3);
        }
        else if(strcmp($4,">") == 0){
            if_opr = ">";
            fprintf(opt2,"SUB %s %s %s\n",r3,r1,r2);
            add_strs("=",$1,r3);
        }
        else if(strcmp($4,"<=") == 0){
            if_opr = "<=";
            fprintf(opt2,"SUB %s %s %s\n",r3,r1,r2);
            add_strs("=",$1,r3);
        }
        else if(strcmp($4,">=") == 0){
            if_opr = ">=";
            fprintf(opt2,"SUB %s %s %s\n",r3,r1,r2);
            add_strs("=",$1,r3);
        }
        //add_strs("=",$1,r3);
        
	}
	|	T_ID T_EQL T_ID Operator T_NUM {

        char *r1,*r3,*r0;
        r0 = getVar($5);
        
        if(strlen(r0)==0){
            r0 = temp_register();
            fprintf(opt2,"MOV %s %d\n",r0,$5);
            add_update(r0,$5);
        }
        
        if(find_str($3))
            r1 = data;
        else {
            r1 = temp_register();
            add_strs("=",r1,$3);
            fprintf(opt2,"LD %s %s\n",r1,$3);
        }
        r3 = temp_register();
        if(strcmp($4,"+") == 0) {fprintf(opt2,"ADD %s %s %s\n",r3,r1,r0);fprintf(opt2,"STR %s %s\n",$1,r3);changeStatus(r3);}
        else if(strcmp($4,"-") == 0) {fprintf(opt2,"SUB %s %s %s\n",r3,r1,r0);fprintf(opt2,"STR %s %s\n",$1,r3);changeStatus(r3);}
        else if(strcmp($4,"*") == 0) {fprintf(opt2,"MUL %s %s %s\n",r3,r1,r0);fprintf(opt2,"STR %s %s\n",$1,r3);changeStatus(r3);}
        else if(strcmp($4,"/") == 0) {fprintf(opt2,"DIV %s %s %s\n",r3,r1,r0);fprintf(opt2,"STR %s %s\n",$1,r3);changeStatus(r3);}
        else if(strcmp($4,"<") == 0){
            if_opr = "<";
            fprintf(opt2,"SUB %s %s %s\n",r3,r1,r0);
            add_strs("=",$1,r3);
        }
        else if(strcmp($4,">") == 0){
            if_opr = ">";
            fprintf(opt2,"SUB %s %s %s\n",r3,r1,r0);
            add_strs("=",$1,r3);
        }
        else if(strcmp($4,"<=") == 0){
            if_opr = "<=";
            fprintf(opt2,"SUB %s %s %s\n",r3,r1,r0);
            add_strs("=",$1,r3);
        }
        else if(strcmp($4,">=") == 0){
            if_opr = ">=";
            fprintf(opt2,"SUB %s %s %s\n",r3,r1,r0);
            add_strs("=",$1,r3);
        }
        //add_strs("=",$1,r3);

	}
	|	T_ID T_EQL T_NUM Operator T_ID {

        char *r1,*r3,*r0;
        r0 = getVar($3);
        if(strlen(r0)==0){
            r0 = temp_register();
            fprintf(opt2,"MOV %s %d\n",r0,$3);
            add_update(r0,$3);
        }

        if(find_str($5))
            r1 = data;
        
        else {
            r1 = temp_register();
            add_strs("=",r1,$5);
            fprintf(opt2,"LD %s %s\n",r1,$5);
        }
        r3 = temp_register();
        
        if(strcmp($4,"+") == 0) {fprintf(opt2,"ADD %s %s %s\n",r3,r1,r0);fprintf(opt2,"STR %s %s\n",$1,r3);changeStatus(r3);}
        else if(strcmp($4,"-") == 0) {fprintf(opt2,"SUB %s %s %s\n",r3,r1,r0);fprintf(opt2,"STR %s %s\n",$1,r3);changeStatus(r3);}
        else if(strcmp($4,"*") == 0) {fprintf(opt2,"MUL %s %s %s\n",r3,r1,r0);fprintf(opt2,"STR %s %s\n",$1,r3);changeStatus(r3);}
        else if(strcmp($4,"/") == 0) {fprintf(opt2,"DIV %s %s %s\n",r3,r1,r0);fprintf(opt2,"STR %s %s\n",$1,r3);changeStatus(r3);}
        else if(strcmp($4,"<") == 0){
            if_opr = "<";
            fprintf(opt2,"SUB %s %s %s\n",r3,r1,r0);
            add_strs("=",$1,r3);
            
        }
        else if(strcmp($4,">") == 0){
            if_opr = ">";
            fprintf(opt2,"SUB %s %s %s\n",r3,r1,r0);
            add_strs("=",$1,r3);
            
        }
        else if(strcmp($4,"<=") == 0){
            if_opr = "<=";
            fprintf(opt2,"SUB %s %s %s\n",r3,r1,r0);
            add_strs("=",$1,r3);
            
        }
        else if(strcmp($4,">=") == 0){
            if_opr = ">=";
            fprintf(opt2,"SUB %s %s %s\n",r3,r1,r0);
            add_strs("=",$1,r3);
            
        }
        //add_strs("=",$1,r3);
        
    }


    |   T_IF T_ID T_GOTO T_ID    { 
        char *r1;
        if(find_str($2))
            r1 = data;
        //printf("data : %s",r1);
        if(strcmp(if_opr,"<")== 0)   fprintf(opt2,"BLTZ %s %s\n",r1,$4);
        else if(strcmp(if_opr,">")== 0)   fprintf(opt2,"BGTZ %s %s\n",r1,$4);
        else if(strcmp(if_opr,"<=")== 0)   fprintf(opt2,"BLEZ %s %s\n",r1,$4);
        else if(strcmp(if_opr,">=")== 0)   fprintf(opt2,"BGEZ %s %s\n",r1,$4);
        }
    |   T_GOTO T_ID     {fprintf(opt2,"BR %s\n",$2);}
    |   T_ID T_COLON    {fprintf(opt2,"%s :\n",$1);}
	;

Operator:
T_ADD	{$$="+";} | T_SUB {$$="-";} | T_MUL {$$="*";} | T_DIV {$$="/";} | T_EQL {$$="=";} | T_LT {$$="<";} | T_GT {$$=">";} | T_LE {$$="<=";} | T_GE {$$=">=";}
	;

%%

int find_str(char *str){
    node *temp;
	temp=head;
	while(temp!=NULL){
        
        if( strcmp(temp->str1,str) == 0){	
			data = temp->str2;
			return 1;
		}
		else if(strcmp(temp->str2,str) == 0){
			data = temp->str1;
			return 1;
		}
		temp=temp->next;
	}
    
	return 0;
}

char* newTemp(){
	char *s = (char*)malloc(4*sizeof(char));
	sprintf(s,"R%d",tn);
	tn++;
	return s;
}

int main(){
	opt2 = fopen("output.txt", "w");
	
	if(opt2==NULL)
		printf("ICG not found\n");

	yyin = fopen("input.txt","r");
	if(!yyparse())
		printf("Assembly code generated\n");

	return 1;
}

void yyerror(const char *msg)
{

	printf("\n");
	printf("ERROR\n");
	printf("Parsing Unsuccesful\n");
	printf("Error at line %d\n\n",line);

}

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

void display(){
    node *temp;
	temp=head;
	while(temp!=NULL){
        
		printf("%s %s\n",temp->str1,temp->str2);
		temp=temp->next;
	}
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

char*  getVar(int num){
	for(int i = top;i>=0;i--){
		if(table[i].data==num){
			return table[i].name;
		}
	}
	return "";
}


char* temp_register(){
    REGISTERS *temp;
    temp = Rhead;
    while(temp != NULL){
        if(temp->Rstatus == 0){
            temp->Rstatus =1;
            return temp->Rname;
        }
        temp = temp->next;
    }
    REGISTERS *temp2;
    temp2 = (REGISTERS*)malloc(sizeof(REGISTERS));
    char *new_Rname = newTemp();
    temp2->Rname = new_Rname;
    temp2->Rstatus = 1;
    temp2 ->next = Rhead;
    Rhead = temp2;
    return new_Rname;

}

void changeStatus(char *str){
    REGISTERS *temp;
    temp = Rhead;
    while(temp != NULL){
        if(strcmp(temp->Rname,str) == 0){
            temp->Rstatus =0;
            return ;
        }
        temp = temp->next;
    }
}

