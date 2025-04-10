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
    ListNode* mergeNodes(ListNode* head) {
        ListNode*temp=head;
        while(temp){
            ListNode*curr=temp->next;
            temp->val+=curr->val;
            temp->next=curr->next;
            if(curr->val==0){
                temp=temp->next;
                delete curr;
            }
        }
        return head;
    }
};