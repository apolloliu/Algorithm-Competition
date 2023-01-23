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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* node = new ListNode(0);
        ListNode* res = node;
        int f = 0;
        while(l1 != NULL && l2 != NULL){
            int tmp = l1->val + l2->val + f;
            node->next = new ListNode(tmp%10);
            f = tmp/10;
            node = node->next;
            l1 = l1->next;
            l2 = l2->next;
            // cout << "1" << endl;
        }

        while(l1){
            int tmp = l1->val + f;
            node->next = new ListNode(tmp%10);
            f = tmp/10;
            node = node->next;
            l1 = l1->next;
        }
        while(l2){
            int tmp = l2->val + f;
            node->next = new ListNode(tmp%10);
            f = tmp/10;
            node = node->next;
            l2 = l2->next;
        }
        if(f){
            node->next = new ListNode(f);
        }
        return res->next;
    }
};
