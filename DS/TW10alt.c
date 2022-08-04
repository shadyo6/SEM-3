//TW10 doubly linked list
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}Node;

Node *head = NULL;
Node *tail = NULL;

Node* createNode();
void addFront();
void addRear();
int search();
void display();
void deleteNodes();

Node* createNode()
{
    int data;
    Node* tmp = (Node*)malloc(sizeof(Node));
    if(tmp == NULL)
    {
        printf("\nMalloc failure");
        exit(1);
    }
    printf("Front insert data: ");
    scanf("%d", &data);
    
    tmp->data=data;
    tmp->next=tmp->prev=NULL;
    
    return tmp;
}

void addFront()
{
    Node* tmp = createNode();
    if(head == NULL && tail == NULL)
    {
        head = tail = tmp;
    }
    else
    {
        tmp->next=head;
        head->prev=tmp;
        head=tmp;
    }
}

void addRear()
{
    Node* tmp = createNode();
    if(head == NULL && tail == NULL)
    {
        head = tail = tmp;
    }
    else
    {
        tmp->prev=tail;
        tail->next=tmp;
        tail=tmp;
    }
}

void display()
{
    Node* tmp = head;
    printf("\nItems on the list: ");
    while(tmp != NULL)
    {
        printf("%d ",tmp->data);
        tmp=tmp->next;
    }
    printf("\n");
}

void deleteNodes()
{
    Node* tmp = head;
    while(head != NULL)
    {
        head=head->next;
        printf("\nDeleted: %d",tmp->data);
        free(tmp);
        tmp=head;
    }
}

void Search()
{
    int data;
    Node* tmp = head;
    
    if(head == NULL && tail == NULL)
    {
        printf("\nList not created");
        return;
    }

    printf("\nEnter the item to be serached: ");
    scanf("%d", &data);
    
    while(tmp != NULL)
    {
        if(data == tmp->data)
        {
            printf("\nItem found\n");
            return;
        }
        tmp = tmp->next;
    }
    printf("\nItem not found\n");
}

int main(void)
{
    int ch,data;
    
    while(1)
    {
        printf("\n1.Add Front");
        printf("\n2.Add Rear");
        printf("\n3.Search");
        printf("\n4.Display");
        printf("\n5.Exit");
        printf("\nChoose: ");
        scanf("%d", &ch);
        
        switch(ch)
        {
            case 1: addFront();break;
            case 2: addRear();break;
            case 3: Search();break;
            case 4: display();break;
            case 5: deleteNodes();
                printf("\nAll nodes are deleted\n");
                exit(0);
        }
    }
    return 0;
}

