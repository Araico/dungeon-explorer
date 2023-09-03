#pragma once

template <typename T>
class Node {
  private:
   T data;
   Node* next;

  public:
   Node(T data);
   Node(T data, Node* nextNode);
   Node<T>* getNext();
   T& getData();
   void setNext(Node* next);
   void setData(T data);
};

/// imple

template <typename T>
Node<T>::Node(T data) : data(data), next(nullptr) {}

template <typename T>
Node<T>::Node(T data, Node* nextNode) : data(data), next(nextNode) {}

template <typename T>
Node<T>* Node<T>::getNext() {
   return next;
}

template <typename T>
T& Node<T>::getData() {
   return data;
}

template <typename T>
void Node<T>::setNext(Node* next) {
   this->next = next;
}

template <typename T>
void Node<T>::setData(T data) {
   this->data = data;
}
