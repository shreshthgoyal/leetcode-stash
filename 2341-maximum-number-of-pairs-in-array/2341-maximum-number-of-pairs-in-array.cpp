class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto &i:nums)
            m[i]++;
        
        vector<int> ans(2,0);
        
        for(auto &i:m)
        {
            ans[0] += i.second / 2;
            ans[1] += i.second % 2;
        }
        
        return ans;
    }
};