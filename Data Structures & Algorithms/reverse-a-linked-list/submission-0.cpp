class Solution {
public:

    ListNode* reverse(ListNode* head) {
        if(head == NULL || head->next == nullptr)
            return head;

        ListNode* rev = reverse(head->next);

        head->next->next = head;
        head->next = NULL;

        return rev;
    }

    ListNode* reverseList(ListNode* head) {
        return reverse(head);
    }
};