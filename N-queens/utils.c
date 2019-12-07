#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"header.h"
List * initialize()
{  
    // initialize the Doubly linked list 
    List *list = malloc(sizeof(List));
    list->head=NULL;
    list->count=0;
    return list;
}

void print_board(List *list)
{
	int i ,j;
	Node * temp = list->head;

	for(i=1;i<=list->count+1 ; i++)
	{    printf("\t");
		for(j=1;j<=list->count+1 ; j++)
		{	
			if(i==temp->index && j==temp->position)
			printf("Q ");
			else
			printf(". ");
			
		}
		printf("\n");
		temp=temp->next;
	}
	printf("\n");
}

Node * create(int index)
{

    //creates a Doubly linked  list with node containing the following data : index , position, next , previous
    Node *temp=(Node*)malloc(sizeof(Node));
    temp->index=index;
    temp->position=0;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}
void insert_end(List *list , int index)
{

    //inserts N nodes into the linked list , at the end of the list 
    Node *temp=create(index);
    Node *new=list->head;
    if(list->head==NULL)
    {
        list->head=temp;
        return;
    }
    while(new->next)
        new=new->next;
    new->next=temp;
    temp->prev=new;
    temp->next=NULL;
    list->count++;
}


void print_solution(List *list)
{
    // Prints the linked list with each node containing the position of the queen on the chess board
    // Example : 2 4 1 3  
/*

	. Q . .
	. . . Q
	Q . . .
	. . Q .


*/
    Node *temp=list->head;
    if(list->head==NULL)
    {
        printf("Empty\n");
        return;
    }
    while(temp)
    {
        printf("%d " , temp->position);
        temp=temp->next;
    }
    printf("\n\n");
	
}

int place(List *list ,Node *node)
{
 
/* 
	This function checks whether the queen can be placed in the position , by checking horizontally , vertically and diagonally 
	If it is possible to place , it returns a 1
	Else , it returns 0 
	
*/

	int pos = node->index;   // pos holds the index value of the node
    Node * temp = list->head;    
    for(int i=1;i<pos;i++)
    {
        if((temp->position==node->position)||(abs((temp->position-node->position))==abs((temp->index)-pos)))
        return 0;
        temp=temp->next;
        
    }
    
    return 1;
}
List * createBoard(List *list ,int n)
{

// Creates a linked list with nodes having index starting from 1 to N  


    int i ;
    for (i = 1 ; i<=n ; i++)
    {
        insert_end(list , i);
    }
    return list;
}



void queen(List * list, int n)
{
	
// Backtracks the board , to check for all possible positions the queen can be placed at
// Index here represents the row number and position represents the row number in a chess board 


    Node * temp = list->head;
    temp->position = 0;
   
    while(temp->index!=0)
    {
        do
        {
            temp->position++;                         // increments the posiiton when the previous position is not satisfied
           
        }while((temp->position<=n)&&!place(list , temp));
        if(temp->position<=n)
        {
            if(temp->index==n)                        // If the row number is equal to size of board , a solution is found 
	    {
            count++;
            print_solution(list);                  // prints the position in a linked list 
	        print_board(list);                       // prints the board with possible queen solutions 
        }
            else
            {
                temp=temp->next;
                temp->position=0;
            }
        }
        else
        {	
			if(temp->prev!=NULL)
			{temp=temp->prev;}            // if it exceeds , it backtracks to the previous row and continues
			else
			return;
        }
    }
}

void freelist(List * list)                           // frees the list 
{
	free(list->head);
	list->head=NULL;
}
