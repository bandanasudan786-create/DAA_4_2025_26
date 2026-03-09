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
        ListNode* temp = head;
        int count=0;

        while(temp !=NULL && count<k)
        {
            temp=temp->next;
            count++;
        }

        if(count==k) 
        {
            temp=reverseKGroup(temp,k);
            while(count--) 
            {
                ListNode* curr = head->next;
                head->next=temp;
                temp=head;
                head=curr;
            }

            head=temp;
        }

        return head;
    }
};

