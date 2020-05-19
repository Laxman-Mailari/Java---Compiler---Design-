all:
	lex lex1.l
	yacc -d -v java-yacc.y
	gcc y.tab.c lex.yy.c -ll
	