//Expression tree

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>

typedef struct node
{
    char data;
    struct node *left;
    struct node *right;
    struct node *next;
}Node;

Node *top = NULL;

Node* newNode(char);
void inorder(Node*);
void preorder(Node*);
void postorder(Node*);
void push(Node*);
Node* pop();

Node* newNode(char data)
{
    Node* root = (Node*)malloc(sizeof(Node));
    root->data = data;
    root->right = NULL;
    root->left = NULL;
    root->next = NULL;
    return root;
}

void inorder(Node* root)
{
    if(isalnum(root->data))
        printf("%c", root->data);
    else if(root != NULL)
    {
        printf("( ");
        inorder(root->left);
        printf(" %c ", root->data);
        inorder(root->right);
        printf(" )");
    }
}

void preorder(Node* root)
{
    if(root != NULL)
    {
        printf("%c ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%c ",root->data);
    }
}

void push(Node* root)
{
    if(top == NULL)
        root->next = NULL;
    else
        root->next = top;
    top = root;
}

Node* pop()
{
    if(top == NULL)
        return NULL;
    Node* newNode = top;
    top = top->next;
    return newNode;
}

int main(void)
{
    char s[30];
    Node *root = NULL;
    int i,l;
    
    printf("\nEnter the postfix expression: ");
    scanf("%[^\n]s", s);
    l = strlen(s);

    printf("\nExpression: ");
    for(i=0;i<l;i++)
        printf("%c ", s[i]);
    printf("\nlength: %d", l);
    
    for(i=0;i<l;i++)
    {
        root = newNode(s[i]);
        
        if(s[i]=='+' || s[i]=='/' || s[i]=='-' || s[i]=='*')
        {
            root->right = pop();
            root->left = pop();
        }
        push(root);
    }
    
    printf("\nInorder: ");
    inorder(root);
    
    printf("\nPreorder: ");
    preorder(root);
    
    printf("\nPostorder: ");
    postorder(root);
    
    printf("\n");
    return 0;
}
