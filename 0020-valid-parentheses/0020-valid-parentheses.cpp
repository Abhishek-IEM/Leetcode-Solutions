class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if(s[0] == ')' ||s[0] == '}'||s[0] == ']') return false;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
            else
            {
                if(st.size() == 0) return false;
                else if(s[i]==')' && st.top()!='(') return false;
                else if(s[i]=='}' && st.top()!='{') return false;
                else if(s[i]==']' && st.top()!='[') return false;
                st.pop();
            }
        }
        if(st.size() == 0) return true;
        else return false;
    }
};