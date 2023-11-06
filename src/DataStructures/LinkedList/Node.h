#pragma once

template <typename T>
class Node {
  private:
   T data;
   Node<T>* nextNodePtr;
   Node<T>* prevNodePtr;

  public:
   Node(T data, Node<T>* prevNodePtr = nullptr, Node<T>* nextNodePtr = nullptr);
   Node<T>* getNextNodePtr();
   Node<T>* getPrevNodePtr();
   T& getData();
   void setNextNodePtr(Node<T>* nextNode);
   void setPrevNodePtr(Node<T>* prevNode);
   void setData(T data);
};
