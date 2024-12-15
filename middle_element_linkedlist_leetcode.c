/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* middleNode(struct ListNode* head) {
    
    struct ListNode* slow = head;
    struct ListNode* fast = head;
   
   
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;         // move slow pointer one step
        fast = fast->next->next;   // move fast pointer two steps
    }
   
    // When fast reaches the end, slow will be at the middle node
    return slow;
}