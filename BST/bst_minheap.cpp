//

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
     Node* left,* right;
}

struct Node* getNode(int data){
    struct Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;

}
 
void inorderTravel(Node* root, vector<int>& v){
    if(!root) return;
    inorderTravel(root->left, v);
    v.push_back(root->val);
    inorderTravel(root->right, v);
}

void bstToMinHeap(Node* root, vector<int>& v, int i){
    if(root==NULL) return;
    root->data = v[++*i];
    bstToMinHeap(root->left, v, i);
    bstToMinHeap(root->right, v, i);
}



void converToMinHeap(Node* root){
    vector<int> v;
    int i = -1;
    inorderTravel(root, v);
    bstToMinHeap(root, v, &i);
}

void preorderTravel(Node* root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    preorderTravel(root->left);
    preorderTravel(root->right);
}

int main(){
    struct Node* root = getNode(4);
    root->left = getNode(2);
    root->right = getNode(6);
    root->left->left = getNode(1);
    root->left->right = getNode(3);
    root->right->left = getNode(5);
    root->right->right = getNode(7);
    converToMinHeap(root);
    cout<<"preorder :"<<endl;
    preorder(root);
 
}