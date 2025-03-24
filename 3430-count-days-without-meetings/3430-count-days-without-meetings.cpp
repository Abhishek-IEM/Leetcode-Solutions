class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(meetings.begin(), meetings.end());

        int ans = 0, strt = 0, end = 0;

        for(auto &meet : meetings)
        {
            if(meet[0] > end) ans += meet[0] - end - 1;
            end = max(end, meet[1]);
        }

        if(days > end) {
            ans += days-end;
        }

        return ans;
    }
};