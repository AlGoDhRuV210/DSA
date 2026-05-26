class Solution {
public:
    int numberOfSpecialChars(string words) {
        sort(words.begin(),words.end());
        int ans=0;
        for(int i = 0;i<words.length();i++)
        { 
            if(i>0 && words[i]==words[i-1]) continue;

             for(int j = i+1;j<words.length();j++)
        {
            // if( j>i+1 &&( words[j]==words[j-1])) continue;

            if((words[i] ^ ' ') == words[j]) {ans++; break;}
            
        }
        }
        return ans ;
    }
};