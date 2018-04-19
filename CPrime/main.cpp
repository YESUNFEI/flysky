#include <iostream>
#include <stdlib.h>
using namespace std;

#include "linearList.h"
const int defaultSize = 100;
template <class T>
class SeqList: public LinearList<T> {
protected:
    T *data;
    int maxSize;
    int last;

    void reSize(int newSize);

public:
    SeqList(int sz = defaultSize);

    SeqList(SeqList<T> &L);

    ~SeqList() { delete[] data; }

    int Size() const { return maxSize; }

    int Leangth() const { return last + 1; }

    int Search(T &x) const;

    int Locate(int i) const;

    T *getData(int i) const { return (i > 0 && i <= last + 1) ? &data[i - 1] : NULL; }

    void setData(int i, T &x) { if (i > 0 && i <= last + 1) data[i - 1] = x; }

    bool Insert(int i, T &x);

    bool Remove(int i, T &x);

    bool IsEmpty() { return (last == -1) ? true : false; }

    bool IsFull() { return (last == maxSize - 1) ? true : false; }

    void input();

    void output();

    SeqList<T> operator=(SeqList<T> &L);
};

template <class T>
SeqList<T>::SeqList(int sz) {
    if(sz > 0) {
        maxSize = sz;
        last = -1;
        data = new T[maxSize];
        if(data == NULL) {
            cerr << "存储分配错误"<<endl;
            exit(1);
        }
    }
}

template <class T>
SeqList<T>::SeqList(SeqList<T>& L){
    maxSize = L.Size();
    last = L.Length() - 1;
    data = new T[maxSize];
    if(data == NULL){
        cerr << "wrong assignment" << endl;
        exit(1);
    }
    for(int i=1; i<=last+1;i++){
        data[i-1] = L.getData(i);
    }
}

template <class T>
void SeqList<T>::reSize(int newSize) {
    if(newSize <= 0){
        cerr << "no valid array length" << endl;
        return;
    }
    if(newSize != maxSize) {
        T * newarray = new T[newSize];
        if(newarray == NULL){
            cerr << "wrong assignment" << endl;
            exit(1);
        }
        int n = last + 1;
        T * srcptr = data;
        T * destptr = newarray;
        while (n--) * destptr++=*srcptr++;
        delete []data;
        data = newarray;
        maxSize = newSize;
    }
}

template <class T>
int SeqList<T>::Search(T& x)const {
    for(int i=0; i<=last;i++){
        if(data[i]==x)return i+1;
    }
    return 0;
}

template <class T>
int SeqList<T>::Locate(int i) const {
    if(i>=1 && i<=last+1)return i;
    else return 0;
}

template <class T>
bool SeqList<T>::Insert(int i, T& x){
    if(last == maxSize-1) return false;
    if(i<0||i>last+1) return false;
    for(int j=last; j>= i; j--){
        data[j+1] = data[j];
    }
    data[i] = x;
    last ++;
    return true;
}

