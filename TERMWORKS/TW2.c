//TW 2 Conversion of infix exp to postfix exp

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 20

char stack[MAX];
int top=-1;

void push(char x)
{
    if(top==MAX-1)
    {
	printf("\nStack Overflow");
	return;
    }
    stack[++top]=x;
}

char pop()
{
    if(top==-1)
       return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if(x=='(')
        return 0;
    if(x=='+' || x== '-')
        return 1;
    if(x=='*' || x== '/')
        return 2;
}

void valid(char infix[40])
{
	int i;
	for(i=0; infix[i]!='\0'; i++)
	{
		if(infix[i]=='(')
			push('(');
		else
        if(infix[i]==')')
			pop();
	}
	if (top==-1)
    {
        printf("\nExpression is valid\n");
        return;
    }
	else
    {
       printf("\nInvalid expression\n");
       exit(1);
    }
}

int main()
{
    char exp[40], *e, x;
    printf("\nEnter the expression: ");
    scanf("%s", exp);
    valid(exp);

    e=exp;
    while(*e!='\0')
    {
        if(isalnum(*e))
            printf("%c", *e);
        else
        if(*e=='(')
               push(*e);
        else
        if(*e==')')
        {
           while((x=pop())!='(')
                printf("%c", x);
        }
        else
        {
             while(priority(stack[top])>=priority(*e))
                printf("%c", pop());
             push(*e);
        }
        e++;
    }
    while(top!=-1)
        printf("%c", pop());
	printf("\n");
    return 0;
}
