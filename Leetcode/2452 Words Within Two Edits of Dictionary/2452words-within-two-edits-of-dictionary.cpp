class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        if(queries.size()==0) return {};
        int m =queries[0].length();
        //each word has m letters
        vector<string> result;
        for (int i = 0; i < queries.size(); i++)
        {
            string s =queries[i];
            for (int j = 0; j < dictionary.size(); j++)
            {
                int cnt=0;
                string c=dictionary[j];
                for (int k = 0; k < m; k++)
                {
                    if(s[k]!=c[k])cnt++;
                    if(cnt>2) break;    
                }
                if(cnt<=2)
              {   result.push_back(s);
                 break;
              }
                
                /* code */
            }
        }
        return result;
        
        
    }
};
