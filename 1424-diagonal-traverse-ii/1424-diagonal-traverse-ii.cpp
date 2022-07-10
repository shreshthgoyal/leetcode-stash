class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int,vector<int>> m;
        vector<int> v;

        for(int i=0; i<nums.size(); i++)
        {
            v = nums[i];
            for(int j=0; j<v.size(); j++)
            {
                m[i+j].push_back(v[j]);
            }
        }
        
        for(auto &i:m)
            reverse(i.second.begin(), i.second.end());
        
        vector<int> ans;
        
        for(auto &i:m)
            {
            ans.insert(ans.end(), i.second.begin(), i.second.end());
            }     
        return ans;
    }
};