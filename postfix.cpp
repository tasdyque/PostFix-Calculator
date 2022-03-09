///--------------------------------------------------------------------
///
/// postfix.cpp
///  Version 1.1
///  Date written: 10/30/20
///  Date last modified: 11/1/20
///  Authors: Tasdyque Syed
///  
///  Program function: performs postfix arithmetic by taking a postfix equation
///						as input from the user then outputs the stack data during each step   
///						and the calculated result
///  Input Files: none
///  Output Files: none
///  cpp files: StackArray.cpp
///--------------------------------------------------------------------
#include <cstdlib>
#include <string>
#include <iostream>
#include "StackArray.cpp"

using namespace std;

/// <summary>
/// function that computes the result of a postfix mathmatical expression
/// </summary>
/// <typeparam name="DataType"></typeparam>
/// <param name="stackArr"></param>
/// <param name="str"></param>
template <typename DataType>
void postfix(Stack<DataType>& stackArr, string str)
{
	/// <summary>
	/// operand 1
	/// </summary>
	/// <typeparam name="DataType"></typeparam>
	/// <param name="stackArr"></param>
	/// <param name="str"></param>
	double op1;

	/// <summary>
	/// operand 2
	/// </summary>
	/// <typeparam name="DataType"></typeparam>
	/// <param name="stackArr"></param>
	/// <param name="str"></param>
	double op2;

	/// <summary>
	/// result of operation
	/// </summary>
	/// <typeparam name="DataType"></typeparam>
	/// <param name="stackArr"></param>
	/// <param name="str"></param>
	double res;

	/// <summary>
	/// for loop loops through the string character by character
	/// </summary>
	/// <typeparam name="DataType"></typeparam>
	/// <param name="stackArr"></param>
	/// <param name="str"></param>
	for (int i = 0; i < str.size(); i++)
	{
		/// <summary>
		/// checks if the character is a digit, and then pushes it after explicity casting it to 
		/// double and then subtracting 48 to set it to a 0-9 range
		/// </summary>
		/// <typeparam name="DataType"></typeparam>
		/// <param name="stackArr"></param>
		/// <param name="str"></param>
		if (isdigit(str[i]))
		{
			stackArr.push(double(str[i]) - 48);
			stackArr.showStructure();
		}
		/// <summary>
		/// checks if character is the addition operator, proceeds to pops both operands, and then
		///  add them to the result variable. Then pushes the result the stack and output the stack
		/// </summary>
		/// <typeparam name="DataType"></typeparam>
		/// <param name="stackArr"></param>
		/// <param name="str"></param>
		else if (str[i] == '+')
		{
			op1 = stackArr.pop();
			op2 = stackArr.pop();
			res = op1 + op2;
			stackArr.push(res);
			stackArr.showStructure();

		}
		/// <summary>
		/// checks if character is the subtraction operator, proceeds to pops both operands, and then
		///  subtract them to the result variable. Then pushes the result the stack and output the stack
		/// </summary>
		/// <typeparam name="DataType"></typeparam>
		/// <param name="stackArr"></param>
		/// <param name="str"></param>
		else if (str[i] == '-')
		{
			op1 = stackArr.pop();
			op2 = stackArr.pop();
			res = op1 - op2;
			stackArr.push(res);
			stackArr.showStructure();

		}
		/// <summary>
		/// checks if character is the multiplication operator, proceeds to pops both operands, and then
		///  multiplies them to the result variable. Then pushes the result the stack and output the stack
		/// </summary>
		/// <typeparam name="DataType"></typeparam>
		/// <param name="stackArr"></param>
		/// <param name="str"></param>
		else if (str[i] == '*')
		{
			op1 = stackArr.pop();
			op2 = stackArr.pop();
			res = op1 * op2;
			stackArr.push(res);
			stackArr.showStructure();
		}
		/// <summary>
		/// checks if character is the division operator, proceeds to pops both operands, and then
		/// divides them to the result variable. Then pushes the result the stack and output the stack
		/// </summary>
		/// <typeparam name="DataType"></typeparam>
		/// <param name="stackArr"></param>
		/// <param name="str"></param>
		else if (str[i] == '/')
		{
			op1 = stackArr.pop();
			op2 = stackArr.pop();
			res = op2 / op1;
			stackArr.push(res);
			stackArr.showStructure();
		}
	}
	/// <summary>
	/// outputs the result of the expression
	/// </summary>
	/// <typeparam name="DataType"></typeparam>
	/// <param name="stackArr"></param>
	/// <param name="str"></param>
	cout << "Result is: " << stackArr.pop() << endl;
}


int main()
{
	/// <summary>
	/// variable that holds the mathmatical expression
	/// </summary>
	/// <returns></returns>
	string exp = "";
	/// <summary>
	/// postfix stack array
	/// </summary>
	/// <returns></returns>
	StackArray<double> stackArray;

	cout << "Enter a mathmatical expression: ";
	cin >> exp;
	postfix(stackArray, exp);

}