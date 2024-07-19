#include <bits/stdc++.h>
using namespace std;
class Node {
public:
  int val;
  Node *next;
  Node(int data) {
    val = data;
    next = NULL;
  }
};
void insertAtHead(Node *&head, int val) {
  Node *newNode = new Node(val);
  newNode->next = head;
  head = newNode;
}
void insertAtTail(Node *&head, int val) {
  Node *newNode = new Node(val);
  Node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  // temp has reached last
  temp->next = newNode;
}
void insertAtPosition(Node *&head, int val, int pos) {
  if (pos == 0) {
    insertAtHead(head, val);
    return;
  }
  Node *new_node = new Node(val);
  Node *temp = head;
  int current_pos = 0;
  while (current_pos < pos - 1) {
    temp = temp->next;
    current_pos++;
  }
  // temp is at pos-1
  new_node->next = temp->next;
  temp->next = new_node;
}
void updateAtPosition(Node *&head, int val, int k) {
  Node *temp = head;
  int current_pos = 0;
  while (current_pos < k) {
    temp = temp->next;
    current_pos++;
  }
  // temp will be at kth position
  temp->val = val;
}
void deleteAtHead(Node *&head) {
  Node *temp = head;
  head = head->next;
  free(temp);
}
void deleteAtTail(Node* &head){
  Node* second_last = head;
  while(second_last->next->next!=NULL){
    second_last = second_last->next;
  }
  //second_last is at second_last
  Node* temp = second_last->next;
  second_last->next = NULL;
  free(temp);
}
void deleteAtPosition(Node* &head,int pos){
  if(pos==0){
    deleteAtHead(head);
    return;
  }
  Node* prev = head;
  int current_pos = 0;
  while(current_pos!=pos-1){
    prev = prev->next;
    current_pos++;
  }
  //prev will be at pos-1
  Node* temp = prev->next;
  prev->next = prev->next->next;
  free(temp);
  
}
void display(Node *head) {
  Node *temp = head;
  while (temp != NULL) {
    cout << temp->val << "->";
    temp = temp->next;
  }
  cout << "NULL" << endl;
}

int main() {
  Node *head = NULL;
  insertAtHead(head, 2);
  display(head);
  insertAtHead(head, 5);
  display(head);
  insertAtTail(head, 8);
  display(head);
  insertAtPosition(head, 9, 2);
  display(head);
  updateAtPosition(head, 3, 1);
  display(head);

  deleteAtHead(head);
  display(head);
  deleteAtTail(head);
  display(head);
  deleteAtPosition(head,0);
  display(head);
  return 0;
}