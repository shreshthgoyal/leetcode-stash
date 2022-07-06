class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        bool check[plants.size()];
        
        int tempA = capacityA, tempB = capacityB;
        
        int ans = 0;
        
        for(int i=0; i<plants.size()/2; i++)
        {
            check[i] = tempA < plants[i];
            
            if(tempA >= plants[i])
                tempA -= plants[i];
            else
                tempA = capacityA-plants[i];

            check[plants.size()-1-i] = tempB < plants[plants.size()-1-i];
            
            if(tempB >= plants[plants.size()-1-i])
                tempB -= plants[plants.size()-1-i];
            else
                tempB = capacityB-plants[plants.size()-1-i];
        }
        
        if(plants.size()%2)
        {
            check[plants.size()/2] = max(tempA, tempB) < plants[plants.size()/2];
        }
              
        
        for(int i=0; i<plants.size(); i++)
            ans+=check[i];
        
        return ans;
    }
};