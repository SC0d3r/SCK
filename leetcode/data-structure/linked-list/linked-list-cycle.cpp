#include <iostream>
#include <vector>
#include <unordered_map>

//  Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	inline bool hasCycle(ListNode *head)
	{
		if (!head || !head->next)
			return false;

		// method 1:
		// runtime: 23ms a bit slow maybe?

		// auto n = head;
		// while (n->next)
		// {
		// 	m[n]++;
		// 	if (m[n] > 1)
		// 		return true;

		// 	n = n->next;
		// }

		// method 2: using two pointers
		// runtime: 7ms at the best run pretty fast

		ListNode *slow = head;
		ListNode *fast = head;
		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;

			if (slow == fast)
				return true;
		}

		return false;
	}

private:
	std::unordered_map<ListNode *, int> m;
};

int main()
{
	ListNode *root = new ListNode(1);
	root->next = new ListNode(2);
	root->next->next = new ListNode(3);
	root->next->next->next = new ListNode(4);
	// root->next->next->next->next = root->next;
	Solution s;
	std::cout << "has cycle? " << (s.hasCycle(root) ? "TRUE" : "FALSE") << std::endl;
	return 0;
}