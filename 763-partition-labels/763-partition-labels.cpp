class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        if(s.length()==1)
            return {1};
        
        unordered_map<char,int> m;
        
        int n = s.length();
        
        for(int i=0; i<n; i++)
            m[s[i]] = i;
        
        int a=0,b=1;
        
        vector<int> ans;
        int k = 0;
        for(int i=0; i<n; i++)
        {
            if(m[s[i]] > k)
                k=m[s[i]];
            
            if(m[s[i]] == k && i==k)
                ans.push_back(k+1);
        }
        
        for(int i=ans.size()-1; i>0; i--)
            ans[i] = ans[i] - ans[i-1];
        
        return ans;
    }
};