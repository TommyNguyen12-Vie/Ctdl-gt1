#include <iostream>
#include <climits>
using namespace std;
struct Node{
    int value;
    Node *next;
};
void init(Node *&head){
    head = NULL;
}
Node* makeNode(int x){
    Node *p = new Node ;
    p->value = x;
    p->next = NULL;
    return p;
}
void addFirst(Node *&head, int x){
    Node *p= makeNode(x);
    p->next = head;
    head =p;
}
void addLast(Node *&head, int x){
    Node *p = makeNode(x);
    if(head == NULL){
        head =p;
    }
    else {
        Node *last = head;
        while(last->next != NULL){
            last = last->next;
        }
        last->next = p;
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
        Node *prev  = NULL;
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
// Tim phan tu lon nhat trong danh sach
Node* maxElement( Node *head){
    int max = INT_MIN;
    Node *kq = NULL;

    Node *p = head;
    while (p != NULL){
        if(p->value > max){
            max = p->value;
            kq =p;
        }
        p= p->next;
    }
    return kq;

}
void swap(int &a, int &b){
    int tmp =a ;
    a =b;
    b =tmp;
}
// Sap xep cac phan tu dslk giam dan theo pp interchange sort
void interchangeSort(Node *head){
    for(Node *p = head ; p != NULL; p = p->next){
        for(Node *q = p->next; q != NULL; q = q->next){
            if(p ->value < q ->value){
                swap(p->value , q->value);
            }
        }
    }
}
// sap xep cac phan tu dslk giam dan theo pp selection sort
void selectionSort(Node *head){
    Node *p = head;
    while(p != NULL){
        Node *r = maxElement(p);
        if(r != p)
            swap(p->value , r->value);
        p = p->next;    
    }
}
void outPut( Node *head){
   Node *p = head;
   while(p != NULL){
    cout << p->value << " ";
    p = p->next;
   }
}

int main(){
    Node *head;
    init(head);
    addFirst(head,10);
    addFirst(head,8);
    addLast (head, 9);
    addFirst(head,25);
    addFirst(head,20);
   
    Node *p= maxElement(head);
    if(p == NULL)
    cout <<"Danh sach rong"<< endl;
    else 
    cout << "Phan tu lon nhat la: "<< p->value << endl;
    outPut(head);
    cout << endl;
    cout << "========Interchange Sort========" << endl;
    // interchangeSort(head);
    selectionSort(head);

    outPut(head);

    return 0;
}