class Solution {
public:
    vector<vector<int>> list;
    
    int help(int headID, vector<int>& informTime)
    {
        int time = 0;
        for(auto &i: list[headID])
            time = max(time, help(i, informTime));
        
        return informTime[headID]+time;
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        list.resize(n);
        
        for(int i=0; i<n; i++)
        {
            if(manager[i] != -1)
                list[manager[i]].push_back(i);
        }
        
        return help(headID, informTime); ;
    }
};