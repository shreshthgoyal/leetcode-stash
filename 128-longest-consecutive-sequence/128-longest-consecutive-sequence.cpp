class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> m;
        if(nums.size()==0) return 0;
        for(auto &i:nums)
            m.insert(i);
        
        vector<int> v;
        
        for(auto &i:m)
            v.push_back(i);
        
        int len = 1;
        int ans = INT_MIN;
                
        for(int i=1; i<v.size(); i++)
        {
            if(v[i] == v[i-1]+1) len++;
            
            else
            {
                ans = max(ans, len);
                len = 1;
            }
        }
        
        ans = max(ans, len);
        
        return ans;
    }
};