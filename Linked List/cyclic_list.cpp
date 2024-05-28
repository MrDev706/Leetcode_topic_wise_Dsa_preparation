

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
}

bool isCircular(struct Node *head){
    if(head==NULL){
        return true;
    }
 
    struct Node * slow = head->next;

    while(slow!=NULL && slow!=head){
        slow = slow->next;
    }
   return slow==head;
}

Node* newNode(int data){
    Node * temp = new Node
    temp->data = data;
    temp->next = NULL;
    return temp; 
}


int main(){
  struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
  
    isCircular(head)? cout << "Yes\n" :
                      cout << "No\n" ;
  
    // Making linked list circular
    head->next->next->next->next = head;

    isCircular(head)? cout << "Yes\n" :
                      cout << "No\n" ;


}