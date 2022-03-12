#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 5 // pre-processor macro
int stack[CAPACITY],top = -1;
void push(int);
void pop(void);
void peek(void);
void traverse(void);
int isEmpty(void);
int isFull(void);
int main(){
	while(1){

			int ch,ele;
			
			printf("1. Push \n");
			printf("2. Pop \n");
			printf("3. Peek \n");
			printf("4. Traverse \n");
			printf("5. Quit \n");

			printf("Enter your choice : ");
			scanf("%d",&ch);

			switch(ch){
				case 1 :printf("Enter the element : \n");
						scanf("%d",&ele); 
						 push(ele);
						 break;
				case 2 : pop();
						 break;
				case 3 : peek();
						 break;
				case 4 : traverse();
						 break;
				case 5 : exit(0);
				default: printf("Invalid input \n\n");
			}
   		}
return 0;   		
}  

void push(int ele){
 	if(isFull()){
 		printf("Stack is full / overflow \n");

 	}
 	else{
 		top++;
 		stack[top]= ele;
 		printf("Element added to stack :  %d \n",ele);

 	}

 }
 int isFull(){
 	if(top==CAPACITY-1){

 		return 1;
 	}
 	else{

 		return 0;
 	}
 }
 void pop(){
 	if(isEmpty()){
 		printf("No element in the stack or stack underflow\n");
 	}
 	else{
 		printf("popped element from the stack %d \n",stack[top]);
 		top--;
 	}

 }

 int isEmpty(){
 	if(top==-1){
 		return 1;
 	}
 	else{
 		return 0;
 	}
 }
 void peek(){
 	if(isEmpty()){
 		printf("Stack is empty or underflow \n");
 	}
 	else{
 		printf("The peek element is : %d \n",stack[top]);
 	}

 }

 void traverse(){
     if(isEmpty()){
         printf("No elements in stack or stack underflow");
     }
     else{
     printf("All the elements are : \n");
 	
 	for(int i=0;i<=top;i++){
 	   
 		printf("%d\n",stack[i]);
 	   }
     }

 }




