#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* next;
};
Node* deleteNode(Node* start, int k){
    if (k < 1)
        return start;
    if (start == NULL)
        return NULL;
    if (k == 1){
        Node *res = start->next;
        delete(start);
        return res;
    }
    start->next = deleteNode(start->next, k-1);
    return start;
}
void push(struct Node **head_ref, int new_data){
    struct Node *new_node = new Node;
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}
void printList(struct Node *head){
    while (head!=NULL){
        cout << head->data << " ";
        head = head->next;
    }
    printf("\n");
}
int main(){
    struct Node *head = NULL;
    push(&head,3);
    push(&head,2);
    push(&head,6);
    push(&head,5);
    push(&head,11);
    push(&head,10);
    push(&head,15);
    push(&head,12);
    int k = 3;
    head = deleteNode(head, k);
    printf("\nModified Linked List: ");
    printList(head);
    return 0;
}
