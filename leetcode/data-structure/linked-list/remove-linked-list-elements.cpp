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
	inline ListNode *removeElements(ListNode *head, int val)
	{
		if (!head)
			return head;
		if (!head->next && head->val == val)
			return nullptr;

		// method 1:
		// runtime: 24ms faster than 91% of submissions

		ListNode *prev = nullptr;
		ListNode *p = head;
		while (p)
		{
			if (p->val == val)
			{
				if (!prev)
				{
					if (!head)
						break;
					head = head->next;
				}
				else
				{
					prev->next = p->next;
				}

				ListNode *toBeDeleted = p;
				p = p->next;
				delete toBeDeleted;
				continue;
			}

			prev = p;
			p = p->next;
		}

		return head;
	}
};

int main()
{
	Solution s;

	ListNode *root1 = new ListNode(1);
	// root1->next = new ListNode(5);
	// root1->next->next = new ListNode(4);

	ListNode *root2 = new ListNode(1);
	root2->next = new ListNode(2);
	root2->next->next = new ListNode(2);
	root2->next->next->next = new ListNode(1);
	// root2->next->next->next->next = new ListNode(4);
	// root2->next->next->next->next->next = new ListNode(5);
	// root2->next->next->next->next->next->next = new ListNode(6);

	const auto res = s.removeElements(root2, 2);

	// printing
	auto n = res;
	while (n)
	{
		std::cout << n->val << ", ";
		n = n->next;
	}
	std::cout << std::endl;

	return 0;
}