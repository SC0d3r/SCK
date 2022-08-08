#include <iostream>
#include <vector>
#include <stack>
#include <string>

class Solution
{
public:
	bool isValid(std::string &s)
	{
		// method 1:
		// runtime: 0ms faster than 100% of submissions

		if (s.size() == 0)
			return true;

		if (s.size() == 1)
			return false;

		// [, ], {, }, (, )
		std::stack<char> stack;
		for (const auto c : s)
		{
			if (stack.empty())
			{
				stack.push(c);
				continue;
			}

			const auto x = stack.top();
			if (c == ')')
			{
				if (x != '(')
					return false;
				else
					stack.pop();
				continue;
			}
			if (c == ']')
			{
				if (x != '[')
					return false;
				else
					stack.pop();
				continue;
			}
			if (c == '}')
			{
				if (x != '{')
					return false;
				else
					stack.pop();
				continue;
			}

			stack.push(c);
		}

		return stack.empty();
	}
};

int main()
{
	Solution s;
	const auto res = s.isValid("((");
	std::cout << "Is valid? " << (res ? "True" : "False") << std::endl;
	return 0;
}