//
// Created by yesunfei on 18-4-24.
//

#ifndef YEYEYYE_STACK_H
#define YEYEYYE_STACK_H

const int maxSize = 50;
template <class T>
class Stack {
public:
    Stack(){}; //构造函数
    virtual void Push(const T& x) = 0; //新元素进栈
    virtual bool Pop(T& x) = 0; //栈顶元素出栈
    virtual bool getTop(T& x)const = 0; //读取栈顶元素
    virtual bool IsEmpty() const = 0; //判断栈空否
    virtual bool IsFull() const = 0;//判断栈满否
    virtual int getSize() const = 0; //计算栈中元素个数
};


#endif //YEYEYYE_STACK_H