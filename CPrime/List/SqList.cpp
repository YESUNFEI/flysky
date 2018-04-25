//
// Created by yesunfei on 18-4-19.
//
#include <iostream>
using namespace std;

int maxSize = 100;

template <class T>
class SqListClass
{
private:
    T *data; //存放顺序表的元素
    int length; //存放顺序表的长度
public:
    SqListClass(); //构造函数
    ~SqListClass(); //析构函数
    void CreateList(T a[], int n); //建造顺序表
    void DisplayList(); //输出顺序表中所有元素
    int ListLength(); //求顺序表的长度
    bool GetElem(int i, T &e); //求某序列号的元素值
    int LocateElem(T e); //按元素查找第一个序号位置
    bool ListInsert(int i, T e); // 在位置i插入数据元素
    bool ListDelete(int i); //在位置i删除数据元素
    void ReverseList(SqListClass<T> &L); //翻转顺序表
    void reSize(int newSize); //扩充顺序表存储空间大小
};

//线性表的初始化
template <class T>
SqListClass<T>::SqListClass() {
    data = new T[maxSize];
    length = 0;
}

//析构函数
template <class T>
SqListClass<T>::~SqListClass() {
    delete [] data;
}

// 创建线性表
template <class T>
void SqListClass<T>::CreateList(T a[], int n) {
    int i;
    for(i=0;i<n;i++){
        data[i] = a[i];
    }
    length = i;
}

//　输出线性表所有元素
template <class T>
void SqListClass<T>::DisplayList() {
    cout << "out: " << endl;
    for(int i=0;i<length; i++){
        cout << data[i] << " ";
    }
    cout << endl;
}

//求线性表的长度
template <class T>
int SqListClass<T>::ListLength() {
    return length;
}

//求顺序表中某序列号的元素值
template <class T>
bool SqListClass<T>::GetElem(int i, T &e) {
    if(i<0 || i>length) return false;
    e = data[i-1];
    return true;
}

//按元素查找其第一个序号位置
template <class T>
int SqListClass<T>::LocateElem(T e) {
    int i = 0;
    while(i<length && data[i]!=e) i++;
    if(i>=length) return 0;
    else return i+1;
}

//在位置ｉ插入元素e
template <class T>
bool SqListClass<T>::ListInsert(int i, T e) {
    if(i<0 || i>length) return false;
    for(int j=length;j>=i;j--){
        data[j] = data[j-1];
    }
    data[i-1] = e;
    length ++;
    return true;
}

// 在位置ｉ删除元素
template <class T>
bool SqListClass<T>::ListDelete(int i) {
    if(i<0 || i>length) return false;
    for(int j=i-1;j<length;j++){
        data[j] = data[j+1];
    }
    length--;
    return true;
}

//　翻转顺序表
template <class T>
void SqListClass<T>::ReverseList(SqListClass<T> &L) {
    T temp;
    for(int j=0; j<L.length/2;j++){
        temp = L.data[j];
        L.data[j] = L.data[length-j-1];
        L.data[length-j-1] = temp;
    }
}

//扩充顺序表的存储数组空间大小，新数组元素个数为newsize
template <class T>
void SqListClass<T>::reSize(int newSize) {
    if(newSize <= 0){
        cerr << "无效的数组大小" << endl;return ;
    }
    if(newSize != maxSize){
        T * newArray = new T[newSize];
        if(newArray == NULL) {
            cerr << "存储分配错误" << endl; exit(1);
        }
        T * srcptr = data; //源数组首地址
        T * destptr = newArray; //目的数组首地址
        int n = length;
        while(n--) *destptr++=*srcptr++;
        delete []data;
        data = newArray;
        maxSize = newSize;
    }
}

int main(){
    SqListClass<int> sqList;
    int arr[3] = {3,4,5};
    sqList.CreateList(arr, 3);
    sqList.DisplayList();
    cout << "sqList length is " << sqList.ListLength() << endl;
    cout << "the 5 elem is local: " << sqList.LocateElem(5) << endl;
    int a;
    sqList.GetElem(2, a);
    cout << "The 2 local is elem " << a << endl;
    sqList.ListInsert(2, 6);
    sqList.DisplayList();
    sqList.ListDelete(1);
    sqList.DisplayList();
    sqList.ReverseList(sqList);
    sqList.DisplayList();
    cout << "maxSize: " << maxSize << endl;
    sqList.reSize(9);
    cout << "maxSize: " << maxSize << endl;
    sqList.DisplayList();
    return 0;
}