class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        vector<int> ans;
        
        sort(arr.begin(), arr.end());
        int med = arr[(arr.size()-1)/2];
        
        vector<pair<int,int>> v;
        for(int i=0; i<arr.size(); i++)
        {
           v.push_back({abs(arr[i]-med), i});
        }
        
        cout << med << endl;
        sort(v.rbegin(), v.rend());
        
        for(int i=0;i<k; i++)
            ans.push_back(arr[v[i].second]);
        
        return ans;
    }
};