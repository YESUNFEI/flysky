//
// Created by yesunfei on 18-4-23.
//
#include <iostream>
using namespace std;
template <class T>
struct CircLinkNode {
   T data;
   CircLinkNode<T> *link;
   CircLinkNode(CircLinkNode<T> *ptr = NULL) {link = ptr;}
   CircLinkNode(const T& item, CircLinkNode<T> *ptr = NULL){
       data = item;
       link = ptr;
   }
};

template <class T>
class CircList{
public:
   CircList<T>(){first = new CircLinkNode<T>;};
   CircLinkNode<T> *getHead()const { return first; };
   bool Insert(int i, T x);
private:
   CircLinkNode<T> *first, *last;
};


template <class T>
bool CircList<T>::Insert(int i, T x) {
   if(i<0) return false;
   CircLinkNode<T> *current = getHead();
   int k=1;
   while (k<i){
       current = current->link;
       k++;
   }
   CircLinkNode<T> *newNode = new CircLinkNode<T>(x);
   if(newNode == NULL) {cerr << "分配失误" <<endl;}
   current->link = newNode;
   newNode->link = getHead()->link;
   return true;
}


template <class T>
int Josephus(CircList<T>&Js, int n, int m){
   CircLinkNode<T> *p = Js.getHead()->link, *pre = NULL;
   int i,j;
   for(i=0;i<n-1;i++){
       for(j=1;j<m;j++){
           pre = p; p = p->link;
       }
       cout << "被淘汰的：" << p->data << endl;
       pre->link = p->link;
       delete p;
       p = pre->link;

   }
   cout << "结果：" << pre->data << endl;
   return 0;
}

int main(){
   CircList<int> clist;
   int i, n, m;
   cin >> n >> m;
   for(i=1; i<=n ; i++){
       clist.Insert(i, i);
   }
   Josephus(clist, n, m);
   return 0;
}