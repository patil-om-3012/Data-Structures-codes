//Leetcode 234. Palindrome Linked list
//checks if a linked list is palindrome in one pass and constant space
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
    ListNode* reverse(ListNode* head){
        if(!head){
            return nullptr;
        }

        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* nextNode = nullptr;

        while(cur){
            nextNode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextNode;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(!head || !head->next){
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* reverseHead = reverse(slow);

        while(reverseHead){
            if(head->val != reverseHead->val){
                return false;
            }
            else{
                head = head->next;
                reverseHead = reverseHead->next;
            }
        }

        return true;
    }
};
