class Solution {
public:
string helper(string s)
{
    string final = {};
    int z = s.size();
    int count = 0;
    char candidate = s[0];
    for (int i = 0; i < z; i++)
    {
        if (s[i] == candidate)
            count++;
        else
        {
            final += to_string(count)+candidate;
            count = 1;
            candidate = s[i];
        }
    }
    final += to_string(count)+candidate;
    return final;
}
    string countAndSay(int n) {
              if(n == 1) return "1";
        return helper(countAndSay(n-1));
    }
};