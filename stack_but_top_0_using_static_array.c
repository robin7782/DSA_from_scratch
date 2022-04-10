
#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 5 // pre-processor macro
int stack[CAPACITY],top = 0;
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
 		stack[top]= ele;
 		printf("Element added to stack :  %d \n",ele);
 		top++;

 	}

 }
 int isFull(){
 	if(top==CAPACITY){

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
 		top--;
 		printf("popped element from the stack %d \n",stack[top]);
 	}

 }

 int isEmpty(){
 	if(top== 0){
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
 	    
 		printf("The peek element is : %d \n",stack[top-1]);
 	}

 }

 void traverse(){
     if(isEmpty()){
         printf("No elements in stack or stack underflow\n");
     }
     else{
     printf("All the elements are : \n");
 	
 	for(int i=0;i<top;i++){
 	   
 		printf("%d\n",stack[i]);
 	   }
     }

 }




