//TW 3 Evaluation of Postfix Exp

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int stack[MAX], top;

void push(int item);
int pop();
int postfixeval(char []);

int main()
{
    char exp[20];
    top=-1;
    printf("\nEnter a valid postfix expression: ");
    scanf("%[^\n]s",exp);
    printf("\nEvaluated result is: %d\n", postfixeval(exp));
    return 0;
}

void push(int item)
{
    if(top==MAX-1)
    {
        printf("\nStack Overflow");
        return;
    }
    stack[++top]=item;
}


int pop()
{
    if(top==-1)
    {
        printf("\nStack Underflow");
        return(-1);
    }
    return(stack[top--]);

}


int postfixeval(char exp[])
{
    int i, opd1, opd2;
    for(i=0; exp[i]!='\0'; i++)
    {
        if(exp[i]>='0' && exp[i]<='9')
            push(exp[i]-'0');
        else
        {
            opd2 = pop();
            opd1 = pop();
            switch(exp[i])
            {
                case '+': push(opd1+opd2); break;
                case '-': push(opd1-opd2); break;
                case '*': push(opd1*opd2); break;
                case '/': if(opd2==0)
                          {
                              printf("\nDivide by zero error\n");
                              exit(1);
                          }
                          push(opd1/opd2);
            }
    }
    }
    return(pop());
}
