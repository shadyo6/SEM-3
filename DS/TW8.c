// TW 8 BST

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    char data;
    struct Node *right;
    struct Node *left;
}Node;

//Prototypes
Node* createNode(int);
Node* insert(Node *, int);
int leafNodes(Node *);
int nonLeafNodes(Node *);
int twoDegreeNodes(Node *);
int totalNodes(Node *);
Node* deleteNodes(Node *);

Node* createNode(int data)
{
    Node *tmp = (Node*)malloc(sizeof(Node));
    if(tmp == NULL)
    {
        printf("\nMalloc failure");
        return NULL;
    }
    tmp->data = data;
    tmp->right = tmp->left = NULL;
    return tmp;
}

Node* insert(Node *root, int data)
{
    if(root == NULL)
    {
        root = createNode(data);
    }
    else if(data < root->data)
    {
        root->left = insert(root->left,data);
    }
    else if(data > root->data)
    {
        root->right = insert(root->right,data);
    }
    return root;
}

int leafNodes(Node *root)
{
    if(root != NULL)
    {
        if(root->left == NULL && root->right == NULL)
        {
            return 1;
        }
        else
        {
            return leafNodes(root->left)+leafNodes(root->right);
        }
    }
    else
        return 0;
}
int nonLeafNodes(Node *root)
{
    if(root == NULL)
    {
        return 0;
    }
    else if(root->left == NULL && root->right == NULL)
    {
        return 0;
    }
    else
    {
        return 1+nonLeafNodes(root->left)+nonLeafNodes(root->right);
    }
}
int twoDegreeNodes(Node *root)
{
    if(root == NULL)
    {
        return 0;
    }
    else if(root->left != NULL && root->right != NULL)
    {
        return 1+twoDegreeNodes(root->left)+twoDegreeNodes(root->right);
    }
    else if(root->left != NULL)
    {
        return twoDegreeNodes(root->left);
    }
    else if(root->right != NULL)
    {
        return twoDegreeNodes(root->right);
    }
    return 0;
}

Node* deleteNodes(Node *root)   //Postorder deletion
{
    if(root == NULL)
    {
        return NULL;
    }
    root->left = deleteNodes(root->left);
    root->right = deleteNodes(root->right);
    printf("\nDeleted: %d", root->data);
    free(root);
    return root;
}

int totalNodes(Node *root)
{
    if(root == NULL)
    {
        return 0;
    }
    return 1+totalNodes(root->left)+totalNodes(root->right);
}

int main(void)
{
    int n,i,data;
    Node *root=NULL;
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the elements");
    for(i=0;i<n;i++)
    {
        printf("\nEnter the element %d: ",i+1);
        scanf("%d", &data);
        root = insert(root,data);
    }
    
    printf("\nNumber of leaf nodes: %d", leafNodes(root));
    printf("\nNumber of non leaf nodes: %d", nonLeafNodes(root));
    printf("\nNumber of nodes having two out degree: %d", twoDegreeNodes(root));
    printf("\nTotal number of nodes: %d", totalNodes(root));
    
    root = deleteNodes(root);   //deletes all nodes and return NULL
    printf("\n");
    return 0;
}
