import java.util.Scanner;

public class Stack {
    static Scanner sc = new Scanner(System.in);
    static int stack[],top= -1,size;

    static{
        Stack.create();
    }
    public static void main(String[] args) {
        int ch,item;
        while(true) {
            System.out.println("1.Push");
            System.out.println("2.Pop");
            System.out.println("3.Peek");
            System.out.println("4.Traverse");
            System.out.println("5.Quit");

            System.out.print("Enter your choice : ");
             ch = Stack.sc.nextInt();

             switch (ch){
                 case 1:
                     System.out.println("Enter element to push: ");
                     item = sc.nextInt();
                     Stack.push(item);
                         break;
                 case 2: item = Stack.pop();
                         if(item == 0){
                             System.out.println("Stack is underflow");
                         }
                         else{
                             System.out.println("popped item : "+item);
                         }
                         break;
                 case 3: item = Stack.peek();
                         if(item == 0){
                             System.out.println("Stack is underflow: "+item);

                         }
                         else{
                             System.out.println("peeked item: "+item);
                         }
                         break;
                 case 4: Stack.traverse();
                         break;
                 case 5: System.exit(1);
                 default:
                     System.out.println("Invalid choice");
             }
        }
    }
    static void create(){

        System.out.println("Enter size of stack: ");
        size = Stack.sc.nextInt();
        Stack.stack = new int[size];
        System.out.println("Stack created with size: "+size);
    }

    static void push(int item){
        if(Stack.isFull()){
            System.out.println("Stack is overflow");
        }
        else{

            Stack.stack[++top]= item;

        }
    }
    static boolean isFull(){
        if(top == size-1){
            return true;
        }
        else{
            return false;
        }
    }

    static int pop(){
        if(isEmpty()){
            return 0;
        }
        else{
            return stack[top--];
        }
    }
    static boolean isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }

    static int peek(){
        if(isEmpty()){
            return 0;
        }
        else{
            return stack[top];
        }

    }

    static void traverse(){
        System.out.println("All Stacks elements are : ");
        for(int i=0;i<=top;i++){
            System.out.println(+Stack.stack[i]);
        }
    }
}
