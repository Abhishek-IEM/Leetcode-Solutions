class Solution {
public:
    int findWinner(int n, int k)
    {
        if(n == 1) return 0;
        return (findWinner(n - 1, k) + k) % n; 
    }

    int findTheWinner(int n, int k) {
        // queue<int> q;
        // for(int i = 0; i < n; i++) q.push(i + 1);

        // while(q.size() > 1)
        // {
        //    for (int i = 1; i < k; i++)
        //     {
        //         q.push(q.front()); 
        //         q.pop();           
        //     }
        // q.pop();
        // }
        // return q.front();


        return findWinner(n, k) + 1;
    }
};