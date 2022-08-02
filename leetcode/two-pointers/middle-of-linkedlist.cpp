#include <iostream>
#include <cmath>

/**
 * Definition for singly-linked list.
 */
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
	inline ListNode *middleNode(ListNode *head)
	{
		int size = 0;
		auto cur = head;
		while (cur != nullptr)
		{
			cur = cur->next;
			size++;
		}

		int mid = std::ceil(size / 2);

		int i;
		cur = head;
		for (i = 0; i < mid; i++)
		{
			cur = cur->next;
		}
		return cur;
	}
};

int main()
{
	ListNode *d = new ListNode(5);
	ListNode *c = new ListNode(4, d);
	ListNode *b = new ListNode(3, c);
	ListNode *a = new ListNode(2, b);
	ListNode *head = new ListNode(1, a);

	Solution s;
	std::cout << s.middleNode(head)->val << "\n";
	return 0;
}