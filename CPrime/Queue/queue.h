//
// Created by yesunfei on 18-4-25.
//

#include <cxxabi.h>

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

const int maxSize = 50;
template <class T>
class Queue {
public:
    Queue(){}; //构造函数
    ~Queue(){}; //析构函数
    virtual bool EnQueue(const T& x) = 0; //新元素ｘ进队列
    virtual bool DeQueue(T& x) = 0; //队头元素出队列
    virtual bool getFront(T& x) = 0; //读取队头元素的值
    virtual bool IsEmpty()const = 0; //判断队列空否
    virtual bool IsFull()const = 0; //判断队列满否
    virtual int getSize()const = 0; //求队列元素个数
};

#endif //QUEUE_QUEUE_H
