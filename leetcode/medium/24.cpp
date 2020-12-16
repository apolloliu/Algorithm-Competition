// 头条面试题

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
    ListNode* dfs(ListNode* head, int step){
        if(head == NULL)return NULL;
        head->next = dfs(head->next, step+1);
        if(step % 2 == 0 && head->next != NULL){
            ListNode* tmp1 = head;
            ListNode* tmp2 = head->next->next;
            head = head->next;
            head->next = tmp1;
            tmp1->next = tmp2;
        }
        return head;
    }
    ListNode* swapPairs(ListNode* head) {
        head = dfs(head, 0);
        return head;
    }
};
