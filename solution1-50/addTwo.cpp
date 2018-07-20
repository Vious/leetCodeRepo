#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using std::vector;
using std::map;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *results;
		int uper = 0;
		results = new ListNode(0);
		results->val = l1->val + l2->val;
		if (results->val >= 10) {
			results->val -= 10;
			uper = 1;
		}
		ListNode *pt = results;
		ListNode *p1 = l1->next, *p2 = l2->next;
		while (p1 != NULL || p2 != NULL) {
			ListNode *ptNew = new ListNode(0);
			pt->next = ptNew;
			pt = ptNew;
			if (p1 != NULL && p2 != NULL) {
				int tmp = p1->val + p2->val + uper;
				pt->val += tmp;
				if (tmp >= 10) {
					pt->val -= 10;
					uper = 1;
				}
				else
				{
					uper = 0;
				}
				p1 = p1->next;
				p2 = p2->next;
			}
			else if (p1 != NULL) {
				int tmp = p1->val + uper;
				pt->val += tmp;
				if (tmp >= 10) {
					pt->val -= 10;
					uper = 1;
				}
				else
				{
					uper = 0;
				}
				p1 = p1->next;
			}
			else if (p2 != NULL) {
				int tmp = p2->val + uper;
				pt->val += tmp;
				if (tmp >= 10) {
					pt->val -= 10;
					uper = 1;
				}
				else
				{
					uper = 0;
				}
				p2 = p2->next;
			}
		}
		if (uper > 0) {
			ListNode *ptNew = new ListNode(0);
			pt->next = ptNew;
			pt = ptNew;
			pt->val = uper;
		}
		return results;
	}
};

//int main()
//{
//	Solution sl;
//	ListNode *l1, *l2, *p1, *p2;
//	l1= new ListNode(9);
//	l2 = new ListNode(9);
//	p1 = new ListNode(5);
//	p2 = new ListNode(5);
//	p1->next = NULL;
//	p2->next = NULL;
//	//l1->next = p1;
//	//l2->next = p2;
//
//	ListNode *results = sl.addTwoNumbers(l1, l2);
//	
//	int c = 5;
//
//	while (results != NULL) {
//		std::cout << results->val << std::endl;
//		results = results->next;
//	}
//
//	system("pause");
//	return 0;
//}
