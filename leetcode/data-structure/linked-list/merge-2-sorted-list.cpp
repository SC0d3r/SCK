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
	ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
	{

		if (!list1)
			return list2;
		if (!list2)
			return list1;

		// method 1:
		// runtime: 3ms at best run faster the 98% of the submissions

		// ListNode *prev = nullptr;
		// ListNode *p1 = list1;
		// ListNode *p2 = list2;

		// while (p2 && p1)
		// {
		// 	if (p1->val == p2->val)
		// 	{
		// 		const auto nextP1 = p1->next;
		// 		const auto nextP2 = p2->next;
		// 		p1->next = p2;
		// 		p2->next = nextP1;
		// 		p2 = nextP2;

		// 		prev = p1;
		// 		p1 = p1->next;
		// 		continue;
		// 	}

		// 	ListNode *prevP2 = nullptr;
		// 	const auto snapshot = p2;
		// 	auto didLoop = false;
		// 	while (p2 && p2->val <= p1->val)
		// 	{
		// 		didLoop = true;
		// 		prevP2 = p2;
		// 		p2 = p2->next;
		// 	}

		// 	if (didLoop)
		// 	{
		// 		if (!prev)
		// 		{
		// 			list1 = snapshot;
		// 			prevP2->next = p1;
		// 		}
		// 		else
		// 		{
		// 			prev->next = snapshot;
		// 			prevP2->next = p1;
		// 		}
		// 	}

		// 	if (!p2)
		// 	{
		// 		// this means that the p1 is bigger than whole the remaining items in list2
		// 		if (prev)
		// 		{
		// 			prev->next = snapshot;
		// 			prevP2->next = p1;
		// 		}
		// 		break;
		// 	}

		// 	if (p2->val < p1->val)
		// 	{
		// 		if (prev)
		// 		{
		// 			prev->next = p2;
		// 			const auto nextP2 = p2->next;
		// 			p2->next = p1;
		// 			p2 = nextP2;
		// 		}
		// 		else
		// 		{
		// 			const auto nextP2 = p2->next;
		// 			p2->next = p1;
		// 			list1 = p2;
		// 			p2 = nextP2;
		// 		}
		// 		continue;
		// 	}

		// 	// p2->val is greater than p1->val so it should come after
		// 	prev = p1;
		// 	p1 = p1->next;
		// }

		// if (p2)
		// {
		// 	prev->next = p2;
		// }

		// return list1;

		// method 2: using dummy node and 2 pointers
		// runtime: 4ms faster than the 94% of online submissions

		ListNode dummy;
		ListNode *lastNode = nullptr;
		ListNode *p1 = list1;
		ListNode *p2 = list2;

		while (p1 && p2)
		{
			if (p1->val <= p2->val)
			{
				if (!lastNode)
				{
					dummy.next = p1;
				}
				else
				{
					lastNode->next = p1;
				}
				lastNode = p1;
				p1 = p1->next;
			}
			else
			{
				if (!lastNode)
				{
					dummy.next = p2;
				}
				else
				{
					lastNode->next = p2;
				}
				lastNode = p2;
				p2 = p2->next;
			}
		}

		if (p1)
		{
			lastNode->next = p1;
		}
		if (p2)
		{
			lastNode->next = p2;
		}

		return dummy.next;
	}
};

int main()
{
	ListNode *root1 = new ListNode(1);
	// root1->next = new ListNode(5);
	// root1->next->next = new ListNode(4);

	ListNode *root2 = new ListNode(1);
	// root2->next = new ListNode(-6);
	// root2->next->next = new ListNode(-3);
	// root2->next->next->next = new ListNode(-1);
	// root2->next->next->next->next = new ListNode(1);
	// root2->next->next->next->next->next = new ListNode(6);

	Solution s;
	const auto res = s.mergeTwoLists(root1, root2);

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