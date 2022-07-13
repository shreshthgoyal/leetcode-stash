class Solution {
public:
    
    void dfs(int node, vector<bool>& check, vector<vector<int>> rooms)
    {
        check[node] = 1;
        for(auto &i:rooms[node])
        {
            if(!check[i])
            {
               dfs(i,check,rooms);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> check(rooms.size(), false);
              
        dfs(0, check, rooms);
        
        for(auto i:check)
            if(i==false)
                return 0;
        
        return 1;
    }
};