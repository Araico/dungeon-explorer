#pragma once
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "Node.h"

using namespace std;

template <typename T>
class LinkedList {
  private:
   Node<T>* first;
   int length = 1;

  public:
   LinkedList(T firstVal);
   T& operator[](int index);
   int getLength();
   void Insert(T data, int index = -1);
};

// implementation
template <typename T>
LinkedList<T>::LinkedList(T firstVal) : first(new Node<T>(firstVal)) {}

template <typename T>
void LinkedList<T>::Insert(T data, int index) {
   Node<T>* currentNode = first;

   if (index == -1) {
      while (currentNode->getNext() != nullptr) {
         currentNode = currentNode->getNext();
      }
      currentNode->setNext(new Node<T>(data));
   } else if (index == 0) {
      first = new Node<T>(data, first);
   } else if (index < (length)) {
      for (int i = 1; i < index; i++) {
         currentNode = currentNode->getNext();
      }
      currentNode->setNext(new Node<T>(data, currentNode->getNext()));
   } else {
      throw runtime_error("Index is out of range");
   }

   length++;
}

template <typename T>
T& LinkedList<T>::operator[](int index) {
   if (index > (length - 1)) throw runtime_error("Index is out of range");

   Node<T>* currentNode = first;

   if (index == -1) {
      while (currentNode->getNext() != nullptr) {
         currentNode = currentNode->getNext();
      }
      return currentNode->getData();

   } else {
      for (int i = 0; i < index; i++) {
         currentNode = currentNode->getNext();
      }

      return currentNode->getData();
   }
}

template <typename T>
int LinkedList<T>::getLength() {
   return length;
}
