class Solution {
public:
    bool isValid(string ss) {
        stack<char> s;
        for(auto i  : ss)
        {
            if(i=='(' || i=='[' || i=='{') s.push(i);
             else
             {
                if(i==')')
                {
                    if(s.empty() || s.top()!='(') return false;
                    s.pop();
                }
                if(i==']')
                {
                    if(s.empty() || s.top()!='[') return false;
                    s.pop();
                }
                if(i=='}')
                {
                    if(s.empty() || s.top()!='{') return false;
                    s.pop();
                }
             }

        }
        if(s.empty()) return true;
        return false;
    }
};