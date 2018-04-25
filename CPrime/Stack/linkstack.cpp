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
   bool Pop(T& x); //退栈
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
   top = new LinkNode<T>(x, top);
   assert(top != NULL);
}

template <class T>
bool LinkedStack<T>::Pop(T &x) {
   if(IsEmpty() == true) return false;
   LinkNode<T> *del = top;
   top = top->link;
   x = del->data;
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

