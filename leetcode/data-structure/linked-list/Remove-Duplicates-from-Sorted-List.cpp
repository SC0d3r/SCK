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
	inline ListNode *deleteDuplicates(ListNode *head)
	{
		if (!head)
			return head;
		if (!head->next)
			return head;

		ListNode *pNext = head->next;
		ListNode *pCur = head;
		while (pCur && pNext)
		{
			if (pCur->val == pNext->val)
			{
				ListNode *del = pNext;
				pNext = pNext->next;
				delete del;

				if (!pNext)
				{ // this means reached the end
					pCur->next = nullptr;
				}
				continue;
			}
			if (pCur != pNext)
			{
				pCur->next = pNext;
			}

			pCur = pNext;
			pNext = pNext->next;
		}

		return head;
	}
};

int main()
{
	ListNode *root = new ListNode(1);
	root->next = new ListNode(1);
	root->next->next = new ListNode(2);
	// root->next->next->next = new ListNode(2);
	// root->next->next->next->next = new ListNode(3);
	Solution s;
	auto res = s.deleteDuplicates(root);

	// printing
	while (res)
	{
		std::cout << res->val << ", ";
		res = res->next;
	}
	std::cout << std::endl;
	return 0;
}