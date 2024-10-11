class Solution {
public:
    typedef pair<int, int> P;
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        priority_queue<P, vector<P>, greater<P>> occupied;
        priority_queue<int, vector<int>, greater<int>> free;
        int targetFriendArrivalTime = times[targetFriend][0];
        int chair = 0;
        sort(times.begin(), times.end());

        for(int i = 0; i < n; i++)
        {
            int arrival = times[i][0];
            int depart = times[i][1];

            while(!occupied.empty() && occupied.top().first <= arrival)
            {
                free.push(occupied.top().second);
                occupied.pop();
            }

            if(free.empty())
            {
                occupied.push({depart, chair});
                if(arrival == targetFriendArrivalTime) return chair;
                chair++;
            }
            else{
                int leastChair = free.top();
                free.pop();
                if(arrival == targetFriendArrivalTime) return leastChair;
                occupied.push({depart, leastChair});
            }
        }
        return -1;
    }
};