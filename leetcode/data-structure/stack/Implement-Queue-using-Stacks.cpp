#include <iostream>
#include <stack>
#include <vector>

class MyQueue
{
public:
	MyQueue()
	{
	}

	void push(int x)
	{
		if (stack.empty())
		{
			stack.push(x);
			return;
		}

		std::stack<int> tempStack;
		while (!stack.empty())
		{
			tempStack.push(stack.top());
			stack.pop();
		}
		stack.push(x);
		while (!tempStack.empty())
		{
			stack.push(tempStack.top());
			tempStack.pop();
		}
	}

	int pop()
	{
		auto res = stack.top();
		stack.pop();
		return res;
	}

	int peek()
	{
		return stack.top();
	}

	bool empty()
	{
		return stack.empty();
	}

private:
	std::stack<int> stack;
};

int main()
{
	MyQueue *obj = new MyQueue();
	obj->push(1);
	obj->push(2);
	obj->push(3);
	obj->push(4);
	int param_2 = obj->pop();
	int param_3 = obj->peek();
	bool param_4 = obj->empty();

	std::cout << "param2: " << param_2 << std::endl;
	std::cout << "param3: " << param_3 << std::endl;
	std::cout << "param4: " << param_4 << std::endl;
	return 0;
}