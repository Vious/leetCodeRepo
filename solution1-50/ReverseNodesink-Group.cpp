#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
		if (head == NULL || k == 1) {
			return head;
		}

		ListNode *current = head;
		ListNode *next = NULL;
		ListNode *prev = NULL;
		int count = 1;
		ListNode *checkK = head;
		for (int i = 0; i < k; i++) {
			if (checkK != NULL ) {
				checkK = checkK->next;
				count++;
			}
			else {
				break;
			}
		}
		if (checkK == NULL && count != k+1) {
			return head;
		}
		count = 1;
		while (current != NULL && count <= k) {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
			++count;
		}

		if (next != NULL) {
			head->next = reverseKGroup(next, k);
		}

		return prev;
        
    }
};


int main(int argc, char const *argv[])
{
    Solution sl;
    ListNode *p1 = new ListNode(1);
    ListNode *pt = p1;
    for (int i = 2; i <= 10; i++) {
        ListNode *tmp = new ListNode(i);
        pt->next = tmp;
        pt = pt->next;
        tmp = tmp->next;
        delete tmp;
    }
    int k = 5;
    ListNode *res = sl.reverseKGroup(p1, k);
    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << '\n';


    return 0;
}
