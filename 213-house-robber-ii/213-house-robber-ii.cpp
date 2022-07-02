class Solution {
public:
    int Erob(vector<int>& nums) {
        int n = nums.size();
        int dp[n+1];
        dp[0] = 0;
        dp[1] = nums[0];
        if(n>1)
        dp[2] = max(nums[0], nums[1]);
        
        for(int i=2; i<n;i++)
        {
             dp[i+1] = max(dp[i], dp[i-1]+nums[i]);
        }
        
        return dp[n];
    }
        
    int rob(vector<int>& nums) {
        if(!nums.size()%2)
            return Erob(nums);
        
        if(nums.size()==1) return nums[0];
        
        vector<int> v1(nums.begin(), nums.end()-1);
        vector<int> v2(nums.begin()+1, nums.end());
        return max(Erob(v1), Erob(v2));
        
    }
};