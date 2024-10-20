class Solution {
public:
    char solveOp(vector<char> &values, char op)
    {
        if(op == '!')
        {
            return values[0] == 't' ? 'f' : 't';
        }
        if(op == '&')
        {
            for(char &ch : values)
            {
                if(ch == 'f') return 'f';
            }
            return 't';
        }
        if(op == '|'){
            for(char &ch : values)
            {
                if(ch == 't') return 't';
            }
            return 'f';
        }
        return 't';
    }
    
    bool parseBoolExpr(string exp) {
        int n = exp.size();
        stack<char> st;
        for(int i = 0; i < n; i++)
        {
            if(exp[i] == ',') continue;
            if(exp[i] == ')')
            {
                vector<char> values;
                while(st.top() != '(')
                {
                    values.push_back(st.top());
                    st.pop();
                }
                st.pop(); // for '(' bracket
                char op = st.top();
                st.pop();
                st.push(solveOp(values, op));
            }
            else st.push(exp[i]);
        }
        return st.top() == 't' ? true : false;
    }
};