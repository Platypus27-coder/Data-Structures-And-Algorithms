/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;
        while(list1 != NULL && list2 != NULL) {
            if (list1->val < list2->val) {
                tail->next = list1;
                tail = list1;
                list1 = list1->next;
            }
            else {
                tail->next = list2;
                tail = list2;
                list2 = list2->next;
            }
        }
        tail->next = NULL;
        if (list1 != NULL) {
            tail->next = list1;
        }
        if (list2 != NULL) {
            tail->next = list2;
        }
        return dummy->next;
    }
};
