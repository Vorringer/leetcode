#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	void reorderList(ListNode* head) {
		ListNode* init = head;
		reorder(head, init);
	}
private:
	void reorder(ListNode* head,ListNode* init) {
		if (head == NULL) return;
		reorder(head->next,init->next);
		if (head->next != NULL) head->next = NULL;
		if (init->next == NULL) return;
		head->next = init->next;
		init->next = head;
		init = head->next;
	}
};
int main()
{
	ListNode* test = new ListNode(1);
	ListNode* test2 = new ListNode(2);
	ListNode* test3 = new ListNode(3);
	test->next = test2;
	test2->next = test3;
	Solution solve;
	solve.reorderList(test);
	while (test != NULL)
	{
		cout << test->val << " ";
		test = test->next;
	}
	system("pause");
}