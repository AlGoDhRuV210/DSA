class Solution {
public:

int helper(string s ,int sign, long long  sum)
{
    if(s==""|| s==" ") return sum*sign;
    if(s[0]-'0'>9 || s[0]-'0'<0 ) return sum*sign;
    // if(!isdigit(s[0])) return sum*sign;
      if(sum > (INT_MAX - (s[0]-'0')) / 10)
        return (sign == -1) ? INT_MIN : INT_MAX;
    sum=sum*10 + s[0]-'0';
    return helper(s.substr(1,s.length()-1),sign,sum);

}
    int myAtoi(string s) {
        if(s==" "   || s=="") return 0;
        if(s[0]==' ') return myAtoi(s.substr(1,s.length()-1));
         int sign=1;
        if(s[0]=='-')  sign = -1; 
        if((s[0]=='-' || s[0]=='+') && (s.length()==1 || !isdigit(s[1]))) return 0; 
        if(s[0]=='-' || s[0]=='+')
        return helper(s.substr(1,s.length()-1),sign,0LL);
        else 
        return helper(s,sign,0LL);

        

        
    }
};