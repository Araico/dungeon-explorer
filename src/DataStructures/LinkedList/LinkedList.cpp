#include "LinkedList.h"
#include <stdexcept>
#include "../../classes/Dungeon.h"
#include "../../classes/Monster.h"
#include "../../classes/Spell.h"
using namespace std;

/**
 * @brief Constructor for the LinkedList class.
 */
template <typename T>
LinkedList<T>::LinkedList() {}

/**
 * @brief Get a pointer to the first node.
 * @return A pointer to the first node.
 */
template <typename T>
Node<T>* LinkedList<T>::getFirstNodePtr() {
   return firstNodePtr;
}

/**
 * @brief Get a pointer to the last node.
 * @return A pointer to the last node.
 */
template <typename T>
Node<T>* LinkedList<T>::getLastNodePtr() {
   return lastNodePtr;
}

/**
 * @brief Set the pointer to the first node.
 * @param nodePtr Pointer to the first node.
 */
template <typename T>
void LinkedList<T>::setFirstNodePtr(Node<T>* nodePtr) {
   firstNodePtr = nodePtr;
}

/**
 * @brief Set the pointer to the last node.
 * @param nodePtr Pointer to the last node.
 */
template <typename T>
void LinkedList<T>::setLastNodePtr(Node<T>* nodePtr) {
   lastNodePtr = nodePtr;
}

/**
 * @brief Get the length of the linked list.
 * @return The length of the linked list.
 */
template <typename T>
int LinkedList<T>::getLength() {
   return length;
}

/**
 * @brief Get the element located at the given index.
 * Use [-1] for the last element.
 * @param index The index of the element to retrieve.
 * @return The element at the specified index.
 * @throws runtime_error if the index is out of range.
 */
template <typename T>
inline T& LinkedList<T>::operator[](int index) {
   if (index > (length - 1) || (index == -1 && firstNodePtr == nullptr))
      throw runtime_error("List index is out of range");

   if (index == -1) {
      return getLastNodePtr()->getData();
   } else {
      Node<T>* tempNode = firstNodePtr;
      for (int i = 0; i < index; i++) {
         tempNode = tempNode->getNextNodePtr();
      }
      return tempNode->getData();
   }
}

/**
 * @brief Insert an element at the given index.
 * [0] inserts at the start, [-1] inserts at the end.
 * @param element The element to insert.
 * @param index The index to insert the element at.
 * @throws runtime_error if the index is out of range.
 */
template <typename T>
void LinkedList<T>::insert(const T& element, int index) {
   if (firstNodePtr == nullptr) {
      firstNodePtr = new Node<T>(element);
      lastNodePtr = firstNodePtr;
      length++;
      return;
   }

   if (index == -1) {
      Node<T>* tempNode = firstNodePtr;
      while (tempNode->getNextNodePtr() != nullptr) {
         tempNode = tempNode->getNextNodePtr();
      }
      tempNode->setNextNodePtr(new Node<T>(element, tempNode));
      lastNodePtr = tempNode->getNextNodePtr();
      length++;
   } else if (index == 0) {
      firstNodePtr = new Node<T>(element, nullptr, firstNodePtr);
      length++;
   } else if (index < (length)) {
      Node<T>* tempNode = firstNodePtr;
      for (int i = 1; i < index; i++) {
         tempNode = tempNode->getNextNodePtr();
      }
      tempNode->setNextNodePtr(new Node<T>(element, tempNode->getPrevNodePtr(),
                                           tempNode->getNextNodePtr()));
   } else {
      throw runtime_error("List index is out of range");
   }
}

/**
 * @brief Removes an element from the linked list at the specified index.
 * @param index The index of the element to be removed. Use -1 to remove the
 * last element.
 * @throw runtime_error If the list is empty or the index is out of range.
 */
template <typename T>
void LinkedList<T>::remove(int index) {
   if (length == 0) {
      throw runtime_error("Cant remove from an empty list");
      return;
   }

   if (index == -1) {
      Node<T>* tempNode = lastNodePtr;
      lastNodePtr = lastNodePtr->getPrevNodePtr();
      lastNodePtr->setNextNodePtr(nullptr);
      delete tempNode;

      length--;
   } else if (index == 0) {
      Node<T>* tempNode = firstNodePtr;
      firstNodePtr = firstNodePtr->getNextNodePtr();
      firstNodePtr->setPrevNodePtr(nullptr);
      delete tempNode;

      length--;
   } else if (index < (length)) {
      Node<T>* tempNode = firstNodePtr;
      for (int i = 0; i < index; i++) {
         tempNode = tempNode->getNextNodePtr();
      }
      tempNode->getPrevNodePtr()->setNextNodePtr(tempNode->getNextNodePtr());
      delete tempNode;

      length--;
   } else {
      throw runtime_error("List index is out of range");
   }
}

template <typename T>
void LinkedList<T>::sort() {
   for (int i = 0; i < length; i++) {
      for (int j = 0; j < length - j - 1; j++) {
         if ((*this)[j] > (*this)[j + 1]) {
            T temp = (*this)[j];
            (*this)[j] = (*this)[j + 1];
            (*this)[j + 1] = temp;
         }
      }
   }
}

/**
 * @brief Print the Linked List.
 */
template <typename T>
void LinkedList<T>::print() {
   cout << "[Linked list contents]\n";
   Node<T>* tempNode = firstNodePtr;
   int i = 0;
   while (tempNode != nullptr) {
      cout << "----[Index: " << i << "]----" << endl;
      // cout << tempNode->getData() << "\n\n";
      tempNode = tempNode->getNextNodePtr();
      i++;
   }
}

// Explicit instantiation for the int type
template class LinkedList<int>;
template class LinkedList<Monster>;
template class LinkedList<Dungeon>;
template class LinkedList<Spell>;
template class LinkedList<string>;
