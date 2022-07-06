class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        
        int tempA = capacityA, tempB = capacityB;
        
        int ans = 0;
        
        for(int i=0; i<plants.size()/2; i++)
        {
            ans+= tempA < plants[i];
            
            if(tempA >= plants[i])
                tempA -= plants[i];
            else
                tempA = capacityA-plants[i];

            ans+= tempB < plants[plants.size()-1-i];
            
            if(tempB >= plants[plants.size()-1-i])
                tempB -= plants[plants.size()-1-i];
            else
                tempB = capacityB-plants[plants.size()-1-i];
        }
        
        if(plants.size()%2)
        {
            ans+= max(tempA, tempB) < plants[plants.size()/2];
        }
                     
        return ans;
    }
};