class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;

        while (prev->next && prev->next->next) {
            ListNode* a = prev->next;
            ListNode* b = a->next;

            // troca
            a->next = b->next;
            b->next = a;
            prev->next = b;

            // avança
            prev = a;
        }

        return dummy->next;
    }
};
