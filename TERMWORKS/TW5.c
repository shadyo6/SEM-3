// TW 5 Hashtable

#include<stdio.h>
#include<stdlib.h>
 
#define SIZE 10
 
struct Customer
{
	int custid;
	char custname[30];
	int custphno;
};

struct Record
{
	struct Customer info;
	int empty;
};	
 
int HashFn(int key)
{
	return (key % SIZE);
}
 
int Search(int key, struct Record ht[])
{
	int count, temp, pos;
    	temp = HashFn(key);				
	pos = temp;
	for(count = 1; count <= SIZE ; count++)
	{
		if(ht[pos].empty == 1) 
		{
			return -1;
		}
		if( (ht[pos].info).custid == key)
		{
			return pos;
		}
		pos = (temp + count) % SIZE;	

	}
	return -1;
}
 
void InsHT_LP(struct Customer cust, struct Record ht[])
{
	int count, pos, temp;
	int key = cust.custid;
	temp = HashFn(key);				
	pos = temp;	
	for(count = 1; count <= SIZE ; count++)
	{
		if(ht[pos].empty == 1)
		{
			ht[pos].info = cust;
			ht[pos].empty = -1;	
			printf("\nRecord Inserted into Hash Table\n");
			return;
		}
		if((ht[pos].info).custid == key)
		{
			printf("\nDuplicate Record cannot be Inserted\n");
			return;
		}
        pos = (temp + count) % SIZE;				
	}
	printf("\nHash Table is full\n");
}
 
void Display(struct Record ht[])
{
	int count;
	printf("\nHash Table");
	for(count = 0; count < SIZE; count++)
	{
		printf("\n[%d]:\t", count);
		if(ht[count].empty == -1) 
		{
			printf("\nCustomer - ID: %d Name: %s Phone: %d",(ht[count].info).custid, (ht[count].info).custname, (ht[count].info).custphno);
		}
		
		else
		{
			printf("\nNo Hash Entry\n");
		}
	}
}
 

 
int main()
{
	int count, key, option;
	struct Record ht[SIZE];
	struct Customer cust;
	for(count = 0; count < SIZE ; count++)
	{
		ht[count].empty = 1;
	}	
	while(1)
	{
		printf("\n\n1. Insert a Record");
		printf("\n2. Search a Record");
		printf("\n3. Display All Records");
		printf("\n4. Exit");
		printf("\nEnter Your Option:");
		scanf("%d", &option);
		switch(option)
		{
			case 1: printf("\nEnter Customer id, name, ph:");
				scanf("%d%s%d", &cust.custid,cust.custname,&cust.custphno);			
				InsHT_LP(cust, ht);
				break;
 
			case 2: printf("\nEnter the Key to Search:");
				scanf("%d", &key);
				count = Search(key, ht);
				if(count == -1)
				{
					printf("\nRecord Not Found\n");
				}
				else
				{
					printf("\nRecord Found at Index pos:%d\n", count);
				}
				break;
 
 
			case 3:	Display(ht);
				break;
 
			case 4:	exit(1);
		}
	}
	return 0;
}
