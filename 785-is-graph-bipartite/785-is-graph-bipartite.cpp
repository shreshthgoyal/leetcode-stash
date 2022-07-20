class Solution {
public:
    
    bool bipbfs(vector<vector<int>> &graph,  vector<int> &color, int i)
    {
        color[i] =1;
        queue<int> q;
        q.push(i);
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(auto &j: graph[node])
            {
                if(color[j]==-1)
                {
                    color[j]=1-color[node];
                    q.push(j);
                }
                
                else if(color[j]==color[node])
                    return false;
            }
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        
        for(int i=0; i<graph.size(); i++)
        {
            if(color[i]==-1)
            {
                if(!bipbfs(graph,color, i))
                return false;
            }
        }
        
        return true;        
    }
};