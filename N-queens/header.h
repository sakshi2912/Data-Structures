#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <time.h>


int count ;

typedef struct Node 
{
    int index;
    int position;
    struct Node *next;
    struct Node *prev;
}Node;

typedef struct List 
{
    Node *head;
    int count;
}List;

List * initialize();
void print_board(List *);
Node * create(int);
void insert_end(List *, int);
void print_solution(List *);
int place(List *,Node *);
List * createBoard(List *,int );
void queen(List *, int );
void freelist(List *);             
