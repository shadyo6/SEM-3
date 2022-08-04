//TW4 Message Queue

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char *msg;
    struct node *next;
} NODE;

//Prototypes
void Sender(NODE **, NODE **, char *);
char* Receiver(NODE **, NODE **);
void DispQ(NODE *);


int main()
{
    //Create an empty Queue

    NODE *front = NULL;
    NODE *rear = NULL;
    int opt;
    char *msg;
    msg=(char *)malloc(50);
    if(msg==NULL)
    {
        printf("\nMalloc failure");
        exit(1);
    }
    
    while(1)
    {
        printf("\n1: Send a message");
        printf("\n2: Receive message");
        printf("\n3: Display");
        printf("\n4: Exit");
        printf("\nChoose: ");
        scanf("%d", &opt);
        switch(opt)
        {
        case 1: printf("\nEnter the message: ");
                    scanf("%s", msg);
                    Sender(&front, &rear, msg);
                    break;

         case 2:  strcpy(msg,Receiver(&front, &rear));
                  if(strcmp(msg,"Queue underflow")==0)
                    printf("\n%s", msg);
                  else
                    printf("\nReceived message is: %s\n", msg);
                  break;

         case 3: DispQ(front);
                break;
         case 4: exit(0);
        }
    }

    return 0;
}

void Sender(NODE **front, NODE **rear, char *item)
{
    NODE *tmp=(NODE *)malloc(sizeof(NODE));
    if(tmp==NULL)
    {
        printf("\nMemory allocation failure");
        exit(1);
    }

    tmp->msg=(char *)malloc(sizeof(item));
    
    if(tmp->msg==NULL)
    {
        printf("\nMalloc failure");
        exit(2);
    }
    
    strcpy(tmp->msg, item);
    tmp->next=NULL;

    // Empty Queue
    if(*rear==NULL)
        *front=*rear=tmp;
    else
    {
        (*rear)->next=tmp;
        *rear=tmp;
    }
}



char* Receiver(NODE **front, NODE **rear)
{
    char* item;
    NODE *tmp = *front;

    if(*front==NULL)
    {
        *rear=NULL;
        return ("Queue underflow");
    }

    item=(char *)malloc(sizeof((*front)->msg));
    
    if(item==NULL)
    {
        printf("\nMalloc failure");
        exit(3);
    }
    
    strcpy(item, (*front)->msg);
    *front=(*front)->next;

    if(*front==NULL)
        rear=NULL;
    free(tmp);
    return item;
}


void DispQ(NODE *front)
{
    NODE *tmp=front;
    if(tmp==NULL)
    {
        printf("\nEmpty Queue");
        return;
    }
    printf("\nThe Queue contents are:\n");
    while(tmp)
    {
        printf("%s\t", tmp->msg);
        tmp=tmp->next;
    }
}
