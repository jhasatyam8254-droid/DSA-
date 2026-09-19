class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return head;

        ListNode* sorted = NULL;
        ListNode* current = head;

        while (current != NULL) {

            ListNode* next = current->next;

            if (sorted == NULL || current->val < sorted->val) {
                current->next = sorted;
                sorted = current;
            }
            else {
                ListNode* temp = sorted;

                while (temp->next != NULL &&
                       temp->next->val < current->val) {
                    temp = temp->next;
                }

                current->next = temp->next;
                temp->next = current;
            }

            current = next;
        }

        return sorted;
    }
};