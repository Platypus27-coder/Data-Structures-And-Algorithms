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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int, int> mp;
        ListNode *tmp = head;
        while(tmp != NULL) {
            mp[tmp->val]++;
            tmp = tmp->next; 
        }
        ListNode *prev = NULL;
        while(head != NULL && mp[head->val] > 1) {
            ListNode *del = head;
            head = head->next;
            delete del;
        }
        tmp = head;
        while(tmp != NULL) {
            if (mp[tmp->val] > 1) {
                prev->next = tmp->next;
                delete tmp;
                tmp = prev->next;
            }
            else {
                prev = tmp;
                tmp = tmp->next;
            }
        }
        return head;
    }
};
