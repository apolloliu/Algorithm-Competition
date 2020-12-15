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

const int inf = 0x7f7f7f7f;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = new ListNode(0);
        ListNode* head = res;
        if(!lists.size())return head->next;
        int n = lists.size();
        int val;
        while(true){
            val = inf;
            for(auto p: lists)if(p != NULL)val = min(val, p->val);
            if(val == inf)break;
            for(auto p = lists.begin(); p != lists.end(); ++p)if(*p != NULL && val == (*p)->val){  // 这里如果用 auto p: lists会有问题，只是引用，不能修改
                head->next = new ListNode(val);
                head = head->next;
                ListNode* tmp = (*p)->next;
                (*p) = tmp;
            }
            if(val == inf)break;
        }
        return res->next;
    }
};
