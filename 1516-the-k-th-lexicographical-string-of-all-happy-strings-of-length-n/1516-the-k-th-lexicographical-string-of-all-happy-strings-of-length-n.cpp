class Solution {
public:
    void solve(int n, int &k, int &count, string  &curr, string &result)
    {
        if(curr.length() == n)
        {
            count++;
            if(count == k) {
                result = curr;
                return;
            }
            return;
        }
        for(char ch = 'a'; ch <= 'c'; ch++)
        {
            if(!curr.empty() && curr.back() == ch) continue;
            curr.push_back(ch);
            solve(n, k, count, curr, result);
            curr.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        string curr = "", result = "";

        int count = 0;

        solve(n, k, count, curr, result);

        return result;
    }
};