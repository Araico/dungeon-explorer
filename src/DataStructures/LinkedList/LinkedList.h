#pragma once

#include <iostream>
#include "Node.h"

template <typename T>
class LinkedList {

  private:
   int length = 0;
   Node<T>* firstNodePtr = nullptr;
   Node<T>* lastNodePtr = nullptr;

  public:
   LinkedList();
   Node<T>* getFirstNodePtr();
   Node<T>* getLastNodePtr();
   void setFirstNodePtr(Node<T>* nodePtr);
   void setLastNodePtr(Node<T>* nodePtr);
   int getLength();

   T& operator[](int index);

   void insert(const T& element, int index = -1);
   void remove(int index = -1);

   void print();

   // void Swap(int index1, int index2);
};
