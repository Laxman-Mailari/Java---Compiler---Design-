all:
	lex lex.l
	yacc -d -v yac.y
	gcc lex.yy.c y.tab.c -ll -ly