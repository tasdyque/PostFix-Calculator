#include "StackLinked.h"


/// <summary>
/// StackNode constructor that creates a data node to be entered into the Stack and a pointer for the next link
/// </summary>
/// 
/// precondition: new data and a link is ready to be appended to the list
/// postcondition: a StackNode is initialized with the data and pointer
/// <typeparam name="DataType"></typeparam>
/// <param name="nodeData"></param>
/// <param name="nextPtr"></param>
template <typename DataType>
StackLinked<DataType>::StackNode::StackNode(const DataType& nodeData, StackNode* nextPtr)
{
	dataItem = nodeData;
	next = nextPtr;
}

/// <summary>
/// Constructor for a linked list based Stack
/// </summary>
/// 
/// precondition: stack is uninitialized
/// postcondition: stack is initialized 
/// <typeparam name="DataType"></typeparam>
template <typename DataType>
StackLinked<DataType>::StackLinked()
{
	top = NULL;
}

/// <summary>
/// StackLinked copy constructor that copies data from another stack
/// </summary>
/// 
/// precondition: stack is uninitialized
/// postcondition: stack is initialized with data from the other stack
/// <typeparam name="DataType"></typeparam>
template <typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked& other)
{
	this->top = other.top;
}

/// <summary>
/// assignment operator overload
/// </summary>
/// 
/// precondition: the two stacks are different
/// postcondition: the stacks have the same data, which is the other stack data
/// <typeparam name="DataType"></typeparam>
/// <param name="other"></param>
template <typename DataType>
StackLinked<DataType>& StackLinked<DataType>::operator=(const StackLinked& other)
{
	this->top = other.top;
}

/// <summary>
/// Recursive function that is called by the destructor to delete every node in the stack
/// </summary>
/// 
/// precondition: the stack object contains data
/// postcondition: the stack object is empty
/// <typeparam name="DataType"></typeparam>
/// <param name="curerntNode"></param>
template <typename DataType>
void StackLinked<DataType>::destructorHelper(StackNode* currentNode)
{
	if (currentNode != NULL)
	{
		destructorHelper(currentNode->next);
		delete currentNode;
	}
}

/// <summary>
/// StackLinked destructor that calls the destructorHelper member function
/// </summary>
/// 
/// precondition: the stack object contains data
/// postcondition: the stack object is empty
/// <typeparam name="DataType"></typeparam>
template <typename DataType>
StackLinked<DataType>::~StackLinked()
{
	destructorHelper(top);
}

/// <summary>
/// The push function enters a dataNode at the top of the stack or returns an error if the stack is full
/// </summary>
/// 
/// precondition: stack object has been initialized
/// postcondition: stack object has the new dataNode pushed onto the stack or returns an error
/// <typeparam name="DataType"></typeparam>
/// <param name="newDataItem"></param>
template <typename DataType>
void StackLinked<DataType>::push(const DataType& newDataItem) throw (logic_error)
{
	if (isFull())
	{
		throw logic_error("stack is full");
	}
	else if (top == NULL)
	{
		top = new StackNode(newDataItem, top);
	}
	else
	{
		StackNode* tempNode = new StackNode(newDataItem, top);
		top = tempNode;
	}
}

/// <summary>
/// The pop function deletes the dataNode at the top of the stack or return an error if the stack is empty
/// </summary>
/// 
/// precondition: stack object contains data
/// postcondition: the dataNode at the top of the stack is deleted and adjusts the top pointer or throws an error message
/// <typeparam name="DataType"></typeparam>
/// <param name="nedwDataItem"></param>
template <typename DataType>
DataType StackLinked<DataType>::pop() throw (logic_error)
{
	if (top == 0)
	{
		throw logic_error("stack is empty");
	}
	else
	{
		DataType tempData;
		StackNode* tempNode;
		tempNode = top;
		tempData = tempNode->dataItem;
		top = top->next;
		delete tempNode;
		return tempData;
	}
}

/// <summary>
/// The clear function deletes all the data in a stack by calling the recursive destructorHelper member function
/// </summary>
/// 
/// precondition: stack object contains data
/// postcondition: the stack is empty and top points to NULL
/// <typeparam name="DataType"></typeparam>
template <typename DataType>
void StackLinked<DataType>::clear()
{
	destructorHelper(top);
	top = NULL;
}

/// <summary>
/// the isEmpty function returns true if the stack is empty/top points to NULL or returns false if the stack contains data
/// </summary>
/// 
/// precondition: stack object has been initialized
/// postcondition: returns true if the stack is empty, otherwise returns false
/// <typeparam name="DataType"></typeparam>
template <typename DataType>
bool StackLinked<DataType>::isEmpty() const
{
	if (top == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/// <summary>
/// the isFullHelper function is a recursive function that returns true if the stack is full or false if its not full
/// </summary>
/// 
/// precondition: stack object contains data
/// postcondition: returns true if the stack is full, otherwise returns false
/// <typeparam name="DataType"></typeparam>
/// <param name="currentNode"></param>
template <typename DataType>
int StackLinked<DataType>::isFullHelper(StackNode* currentNode) const
{
	if (currentNode != NULL)
	{
		return isFullHelper(currentNode->next) + 1;
	}
	else
	{
		return 0;
	}
}

/// <summary>
/// the isFull function calls the recursive isFullHelper to determine if the stack is full or not
/// </summary>
/// 
/// precondition: stack object contains data
/// postcondition: returns true if the stack is full, otherwise returns false
/// <typeparam name="DataType"></typeparam>
template <typename DataType>
bool StackLinked<DataType>::isFull() const
{
	
	if (isFullHelper(top) == Stack<DataType>::MAX_STACK_SIZE)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/// <summary>
/// Outputs the contents of the stack from the bottom to the top of the stack
/// or it outputs "empty stack" if the stack is empty
///
/// precondition: stack object has been initialized
/// postcondition: Stack contents are outputted in order from bottom to top or outputs "Empty Stack"
/// </summary>
/// <typeparam name="DataType"></typeparam>
template <typename DataType>
void StackLinked<DataType>::showStructure() const 
{
    if( isEmpty() )
    {
	cout << "Empty stack" << endl;
    }
    else
    {
        cout << "Top\t";
	for (StackNode* temp = top; temp != 0; temp = temp->next) {
	    if( temp == top ) {
		cout << "[" << temp->dataItem << "]\t";
	    }
	    else {
		cout << temp->dataItem << "\t";
	    }
	}
        cout << "Bottom" << endl;
    }

}
