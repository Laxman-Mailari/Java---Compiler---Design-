all:
	lex optimicons.l
	yacc -d -v optimicons.y
	gcc lex.yy.c y.tab.c -ll -ly 
	
	