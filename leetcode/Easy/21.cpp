// 就是比较大小
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* head = res;
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){head->next = new ListNode(l1->val); head = head->next; l1 = l1->next;}
            else {head->next = new ListNode(l2->val); head = head->next; l2 = l2->next;}
        }
        while(l1 != NULL){
            head->next = new ListNode(l1->val);
            head = head->next;
            l1 = l1->next;
        }
        while(l2 != NULL){
            head->next = new ListNode(l2->val);
            head = head->next;
            l2 = l2->next;
        }
        return res->next;
    }
};
