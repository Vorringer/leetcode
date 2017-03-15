#include<iostream>
using namespace std;
struct ListNode {     
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* sortList(ListNode* head)
	{
		if (head == NULL) return NULL;
		ListNode* headtemp = head;
		while (headtemp->next != NULL) headtemp = headtemp->next;
		ListNode* tail = new ListNode(0);
		headtemp->next = tail;
		headtemp = head;
		quickSort(headtemp, tail);
		delete tail;
		return head;
	}
private:
	void quickSort(ListNode* head, ListNode* tail)
	{
		if (head == tail || head->next == tail) return;
		ListNode* nhead = new ListNode(0);
		int x = head->val;
		nhead->next = head;
		ListNode* cur = nhead;
		ListNode* xpos = cur->next;
		while (xpos->next != tail)
		{
			if (xpos->next->val<x)
			{
				ListNode* ntemp = xpos->next;
				xpos->next = ntemp->next;
				ntemp->next = cur->next;
				cur->next = ntemp;
				cur = cur->next;
			}
			else
			{
				xpos = xpos->next;
			}
		}
		ListNode* headnew = nhead->next;
		delete nhead;
		quickSort(headnew, cur->next);
		quickSort(cur->next, tail);
	}
};
int main()
{
	Solution solve;
	ListNode* t = new ListNode(3);
	ListNode* t2 = new ListNode(2);
	ListNode* t3 = new ListNode(1);
	t->next = t2;
	t2->next = t3;
	cout<<solve.sortList(t)->val;
	system("pause");
}