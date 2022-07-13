class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> m;
        
        for(auto &i:edges)
            for(auto &j:i)
                m[j]++;
        
        int ans;
        
        for(auto &i:m)
            if(i.second==edges.size())
                ans=i.first;
        
        return ans;
    }
};