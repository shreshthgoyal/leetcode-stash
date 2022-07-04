class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ans = 0;
        int size = arr.size();
        int window_sum = 0;
        
        for(int idx=0; idx < k; idx ++)
            window_sum+=arr[idx];
        
         if(window_sum/k >= threshold) ans++;
        
        for(int idx = k; idx < size; idx++)
        {            
            window_sum = window_sum + (arr[idx]-arr[idx-k]);
            
             if(window_sum/k >= threshold) ans++;
        }
        
        
        return ans;
    }
};