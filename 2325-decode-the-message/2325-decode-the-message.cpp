class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char,char> m;
        int k =0;
        for(int i=0; i<key.length();i++)
        { 
           
            if(key[i] != ' ' && !m[key[i]])
            {
                m[key[i]] = 97+k;
                k++;
            } 
            
            if(k==26) break;
        }
        
       for(int i=0; i< message.length(); i++)
        {
           if(message[i] != ' ')
          message[i] = m[message[i]];
        }
        
       return message;
        
    }
};