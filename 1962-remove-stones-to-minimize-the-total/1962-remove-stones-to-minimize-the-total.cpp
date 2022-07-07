class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int ans = 0;
        int temp;
        for(auto &i:piles)
            pq.push(i);
        
        while(k--)
        {
           temp = pq.top();
            pq.pop();
            temp-= temp/2;
            pq.push(temp);
        }
        
        while(!pq.empty())
        {
            ans+=pq.top();
            pq.pop();
        }
        
        return ans;
    }
};