// Inheritance-OverridingMemberFunction.cpp : Defines the entry point for the console application.
//
/*
Overloading functions in base and derived class
*/

#include "stdafx.h"
#include <iostream>
#include <process.h> //for exit()

class Stack
{
protected:							// this can not be private
	static const int MAX = 3;		// size of the stack array
	int stack[MAX];					// stack array of integers
	int top;						// index to top of stack
public:
	Stack()							// Constructor
	{
		top = -1;
	}
	void push(int var)				// put number on stack
	{
		stack[++top] = var;
	}
	int pop()						// take number off stack
	{
		return stack[top--];
	}
};
class Stack2 : public Stack
{
public: 
	void push(int var)				// put number on stack
	{
		if (top >= MAX-1)			// error if stack is full
		{
			std::cout << "\nError: stack is full"; exit(1);
		}
		Stack::push(var);			// call push() in Stack class
	}
	int pop()						// take numner or stack
	{
		if (top < 0)				// error if stack empty
		{
			std::cout << "\nError: stack is empty"; exit(1);
		}
		return Stack::pop();		// call pop() in Stack class
	}
};

int main()
{
	Stack2 s1;

	s1.push(11);					// push some values onto stack
	s1.push(22);
	s1.push(33);

	std::cout << std::endl << s1.pop(); //pop some values from stack
	std::cout << std::endl << s1.pop();
	std::cout << std::endl << s1.pop();
	//std::cout << std::endl << s1.pop(); // this one was one too many

	system("pause");
    return 0;
}

