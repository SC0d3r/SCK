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
		// method1: O(N) time
		// runtime: 0ms

		// int size = 0;
		// auto cur = head;
		// while (cur != nullptr)
		// {
		// 	cur = cur->next;
		// 	size++;
		// }

		// int mid = std::ceil(size / 2);

		// int i;
		// cur = head;
		// for (i = 0; i < mid; i++)
		// {
		// 	cur = cur->next;
		// }
		// return cur;

		// method 2: O(N) using two-pointers
		// runtime: 2ms at best this uses way less memory

		ListNode *pFaster = head;
		ListNode *pSlower = head;
		while (pFaster != nullptr)
		{
			// two steps at a time
			pFaster = pFaster->next;
			if (pFaster == nullptr)
			{
				break;
			}
			pFaster = pFaster->next;

			// one step at at a time
			pSlower = pSlower->next;
		}
		// when the faster pointer reaches the end
		// the slower pointer reaches the center
		return pSlower;
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