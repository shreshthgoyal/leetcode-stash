class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        set<pair<int,int>> s;
        
        for(auto &i:nums)
            m[i]++;
        
        
        for(auto &i:nums)
        {
            if(k==0 && m[i] > 1)
            {
                s.insert({i,i});
            }
            else if(k!=0 && m[i-k] > 0)
            {
                s.insert({i,i-k});
            }
        }
    
        
        return s.size();
    }
};