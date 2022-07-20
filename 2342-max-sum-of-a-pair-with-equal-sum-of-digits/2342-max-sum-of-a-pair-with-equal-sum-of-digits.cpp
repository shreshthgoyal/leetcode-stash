class Solution {
public:
    
    int sumofDigit(int n) {
        
        int sum = 0;
        
        while(n>0)
        {
            sum+= n%10;
            n/=10;
        }
        return sum;
    }
    
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> m;
        
        for(auto &i:nums)
        {
            m[sumofDigit(i)].push_back(i);
        }
        
        for(auto &i:m)
            sort(i.second.begin(), i.second.end(), greater<int>());
        
        int ans = -1;
        
        for(auto &i:m)
        {
            vector<int> j = i.second;
            
            if(j.size() > 1)
            ans= max(ans, j[0]+j[1]);
        }
        
        return ans;
    }
};