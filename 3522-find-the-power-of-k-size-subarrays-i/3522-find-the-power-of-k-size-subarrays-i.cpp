class Solution {
public:
    vector<int> resultsArray(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans;

        if (k > n) return vector<int>(1, -1);

        for (int i = 0; i <= n - k; i++) {
            bool isValid = true;
            int maxi = arr[i];

            for (int j = i; j < i + k - 1; j++) {
                if (arr[j + 1] - arr[j] != 1) {
                    isValid = false;
                    break;
                }
                maxi = max(maxi, arr[j + 1]);
            }

            if (isValid)
                ans.push_back(maxi);
            else
                ans.push_back(-1);
        }

        return ans;
    }
};
