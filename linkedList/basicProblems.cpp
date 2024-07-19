// Given the head of linked list, delete every alternate from the list staring
// from the second element--> deleteAlternateNodes();

// Given the head of a sorted linkedlist,delete all duplicates such that each
// element appears only once. Return the linked list sorted as
// well-->deleteDuplicatNode();

// Given teh head of ll, print all its elements in reverse order( don'd reverse
// the ll,just print it in reverse order)--> recursive approach-->
// reversePrint()

// Given the head of ll, reverse the ll--> reverseLinkedlist()

// Given the head of ll, reverse the ll using recursive approach--> reverseLLRecursion()

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
class linkedList {
public:
  Node *head;
  linkedList() { head = NULL; }
  void insertAtTail(int val) {
    Node *new_node = new Node(val);
    if (head == NULL) // linkedlist is empty
    {
      head = new_node;
      return;
    }
    Node *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    } // temp is at last element
    temp->next = new_node;
  }
  void display() {
    Node *temp = head;
    while (temp != NULL) {
      cout << temp->val << "->";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }
};
void deleteAlternateNodes(Node *&head) {
  Node *current = head;
  while (current != NULL && current->next != NULL) {
    Node *temp = current->next;
    current->next = current->next->next;
    free(temp);
    current = current->next;
  }
}
void deleteDuplicateNode(Node *head) {
  Node *current = head;
  while (current != NULL) {
    while (current->next != NULL && current->val == current->next->val) {
      Node *temp = current->next;
      current->next = current->next->next;
      free(temp);
    }
    current = current->next;
    // cout<<current<<endl;
  }
}
void reversePrint(Node *&head) {
  Node *current = head;
  if (current == NULL)
    return;
  reversePrint(current->next);
  cout << head->val << " ";
}
Node *reverseLinkedlist(Node *&head) {
  Node *current = head;
  Node *prev = NULL;
  while (current != NULL) {
    Node *temp = current->next;
    current->next = prev;
    prev = current;
    current = temp;
  }
  return prev;
}
Node* reverseLLRecursion(Node* &head){
  //base case
  if(head==NULL || head->next==NULL){
    return head;
  }
  Node* new_node = reverseLLRecursion(head->next);
  head->next->next = head;
  head->next=NULL;
  return new_node;
}
int main() {
  linkedList ll;
  ll.insertAtTail(1);
  ll.insertAtTail(2);
  ll.insertAtTail(3);
  ll.insertAtTail(4);
  ll.insertAtTail(5);
  ll.insertAtTail(6);
  ll.display();
  // deleteAlternateNodes(ll.head);
  // ll.display();
  // deleteDuplicateNode(ll.head);
  // ll.display();
  // reversePrint(ll.head);
  // ll.head= reverseLinkedlist(ll.head);
  // ll.display();
  ll.head = reverseLLRecursion(ll.head);
  ll.display();
  return 1;
}