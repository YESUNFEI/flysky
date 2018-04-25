//
// Created by yesunfei on 18-4-25.
//
#include <assert.h>
#include <iostream>
#include "queue.h"
using namespace std;

template <class T>
class SeqQueue: public Queue<T> {
public:
   SeqQueue(int sz = 10); //构造函数
   ~SeqQueue() {delete[] elements;} //析构函数
   bool EnQueue(const T& x);
   bool int DeQueue(T& x);
   bool getFront(T& x);
   void makeEmpty() {front = rear = 0;}
   bool IsEmpty()const {return (front == rear)?true:false;}
   bool IsFull()const {return ((rear+1)%maxSize == front)?true:false;}
   int getSize()const {return (rear-front+maxSize)%maxSize;}

protected:
   int rear, front; //队尾与队头指针
   T *elements; //存放队列元素的数组
   int maxSize;
};

template <class T>
SeqQueue<T>::SeqQueue(int sz):front(0),rear(0),maxSize(sz) {
   elements = new T[maxSize];
   assert(elements != NULL);
};

template <class T>
bool SeqQueue<T>::EnQueue(const T &x) {
   if(IsEmpty() == true) return false;
   elements[rear] = x;
   rear = (rear+1) % maxSize;
   return true;
};

template <class T>
bool SeqQueue<T>::DeQueue(T &x) {
   if(IsEmpty() == true) return false;
   x = elements[front];
   front = (front+1) % maxSize;
   return true;
}

template <class T>
bool SeqQueue<T>::getFront(T &x) {
   if(IsEmpty() == true) return false;
   x = elements[front];
   return true;
}