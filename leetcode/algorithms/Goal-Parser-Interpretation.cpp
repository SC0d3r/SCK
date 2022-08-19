#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
	inline std::string interpret(std::string &command)
	{
		std::string res;
		while (p < command.size())
			res += consume(command);
		return res;
	}

private:
	int p = 0;
	inline std::string consume(std::string &cmd)
	{
		const auto x = cmd[p];
		if (x == 'G')
		{
			p++;
			return "G";
		}
		if (x == '(' && cmd[p + 1] == 'a')
		{
			p += 4;
			return "al";
		}
		p += 2;
		return "o";
	}
};

int main()
{
	std::string cmd = "G()(al)";
	Solution s;
	std::cout << "ans: " << s.interpret(cmd) << std::endl;
	return 0;
}