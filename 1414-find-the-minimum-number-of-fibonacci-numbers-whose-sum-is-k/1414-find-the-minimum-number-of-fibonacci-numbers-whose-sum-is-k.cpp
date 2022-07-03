class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> v;
        v.push_back(1);
        v.push_back(1);
        
        int t;
        
        while(1)
        {
            t=v[v.size()-1] + v[v.size()-2];
            v.push_back(t);
            
            if(v[v.size()-1] > k) 
            break;
        }
        
        int c = 0;
        int j  = v.size()-1;
        
        while(true){
            long long x = v[j];
            c += k/x;
            k%=x;
            if(k==0)
                break;
            j--;
        }
        
        return c;
    }
};