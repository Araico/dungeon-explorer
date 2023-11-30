#include "Node.h"
#include <iostream>
#include "../../classes/Dungeon.h"
#include "../../classes/Monster.h"
#include "../../classes/Spell.h"

using namespace std;

/**
 * @brief Constructor for the Node class.
 *
 * @param data The data to store in the node.
 * @param prevNodePtr Pointer to the previous node.
 * @param nextNodePtr Pointer to the next node.
 */
template <typename T>
inline Node<T>::Node(T data, Node<T>* prevNodePtr, Node<T>* nextNodePtr) {
   this->data = data;
   setPrevNodePtr(prevNodePtr);
   setNextNodePtr(nextNodePtr);
}

/**
 * @brief Get a pointer to the next node.
 *
 * @return A pointer to the next node.
 */
template <typename T>
Node<T>* Node<T>::getNextNodePtr() {
   return nextNodePtr;
}

/**
 * @brief Get a pointer to the previous node.
 *
 * @return A pointer to the previous node.
 */
template <typename T>
Node<T>* Node<T>::getPrevNodePtr() {
   return prevNodePtr;
}

/**
 * @brief Get the data stored in the node.
 *
 * @return A reference to the data.
 */
template <typename T>
T& Node<T>::getData() {
   return data;
}

/**
 * @brief Set the pointer to the next node.
 *
 * @param nextNode Pointer to the next node.
 */
template <typename T>
void Node<T>::setNextNodePtr(Node<T>* nextNode) {
   nextNodePtr = nextNode;
}

/**
 * @brief Set the pointer to the previous node.
 *
 * @param prevNode Pointer to the previous node.
 */
template <typename T>
void Node<T>::setPrevNodePtr(Node<T>* prevNode) {
   prevNodePtr = prevNode;
}

/**
 * @brief Set the data in the node.
 *
 * @param data The new data to store in the node.
 */
template <typename T>
void Node<T>::setData(T data) {
   this->data = data;
}

// Explicit instantiation for the int type
template class Node<int>;
template class Node<Monster>;
template class Node<Dungeon>;
template class Node<Spell>;
