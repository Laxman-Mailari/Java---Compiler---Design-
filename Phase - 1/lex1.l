%{
	#include <stdio.h>
	#include <stdlib.h>	
	#include "y.tab.h"
	int line = 1;
%}

digit	[0-9]
alpha	[a-zA-Z]
und	"_"
Equality [==]
comment_start \/\* 
comment_end  \*\/ 

%%

[\n]  {line++;}
[\t \n]
\/\/(.*) {}; 
{comment_start}(.|[\n])*{comment_end} {};
({digit})+	{yylval.number=atoi(yytext); return T_NUM;}
({digit})*[.]({digit})+ {yylval.fnumber=atof(yytext); return T_FNUM;}


"import" {return T_IMPORT;}	
"class"	 {return T_CLASS;}

"public" 	{return T_PUBLIC;} 
"private" 	{return T_PRIVATE;}
"protected" {return T_PROTECTED;}

"static" {return T_STATIC;} 
"void"	 {return T_VOID;}
"main"	 {return T_MAIN;}
"new" 	 {return T_NEW;}
"return" {return T_RETURN;}
"break"  {return T_BREAK;}

"boolean" {return T_BOOL;} 
"short"   {return T_SHORT;}
"byte"	  {return T_BYTE;}
"char"	  {return T_CHAR;}	
"int" 	  {return T_INT;}
"float"   {return T_FLOAT;}
"long"	  {return T_LONG;}
"double"  {return T_DOUBLE;}

"String args[]" 		{return T_STR_ARG;} 
"String" 				{return T_STR;}
"System.out.println" 	{return T_STDOUT;}

"if" 	{return T_IF;} 
"else" 	{return T_ELSE;} 
"while" {return T_WHILE;}
"for" 	{return T_FOR;}
"do" 	{return  T_DO;}

"true"  {return T_TRUE;} 
"false" {return T_FALSE;}

Equality {return T_S_EQ;}
"+"  	 {return T_S_PLUS;}
"-"   	 {return T_S_MINUS;}
"*"		 {return T_S_MULT;}
"/"		 {return T_S_DIV;}
"--" 	 {return T_U_INCR;}
"++" 	 {return T_U_DECR;}
"+="	 {return T_S_PLUSEQ;}
"-="	 {return T_S_MINUSEQ;}
"*="	 {return T_S_MULTEQ;}
"/="     {return T_S_DIVEQ;}


"!="     {return T_NE;}
">="	 {return T_GEQ;}
"<="	 {return T_LEQ;}
">"		 {return T_GE;}
"<"		 {return T_LE;}
"="      {return T_ASSG;}

"||"	 {return T_LOR;}
"&&"	 {return T_LAND;}
"!"		 {return T_NOT;}


"{"		 {return T_OFB;}
"}"		 {return T_CFB;}
\"({alpha}|{und})({alpha}|{und}|{digit})*\" {yylval.string=strdup(yytext); return T_STRVAL; }
({alpha}|{und})({alpha}|{und}|{digit})*	{yylval.string=strdup(yytext); return T_ID; }
.    {return yytext[0];}
%%
