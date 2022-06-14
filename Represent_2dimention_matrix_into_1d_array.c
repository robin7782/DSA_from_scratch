
#include<stdio.h>
void set();//use prototype unless some complier coz error.
int get();
void display();

struct Matrix{
  int a[10];
  int n;// dimenstion 4*4
};

void set(struct Matrix *m,int i, int j,int x){
 
 if(i==j){
    m->a[i-1]=x;
 }

}

int get(struct Matrix *m,int i,int j){
 if(i==j)return m->a[i-1];
 else return 0;
 
}

void display(struct Matrix* m){
  for(int i=1;i<=m->n;i++){
    for(int j=1;j<=m->n;j++){
      if(i==j)printf("%d", m->a[i-1]);
      
      else printf("0");
    }
    printf("\n");
  }
}

int main(){
  
  struct Matrix m;
  m.n = 4;
  set(&m,1,1,17);set(&m,2,2,89);set(&m,3,3,55);set(&m,4,4,23);
  printf("\n");
  display(&m);
  printf("%d",get(&m,2,3));
}
