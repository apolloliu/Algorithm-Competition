// 模拟，前面加一个头节点，方便计算
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* res = new ListNode(0);
        res->next = head;
        head = res;
        for(; head->next != NULL;){
            int t = 0;
            for(auto p = head; p->next != NULL && t < k; p = p->next, t++)if(t == k)break;
            if(t != k)break;
            auto last = head->next, first = last, first_tmp = first;
            last = last->next;
            for(int i = 0; i < k - 1; ++i){
                if(last == NULL)break;
                auto tmp1 = last->next, tmp2 = last;
                last->next = first;
                last = tmp1;
                first = tmp2;
            }
            head->next = first;
            first_tmp->next = last;
            head = first_tmp;
        }
        return res->next;
    }
};
