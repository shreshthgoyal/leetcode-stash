class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> m;
        for(auto &i:arr)
            m[i]++;
        
        priority_queue<pair<int,int>> pq;
        
        for(auto &i:m)
            pq.push({i.second, i.first});
        
        int n = arr.size();
        int half = n/2;
        int ans =0;
        while(!pq.empty())
        {

            n-= pq.top().first;
            ans++;
            if(n<=half) break;
            pq.pop();
        }
        
        return ans;
    }
};