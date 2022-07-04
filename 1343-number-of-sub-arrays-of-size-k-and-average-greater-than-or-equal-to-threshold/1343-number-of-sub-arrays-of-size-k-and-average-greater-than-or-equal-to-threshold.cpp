class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        
        //Declaring Variables
        
        int ans = 0;
        int size = arr.size();
        int window_sum = 0;
        
        //In this loop, we calculate sum of our first window ie of size k from index 0 to k-1
        
        for(int idx=0; idx < k; idx ++)
            window_sum+=arr[idx];
        
        //Incrementing our answer if condition holds.
        
         if(window_sum/k >= threshold) ans++;
        
        /*
        Here we are sliding our window index by index to check for all possible windows.
        
        Basically whenever we slide to new index, we are removing the first value from our current window           and adding a new value to this window.
        
            Visualisation                                Window_Sum (Window of size 2, k=2)
         ____________________________
        |  1|  2|  3|  4|  5|  6|  7|                        
        |___|___|___|___|___|___|___|                      (1+2)
        <------->
        
         ____________________________                   
        |  1|  2|  3|  4|  5|  6|  7|                      
        |___|___|___|___|___|___|___|                      (1+2)+(3-1) => (2+3)
            <------->
            
        ____________________________
        |  1|  2|  3|  4|  5|  6|  7|                      
        |___|___|___|___|___|___|___|                       (2+3)+(4-2) => (3+4)
                <------->
        
        ____________________________
        |  1|  2|  3|  4|  5|  6|  7|                      
        |___|___|___|___|___|___|___|                       (3+4)+(5-3) => (4+5)
                    <------->
                    
         ____________________________
        |  1|  2|  3|  4|  5|  6|  7|                      
        |___|___|___|___|___|___|___|                       (4+5) +(6-4) => (5+6)
                        <------->
                        
         ____________________________
        |  1|  2|  3|  4|  5|  6|  7|                      
        |___|___|___|___|___|___|___|                       (5+6) + (7-5) => (6+7)
        
                            <------->
                            
        Then we check the average for each window and increment our answer if average >= threshold.
        
        */
        for(int idx = k; idx < size; idx++)
        {            
            window_sum = window_sum + (arr[idx]-arr[idx-k]);
            
             if(window_sum/k >= threshold) ans++;
        }
                
        return ans;
    }
};