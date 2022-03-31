
#include<stdio.h>
#include<stdlib.h>
void push_();
void pop_();
void traverse();

struct node{
  int data;
  struct node *link;
};
struct node *top=NULL;


void push_(){
        
        struct node *temp=NULL;
        temp = (struct node*)malloc(sizeof(struct node));
        printf("Enter your data:\n");
        scanf("%d",&temp->data);
        printf(" %d data pushed into the stack", temp->data);
        temp->link = top;
        top = temp;
        
}
void pop_(){
    if(top==NULL){
      printf("Stack in empty\n");
    }
    else{
      struct node *temp = NULL;
      temp = top;
      printf(" %d popped \n",temp->data);
      top = temp->link;
      temp->link = NULL;
      free(temp);
    }
}

void traverse(){
  if(top==NULL){
    printf("No elements in stack\n");
  }
  else{
    struct node *temp=NULL;
    temp = top;
    while(temp!=NULL){
      printf("%d --> ",temp->data);
      temp = temp->link;
    }
  }
}


int main()
{
int ch;
while(1)
{
printf("Available choices of Stack using link list are\n");
printf("1.Insert\n");
printf("2.Delete\n");
printf("3.Display\n");
printf("4.Exit\n");

printf("Enter your choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1: push_();
        break;
case 2: pop_();
        break;
case 3: traverse();
        break;
case 4: exit(0);
default: printf("invalid input\n");
}
printf("\n");
}
return 0;
}
