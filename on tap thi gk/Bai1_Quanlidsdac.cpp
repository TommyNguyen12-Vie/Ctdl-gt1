#include <iostream>
using namespace std;
#define MAX 100

struct List 
{
    int a[MAX];
    int n;
};
void inPut (List &l)
{
    cout <<"n = ";
    cin >> l.n;
    for( int i =0 ; i <l.n; i++)
    {
        cout << "a[" << i << "]";
        cin >> l.a[i];
    }
}

void outPut (List l)
{
    for( int i =0 ; i < l.n; i++)
    {
        cout << l.a[i] << " ";
    }
    cout << endl;
}
// Kiem tra danh sach co tang dan khong?
bool checkInc(const List l){
   for(int i =0 ; i < l.n -1; i++)
   {
    if(l.a[i] > l.a[i + 1])
    {
        return false;
    }
    return true;
   }
}
// Kiem tra co doan con co k phan tu tang dan khong?
 bool checkIncK(const List l, const int k){
    int count =0;
    for( int i=0; i < l.n -1; i++)
    {
        if(l.a[i] < l.a[i + 1]){
            count ++;
            if(count + 1 == k)
            return true;
        }
        else 
            count =0;
    }
    return false;
 }

 // Tim phan tu lon nhat trong ds?
 int searchMax(const List l){
    if(l.n > 0){
        int idx =0;
        for( int i =1; i < l.n; i++){
            if(l.a[i] > l.a[idx])
            idx = i;
        }
    return idx;
    }
    else
    return -1;
 }
 // Tim phan tu lon thu hai
 int searchSecondMax(const List l){
    if(l.n >= 2){
        int firstMax, secondMax;
        if(l.a[0] > l.a[1]){
            firstMax = 0;
            secondMax =1;
        }
        else {
            firstMax = 1;
            secondMax =0;

        }
        for(int i = 2; i < l.n; i++)
        if(l.a[i] > l.a[firstMax]){
            secondMax = firstMax ;
            firstMax =i;
        }
        else if(l.a[i] > secondMax)
        secondMax =i;
    }
    return -1;
 }
 // Tim mot phan tu trong danh sach
 int search(const List &l, int x){
    for( int i =0; i <l.n ; i++)
    {
        if(l.a[i] == x)
        {
            return i; // tra ve chi so cua phan tu
        }
    }
    return  -1;// tra ve neu khong tim thay
 }
 // Them  mot phan tu vao cuoi danh sach
 void insertLast(List &l, int x){
    if(l.n > MAX){
        l.a[l.n] = x;
        l.n ++;
    }
    else {
        cout <<"Danh sach da day, khong the them phan tu: "<< endl;
    }
 }
 
 // Them mot phan tu vao danh sach tai vi tri i
 void insertPosition(List &l, int x, int k){
    if(x >= 0 && x <= l.n){
        if(l.n < MAX){
            for( int i = l.n; i > x; i--){
                l.a[i] = l.a[i -1];
            }
            l.a[x] = k;
            l.n ++;
        }
        else{
            cout <<"Danh sach da day, khong the them phan tu :"<< endl;
        }
    }
    else 
    {
        cout <<"Vi tri khong hop le !!"<< endl;
    }
 }

 // Xoa phan tu cuoi danh sach
 void deleteLast (List &l){
    if(l.n > 0){
        l.n --;
    }
    else 
    {
        cout <<"Danh sach rong, khong the xoa phan tu: "<< endl;
    }
 }

 // Xoa phan tu tai vi tri thu i
 void deletePosition(List &l, int x)
 {
    if(x >= 0 && x < l.n)
    {
        for( int i =0; i < l.n -1; i++)
        {
            l.a[i] = l.a[i + 1];
        }
        l.n--;
    }
    else {
        cout <<"Vi tri khong hop le !!!"<< endl; 
    }
 }
 
int main()
{
    List l;
    inPut (l);
    outPut(l);
    if(checkInc(l) == true)
    cout <<"Tang dan "<< endl;
    else 
    cout <<"Khong tang dan"<< endl;

    if(checkIncK(l,3) == true )
    cout <<"co 3 phan tu k lien tiep tang" << endl;
    else
    cout <<"Khong co phan tu lien tiep tang dan"<< endl;

    int idx = searchMax(l);
    if(idx >= 0)
    cout <<"Phan tu lon nhat " << l.a[idx] << " tai vi tri " << idx << endl;
    cout << endl;
    int idx2 = searchSecondMax(l);
    if(idx2 >= 0)
    cout << "Phan tu lon thu hai "<< l.a[idx2] << " tai vi tri " << idx2 << endl;

    insertLast(l,10);
    outPut(l);


    return 0;
}
    