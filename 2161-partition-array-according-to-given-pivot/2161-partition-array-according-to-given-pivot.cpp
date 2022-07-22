class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> l,e,g;
        
        for(auto &i:nums)
        {
            if(i<pivot)
                l.push_back(i);
            else if(i==pivot)
                e.push_back(i);
            else
                g.push_back(i);            
        }
        
        l.insert(l.end(), e.begin(), e.end());
        l.insert(l.end(), g.begin(), g.end());
        
        return l;
    }
};