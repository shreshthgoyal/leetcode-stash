class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n);
        
        int u,v;
        
        for(auto &i:roads)
        {
            u = i[0];
            v= i[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int ans =INT_MIN;
        
        for(int i=0; i<n; i++)
        {
            int rank = 0;
            for(int j=0; j<n; j++)
            {
                if(i!=j)
                {
                rank = adj[i].size()+adj[j].size();
                
                if(count(adj[i].begin(), adj[i].end(), j))
                    rank--;
                
                ans= max(ans, rank);
                }
            }
        }
        
        return ans;
    }
};