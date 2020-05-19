
#include <stdio.h>
#include<limits.h>
//include "header.h"
//#include "y.tab.h"
int tn = 1,ln=0;
char *var1,*var2;
char* newLabel();
char* newTemp();

/*stack for temporary variable*/
typedef struct LList { 
    char *data;
    struct LList* next;
}node;

node * head = NULL;
node* add_node(char* item);
char* remove_node();

static int lbl;

int ex(nodeType *p) {
    int lbl1, lbl2, lbl3;
    

    if (!p) return 0;
    //printf("in ex\n");
    switch(p->type) {
    case typeCon:
        //printf("\tpush\t%d\n", p->con.value);
        break;
    case typeId:
        //printf("\tpush\t%s\n", p->id.str);
        break;
    case typeOpr:
        switch(p->opr.oper) {
        case T_WHILE:
            //printf("\n----while loop ---\n\n");

            printf("L%01d: ", lbl1 = lbl++);
            char *t1=newTemp();
            var1=t1;
            ex(p->opr.op[0]);
            printf("if %s goto L%01d\n",t1,lbl3 = lbl++);
            printf("goto L%01d\n", lbl2 = lbl++);
            printf("L%01d: ", lbl3);
            ex(p->opr.op[1]);
            printf("goto L%01d\n",lbl1);
            printf("L%01d:\n", lbl2);

            break;
        case T_IF:
            /* if else*/
            if (p->opr.nops > 2) {
                //printf("\n ----if else---\n\n");
                char *temp=newTemp();
                var1=temp;
                ex(p->opr.op[0]);
                //printf("%s = %s\n",temp,)
                printf("if %s goto L%01d\n",temp,lbl1 = lbl++);
                printf("goto L%01d\n", lbl2 = lbl++);
                printf("L%01d:\n", lbl1);
                ex(p->opr.op[1]);
                printf("L%01d:\n", lbl2);
                ex(p->opr.op[2]);
                printf("\n");
            } 
            /*if statement*/
            else {
                //printf("\n ----if condition---\n\n");
                char *temp=newTemp();
                var1=temp;
                ex(p->opr.op[0]);
                //printf("%s = %s\n",temp,)
                printf("if %s goto L%01d\n",temp,lbl1 = lbl++);
                printf("goto L%01d\n", lbl2 = lbl++);
                printf("L%01d:\n", lbl1);
                ex(p->opr.op[1]);
                printf("L%01d:\n\n", lbl2);
            }
            break;
        case '=':
            //printf("in equal\n");
            if(p->opr.op[1]->type == 0){
                printf("%s = %d\n",p->opr.op[0]->id.str,p->opr.op[1]->con.value);
            }
            else if(p->opr.op[1]->type == 1){
                printf("%s = %s\n",p->opr.op[0]->id.str,p->opr.op[1]->id.str);
            }
            else{
                char* temp=newTemp();
                var1=temp;
                //printf("hi\n");
                //head=add_node(temp);
                ex(p->opr.op[1]);
                printf("%s = %s\n",p->opr.op[0]->id.str,temp);
            }
            break;
        case ';':
            //printf("in semicoln\n");
            ex(p->opr.op[0]);
            ex(p->opr.op[1]);
            break;
        case '+':
            if(p->opr.op[0]->type == 2 && p->opr.op[1]->type == 2){
                char *temp1=var1,*temp2=newTemp(),*temp3=newTemp();
                var1=temp2,var2=temp3;
                ex(p->opr.op[0]);
                ex(p->opr.op[1]);
                printf("%s = %s + %s\n",temp1,temp2,temp3);
            }
            else if(p->opr.op[0]->type == 2 || p->opr.op[1]->type == 2){
                char *temp1=var1,*temp2=newTemp();
                var1=temp2;
                if(p->opr.op[0]->type == 0){
                    ex(p->opr.op[1]);
                    printf("%s = %d + %s\n",temp1,p->opr.op[0]->con.value,temp2);
                }
                    
                else if(p->opr.op[0]->type == 1){
                    ex(p->opr.op[1]);
                    printf("%s = %s + %s\n",temp1,p->opr.op[0]->id.str,temp2);
                }
                    
                else if(p->opr.op[1]->type == 0){
                    ex(p->opr.op[0]);
                    printf("%s = %s + %d\n",temp1,temp2,p->opr.op[1]->con.value);
                }
                    
                else if(p->opr.op[1]->type == 1){
                    ex(p->opr.op[0]);
                    printf("%s = %s + %s\n",temp1,temp2,p->opr.op[1]->id.str);
                }
            }
            else{
                
                char* temp = var1;
                if(var2) var1=var2;
                
                if(p->opr.op[0]->type == 0 && p->opr.op[1]->type == 0)
                    printf("%s = %d + %d\n",temp,p->opr.op[0]->con.value,p->opr.op[1]->con.value);
                else if(p->opr.op[0]->type == 0 && p->opr.op[1]->type == 1)
                    printf("%s = %d + %s\n",temp,p->opr.op[0]->con.value,p->opr.op[1]->id.str);
                else if(p->opr.op[0]->type == 1 && p->opr.op[1]->type == 0)
                    printf("%s = %s + %d\n",temp,p->opr.op[0]->id.str,p->opr.op[1]->con.value);
                else
                    printf("%s = %s + %s\n",temp,p->opr.op[0]->id.str,p->opr.op[1]->id.str);
            }
            break;
        case '-':
            if(p->opr.op[0]->type == 2 && p->opr.op[1]->type == 2){
                char *temp1=var1,*temp2=newTemp(),*temp3=newTemp();
                var1=temp2,var2=temp3;
                ex(p->opr.op[0]);
                ex(p->opr.op[1]);
                printf("%s = %s - %s\n",temp1,temp2,temp3);
            }
            else if(p->opr.op[0]->type == 2 || p->opr.op[1]->type == 2){
                char *temp1=var1,*temp2=newTemp();
                var1=temp2;
                if(p->opr.op[0]->type == 0){
                    ex(p->opr.op[1]);
                    printf("%s = %d - %s\n",temp1,p->opr.op[0]->con.value,temp2);
                }
                    
                else if(p->opr.op[0]->type == 1){
                    ex(p->opr.op[1]);
                    printf("%s = %s - %s\n",temp1,p->opr.op[0]->id.str,temp2);
                }
                    
                else if(p->opr.op[1]->type == 0){
                    ex(p->opr.op[0]);
                    printf("%s = %s - %d\n",temp1,temp2,p->opr.op[1]->con.value);
                }
                    
                else if(p->opr.op[1]->type == 1){
                    ex(p->opr.op[0]);
                    printf("%s = %s - %s\n",temp1,temp2,p->opr.op[1]->id.str);
                }
            }
            else{
                
                char* temp = var1;
                if(var2) var1=var2;
                
                if(p->opr.op[0]->type == 0 && p->opr.op[1]->type == 0)
                    printf("%s = %d - %d\n",temp,p->opr.op[0]->con.value,p->opr.op[1]->con.value);
                else if(p->opr.op[0]->type == 0 && p->opr.op[1]->type == 1)
                    printf("%s = %d - %s\n",temp,p->opr.op[0]->con.value,p->opr.op[1]->id.str);
                else if(p->opr.op[0]->type == 1 && p->opr.op[1]->type == 0)
                    printf("%s = %s - %d\n",temp,p->opr.op[0]->id.str,p->opr.op[1]->con.value);
                else
                    printf("%s = %s - %s\n",temp,p->opr.op[0]->id.str,p->opr.op[1]->id.str);
            }
            break;
        case '*':
            if(p->opr.op[0]->type == 2 && p->opr.op[1]->type == 2){
                char *temp1=var1,*temp2=newTemp(),*temp3=newTemp();
                var1=temp2,var2=temp3;
                ex(p->opr.op[0]);
                ex(p->opr.op[1]);
                printf("%s = %s * %s\n",temp1,temp2,temp3);
            }
            else if(p->opr.op[0]->type == 2 || p->opr.op[1]->type == 2){
                char *temp1=var1,*temp2=newTemp();
                var1=temp2;
                
                //ex(p->opr.op[1]);
                if(p->opr.op[0]->type == 0){
                    ex(p->opr.op[1]);
                    printf("%s = %d * %s\n",temp1,p->opr.op[0]->con.value,temp2);
                }
                    
                else if(p->opr.op[0]->type == 1){
                    ex(p->opr.op[1]);
                    printf("%s = %s * %s\n",temp1,p->opr.op[0]->id.str,temp2);
                }
                    
                else if(p->opr.op[1]->type == 0){
                    ex(p->opr.op[0]);
                    printf("%s = %s * %d\n",temp1,temp2,p->opr.op[1]->con.value);
                }
                    
                else if(p->opr.op[1]->type == 1){
                    ex(p->opr.op[0]);
                    printf("%s = %s * %s\n",temp1,temp2,p->opr.op[1]->id.str);
                }
                    
            }
            else{
                
                char* temp = var1;
                if(var2) var1=var2;
                if(p->opr.op[0]->type == 0 && p->opr.op[1]->type == 0)
                    printf("%s = %d * %d\n",temp,p->opr.op[0]->con.value,p->opr.op[1]->con.value);
                else if(p->opr.op[0]->type == 0 && p->opr.op[1]->type == 1)
                    printf("%s = %d * %s\n",temp,p->opr.op[0]->con.value,p->opr.op[1]->id.str);
                else if(p->opr.op[0]->type == 1 && p->opr.op[1]->type == 0)
                    printf("%s = %s * %d\n",temp,p->opr.op[0]->id.str,p->opr.op[1]->con.value);
                else
                    printf("%s = %s * %s\n",temp,p->opr.op[0]->id.str,p->opr.op[1]->id.str);
            }
            break;
        case '/':
            if(p->opr.op[0]->type == 2 && p->opr.op[1]->type == 2){
                char *temp1=var1,*temp2=newTemp(),*temp3=newTemp();
                var1=temp2,var2=temp3;
                
                ex(p->opr.op[0]);
                ex(p->opr.op[1]);
                printf("%s = %s / %s\n",temp1,temp2,temp3);
            }
            else if(p->opr.op[0]->type == 2 || p->opr.op[1]->type == 2){
                char *temp1=var1,*temp2=newTemp();
                var1=temp2;
                if(p->opr.op[0]->type == 0){
                    ex(p->opr.op[1]);
                    printf("%s = %d / %s\n",temp1,p->opr.op[0]->con.value,temp2);
                }
                    
                else if(p->opr.op[0]->type == 1){
                    ex(p->opr.op[1]);
                    printf("%s = %s / %s\n",temp1,p->opr.op[0]->id.str,temp2);
                }
                    
                else if(p->opr.op[1]->type == 0){
                    ex(p->opr.op[0]);
                    printf("%s = %s / %d\n",temp1,temp2,p->opr.op[1]->con.value);
                }
                    
                else if(p->opr.op[1]->type == 1){
                    ex(p->opr.op[0]);
                    printf("%s = %s / %s\n",temp1,temp2,p->opr.op[1]->id.str);
                }
            }
            else{
                char *temp=var1;
                if(var2) var1=var2;
                if(p->opr.op[0]->type == 0 && p->opr.op[1]->type == 0)
                    printf("%s = %d / %d\n",temp,p->opr.op[0]->con.value,p->opr.op[1]->con.value);
                else if(p->opr.op[0]->type == 0 && p->opr.op[1]->type == 1)
                    printf("%s = %d / %s\n",temp,p->opr.op[0]->con.value,p->opr.op[1]->id.str);
                else if(p->opr.op[0]->type == 1 && p->opr.op[1]->type == 0)
                    printf("%s = %s / %d\n",temp,p->opr.op[0]->id.str,p->opr.op[1]->con.value);
                else
                    printf("%s = %s / %s\n",temp,p->opr.op[0]->id.str,p->opr.op[1]->id.str);
            }
            break;
        case '>':
            if(p->opr.op[0]->type == 2 && p->opr.op[1]->type == 2){
                char *temp1=var1,*temp2=newTemp(),*temp3=newTemp();
                var1=temp2,var2=temp3;
                
                ex(p->opr.op[0]);
                ex(p->opr.op[1]);
                printf("%s = %s > %s\n",temp1,temp2,temp3);
            }
            else if(p->opr.op[0]->type == 2 || p->opr.op[1]->type == 2){
                char *temp1=var1,*temp2=newTemp();
                var1=temp2;
                if(p->opr.op[0]->type == 0){
                    ex(p->opr.op[1]);
                    printf("%s = %d > %s\n",temp1,p->opr.op[0]->con.value,temp2);
                }
                    
                else if(p->opr.op[0]->type == 1){
                    ex(p->opr.op[1]);
                    printf("%s = %s > %s\n",temp1,p->opr.op[0]->id.str,temp2);
                }
                    
                else if(p->opr.op[1]->type == 0){
                    ex(p->opr.op[0]);
                    printf("%s = %s > %d\n",temp1,temp2,p->opr.op[1]->con.value);
                }
                    
                else if(p->opr.op[1]->type == 1){
                    ex(p->opr.op[0]);
                    printf("%s = %s > %s\n",temp1,temp2,p->opr.op[1]->id.str);
                }
            }
            else{
                char *temp=var1;
                if(var2) var1=var2;
                if(p->opr.op[0]->type == 0 && p->opr.op[1]->type == 0)
                    printf("%s = %d > %d\n",temp,p->opr.op[0]->con.value,p->opr.op[1]->con.value);
                else if(p->opr.op[0]->type == 0 && p->opr.op[1]->type == 1)
                    printf("%s = %d > %s\n",temp,p->opr.op[0]->con.value,p->opr.op[1]->id.str);
                else if(p->opr.op[0]->type == 1 && p->opr.op[1]->type == 0)
                    printf("%s = %s > %d\n",temp,p->opr.op[0]->id.str,p->opr.op[1]->con.value);
                else
                    printf("%s = %s > %s\n",temp,p->opr.op[0]->id.str,p->opr.op[1]->id.str);
            }
            break;
        case '<':
            if(p->opr.op[0]->type == 2 && p->opr.op[1]->type == 2){
                char *temp1=var1,*temp2=newTemp(),*temp3=newTemp();
                var1=temp2,var2=temp3;
                
                ex(p->opr.op[0]);
                ex(p->opr.op[1]);
                printf("%s = %s < %s\n",temp1,temp2,temp3);
            }
            else if(p->opr.op[0]->type == 2 || p->opr.op[1]->type == 2){
                char *temp1=var1,*temp2=newTemp();
                var1=temp2;
                if(p->opr.op[0]->type == 0){
                    ex(p->opr.op[1]);
                    printf("%s = %d < %s\n",temp1,p->opr.op[0]->con.value,temp2);
                }
                    
                else if(p->opr.op[0]->type == 1){
                    ex(p->opr.op[1]);
                    printf("%s = %s < %s\n",temp1,p->opr.op[0]->id.str,temp2);
                }
                    
                else if(p->opr.op[1]->type == 0){
                    ex(p->opr.op[0]);
                    printf("%s = %s < %d\n",temp1,temp2,p->opr.op[1]->con.value);
                }
                    
                else if(p->opr.op[1]->type == 1){
                    ex(p->opr.op[0]);
                    printf("%s = %s < %s\n",temp1,temp2,p->opr.op[1]->id.str);
                }
            }
            else{
                char *temp=var1;
                if(var2) var1=var2;
                if(p->opr.op[0]->type == 0 && p->opr.op[1]->type == 0)
                    printf("%s = %d < %d\n",temp,p->opr.op[0]->con.value,p->opr.op[1]->con.value);
                else if(p->opr.op[0]->type == 0 && p->opr.op[1]->type == 1)
                    printf("%s = %d < %s\n",temp,p->opr.op[0]->con.value,p->opr.op[1]->id.str);
                else if(p->opr.op[0]->type == 1 && p->opr.op[1]->type == 0)
                    printf("%s = %s < %d\n",temp,p->opr.op[0]->id.str,p->opr.op[1]->con.value);
                else
                    printf("%s = %s < %s\n",temp,p->opr.op[0]->id.str,p->opr.op[1]->id.str);
            }
            break;
        default:
                printf("NOT IMPLEMENTED\n");
        
        }
    }
    return 0;
}

char* newLabel(){
	char *s = (char*)malloc(4*sizeof(char));
	sprintf(s,"L%d",ln);
	ln++;
	return s;
}

char* newTemp(){
	char *s = (char*)malloc(4*sizeof(char));
	sprintf(s,"T%d",tn);
	tn++;
	return s;
}

node* add_node(char* item){
    node * temp;
    
    temp->data=item;
    //printf("item in mem:%s\n",temp->data);
    if(head == NULL){
        temp->next=NULL;
        head=temp;
        //printf("item in mem:%s\n",head->data);
        return head;
    }
    temp->next=head->next;
    head=temp;
    return head;
}

char* remove_node(){
    
    if(head == NULL)
        return NULL;
    char* data=head->data;
    //printf("item in mem:%s\n",head);
    head=head->next;
    return data;
}
