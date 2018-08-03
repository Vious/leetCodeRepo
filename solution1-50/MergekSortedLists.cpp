#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        for (decltype(lists.size()) i = 0; i < lists.size(); i++) {
            if (lists[i] == NULL) {
                lists.erase(lists.begin() + (i));
                i--;
            }
        }
        // using lamda functional for comparison
        auto cmp = [](ListNode *p1, ListNode *p2) {
            return p1->val > p2->val;
        };
        ListNode *results = new ListNode(0);
        ListNode *pt = results;
        priority_queue <ListNode *, vector<ListNode *>, decltype(cmp)> compareQue(cmp);
        for (decltype(lists.size()) i = 0 ; i < lists.size() ; i++) {
            compareQue.push(lists[i]);
        }

        while ( !compareQue.empty() ) {
            ListNode *tmp = compareQue.top();
            compareQue.pop();
            pt->next = tmp;
            pt = pt->next;
            if (tmp->next != NULL) {
                compareQue.push(tmp->next);
            }
        }
        pt->next = NULL;
        results = results->next;

        return results;
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
    
    ListNode *p2 = new ListNode(1);
    pt = p2;
    for (int i = 2; i <= 10; i++) {
        ListNode *tmp = new ListNode(i);
        pt->next = tmp;
        pt = pt->next;
        tmp = tmp->next;
        delete tmp;
    }
    ListNode *p3 = new ListNode(1);
    pt = p3;
    for (int i = 2; i <= 10; i++) {
        ListNode *tmp = new ListNode(i);
        pt->next = tmp;
        pt = pt->next;
        tmp = tmp->next;
        delete tmp;
    }

    vector <ListNode *> lists;
    lists.push_back(p1);
    lists.push_back(p2);
    lists.push_back(p3);
    ListNode * res = sl.mergeKLists(lists);
    while (res->next != NULL) {
        cout << res->val << " " << '\n';
        res = res->next;
    }

    return 0;
}
