#include <iostream>
#include <vector>
#include <string>

// Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
	inline int getDecimalValue(ListNode *head)
	{
		// method 1:
		// runtime : 0ms

		// std::string res;
		// auto p = head;
		// while (p)
		// {
		// 	res += std::to_string(p->val);
		// 	p = p->next;
		// }

		// return std::stoi(res, nullptr, 2);

		// method 2:
		// runtime: 0ms

		int res = 0;
		auto p = head;
		while (p)
		{
			res = res * 2 + p->val;
			p = p->next;
		}
		return res;
	}
};

int main()
{
	ListNode *head = new ListNode(1);
	head->next = new ListNode(0);
	head->next->next = new ListNode(1);
	Solution s;
	std::cout << "ans: " << s.getDecimalValue(head) << std::endl;
	return 0;
}