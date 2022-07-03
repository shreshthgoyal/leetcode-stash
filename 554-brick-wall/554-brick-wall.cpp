class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int cnt = 0;
        for(int i=0; i<wall.size(); i++)
        {
            if(wall[i].size()==1) cnt++;
        }
        
        if(cnt == wall.size()) return wall.size();
        
        int sum = 0;
        
        for(int i=0; i<wall[0].size(); i++)
            sum+=wall[0][i];
        
        unordered_map<int,int> m;
        
        for(int i=0; i<wall.size();i++)
        {
            m[wall[i][0]]++;
            
            for(int j=1; j<wall[i].size();j++)
            {
                wall[i][j] += wall[i][j-1];
                m[wall[i][j]]++;
            }
        }
        
        int mx = INT_MIN;
        
        for(auto &i:m)
        {
        if(i.first < sum)
        mx = max(mx, i.second);
        }
        
        if(mx == INT_MIN)
            return 0;
        
        return wall.size() - mx;
        
    }
};