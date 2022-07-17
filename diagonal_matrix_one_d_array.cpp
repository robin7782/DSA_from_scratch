
#include<bits/stdc++.h>
using namespace std;
//diagonal matrix with one dimention arrary
class Diagonal{
private:
  int n;
  int *A;

public:
  Diagonal(){
    n = 2;
    A = new int[2];
  }
  Diagonal(int n){
    this->n = n;
    A = new int[n];
  }
  ~Diagonal(){
    delete []A;
  }
  void set(int i, int j, int x);
  int get(int i,int j);
  void display();
};

void Diagonal::set(int i, int j, int x){
  if(i==j)A[i]=x;
}
int Diagonal::get(int i,int j){
  if(i==j)return A[i];

  return 0;
}

void Diagonal::display(){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
       if(i==j){
        cout<<A[i]<<" ";
       }
       else cout<<"0 ";
    }
    cout<<endl;
  }
}

int main(){
  Diagonal d(4);
  d.set(0,0,8);
  d.set(1,1,9);
  d.set(2,2,7);
  d.set(3,3,6);
  d.display();
  cout<<endl;
  cout<<d.get(0,2);
  
return 0;  
}
