//link: https://leetcode.com/explore/interview/card/google/63/sorting-and-searching-4/3081/

class Solution {
public:
    
    int searchInVector(vector<int>& nums, int target, int start, int end , bool isLowerBound){
        
       
        
        if(end- start <= 1){
            if(isLowerBound){
                if(nums[start] == target)
                    return start;
                if(nums[end] == target)
                    return end;
            
            }
            if(nums[end] == target)
                return end;
            
            if(nums[start] == target)
                return start;
            

          
            return -1;
        }
        int midIndex = (start + end) / 2;
        int midValue = nums[midIndex];
        if((isLowerBound && midValue >= target) || midValue > target){
            return searchInVector(nums, target, start, midIndex, isLowerBound);
        }
        else{
            return searchInVector(nums, target, midIndex, end, isLowerBound);
        }
        
        
        
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>range = {-1,-1};
        if(n == 0)
            return range;
        int lowerBound =  searchInVector(nums, target, 0, n - 1 , true);
        int upperBound =  searchInVector(nums, target, 0, n - 1 , false);
        
     
        range = {lowerBound,upperBound};
       
        return range;
    }
};