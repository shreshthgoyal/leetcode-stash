class Solution {
public:
    int numberOfSubstrings(string s) {
         int ans = 0;
        string temp = "abc";
        unordered_map<char, int> umap;
        for(char it: temp){
            umap[it]++;
        }
        int i=0, j=0, count = umap.size();
        while(j<s.size()){
            if(umap.find(s[j])!=umap.end()){
                umap[s[j]]--;
                if(umap[s[j]]==0) count--;
            }
            if(count > 0) j++;
            else if(count == 0){
                while(count==0){
                    if(umap.find(s[i])!=umap.end()){
                        ans+= s.size()-j;
                        umap[s[i]]++;
                        if(umap[s[i]] > 0) count++;
                    }
                    i++;
                }
                j++;
            }
        }
        return ans; 
    }
};