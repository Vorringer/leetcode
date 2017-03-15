#include<iostream>
using namespace std;
struct ListNode {
   int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode* result1 = new ListNode(0);
		ListNode* result = result1;
		int plus = 0;
		while (l1 != NULL || l2 != NULL)
		{
			if (l1 == NULL)
			{
				result->val += l2->val + plus;
				l2 = l2->next;
			}
			else if (l2 == NULL)
			{
				result->val += l1->val + plus;
				l1 = l1->next;
			}
			else
			{
				result->val += l1->val + l2->val + plus;
				l1 = l1->next;
				l2 = l2->next;
			}
			if (result->val >= 10)
			{
				plus = result->val / 10;
				result->val %= 10;
			}
			else plus = 0;
			if ((l1 != NULL || l2 != NULL) && result->next == NULL)
			{
				result->next = new ListNode(0);
				result = result->next;
			}
		}
		if (plus != 0) result->next = new ListNode(plus);
		return result1;
	}
};
int main()
{
	ListNode* n1 = new ListNode(2);
	ListNode* n2 = new ListNode(4);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(5);
	ListNode* n5 = new ListNode(6);
	ListNode* n6 = new ListNode(4);
	n1->next = n2;
	n2->next = n3;
	n4->next = n5;
	n5->next = n6;
	Solution solve;
	ListNode* result=solve.addTwoNumbers(n1, n4);
	while (result != NULL)
	{
		cout << result->val << " ";
		result = result->next;
	}
	system("pause");
}