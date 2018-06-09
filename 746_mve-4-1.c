#include <stdlib.h>
#include <stdio.h>

typedef struct node {
int value;
struct node *next;
} node;

node *head=NULL;
node *tail=NULL;

void init(int data)
{
node *tmp = malloc(sizeof(node));
tmp->value = data;
tmp->next = NULL;
head = tmp;
tail = tmp;
}

int isEmpty()
{
if (head==NULL && tail==NULL)
return 1;
else return 0;
}

void push(int data)
{
node *tmp = malloc(sizeof(node));
tmp->value = data;
tmp->next=NULL;
tail->next=tmp;
tail=tmp;
}

void out()
{
node *tmp=head;
while (tmp!=NULL)
{
        printf("%d",tmp->value);
        printf(" ");
        tmp=tmp->next;
}
}

void deleteFirst()
{
node *tmp=head;
node *tmp1=NULL;
tmp1=tmp->next;
free(tmp);
head=tmp1;
}

int main()
{
int n, value;
scanf("%d",&n);
scanf("%d", &value);
init(value);
for (int i=1;i<n;i++)
{
        scanf("%d",&value);
        push(value);
}
printf("\n");
out();
printf("\n");
for (int i=0;i<n;i++)
{
        deleteFirst();
        out();
        printf("\n");
}
return 0;
}
