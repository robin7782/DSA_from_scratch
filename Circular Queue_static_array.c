
#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 5
int queue [CAPACITY];
int rear=-1;
int front=-1;

void insert(int);
void delete_();
void display();

void insert(int ele){
 if((front==rear+1) || (front==0 && rear==CAPACITY-1)){
    printf("Queue is full \n");
 }
 else if(front==-1 && rear==-1){
    front=rear=0;
    queue[rear]=ele;
    printf("element inserted %d ",queue[rear]);
 }
 else if(rear== CAPACITY-1){
    rear=0;
    queue[rear]=ele;
    printf("element inserted %d ",queue[rear]);
 }
 else{
    rear++;
    queue[rear]=ele;
    printf("element inserted %d ",queue[rear]);
 }

}

void delete_()
{
    int ele;
    if(front==-1 && rear==-1){
        printf("Queue is empty\n");
    }
    else if(front==rear){
        ele =  queue[front];
        printf("element deleted %d ",ele);
        rear = front = -1;
    }
    else if(front== CAPACITY-1){
        ele = queue[front];
        printf("element deleted %d ",ele);
        front=0;
    }
    else{
        ele = queue[front];
        printf("element deleted %d ",ele);
        front++;
    }
 
}

void display(){
if(front==-1 && rear==-1)printf("Queue is empty\n");   
else if(front<=rear){ 
    for(int i=front;i<=rear;i++){
         printf("%d  ",queue[i]);
            }
           
       }  
else{
        for(int i=front;i<CAPACITY;i++){
                 printf("%d  ",queue[i]);}
        for(int i=0;i<=rear;i++){
                 printf("%d  ",queue[i]);
           }
       }
        
   

 
}


void main()
{
int ch,ele;
while(1)
{
printf("Available choices of circular queue are\n");
printf("1.Insert\n");
printf("2.Delete\n");
printf("3.Display\n");
printf("4.Exit\n");

printf("Enter your choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("enter element to be insert\n");
        scanf("%d",&ele);
        insert(ele);
break;
case 2: delete_();
        break;
case 3: display();
        break;
case 4: exit(0);
default: printf("invalid input\n");
}
printf("\n");
}
}
