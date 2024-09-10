// Mỗi nhân viên có thông tin họ tên , mức lương, chức vụ, quê quán,. 
// Sử dụng dslk quản lí nhân viên của công ty.
// - Đọc danh sách nhân viên tù tập tin và thêm vào danh sách liên kết
// - Tìm kiếm nhân viên theo họ tên hoặc khoảng lương
// -Sắp xếp danh sách nhân viên giảm dần theo lương.
// -Sắp xếp nhân viên giảm dần theo quê quán, nếu cùng quê thì tăng dần theo họ tên.
// -In danh sách nhân viên theo từng nhóm quê quán, và cho mỗi quê quán cho bao 
//  nhiêu nhân viên, mức lương Tb và ghi kết quả ra tập tin.
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct NhanVien {
    string hoTen;
    double luong;
    string queQuan;
    string chucVu;
};

struct Node {
    NhanVien value;
    Node *next ;
};
void init(Node *&head){
    head = NULL;
}

Node* makeNode (NhanVien x){
    Node *p = new Node ;
    p->value =x;
    p->next = NULL;
    return p;
}
void addFirst(Node *&head , NhanVien x){
    Node *p= makeNode(x);
    p->next = head;
    head =p;
}

void readFileNhanVien(Node *&head){
    ifstream f;
    f.open ("NhanVien.txt", ios::in);
    while(!f.eof()){
        NhanVien nv;
        getline(f, nv.hoTen);
        f >> nv.luong;
        f.ignore();
        getline(f,nv.chucVu);
        getline(f,nv.queQuan);
        addFirst(head,nv);
    }

    f.close();
}
// Nen viet xuart 1 Nv truoc khi xuat nhieu nv
void disPlayAnEmloyess(NhanVien nv){
    cout << "Ho ten: "<< nv.hoTen << endl;
    cout << "Luong: "<< nv.luong << endl;
    cout << "Chuc vu: "<< nv.chucVu << endl;
    cout << "Que quan: "<< nv.queQuan << endl;
    cout << "=============="<< endl;
}
void disPlay(Node *head){
    Node *p = head;
    while(p != NULL){
        disPlayAnEmloyess(p->value);
        p= p->next;
    }
}

// Tim kiem theo khoang luong 
Node* search(Node *head, double fromPrice , double toPrice){
    Node *kq;
    init(kq);

    Node *p = head;
    while(p != NULL){
        if(p ->value.luong >= fromPrice && p->value.luong <= toPrice)
        addFirst(kq,p->value);
        p= p->next;
    }

    return kq;

}
void deleteFirst(Node *&head){
   if(head != NULL){
    Node *p = head;
    head = p->next;
    p->next = NULL;
    delete(p);
   }
}
// Giai phong tat ca bo nho
void clean (Node *&head){
    while(head != NULL){
        deleteFirst(head);
    }
}
// Tim nhan vien theo ten
Node *search (Node *head, string keyword){
    Node *kq;
    init(kq);
    Node *p = head;
    while (p != NULL){
        if(p->value.hoTen.find(keyword) != string ::npos)
        addFirst(kq, p->value);
        p=p->next;
    }
    return kq;
}
void sortInterchange(Node *head){
    for(Node *p = head; p!= NULL; p =p->next){
        for(Node *q = p->next; q != NULL; q = q->next){
            if(p->value.luong < q->value.luong)
                swap(p->value, q->value);
        }
    }
}
// Sap xep nhan vien giam dan theo que quan
void sort(Node *head){
    for(Node *p = head; p != NULL; p = p->next){
        for(Node *q = p->next; q != NULL; q= q->next)
            if(p->value.queQuan < q->value.queQuan)
                swap(p->value, q->value);
            else if(p->value.queQuan == q->value.queQuan)
                if(p->value.hoTen > q->value.hoTen)
                    swap(p->value , q->value);
    }
}


int main(){
    Node *head;
    init(head);
    cout <<"=== DANH SACH NHAN VIEN ===" << endl;
    readFileNhanVien(head);
    disPlay(head);

    cout <<"===== Tim Nhan Vien Theo Luong ===="<< endl;
    Node *kq = search(head, 9, 10);
    disPlay(kq);

    cout <<"===== Tim Nhan Vien Theo ten ===="<< endl;
    Node *kq1 = search(head,"Tran");
    disPlay(kq1);

    cout <<"Danh sach giam theo QQ tang theo ho ten"<< endl;
    sort(head);
    disPlay(head);
    clean(kq1);
    clean(kq);
    clean(head);
    return 0;
}