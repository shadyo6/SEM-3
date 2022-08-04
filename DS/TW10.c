// TW 10 Doubly Linked List

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}NODE;

//Prototypes
void addFront(NODE**,NODE**);
void addRear(NODE**,NODE**);
void disp(NODE*);
void search(NODE*);
void deleteNodes(NODE*);

void addFront(NODE **head, NODE **tail)
{
    int data;
    NODE *tmp=(NODE *)malloc(sizeof(NODE));
    if(tmp==NULL)
    {
        printf("\nMalloc failure");
        exit(1);
    }

    printf("\nEnter data to add: ");
    scanf("%d", &data);
    tmp->data=data;
    tmp->prev=tmp->next=NULL;

    if(*head==NULL && *tail == NULL)
    {
        *head = tmp;
        *tail = tmp;
    }
    else
    {
        tmp->next=(*head);
        (*head)->prev=tmp;
        (*head)=tmp;
    }
}

void addRear(NODE **head, NODE **tail)
{
    int data;
    //NODE *trav;
    NODE *tmp=(NODE *)malloc(sizeof(NODE));
    if(tmp==NULL)
    {
        printf("\nMalloc failure");
        exit(1);
    }

    printf("\nEnter data to add: ");
    scanf("%d", &data);
    tmp->data=data;
    tmp->prev=tmp->next=NULL;

    if(*head==NULL && *tail==NULL) //Empty List
    {
        *head = tmp;
        *tail = tmp;
    }
    else 
    {
        (*tail)->next=tmp;
        tmp->prev=(*tail);
        *tail = tmp;
    }
}

void disp(NODE *head)
{
    if(head==NULL)
    {
        printf("\nList is empty");
        return;
    }

    printf("\nThe List contents are: ");
    while(head)
    {
        printf("%d    ", head->data);
        head=head->next;
    }
}


void search(NODE *head)
{
    int item, count=0;
    if(head==NULL)
    {
        printf("\nList is empty");
        return;
    }
    printf("\nEnter data to search: ");
    scanf("%d", &item);
    while(head)
    {
        if(item==head->data)
        {
            printf("\nData %d present at position %d", item, count+1);
            return;
        }
        else
        {
            count++;
            head=head->next;
        }
    }

    printf("\nData %d not present", item);

}

void deleteNodes(NODE* head)
{
    NODE *tmp = head;
    
    while(head != NULL)
    {
        head=head->next;
        printf("\nDeleted: %d", tmp->data);
        free(tmp);
        tmp=head;
    }
}

//Driver
int main()
{
    NODE *head=NULL;
    NODE *tail=NULL;
    int opt;
    while(1)
    {
        printf("\n1:FrontAdd");
        printf("\n2:RearAdd");
        printf("\n3:Display");
        printf("\n4:Search");
        printf("\n5:Exit");
        printf("\nChoose: ");
        scanf("%d", &opt);
        switch(opt)
        {
            case 1: addFront(&head,&tail);
                    break;
            case 2: addRear(&head,&tail);
                    break;
            case 3: disp(head);
                    break;
            case 4: search(head);
                    break;
            case 5: deleteNodes(head);
                    printf("\nAll nodes deleted successfully\n");
                    exit(0);
        }
    }
    return 0;
}
