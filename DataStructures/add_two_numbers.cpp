//Question Link:https://leetcode.com/explore/interview/card/google/60/linked-list-5/3063/


class Solution {
public:
    
    
   
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  
        
        ListNode *currentOp1 = l1;
        ListNode *currentOp2 = l2;
        ListNode *result = new ListNode(0);
        ListNode *currentResDigit = result;
         
        int carry = 0;
        
        while(currentOp1 != nullptr || currentOp2 != nullptr || carry > 0){
            int operandValue1 = currentOp1!=nullptr?  currentOp1->val: 0;
            int operandValue2 = currentOp2!=nullptr?  currentOp2->val: 0;
            int currentSumRes = operandValue1 + operandValue2 +carry;
            if(currentSumRes >= 10){
                carry = 1;
                currentSumRes-=10;
            }
            else 
                carry = 0;
            
            cout<< operandValue1<<" " <<operandValue2 <<" " <<currentSumRes<<" " ;
            currentOp1 =( (currentOp1 != nullptr) ?  currentOp1->next : nullptr );
            currentOp2 =( (currentOp2 != nullptr) ?  currentOp2->next : nullptr );
            currentResDigit->val = currentSumRes;
            if(currentOp1 == nullptr && currentOp2 == nullptr && carry == 0)
                break;
           
            currentResDigit->next = new ListNode(0);;
            currentResDigit = currentResDigit->next;
            
      
        }
        
        
        return result;
    }
};