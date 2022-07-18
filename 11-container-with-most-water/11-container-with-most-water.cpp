class Solution {
public:
    int maxArea(vector<int>& height) {
       int L = 0, R = height.size() - 1;
        int ans = 0;
        while (L <= R) {
            int water = min(height[L], height[R]) * (R - L);
            ans = max(water, ans);
            if (height[L] < height[R])
                L++;
            else
                R--;
        }
        return ans;
    }
};