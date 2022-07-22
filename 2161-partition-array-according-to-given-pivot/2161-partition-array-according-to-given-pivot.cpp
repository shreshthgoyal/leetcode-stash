class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int low = 0, high = nums.size();
        
        for(auto &i:nums)
        {
            if(i<pivot)
                low++;
            else if(i > pivot)
                high--;
        }
        int same = low;
        
        vector<int> ans(nums.size());
        int j=0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==pivot)
            {
                ans[same] = nums[i];
                same++;
            }
            
            else if(nums[i] > pivot)
            {
                ans[high] = nums[i];
                high++;
            }
            else
            {
                ans[j] = nums[i];
                j++;
            }
        }
        
        return ans;
    }
};