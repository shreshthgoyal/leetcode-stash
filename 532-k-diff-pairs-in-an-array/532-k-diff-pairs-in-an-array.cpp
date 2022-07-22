class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        
        for(auto &i:nums)
            m[i]++;
        
        int ans=0;
        for(auto &i:m)
        {
            if(k==0 && i.second > 1)
            {
                ans++;
            }
            else if(k!=0 && m.find(i.first+k)!=m.end())
            {
                ans++;
            }
        }
    
        
        return ans;
    }
};