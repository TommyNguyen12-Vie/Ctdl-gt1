#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *next;
};

void init(Node *&head){
    head = NULL;
}
Node* makeNode (int x){
    Node *p = new Node ;
    p->value =x;
    p->next = NULL;
    return p;
}
void addFirst(Node *& head, int x){
    Node *p = makeNode(x);
    p->next = head;
    head =p;
}

void addLast(Node *&head, int x){
    Node *p = makeNode(x);
    if(head == NULL){
        head =p;
    }
    else{
        Node *last = head;
        while(last->next != NULL){
            last = last->next;
        }
        last->next =p;
    }
}
void deleteFirst(Node *&head){
    if(head != NULL){
        Node *p = head;
        head = p->next;
        p->next = NULL;
        delete(p);
    }
}
void deleteLast(Node *&head){
    if(head != NULL){
        Node *last = head;
        Node *prev = NULL;
        while(last->next != NULL){
            prev = last;
            last = last->next;
        }
        if(prev == NULL){
            deleteFirst(head);
        }
        else{
            prev->next = NULL;
            delete(last);
        }
    }
}
void outPut (Node *head){
    Node *p = head;
    while (p != NULL){
        cout << p->value << " ";
        p = p->next;
    }
}
int main(){
    Node *head;
    init(head);
    addFirst(head,20);
    addFirst(head ,25);
    addFirst(head,30);
    addLast(head,15);
    addLast(head,10);
    deleteFirst(head);
    deleteLast(head);
    outPut(head);
    

    return 0;
}