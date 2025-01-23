#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>

template <typename T> class ListNode{
    public:
    T data;
    ListNode<T> *next;
};

template <typename T> class LLIter{
    private:
    ListNode<T> *ptr;

    public:
    LLIter<T>(ListNode<T> *p) {ptr = p;}

    ListNode<T> *operator->() {return ptr;}

    void operator+(int inc){
        int hops = 0;
        while(hops < inc && ptr != nullptr){
            ptr = ptr->next;
            hops++;
        }
    }

};

template <typename T> class MyList{
    private:

    ListNode<T> *head = nullptr;
    int size = 0;

    public:
    
    MyList();
    ~MyList();
    MyList &operator=(const MyList<T> &rhs); //equality operator
    MyList(const MyList<T> &rhs); //copy constructor
    T &front();
    int size();
    void clear();
    void pushFront(const T &value);
    void popFront();
    void insert(LLIter<T> iter, const T &value);
    void removeVal(const T &value);
    void removeNode(LLIter<T> iter);
    LLIter<T> find(const T &value);
    void reverse();
};


#include "MyList.hpp"
#endif