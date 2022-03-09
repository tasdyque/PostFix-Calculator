#include "StackArray.h"

/// <summary>
/// StackArray default constructor
/// 
/// precondition: stack is uninitialized
/// postcondition: stack is initialized with a max size, identifier for top of the stack
/// </summary>
/// <typeparam name="DataType"></typeparam>
template <typename DataType>
StackArray<DataType>::StackArray()
{
	this->maxSize = Stack<DataType>::MAX_STACK_SIZE;
	this->top = 0;
	this->isEmptyHelper = true;
	this->dataItems = new DataType[maxSize];
}

/// <summary>
/// StackArray copy constructor
/// 
/// precondition: stack is uninitialised
/// postcondition: stack is initialized by copying the data from the other node
/// </summary>
/// <typeparam name="DataType"></typeparam>
/// <param name="other"></param>
template <typename DataType>
StackArray<DataType>::StackArray(const StackArray& other)
{
	dataItems = new DataType[maxSize];

	for (int i = 0; i < maxSize; i++)
	{
		this->dataItems[i] = other->dataItems[i];
	}
}

/// <summary>
/// = operator overload
/// 
/// precondition: stack data is unequal to the other stack
/// postcondition: the stacks are euqal
/// </summary>
/// <typeparam name="DataType"></typeparam>
/// <param name="other"></param>
/// <returns></returns>
template <typename DataType>
StackArray<DataType>& StackArray<DataType>::operator=(const StackArray<DataType>& other)
{
	for (int i = 0; i < maxSize; i++)
	{
		this->dataItems[i] = other->dataItems[i];
	}
}

/// <summary>
/// StackArray destructor
/// 
/// precondition: the stack contains data
/// postcondition: the stack is empty
/// </summary>
/// <typeparam name="DataType"></typeparam>
template <typename DataType>
StackArray<DataType>::~StackArray()
{
	delete[] dataItems;
}

/// <summary>
/// Pushes/Inserts data onto the stack, increments the top index
/// If the stack is full, throws an error
/// 
/// precondition: there is data to be entered into the stack
/// postcondition: data is entered at the top of the stack or throws an error for a full stack
/// </summary>
/// <typeparam name="DataType"></typeparam>
/// <param name="newDataItem"></param>
template <typename DataType>
void StackArray<DataType>::push(const DataType& newDataItem) throw (logic_error)
{
	if (isFull())
	{
		throw logic_error("Full stack");
	}
	else if (isEmptyHelper == true)
	{
		dataItems[top] = newDataItem;
		isEmptyHelper = false;
	}
	else
	{
		top = top + 1;
		dataItems[top] = newDataItem;
	}
	
	
}

/// <summary>
/// Pops/Deletes data off the top of the stack, decrements the top index
/// If the stack is empty, throws an error
/// 
/// precondition: unwanted data is at the top of the stack
/// postcondition: the data item is deleted from the stack or throws an error for an empty stack
/// </summary>
/// <typeparam name="DataType"></typeparam>
template <typename DataType>
DataType StackArray<DataType>::pop() throw (logic_error)
{
	if (isEmpty())
	{
		throw logic_error("stack is empty");
	}
	else
	{
		top = top - 1;
		return dataItems[top + 1];
	}
	
}

/// <summary>
/// Clears all the data thats in the stack
/// 
/// precondition: Stack contains data
/// postcondition: Stack is empty
/// </summary>
/// <typeparam name="DataType"></typeparam>
template <typename DataType>
void StackArray<DataType>::clear()
{
	delete[] dataItems;
}

/// <summary>
/// Checks if the stack is empty
/// returns true if the stack is empty, or false if the stack isnt empty
/// 
/// precondition: stack object exists
/// postcondition: returns true/false if the stack is empty/contains data
/// </summary>
/// <typeparam name="DataType"></typeparam>
template <typename DataType>
bool StackArray<DataType>::isEmpty() const
{
	if (isEmptyHelper == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/// <summary>
/// Checks if the stack is full
/// returns true if the stack is full and false if the stack isn't full
/// 
/// precondition: stack object exists
/// postcondition: returns true/false if the stack is full/not full
/// </summary>
/// <typeparam name="DataType"></typeparam>
template <typename DataType>
bool StackArray<DataType>::isFull() const
{
	if (top == maxSize)
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
/// precondition: stack object exists
/// postcondition: Stack contents are outputted in order from bottom to the top of the stack or
///					outputs "Empty Stack"
/// </summary>
/// <typeparam name="DataType"></typeparam>
template <typename DataType>
void StackArray<DataType>::showStructure() const
{
	if (isEmpty())
	{
		cout << "Empty stack." << endl;
	}
	else 
	{
		int j;
		cout << "Top = " << top << endl;
		for (j = 0; j < maxSize; j++)
			cout << j << "\t";
		cout << endl;
		for (j = 0; j <= top; j++)
		{
			if (j == top)
			{
				cout << '[' << dataItems[j] << ']' << "\t"; // Identify top
			}
			else
			{
				cout << dataItems[j] << "\t";
			}
		}
		cout << endl;
	}
	cout << endl;
}

