//https://leetcode.com/explore/interview/card/google/60/linked-list-5/3065/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* list1It = list1;
        ListNode* list2It = list2;
        if(list1It == nullptr && list2It == nullptr)
               return nullptr;
        
        ListNode* mergedListHead = new ListNode(0);
        if(list1It != nullptr && (list2It == nullptr || list1It->val < list2It->val ) ){
            mergedListHead->val = list1It->val;
            list1It = list1It->next;
        }
        else{
            mergedListHead->val = list2It->val;
            list2It = list2It->next;
        }
        cout<<"Here";
        
        
        if(list1It == nullptr && list2It == nullptr)
               return mergedListHead;
        mergedListHead->next = new ListNode(0);
        
        ListNode* mergedListHeadIt = mergedListHead->next;
        
        while(list1It != nullptr || list2It != nullptr){
            
            if(list1It != nullptr && (list2It == nullptr || list1It->val < list2It->val ) ){
                mergedListHeadIt->val = list1It->val;
                list1It = list1It->next;
            }
            else{
                mergedListHeadIt->val = list2It->val;
                list2It = list2It->next;
            }
            
            if(list1It == nullptr && list2It == nullptr)
                break;
            mergedListHeadIt->next = new ListNode(0);
            mergedListHeadIt = mergedListHeadIt->next;
        }
        
        return mergedListHead;
    }
};