package com.company;

import java.util.Scanner;

import static java.lang.System.exit;

public class Main {
    static int CAPACITY,el;
    static int front =0,rear=0;
    static int[] queue;
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


static boolean isEmpty(){
    return front == rear;
}

static boolean isFull(){
    return CAPACITY == rear;
}

static void insert(){

        if(isFull()){
            System.out.println("Queue is full");
        }
        else{
            System.out.println("please enter element : ");
             el = sc.nextInt();
             queue[rear]= el;
            System.out.println("Value "+el+"   inserted");
            rear++;
        }
}

static void delete_(){
        if(isEmpty()){
            System.out.println("Queue is empty. ");
        }
        else{
            System.out.println("Queue element  " +queue[front]+ " deleted");
            for(int i=0;i<rear-1;i++){
                queue[i] = queue[i+1];
            }
            rear--;
        }
}

static void display(){
        if(isEmpty()){
            System.out.println("There is no element in Queue");

        }
        else{
            System.out.println("Display's elements are : ");
            for(int i =0;i<rear;i++){
                System.out.println(+queue[i]);
            }
        }
}

static void create(){
    System.out.println("Enter size of Queue: ");
    CAPACITY = Main.sc.nextInt();
    Main.queue = new int[CAPACITY];
    System.out.println("Queue created with size : "+CAPACITY);
}

}
