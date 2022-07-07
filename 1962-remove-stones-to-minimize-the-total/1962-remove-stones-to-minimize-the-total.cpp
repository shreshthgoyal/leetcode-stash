class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int ans = 0;
        int temp;
        for(auto &i:piles)
        {
            ans+=i;
            pq.push(i);
        }
        
        while(k--)
        {
           temp = pq.top();
            pq.pop();
            ans-= temp/2;
            pq.push((temp+1)/2);
        }
        
        return ans;
    }
};