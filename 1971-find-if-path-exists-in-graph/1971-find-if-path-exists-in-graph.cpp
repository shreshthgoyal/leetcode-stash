class Solution {
public:
   
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
         
        queue<int> q;
        
        q.push(source);
        vis[source] = 1;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            if(node==destination)
                return true;
            for(auto &i:adj[node])
            {
                if(!vis[i])
                {
                    q.push(i);
                    vis[i]=1;
                }
            }
        }
        
        return false;        
    }
};