class Solution {
public:
    int minLength(string s) {
        int n = s.length();
        stack<char> st;
          // Iterate through the string
    for (int i = 0; i < n; i++) {
        // Check if the top two elements form the pairs 'AB' or 'CD'
        if (!st.empty() && ((st.top() == 'A' && s[i] == 'B') || (st.top() == 'C' && s[i] == 'D'))) {
            st.pop();  // Remove the top if pair is found
        } else {
            st.push(s[i]);  // Otherwise, push the current character
        }
    }
    
    // The size of the stack will be the minimized length
    return st.size();
    }
};