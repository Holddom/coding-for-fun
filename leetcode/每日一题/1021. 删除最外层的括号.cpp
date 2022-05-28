class Solution {
public:
    string removeOuterParentheses(string s) {
        if(s=="")
        return s;
        string ret;
        stack <char> st;
        int flag=0;
        
        for(auto i:s)
        {
            if(i=='('&&st.empty())
            {
                st.push(i);
                continue;
            }
            if(i==')'&&!st.empty()&&flag==0)
            {
                st.pop();
                continue;
            }
            if(i=='(')
            {
                flag++;
            }
            else
            {
                flag--;
            }
            ret.push_back(i);
        }
        return ret;
    }
};

