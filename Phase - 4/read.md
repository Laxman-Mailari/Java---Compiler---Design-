Optimization of intermediate code:

1.constant propagation: replace the variable with constant value
2.constant folding: evaluating the expression has the all constant values(ex. a = 10+20)
3.copy propagation : after copy the data.it will be propagated to subsequent equations.
4.dead code elimination : remove the unused equations
5.common subexpression elimination


execution:

% make

% ./a.out

% lex optimicons2.l

% yacc -d -v optimicons2.y

% gcc lex.yy.c y.tab.c -ll -ly

% ./a.out


// finally optimized output is stored in final.txt
// you need this output data to next phase for assembly code generation
