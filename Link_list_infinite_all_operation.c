//if list is empty then automatically it will insert element from user.
// for the simplicity here, i have used bubble sort. You can use any sorting algorithm.
// for reverse all the node i use iterative method because of the efficiency but you can also use recurssive method.
//you can use adjacent swap node in swapping node case:16,it will work for any condition whether adjacent or any position in the list.
// if you use default mode then link list will behave like lifo(last in first out)

#include<stdio.h>
#include<stdlib.h>
void insert();
void insertatbegin();
void insertatanyplace();
int length();
void display_forward();
void display_reverse();
void delete_frist();
void delete_any();
void delete_last();
void swap_node();
void swapElemets();
void search();
struct node* createNode();
void reverseNode();
void sum_of_all_node();
void sort();
int compare_ac();
int compare_dc();

// Structure decalation for Node
struct node
{
    int data;
    struct node *link;
    
};

struct node* root = NULL;
int ele,len;


int main(){
    int ch,sum;
    while(1){// you can place "true " or "1 " your wish
        printf("\n\n\n");
        printf("Single linked list operation : \n\n");
        printf("1.  Insert default mode\n");
        printf("2.  Delete default mode\n");
        printf("3.  Insert At Begin\n");
        printf("4.  Insert At Any Place\n");
        printf("5.  Length Of List\n");
        printf("6.  Display Elements in forward direction\n");
        printf("7.  Display Elements in reverse or backward direction\n");
        printf("8.  Delete FristElement\n");
        printf("9.  Delete AnyElement\n");
        printf("10. Delete last element\n");
        printf("11. Swapping elements or data\n");
        printf("12. Search Element\n");
        printf("13. Reverse all the Node of Linked list\n");
        printf("14. Sum of all the data in linked list\n");
        printf("15. Sort in accending order\n");
        printf("16. Sort in decending order\n");
        printf("17. Swapping Nodes\n");
        printf("18. Quit\n");

        printf("Enter your Choice : \n\n");
        scanf("%d",&ch);

        switch(ch){
            case 1:  insert();
                     break;
            case 2:  delete_last();
                     break;         
            case 3:  insertatbegin();
                     break;
            case 4:  insertatanyplace();
                     break;
            case 5:  len = length();
                     printf("Length of Link list is : %d\n", len);
                     break;
            case 6:  display_forward();
                     break;
                     
            case 7:  if(root==NULL)insert();
                     else display_reverse(root);
                     break;
                     
            case 8:  delete_frist();
                     break;       
            case 9:  delete_any();
                     break;
            case 10:  delete_last();
                     break;
            case 11: swapElemets();
                     break;              
            case 12: search();
                     break;
            case 13: reverseNode();
                     break;
            case 14: sum_of_all_node();
                     break;
            case 15: sort(compare_ac);
                     break;
            case 16: sort(compare_dc);
                     break;
            case 17: swap_node();
                     break;
            case 18: exit(1);
            default: printf("Invalid Choice !! \U0001F600\n");



        }

    }
return 0;   
}


void insert(){
    struct node* temp = NULL;
    struct node* p;
    if(root == NULL){
        printf("List is empty\n");
        printf("Please Enter some elemets----\n");
        temp = createNode();
        root = temp;
    }
    else{
        temp = root;
        while(temp->link != NULL){
            temp = temp->link;
        }
        p=createNode();
        temp->link = p;
     } 

}

struct node* createNode(){
    struct node* n;
    n = (struct node*)malloc(sizeof(struct node));
    printf("Enter elemets : \n");
    scanf("%d",&ele);
    n->data = ele;
    n->link = NULL;
    return n;   
}

void display_forward(){
    struct node* temp;
    temp = root;
    if(temp==NULL)insert();
    else{ while(temp != NULL){
        
            printf("--%d-->",temp->data);
            temp = temp->link;
         }
    }

}




void display_reverse(struct node* temp){
    
    if(temp==NULL)return;
    
    display_reverse(temp->link);
    printf("--%d-->",temp->data);
    
     
        
    
}



int length(){
    int c=0;
    struct node* temp;
    temp = root;
    while(temp!=NULL){
        c++;
        temp = temp->link;

    }
    return c;
}

void insertatbegin(){
    if(root == NULL){
        insert();
    }
    else{
    struct node* n = NULL;
    struct node* temp;
    temp = root;
    n = createNode();
    n->link= temp;
    temp = n;
    root = temp;

    }

}

void insertatanyplace(){
    struct node *temp,*p=NULL;
    int loc;
    temp = root;
    if(temp==NULL)insert();
    else{
         len = length();
         printf("Enter the location you want to insert: \n");
         scanf("%d",&loc);
            if(loc>len){
                printf("Invalid position\n");
                printf("Total length of List is : %d\n",len);
            }
            else if(loc==1)insertatbegin();
            else{
                int i=1;
                while(i<loc-1){
                    temp = temp->link;
                    i++;
        
                }
                 p = createNode();
                 p->link = temp->link;
                 temp->link = p;
        
        
            }
    }
}

void search(){
    struct node *temp=NULL;
    temp=root;
    
    int sv,p=0;
    int c = 0;
    if(temp == NULL){
            printf("There is no element for search \n");
            insert();
            temp = root;
        }        
    
     printf("Enter the search element : \n");
     scanf("%d",&sv);

    while(temp != NULL){
           p++;
           if(sv==temp->data){  
                sv = temp->data;
                c = 1;
                break;
           }
              temp = temp->link;
        
    }
    if(c==1)printf("Elemet %d found in %d position\n",sv,p);
    else printf("Not found the search elements");
}

void swapElemets(){
    
    int l = length();
    struct node *loop=root,*loop2=root;
    int loc,loc2,tdata,i=1,j=1;
    
    if(root==NULL)
    {
        printf("NO elements in the list\n\n");
    }
    else{
            printf("Which nodes value you want to swap?\n");
            scanf("%d",&loc);
            scanf("%d",&loc2);
          
            if((loc==loc2) || (loc>=l && loc2>=l) || (loc<=1 && loc2<=1))printf("shifting is impossible\n");
            else if((loc>l && loc2<=l) || (loc<=l && loc2>l))printf("shifting not impossible\n");
            else{
                while(i<loc){
                        loop = loop->link;
                        i++;
                }
                    tdata = loop->data;
                while(j<loc2){
                    loop2 = loop2->link;
                    j++;
                }
                loop->data = loop2->data;
                loop2->data = tdata;
                printf("Shifting has been done\n");
            }
    }
    
  

}

        
  

    

void delete_last(){
    struct node *temp=NULL,*prev=NULL;
    if(root==NULL){
        printf("No elements in list to delete\n");
        insert();
    }
    else{
        int len = length();
        if(len==1)delete_frist();
        else{
                temp = root;
                while(temp->link != NULL){
                        prev = temp;
                        temp= temp->link;
                     }
                    printf("%d data deleted \n",temp->data);
                    prev->link = NULL;
                    free(temp);
        }        
          
    }
}



void delete_frist(){
     struct node *temp=NULL;
    temp = root;
    if(temp==NULL){
        printf("No elements in list to delete\n");
        insert();
    }
    else{
      printf("%d data deleted \n",temp->data);
      root = temp->link;
      temp->link=NULL;
      free(temp);   
    }
}

void delete_any(){
    struct node *temp,*t2=NULL;
    temp = root;
    int loc;
    if(temp==NULL)insert();
    else{
            len = length();
            printf("Please Enter your location that you want to delete :\n");
            scanf("%d",&loc);
            if(loc>len || loc<=0){
                printf("Invalid position\n");
                printf("Total length of List is : %d\n",len);
            }
            else if(loc==1){
                delete_frist();
            }
            else if(loc==len){
                delete_last();
            }
            
            else{
               int i=1;
               while(i<loc){
                 temp=temp->link;
               }
              
                  t2= temp->link;
                  printf("%d data deleted \n",t2->data);
                   temp->link=NULL;
                   temp->link=t2->link;
                   t2->link = NULL;
                   free(t2);
                }
    }        
}

void reverseNode(){
    struct node* temp = root;
    struct node *prev=NULL,*next=NULL;
  if(temp==NULL)printf("No elements in the list\n");
  
  else{
        while(temp!=NULL){  
        next = temp->link;
        temp->link = prev;
        prev = temp;
        temp= next;
       }
      root = prev;
       
       printf("All the node successfully reversed\n");
       struct node* loop;
       loop = root;
       while(loop!=NULL){
                printf("--%d-->",loop->data);
                loop = loop->link;
           
       }
   
  } 
}

void sum_of_all_node(){
    struct node* temp = root;
    int sum=0;
    if(temp==NULL)insert();
    
    else{
        while(temp!=NULL){
               sum = sum + temp->data;
               temp= temp->link;
              
        }
         printf("total sum of list is : %d \n",sum);
         
    }
    
}

void sort(int (*compare)(int,int)){
    struct node* temp=root;
    int l = length();
    int i=0;
    int *arr;
    while(temp!=NULL){
            arr[i]=temp->data;
            i++;
            temp = temp->link;
    }
    
    for (int step = 0; step <l; ++step) {
      
    // loop to compare array elements
    for (int i = 0; i < l - step - 1; ++i) {
      
      // compare two adjacent elements
      // change > to < to sort in descending order
      if (compare(arr[i],arr[i+1])) {
        
        // swapping occurs if elements
        // are not in the intended order
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
      }
    }
  }
    
    for(int i =0;i<l;i++){
        printf("--%d-->",arr[i]);
    }
}

int compare_ac(int a,int b){
  if(a > b)return 1;
  else return 0;
}

int compare_dc(int a, int b){
    if(a<b)return 1;
    else return 0;
}


void swap_node(){
    
    struct node *loop=root,*loop2=root,*p1=NULL,*p2=NULL,*t1=NULL,*t2=NULL;
    int loc,loc2,i=1,j=1;
    int l = length();
    if(root==NULL)insert();
    else{
            printf("Which nodes value you want to swap?\n");
            scanf("%d",&loc);
            scanf("%d",&loc2);
          
            if((loc==loc2) || (loc==l && loc2==l) || (loc<=1 && loc2<=1))printf("shifting is impossible\n");
            else if((loc>l && loc2<=l) || (loc<=l && loc2>l))printf("shifting not impossible\n");
   
            else{
            
                      while(i<loc-1){
                            loop = loop->link;
                            i++;
                        }
                        
                      while(j<loc2-1){
                            loop2 = loop2->link;
                            j++;
                        }
                      t1 = loop->link;
                      t2= t1->link;
                      t1->link = NULL;
                      loop->link = NULL;
                      
                      p1= loop2->link;
                      p2= p1->link;
                      p1->link = NULL;
                      loop2->link = NULL;
                      
                     loop->link = p1;
                     p1->link = t2;
                     loop2->link = t1;
                     t1->link = p2;
                     
                     t1=NULL,t2=NULL,p1=NULL,p2=NULL;
                     
                      printf("Shifting node  has been done\n");
            }  
              
             
    }
    

    
    
}

