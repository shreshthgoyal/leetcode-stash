class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
       int h = log2(label);
        vector<int> ans;
        
        while(h>=0)       
        {
        ans.push_back(label);
        label = pow(2,h-1)+pow(2,h)-label/2-1;
        h--;
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};