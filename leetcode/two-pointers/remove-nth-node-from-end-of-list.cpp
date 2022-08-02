#include <iostream>
#include <vector>

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
	inline ListNode *removeNthFromEnd(ListNode *head, int n)
	{
		// method 1:
		// runtime: 3ms at best run
		int size = 0;
		auto p = head;
		while (p != nullptr)
		{
			p = p->next;
			size++;
		}

		if (size == n)
		{
			// removing the first element (aka head)
			auto node = head->next;
			delete head;
			return node;
		}

		const int x = size - n - 1;
		p = head;
		for (int i = 0; i < x; i++)
		{
			p = p->next;
		}

		// delete
		auto node = p->next;
		if (node == nullptr)
		{
			head = nullptr;
		}
		else
		{
			p->next = node->next;
			delete node;
		}

		return head;
	}
};

int main()
{
	// ListNode *d = new ListNode(5);
	// ListNode *c = new ListNode(4, d);
	// ListNode *b = new ListNode(3, c);
	ListNode *a = new ListNode(2);
	ListNode *head = new ListNode(1, a);

	Solution s;
	auto resHead = s.removeNthFromEnd(head, 2);
	ListNode *cur = resHead;

	while (cur != nullptr)
	{
		std::cout << cur->val << std::endl;
		cur = cur->next;
	}

	return 0;
}