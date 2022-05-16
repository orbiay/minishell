#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
	int data;
	struct list *next;
}t_list;
int main ()
{
	t_list *a = malloc (sizeof(t_list));
	t_list *b = malloc(sizeof(t_list));
	t_list *c = malloc(sizeof(t_list));
	a->data = 5;
	b->data = 4;
	c->data = 3;
	a->next = b;
	b->next = c;
   	c->next = NULL;
	int i = 0;
 while (a->next)
 {
	 printf("%d\n",a->data);
	 a = a ->next; 
 }	 
}
