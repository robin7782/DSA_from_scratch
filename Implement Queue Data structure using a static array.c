#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 1000
int queue[CAPACITY];
int front=0,rear=0;
int isEmpty();
int isFull();
void insert();
void delete_();
void display();

int main(){
  while(1){
	int ch;
	printf("\n\n\n");
	printf("1. Insert an element to queue\n");
	printf("2. Delete an element to queue\n");
	printf("3. Traverse/Display all the elements\n");
	printf("4. Exit\n\n\n");
	printf("Enter your choice : \n");
	scanf("%d",&ch);

	switch(ch){
		case 1: insert();
				break;
		case 2: delete_();
				break;
		case 3: display();
				break;
		case 4: exit(1);
		default: printf("please  enter valid input\n");						
	}
}	


}


void insert(){
	int el;
	if(isFull()){
		printf("Queue is full\n");
	}
	else{
		printf("Please Enter elemet : \n");
		scanf("%d",&el);
		queue[rear]= el;
		printf(" Value %d inserted\n", el);
		rear++; 


	}
}

void delete_(){
	if(isEmpty()){
		printf("Queue is empty.\n");
	}
	else{
		printf("Queue element %d deleted\n", queue[front]);
		for(int i=0;i<rear-1;i++){
			  queue[i] = queue[i+1];
		}
		rear--;


	}
}
int isEmpty(){
	if(front==rear){
		return 1;
	}
	else
		return 0;
}

int isFull(){
	if(CAPACITY==rear){
		return 1;
	}
	else
		return 0;

}

void display(){
	if(isEmpty()){
		printf("There is no element in Queue\n");
	}
	else{  printf("Display's elements are : \n");
	        for(int i =0;i<rear;i++){
	             printf("%d\n", queue[i]);
	     }
	 }   
}



