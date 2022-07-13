class Solution {
public:
    
    void help(int node, vector<int>& vis, vector<vector<int>>& adj, vector<int>&dfs)
    {
       dfs.push_back(node);
        vis[node]=1;
        
        for(auto &i:adj[node])
        {
            if(!vis[i])
                help(i,vis,adj,dfs);
        }
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        
        vector<int> vis(n,0);
        int u,k;
        
        for(int i=0; i<edges.size(); i++)
        {
            u = edges[i][0];
            k = edges[i][1];
            
            adj[u].push_back(k);
            adj[k].push_back(u);
        }
        vector<vector<int>> v;
        
        for(int i=0; i<vis.size(); i++)
        {
        vector<int> dfs;
            if(vis[i] == 0)
                help(i, vis, adj, dfs);
            v.push_back(dfs);
        }
        
        for(auto &i:v)
        {
          vector<int> p = i;
           if(count(p.begin(), p.end(), source) && count(p.begin(), p.end(), destination))
               return true;
        }
        
        return false;        
    }
};