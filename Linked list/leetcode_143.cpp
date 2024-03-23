/*
Leetcode_143. Reorder list
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
*/

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
    ListNode* reverse(ListNode* tempHead){
        if(!tempHead){
            return nullptr;
        }

        ListNode* prev = nullptr;
        ListNode* cur = tempHead;
        ListNode* nextNode = nullptr;

        while(cur){
            nextNode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextNode;
        }

        return prev;
    }

    void merge(ListNode* head1,ListNode* head2){
// head2 will be always bigger or equal to head1 as in case of odd number of nodes,there will be n/2 nodes on left and n/2+1 on right
        while(head2){
            ListNode* nextNode = head1->next;
            head1->next = head2;
            head1 = head2;
            head2 = nextNode;
        }
    }

    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next){
            return;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = head;
        
        while(fast && fast->next){
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }

        prev->next = nullptr; //to break the first half side of list
        ListNode* midHead = reverse(slow);
        merge(head,midHead);
    }
};
