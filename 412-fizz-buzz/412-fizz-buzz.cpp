class Solution {
public:
    vector<string> fizzBuzz(int n) {
        string a = "Fizz";
        string b = "Buzz";
        vector<string> ans;
        int j;
        for(int i=0; i<n; i++)
        {
           j = i+1;
            if(!(j%3) && !(j%5))
            {
                ans.push_back(a+b);
            }
            else if(!(j%3))
            {
                ans.push_back(a);
            }
            else if(!(j%5))
            {
                ans.push_back(b);
            }
            else
            {
                ans.push_back(to_string(j));
            }
        }
        
        return ans;
    }
};