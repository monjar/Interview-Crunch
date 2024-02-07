//https://leetcode.com/explore/interview/card/google/59/array-and-strings/3058/

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        
        
        vector<int> distanceToLeft(seats.size());
        int currentDistanceToLeft = INT_MAX;
        for(int i = 0; i < seats.size(); i++){
            if(currentDistanceToLeft == INT_MAX)
                currentDistanceToLeft = seats[i]? 0 : INT_MAX;
            else
                currentDistanceToLeft = seats[i]? 0 : currentDistanceToLeft + 1;
            distanceToLeft[i] = currentDistanceToLeft;
            
        }
        
        vector<int> distanceToRight(seats.size());
        int currentDistanceToRight = INT_MAX;
        for(int i = seats.size() - 1; i >= 0; i--){
            if(currentDistanceToRight == INT_MAX)
                currentDistanceToRight = seats[i]? 0 : INT_MAX;
            else
                currentDistanceToRight = seats[i]? 0 : currentDistanceToRight + 1;
            distanceToRight[i] = currentDistanceToRight;
            
        }
        int maxDistance = 0;
        for(int i = 0; i < seats.size(); i++){
            int closestPersonDist = min(distanceToRight[i], distanceToLeft[i]);
          
            maxDistance = max(closestPersonDist, maxDistance);
        }
        
        return maxDistance;
    }
};