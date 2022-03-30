package com.company;

import java.util.Scanner;

import static java.lang.System.exit;

public class Main {
    static int CAPACITY,el;
    static int front =-1,rear=-1;
    static int[] cqueue;
    static Scanner sc = new Scanner(System.in);
    static{
       Main.create();
    }

    public static void main(String[] args) {

	// write your code here
      while(true) {
          System.out.println("1. Inset an element to queue");
          System.out.println("2. Delete an element to queue");
          System.out.println("3. Traverse/Display all the elements");
          System.out.println("4. Exit");
          System.out.println("Enter your choice: ");
          int ch;
          ch = sc.nextInt();
          switch (ch) {
              case 1 -> insert();
              case 2 -> delete_();
              case 3 -> display();
              case 4 -> exit(1);
              default -> System.out.println("Invalid choice");
          }
      }


    }




static void insert(){

        if((front==rear+1) || (front==0 && rear==CAPACITY-1)){
            System.out.println("Queue is full");
        }
        else if(front==-1 && rear==-1){
            front=rear=0;
            System.out.println("please enter element : ");
             el = sc.nextInt();
             cqueue[rear]= el;
            System.out.println("Value "+el+"   inserted");

        }
        else if(rear== CAPACITY-1){
            rear=0;
            el = sc.nextInt();
            cqueue[rear]=el;
            System.out.println("Value "+el+"    inserted");
        }
        else{
            rear++;
            el = sc.nextInt();
            cqueue[rear]=el;
            System.out.println("Value "+el+"    inserted");
        }
}

static void delete_(){
        if(front==-1 && rear==-1){
            System.out.println("Queue is empty. ");
        }
        else if(front==rear){
            el = cqueue[front];
            System.out.println("Queue element  " +cqueue[front]+ " deleted");
            rear = front =-1;
        }
        else if(front== CAPACITY-1){
            el = cqueue[front];
            System.out.println("Value "+el+"    deleted");
            front=0;
        }
        else{
            el = cqueue[front];
            System.out.println("Value "+el+"    deleted");
            front++;

        }

}

static void display(){
        if(front==-1 && rear==-1){
            System.out.println("There is no element in Queue");

        }
        else if(front<=rear){
            System.out.println("Display's elements are : ");
            for(int i =front;i<=rear;i++){
                System.out.println(+cqueue[i]);
            }
        }
        else{
            System.out.println("Display's elements are : ");
            for(int i=front;i<CAPACITY;i++){
                System.out.println(+cqueue[i]+"  ");
            }
            for(int i=0;i<=rear;i++){
                System.out.println(+cqueue[i]+"  ");
            }
        }
}

static void create(){
    System.out.println("Enter size of Queue: ");
    CAPACITY = Main.sc.nextInt();
    Main.cqueue = new int[CAPACITY];
    System.out.println("Queue created with size : "+CAPACITY);
}

}
