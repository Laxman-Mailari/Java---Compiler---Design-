
Assembly code generation

you should copy the last phase final.txt data to the input.txt

execution:

% make

$ ./a.out

//finally the assembly code will be stored in output.txt

here,we have implemented efficient use of registers
i.e every time before allocating new register.we check previasly allocated registers are free.
if anyone is free we use the register for now.if not we allocate the new register.
