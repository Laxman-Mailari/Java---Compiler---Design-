%{
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	void yyerror(const char *);

	

	FILE *yyin;
	int yylex();
	extern int line;
	FILE *opt2;
	FILE *fp;

	/* every time open the file and serch the quivalent id */
    int find_str(char *str);	
    char* data;	//searched  data stored here
	
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
	STATEMENTS	
	;

STATEMENTS:
	STATEMENT
	| STATEMENT STATEMENTS	
	;
STATEMENT:
	T_ID T_EQL T_ID Operator T_ID {
		
		if(strcmp($4,"<")==0 || strcmp($4,">")==0 || strcmp($4,"<=")==0 || strcmp($4,">=")==0)
				fprintf(opt2,"%s = %s %s %s\n",$1,$3,$4,$5);
        else if(find_str($1)==1){
			char *temp = data;
			if(find_str($3)==1)
				fprintf(opt2,"%s = %s %s %s\n",temp,data,$4,$5);
			else
				fprintf(opt2,"%s = %s %s %s\n",temp,$3,$4,$5); 
            
        }
        else{
			if(find_str($3)==1)
				fprintf(opt2,"%s = %s %s %s\n",$1,data,$4,$5);
			else
				fprintf(opt2,"%s = %s %s %s\n",$1,$3,$4,$5); 
		}
           
	}
	|	T_ID T_EQL T_ID Operator T_NUM {
			if(strcmp($4,"<")==0 || strcmp($4,">")==0 || strcmp($4,"<=")==0 || strcmp($4,">=")==0)
				fprintf(opt2,"%s = %s %s %d\n",$1,$3,$4,$5);
			else if(find_str($1)==1){
				fprintf(opt2,"%s = %s %s %d\n",data,$3,$4,$5);
			}
			else
				fprintf(opt2,"%s = %s %s %d\n",$1,$3,$4,$5);

	}
	|	T_ID T_EQL T_NUM Operator T_ID {
			if(strcmp($4,"<")==0 || strcmp($4,">")==0 || strcmp($4,"<=")==0 || strcmp($4,">=")==0)
				fprintf(opt2,"%s = %d %s %s\n",$1,$3,$4,$5);
			else if(find_str($1)==1){
				fprintf(opt2,"%s = %d %s %s\n",data,$3,$4,$5);
			}
			else
				fprintf(opt2,"%s = %d %s %s\n",$1,$3,$4,$5);
        }


    |   T_IF T_ID T_GOTO T_ID    { fprintf(opt2,"if %s goto %s\n",$2,$4);}
    |   T_GOTO T_ID     {fprintf(opt2,"goto %s\n",$2);}
    |   T_ID T_COLON    {fprintf(opt2,"%s :\n",$1);}
	;

Operator:
T_ADD	{$$="+";} | T_SUB {$$="-";} | T_MUL {$$="*";} | T_DIV {$$="/";} | T_EQL {$$="=";} | T_LT {$$="<";} | T_GT {$$=">";}
	;

%%
int find_str(char *str){
	/*reading the file*/
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    char *p = NULL;
	char *temp1,*temp2;
    fp = fopen("temp_var.txt", "r");  //it has equivalent id's
    if (fp == NULL)
        printf("fp not found\n");

    while((read = getline(&line, &len, fp)) != -1) {
        p = strtok(line," ");
		temp1 = p; 
        p = strtok(NULL," ");
        temp2 = p;
		p = strtok(NULL," ");
		if( strcmp(temp2,str) == 10){	/*temp has newline character along with string so that diff is 10*/
			data = temp1;
			return 1;
		}
		else if(strcmp(temp1,str) == 10){
			data = temp2;
			return 1;
		}
    }
	return 0;
}


int main(){
	opt2 = fopen("final.txt", "w");	
	
	
	if(opt2==NULL)
		printf("ICG not found\n");

	yyin = fopen("Optimised.txt","r");
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




