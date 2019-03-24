// leetcode 148. Sort List
// Merge sort to sort link list
//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)return head;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* pre = head;
        while(fast && fast->next){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        ListNode* L = sortList(head);
        ListNode* R = sortList(slow);
        return merge(L, R);
    }
    ListNode* merge(ListNode* L, ListNode* R){
        ListNode* root = new ListNode(0);
        ListNode* head = root;
        //head = head->next;
        while(L && R){
            if(L->val <= R->val){
                head->next = L;
                L = L->next;
                head = head->next;
            }
            else {
                head->next = R;
                R = R->next;
                head = head->next;
            }
        }
        if(L)head->next = L;
        if(R)head->next = R;
        return root->next;
    }
};
