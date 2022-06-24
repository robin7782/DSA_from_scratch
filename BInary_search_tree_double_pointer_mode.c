

#include <stdio.h>
#include<stdlib.h>
struct BstNode* GetNewNode(int);
int findMin(struct BstNode*);
void Insert(struct BstNode**,int);

struct BstNode{
    int data;
    struct BstNode* left;
    struct BstNode* right;
};

int findMin(struct BstNode* current){
    
    if(current==NULL)return -1;
    
    while(current->left!=NULL){
        current = current->left;
    }
    return current->data;
    
}

struct BstNode* GetNewNode(int data){
   struct BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode));
    newNode->data = data;
    newNode->left = newNode->right=NULL;
    return newNode;
}
void Insert(struct BstNode** root,int data){
    if(*root == NULL){
        *root = GetNewNode(data);
    }
    else if(data <= (*root)->data){
         Insert(&((*root)->left),data);
        
    }
    else {
         Insert(&((*root)->right),data);
    }
}

int main(){
   struct BstNode* root = NULL;
   int min;
    Insert(&root,3);
    Insert(&root,10);
    Insert(&root,20);
    Insert(&root,25);
    Insert(&root,9);
    Insert(&root,12);
    min = findMin(root);
    printf("%d",min);
return 0;    
}
