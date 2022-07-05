class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        if(costs.size()==1)
            return costs[0] <= coins;
        
        sort(costs.begin(), costs.end());
        
        int idx = 0;
        
        while(costs[idx] <= coins && idx < costs.size())
        {
            coins-=costs[idx];
            idx++;
        }
        
        return idx;
    }
};