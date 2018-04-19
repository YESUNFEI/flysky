//
// Created by yesunfei on 18-4-18.
//

#ifndef CPRIME_LINEARLIST_H
#define CPRIME_LINEARLIST_H

template <class T>
class LinearList
{
public:
    LinearList(){}                              //构造函数
    virtual ~LinearList(){}                     //析构函数
public:
    virtual int Size()const = 0;                            //获取最大表项总数
    virtual int Length()const = 0;                          //计算实际表项总数
    virtual int Search(const T& x)const = 0;                //搜索数据值为x的表项并返回表项序号
    virtual int Locate(int i)const = 0;                     //获取第i个表项并返回表项序号
    virtual bool GetData(int i, T& x)const = 0;             //获取第i个表项的数据值保存至x，并返回获取成功与否
    virtual bool SetData(int i, const T& x) = 0;            //修改第i个表项的数据值为x
    virtual bool Insert(int i, const T& x) = 0;             //在第i个表项后插入数据值为x的新表项
    virtual bool Remove(int i, T& x) = 0;                   //删除第i个表项，并将被删表项的数据值保存至x
    virtual bool IsEmpty()const = 0;                        //判断表是否为空
    virtual bool IsFull()const = 0;                         //判断表是否为满
    virtual void Sort() = 0;                                //表排序——冒泡排序
    virtual void InputFront() = 0;                          //前插法建立线性表
    virtual void InputRear() = 0;                           //后插法建立线性表
    virtual void Output()const = 0;                         //输出所有表项的数据值
    virtual void Reverse() = 0;                             //线性表逆置
    virtual void MakeEmpty() = 0;                           //清空线性表
    virtual LinearList<T>& operator=(const LinearList<T>& L) = 0;   //线性表间赋值操作——重载等号运算符
};

#endif //CPRIME_LINEARLIST_H
