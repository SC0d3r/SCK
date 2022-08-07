#include <iostream>
#include <vector>

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
	inline ListNode *reverseList(ListNode *head)
	{
		if (!head)
			return head;
		if (!head->next)
			return head;

		recur(head);
		return last;
	}

private:
	inline ListNode *recur(ListNode *n)
	{
		if (!n->next)
		{
			if (!last)
			{
				last = n;
			}
			return n;
		}

		ListNode *prev = n;
		ListNode *next = recur(n->next);

		prev->next = nullptr;
		next->next = prev;
		return prev;
	}
	ListNode *last = nullptr;
};

int main()
{
	ListNode *root = new ListNode(1);
	root->next = new ListNode(2);
	root->next->next = new ListNode(3);
	Solution s;

	root = s.reverseList(root);

	// printing
	ListNode *n = root;
	while (n)
	{
		std::cout << n->val << ", ";
		n = n->next;
	}
	std::cout << std::endl;
	return 0;
}