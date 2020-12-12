// 先获取链表长度len，然后递归判断链表的下一位是不是要删除的位（len-n），如果是，则直接把当前节点和后面的节点连接起来即可
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
    void dfs(int cur, int k, ListNode* head){
        if(cur + 1 == k){
            head->next = head->next->next;
            return;
        }
        dfs(cur+1, k, head->next);
    }
    int len;
    void getlen(ListNode* head, int cur){
        if(head == NULL){len = cur; return;}
        getlen(head->next, cur+1);
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)return head;
        ListNode* root = head;
        len = 0;
        getlen(head, 1);
        if(len - n == 1)return head->next;
        head = root;
        dfs(1, len-n, head);
        return root;
    }
};
