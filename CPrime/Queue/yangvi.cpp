//
// Created by yesunfei on 18-4-25.
//
//
// Created by yesunfei on 18-4-25.
//
#include <iostream>
#include "queue.h"
using namespace std;
//链表结点类
template <class T>
struct LinkNode {
    T data;
    LinkNode<T> *link;
    LinkNode(LinkNode<T> *ptr = NULL) {link = ptr;}
    LinkNode(const T& item, LinkNode<T> *ptr = NULL){
        data = item;
        link = ptr;
    }
};

template <class T>
class LinkedQueue{
public:
    LinkedQueue():rear(NULL),front(NULL) {}
    ~LinkedQueue(){makeEmpty();};
    bool EnQueue(const T& x);
    bool DeQueue(T& x);
    bool getFront(T& x);
    void makeEmpty();
    bool IsEmpty()const {return (front == NULL)?true:false;}
    int getSize()const;

protected:
    LinkNode<T> *front, *rear; //队头、队尾指针
};

template <class T>
void LinkedQueue<T>::makeEmpty(){
    LinkNode<T> *p;
    while (front != NULL) {
        p = front;
        front = front->link;
        delete p;
    }
}

template <class T>
bool LinkedQueue<T>::EnQueue(const T &x) {
    if(front == NULL) {
        front = rear = new LinkNode<T>(x);
        if(front == NULL) return false;
    } else {
        rear->link = new LinkNode<T>(x);
        if(rear->link == NULL) return false;
        rear = rear->link;
    }
    return true;
};

template <class T>
bool LinkedQueue<T>::DeQueue(T &x) {
    if(IsEmpty() == true) return false;
    LinkNode<T> *del = front;
    x = front->data;
    front = front->link;
    delete del;
    return true;
}

template <class T>
bool LinkedQueue<T>::getFront(T &x) {
    if(IsEmpty() == true ) return false;
    x = front->data;
    return true;
}

template <class T>
int LinkedQueue<T>::getSize() const {
    LinkNode<T> *p = front;int k = 0;
    while (p!=NULL){
        p = p->link;
        k++;
    }
    return k;
}

//杨辉三角形
void YANGVI(int n){
    LinkedQueue<int> Q;
    int k = 0;
    int i=1,j,u,s=0,t;
    Q.EnQueue(i);
    Q.EnQueue(i);
    for(i=1;i<=n;i++){
        Q.EnQueue(k);
        for(j=1; j<=i+2;j++){
            Q.DeQueue(u);
            s = u + s;
            Q.EnQueue(s);
            s = u;
            if(j != i+2){
                cout << s;
            }
        }
        cout << endl;
    }

}

int main(){
    YANGVI(6);
    return 0;
}
