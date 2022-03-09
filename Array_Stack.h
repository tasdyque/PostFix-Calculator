//--------------------------------------------------------------------
//
//  StackLinked.h
// 
//  Class declaration for the linked implementation of the Stack ADT
//
//--------------------------------------------------------------------

#ifndef STACKARRAY_H
#define STACKARRAY_H

#include <stdexcept>
#include <iostream>

using namespace std;

#include "Stack.h"

/// <summary>
/// Array implementation for the stack
/// </summary>
/// <typeparam name="DataType"></typeparam>
template <typename DataType>
class StackArray : public Stack<DataType> 
{
  public:

    /// <summary>
    /// default constructor for the stack
    /// </summary>
    StackArray();

    /// <summary>
    /// paramaterized constructor for the stack, sets members equal to the other stack
    /// </summary>
    /// <param name="other"></param>
    StackArray(const StackArray& other);

    /// <summary>
    /// assignment operator overload sets values equal to another stack
    /// </summary>
    /// <param name="other"></param>
    /// <returns></returns>
    StackArray& operator=(const StackArray& other);

    ///destrctor for the stack array
    ~StackArray();

    /// <summary>
    /// push function for the stack, inserts value at the top
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
    /// clear function deallocates the dynamic array
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
    /// stores max size for the array
    /// </summary>
    int maxSize;
    /// <summary>
    /// stores top index of the array
    /// </summary>
    int top;

    /// <summary>
    /// helper to the isempty function
    /// </summary>
    bool isEmptyHelper;

    /// <summary>
    /// pointer to the array
    /// </summary>
    DataType* dataItems;
};

#endif		//#ifndef STACKARRAY_H
