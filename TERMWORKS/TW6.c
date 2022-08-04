// TW 6 Warehouse as an Ordered List

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE;

NODE* add(NODE*, int);
void disp(NODE*);
int search(NODE*, int);

int main()
{
    //Create an empty warehouse
    NODE *head=NULL;
    int opt, item;
    while(1)
    {
        printf("\n1: Add item");
        printf("\n2: Display Warehouse");
        printf("\n3: Search item");
        printf("\n4: Exit");
        printf("\nChoose: ");
        scanf("%d", &opt);
        switch(opt)
        {
            case 1: printf("\nEnter item to add to warehouse: ");
                    scanf("%d", &item);
                    head=add(head, item);
                    break;
            case 2: disp(head);   break;
            case 3: printf("\nEnter the item to search: ");
                    scanf("%d", &item);
                    if(search(head, item))
                       printf("\nItem %d is present in the warehouse", item);
                    else
                       printf("\nItem %d is NOT present in the warehouse", item);
                    break;
            case 4: exit(0);
        }
    }
    return 0;
}


NODE* add(NODE* head, int item)
{
    NODE *prev, *curr;
    NODE *newnode=(NODE*)malloc(sizeof(NODE));
    if(newnode==NULL)
    {
        printf("\nMalloc failure");
        exit(1);
    }
    newnode->data=item;
    newnode->next=NULL;
    // Case i - List is empty
    if(head==NULL)
        head=newnode;
     // Case ii - adding the smallest item
    else if(item < head->data)
        {
              newnode->next = head;
              head = newnode;
        }
    else // Case iii
    {
        prev=head;
        curr=head->next;
        while(curr && item > curr->data)
        {
            prev=prev->next;
            curr=curr->next;
        }//end of while
        newnode->next=curr;
        prev->next=newnode;

    }//end of else
    return head;
}


void disp(NODE *head)
{
    if(head==NULL)
    {
        printf("\nWarehouse is empty");
        return;
    }
    printf("\nThe warehouse items are: ");
    while(head)
    {
        printf("%d    ", head->data);
        head=head->next;
    }
}


int search(NODE* head, int item)
{
    if(head==NULL)
    {
        printf("\nWarehouse is empty");
        return 0;
    }
    while(head && (item > head->data))
          head=head->next;

    if(head==NULL)
        return 0;

    if(item==head->data)
        return 1;
    else
        return 0;
}
