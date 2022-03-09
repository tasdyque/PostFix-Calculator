//--------------------------------------------------------------------
//
//  StackArray.h
// 
//  Class declaration for the array implementation of the Stack ADT
//
//--------------------------------------------------------------------

#ifndef STACKARRAY_H
#define STACKARRAY_H

#include <stdexcept>
#include <iostream>

using namespace std;

#include "Stack.h"

/// <summary>
/// Linked-list implementation for the stack
/// </summary>
/// <typeparam name="DataType"></typeparam>
template <typename DataType>
class StackLinked : public Stack<DataType> 
{

  public:

      /// <summary>
  /// default constructor for the stack
  /// </summary>
    StackLinked();

    /// <summary>
    /// paramaterized constructor for the stack, sets members equal to the other stack
    /// </summary>
    /// <param name="other"></param>
    StackLinked(const StackLinked& other);

    /// <summary>
   /// assignment operator overload sets values equal to another stack
   /// </summary>
   /// <param name="other"></param>
   /// <returns></returns>
    StackLinked& operator=(const StackLinked& other);

    ///destrctor for the stack linked list nodes
    ~StackLinked();

    /// <summary>
    /// push function for the stack, inserts value at the top node
    /// </summary>
    /// <param name="newDataItem"></param>
    /// <returns></returns>
    void push(const DataType& newDataItem) throw (logic_error);

    /// <summary>
    /// pop function pops most recent item, item at top of stack
    /// </summary>
    /// <returns></returns>
    DataType pop() throw (logic_error);

    /// <summary>
    /// clear function deallocates the nodes
    /// </summary>
    void clear();

    /// <summary>
    /// function checks if stack is empty
    /// </summary>
    /// <returns></returns>
    bool isEmpty() const;

    /// <summary>
   /// function checks if stack is full
   /// </summary>
   /// <returns></returns>
    bool isFull() const;

    /// <summary>
    /// function outputs the stack
    /// </summary>
    void showStructure() const;

  private:

    /// <summary>
    /// inner class facilitates the stack, individual nodes 
    /// </summary>
    class StackNode 
    {
      public:
	    /// <summary>
	    /// parameterized constructor
	    /// </summary>
	    /// <param name="nodeData"></param>
	    /// <param name="nextPtr"></param>
	    StackNode(const DataType& nodeData, StackNode* nextPtr);

	    /// <summary>
	    /// dataitem stored in the node
	    /// </summary>
	    DataType dataItem;

	    /// <summary>
	    /// pointer to next noded
	    /// </summary>
	    StackNode* next;
    };

    /// <summary>
    /// recursive helper to the destructor
    /// </summary>
    /// <param name="currentNode"></param>
    void destructorHelper(StackNode* currentNode);

    /// <summary>
    /// recursive helper to the isFull function
    /// </summary>
    /// <param name="currentNode"></param>
    /// <returns></returns>
    int isFullHelper(StackNode* currentNode) const;

    /// <summary>
    /// pointer to the top node
    /// </summary>
    StackNode* top;
};

#endif		//#ifndef STACKARRAY_H

