//
// Created by yesunfei on 18-4-19.
//

//
// Created by yesunfei on 18-4-19.
//
#include <iostream>
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
//链表类
template <class T>
class LinkList<T> {
public:
   LinkList(){first = new LinkNode<T>;}//构造函数
   LinkList(const T& x){first = new LinkNode<T>(x);} //构造函数
   LinkList(LinkList<T>& L); //复制构造函数
   ~LinkList(){makeEmpty();} //析构函数
   void makeEmpty(){}; //将链表置空
   int Length()const; //计算链表的长度
   LinkNode<T> *getHead()const {return first;} //返回附加头结点地址
   void setHead(LinkNode<T> *p) {first = p;} //设置附加头结点地址
   LinkNode<T> *Search(T x); //搜索含数据x的元素
   LinkNode<T> *Locate(int i); //搜索第ｉ个元素的地址
   T *getData(int i); //取出第i个元素的值
   void setData(int i, T& x); //设置第i个元素的值
   bool Insert(int i, T& x); //在第ｉ个元素后插入ｘ
   bool Remove(int i, T& x); //删除第i个元素，ｘ返回该元素的值
   bool IsEmpty()const {return first->link == NULL ? true:false;} //判断表空否
   bool IsFull()const {return false;} //判断表满否？　不满返回ｆａｌｓｅ
   void Sort(); //排序
   void input(); //输入
   void output(); //输出
   LinkList<T>&operator=(LinkList<T>& L); //重载函数：赋值
protected:
   LinkNode<T> *first; //链表头指针
};

template <class T>
LinkList<T>::LinkList(LinkList<T> &L) {
   T value;
   LinkNode<T> *srcptr = L.getHead();
   LinkNode<T> *destptr = first = new LinkNode<T>;
   while (srcptr -> link != NULL){
       value = srcptr -> link -> data;
       destptr->link = new LinkNode<T>(value);
       destptr = destptr->link;
       srcptr = srcptr->link;
   }
   destptr->link = NULL;
};

template <class T>
void LinkList<T>::makeEmpty(){
   //将链表置空
   LinkNode<T> *q;
   while (first->link != NULL){
       q = first->link;
       first->link = first->link;
       first->link = q->link;
       delete q;
   }
};

template <class T>
int LinkList<T>::Length() const {
   LinkNode<T> *p = first->link;
   int count = 0;
   while (p != NULL){
       p = p->link;count ++;
   }
   return count;
}

//搜索含数据ｘ的结点
template <class T>
LinkNode<T> *LinkList<T>::Search(T x) {
   LinkNode<T> *current = first->link;
   while (current != NULL){
       if(current->data == x)
           break;
       else
           current = current->link;
   }
   return current;
}

//定位函数，返回表中第i个元素的地址
template <class T>
LinkNode<T> *LinkList<T>::Locate(int i) {
   if(i < 0) return NULL;
   LinkNode<T> *current = first->link;int k=0;
   while (current !=NULL && k<i){
       current = current->link;
       k++;
   }
   return current;
}

//取出链表第i个元素的值
template <class T>
T *LinkList<T>::getData(int i) {
   if (i < 0) return NULL;
   LinkNode<T> *current = Locate(i);
   if (current == NULL) return NULL;
   else return &current->data;
}

//给链表第i个元素赋值ｘ
template <class T>
void LinkList<T>::setData(int i, T& x) {
   if(i<0) return;
   LinkNode<T> *current = Locate(i);
   if(current == NULL) return;
   else current->data = x;
}

//将新元素ｘ插入在链表第i个结点之后
template <class T>
bool LinkList<T>::Insert(int i, T& x){
   LinkNode<T> *current = Locate(i);
   if(current == NULL) return false;
   LinkNode<T> *newNode = new LinkNode<T>(x);
   if(newNode == NULL) {cerr << "存储失败" << endl;exit(1);}
   newNode->link = current->link;
   current->link = newNode;
   return true;
}

//删除链表中第i个元素，通过引用型参数x返回改元素的值
template <class T>
bool LinkList<T>::Remove(int i, T &x) {
   LinkNode *current = Locate(i-1);
   if(current == NULL || current->link == NULL) return false;
   LinkNode<T> *del = current->link;
   current->link = del->link;
   x = del->data;
   delete del;
   return true;
}

//将单链表中所有数据按逻辑顺序输出到屏幕上
template <class T>
void LinkList<T>::output() {
   LinkNode<T> *current = first->link;
   while (current != NULL){
       cout << current->data << endl;
       current = current -> link;
   }
}


