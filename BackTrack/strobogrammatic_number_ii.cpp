//link: https://leetcode.com/explore/interview/card/google/62/recursion-4/399/

class Solution {
public:
    
    vector<string> calculateStroboRecursive(int n) {
        if(n == 1)
            return {"0","1","8"};
        else if (n == 2)
            return {"11","69","88","96", "00"};
        
        vector<string> res;
        
        vector<string> childNumbers = calculateStroboRecursive(n - 2);
        
        for(int i = 0; i < childNumbers.size(); i++){
            res.push_back("1" + childNumbers[i] + "1");
            res.push_back("6" + childNumbers[i] + "9");
            res.push_back("8" + childNumbers[i] + "8");
            res.push_back("9" + childNumbers[i] + "6");
            res.push_back("0" + childNumbers[i] + "0");
        }
        return res; 
    }
    vector<string> findStrobogrammatic(int n) {

        vector<string>  result = calculateStroboRecursive( n);
        
        vector<string>  filteredResult;
        
        for(auto numberStr : result){
            if(n == 1 || !numberStr.starts_with("0"))
                filteredResult.push_back(numberStr);
        }
        
        return filteredResult;
    }
};