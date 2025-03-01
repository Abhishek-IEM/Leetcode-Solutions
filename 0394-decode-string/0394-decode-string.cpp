class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        stack<char> st;

        for(int i = 0; i < n; i++)
        {
            if(s[i] != ']') st.push(s[i]);
            else
            {
                string word;
                while(st.top() != '[')
                {
                    word.push_back(st.top());
                    st.pop();
                }
                reverse(word.begin(), word.end());
                st.pop();

                string k;

                while(!st.empty() && isdigit(st.top()))
                {
                    k.push_back(st.top());
                    st.pop();
                }
                reverse(k.begin(), k.end());

                int num = stoi(k);

                string repeat;

                for(int j = 0; j < num; j++) repeat.append(word);

                for(char c: repeat) st.push(c);
            }
        }

        string ans;

        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};