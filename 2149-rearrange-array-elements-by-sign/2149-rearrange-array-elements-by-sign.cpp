class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int idx = 0;
        int k = 0;
        for(int i=0; i<nums.size();i++)
        {
            if(nums[i] > 0)
            {
                ans[idx] = nums[i];
                idx++;
                
                for(int j=k; j<nums.size(); j++)
                {
                    if(nums[j]<0)
                    {
                        k=j+1;
                        ans[idx] = nums[j];
                        idx++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};