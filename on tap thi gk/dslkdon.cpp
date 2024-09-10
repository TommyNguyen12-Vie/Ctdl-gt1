#include <iostream>
using namespace std;
struct Node {
    int value;
    Node *next;
};
void init (Node *&head){
    head = NULL;
}
Node* makeNode (int x){
    Node *p = new Node;
    p->value = x;
    p->next = NULL;
    return p;
}
void addFirst(Node *&head, int x){
    Node *p = makeNode(x);
    p->next = head;
    head =p ;
}
void addLast (Node *&head, int x){
    Node *p = makeNode (x);
    if(head == NULL)
    {
        head =p;
    }
    else
    {
        Node *last = head;
        while(last->next != NULL)
        {
            last = last->next ;
        }
        last->next = p;
    }
}
void addAfter(Node *&head, int v, int x){
    Node *p = makeNode(x);
    Node *q = head;
    while(p != NULL && q->value != v){
        q= q->next;
    }
    if(q != NULL){
        p ->next = q->next;
        q->next = p;
    }
}
// Xoa phan tu dau
void deleteFirst( Node *&head){
    if(head != NULL){
        Node *p = head;
        head = p->next;
        p->next = NULL;
        delete(p);
    }
}
void outPut (Node *head){
    Node *p = head;
    while (p != NULL){
        cout << p ->value << " ";
        p = p->next;
    }
}

int main(){
    Node *head;
    init(head);
    addFirst(head,10);
    addFirst(head,15);
    addFirst(head,30);
    addFirst(head,20);
    addLast(head,5);
    addLast(head,25);
    addAfter(head,30,35);
    deleteFirst(head);
    outPut(head);

    return 0;
}