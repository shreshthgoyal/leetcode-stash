class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        string p = normalise(pattern);
        vector<string> ans;
        
        for(auto &i:words)
            if(p == normalise(i))
                ans.push_back(i);
        
        return ans;
    }
    
    string normalise(string s)
    {
        unordered_map<char,char> m;
        
        int ch = 'a';
        int k = 0;
        
        for(auto &i:s)
        {
            if(!m[i])
            {
                m[i] = ch+k;
                k++;
            }
        }
        
        for(int i=0; i<s.length(); i++)
        {
            s[i] = m[s[i]];
        }
        
        return s;
    }
};