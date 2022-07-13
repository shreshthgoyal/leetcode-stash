class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n);
        vector<vector<int>> check(n, vector<int>(n,0));
        
        int u,v;
        
        for(auto &i:roads)
        {
            u = i[0];
            v= i[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
            check[u][v]=1;
            check[v][u]=1;
        }
        
        int ans =INT_MIN;
        
        for(int i=0; i<n; i++)
        {
            int rank = 0;
            for(int j=0; j<n; j++)
            {
                if(i!=j)
                {
                rank = adj[i].size()+adj[j].size() - check[i][j];
                ans= max(ans, rank);
                }
            }
        }
        
        return ans;
    }
};