
//Question Link: https://leetcode.com/explore/interview/card/google/59/array-and-strings/342/

class Solution {
public:
     

    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        auto comp = []( ListNode* n1, ListNode* n2 ) { return n1->val > n2->val; };
        priority_queue<ListNode*,vector<ListNode*>, decltype( comp )> minHeap( comp );
        
        for(int i = 0; i < lists.size(); i++){
            if(lists[i])
                minHeap.push(lists[i]);
        }

        ListNode resultListHead(0);
        ListNode* tail = &resultListHead;

        while (!minHeap.empty()) {
            tail->next = minHeap.top();
            minHeap.pop();
            tail = tail->next;

            if (tail && tail->next) {
                minHeap.push(tail->next);
            }
        }

        return resultListHead.next; 
    }
};