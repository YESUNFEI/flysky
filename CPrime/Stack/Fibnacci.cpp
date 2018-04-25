//
// Created by yesunfei on 18-4-24.
//
#include <assert.h>
#include <iostream>
#include "stack.h"
using namespace std;

template <class T>
struct LinkNode {
    T data;
    long n;int tag;
    LinkNode<T> *link;
    LinkNode(LinkNode<T> *ptr = NULL) {link = ptr;}
    LinkNode(const T& item, LinkNode<T> *ptr = NULL){
        data = item;
        link = ptr;
    }
};

template <class T>
class LinkedStack: public Stack<T> {
public:
    LinkedStack(): top(NULL) {} //构造函数　置空栈
    ~LinkedStack() {makeEmpty();}; //析构函数
    void Push(const T& x); //进栈
    bool Pop(); //退栈
    bool getTop(T& x)const; //读取栈顶元素
    bool IsEmpty()const {return(top == NULL)?true:false;}
    int getSize()const;//求栈的元素个数
    void makeEmpty(); //清空栈的内容
private:
    LinkNode<T> *top; // 栈顶指针，即链头指针
};

template <class T>
void LinkedStack<T>::makeEmpty() {
    LinkNode<T> *p;
    while (top !=NULL){
        p = top;
        top = top->link;
        delete p;
    }
};

template <class T>
void LinkedStack<T>::Push(const T &x) {
    x->link = top;
    top = x;
    assert(top != NULL);
}

template <class T>
bool LinkedStack<T>::Pop() {
    if(IsEmpty() == true) return false;
    LinkNode<T> *del = top;
    top = top->link;
    delete del;
    return true;
}

template <class T>
bool LinkedStack<T>::getTop(T &x) const {
    if(IsEmpty() == true) return false;
    x = top->data;
    return true;
}

template <class T>
int LinkedStack<T>::getSize() const {
    LinkNode<T> *p = top;int k = 0;
    while (p != NULL){
        p = p->link;
        k++;
    }
    return k;
}

template <class T>
long Fibnacci(LinkedStack<T>& S,long n){
    LinkNode<T> *w = new LinkNode<T>;
    long sum = 0;
    do{
        while (n > 1){
            w->n = n;
            w->tag = 1;
            S.Push(w);
            n--;
        }
        sum = sum + n;
        while (S.IsEmpty() == false){
            S.Pop();
            if(w->tag == 1){
                w->tag = 2;
                n = w->n -2;
                S.Push(w);
                break;
            }
        }

    } while(S.IsEmpty() == false );
    cout << "结果是：" << sum << endl;
    return sum;
}

int main(){
    Stack<int> Sj;
    Fibnacci(Sj,4);
    return 0;
}
