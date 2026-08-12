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

    // Compare two nodes
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // Min Heap
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

        // Put first node of every list into heap
        for (ListNode* list : lists) {
            if (list != nullptr) {
                minHeap.push(list);
            }
        }

        // Dummy node to build answer
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        // Process heap
        while (!minHeap.empty()) {

            // Get smallest node
            ListNode* node = minHeap.top();
            minHeap.pop();

            // Add it to answer
            tail->next = node;
            tail = tail->next;

            // Add next node from same list
            if (node->next != nullptr) {
                minHeap.push(node->next);
            }
        }

        return dummy->next;
    }
};