%{
	
    #include <stdio.h>
    #include <stdlib.h>
    #include "y.tab.h"
 


    extern void yyerror(const char *);
    int line = 1;
%}

digit	[0-9]
alpha	[a-zA-Z]
und	"_"
comment_start \/\* 
comment_end  \*\/ 

%%
[\n]				{line++;}
[\t \n]
\/\/(.*)    {}; 
{comment_start}(.|[\n])*{comment_end} {};
({digit})+	{yylval.number=atoi(yytext); return T_NUM;}
"||"				{return T_LOR;}
"&&"				{return T_LAND;}
"=="				{return T_DEQL;}
"!="				{return T_NEQL;}


":"					{return T_COLON; }
"-"					{return T_SUB; }
"+"					{return T_ADD; }
"*"					{return T_MUL; }
"/"					{return T_DIV; }
"<"					{return T_LT; }
">"					{return T_GT; }
"="					{return T_EQL; }
"<="                {return T_LE;}
">="                {return T_GE;}

"goto"				{return T_GOTO;}
"if"				{return T_IF;}

({alpha}|{und})({alpha}|{und}|{digit})*	{yylval.string=strdup(yytext); return T_ID; }
.					{  }
%%

