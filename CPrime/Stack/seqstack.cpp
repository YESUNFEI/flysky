//
// Created by yesunfei on 18-4-24.
//
#include <assert.h>
#include <iostream>
#include "stack.h"
using namespace std;
const int stackIncreament = 20; //栈溢出时扩展空间的增量
template <class T>
class SeqStack: public Stack<T> {
public:
   SeqStack(int sz = 50); //建立一个空战
   ~SeqStack() {delete[]elements;} //析构函数
   void Push(const T& x);
   bool Pop(T& x);
   bool getTop(T& x);
   bool IsEmpty()const {return (top == -1)?true:false;}
   bool IsFull()const {return (top == maxSize-1)?true: false;}
   int getSize()const{return top + 1;}
   void MakeEmpty() {top = -1;} //清空栈
private:
   T *elements; //存放栈中元素的栈数组的头指针
   int top; //栈顶指针；
   int maxSize; //栈中最大可容纳元素个数
   void overflowProcess(); //栈溢出处理
};

//顺序栈的构造函数
template <class T>
SeqStack<T>::SeqStack(int sz):top(-1), maxSize(sz){
   elements = new T[maxSize]; //创建栈的数组空间
   assert(elements != NULL);   //断言：动态存储分配成功与否
};

//栈溢出处理
template <class T>
void SeqStack<T>::overflowProcess() {
   //私有函数：扩充栈的存储空间
   T *newArray = new T[maxSize + stackIncreament];
   if(newArray == NULL) {cerr<<"存储分配失败！"<<endl;exit(1);}
   for (int i=0; i<=top; i++) newArray[i] = elements[i];
   maxSize = maxSize + stackIncreament;
   delete []elements;
   elements = newArray;
}

template <class T>
void SeqStack<T>::Push(const T &x) {
   if(IsFull() == true) overflowProcess(); // 栈溢出处理
   elements[++top] = x;
}

template <class T>
bool SeqStack<T>::Pop(T &x) {
   if(IsEmpty() == true) return false;
   x = elements[top--];
   return true;
}

template <class T>
bool SeqStack<T>::getTop(T &x) {
   if(IsEmpty() == true) return false;
   x = elements[top];
   return true;
}