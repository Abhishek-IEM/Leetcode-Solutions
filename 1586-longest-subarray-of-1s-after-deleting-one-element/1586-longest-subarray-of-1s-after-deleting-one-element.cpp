class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int flips=0,i=0,j=0;
        int k=1;
        int maxlen=INT_MIN,len=INT_MIN;
        while(j<n){
            if(nums[j]==1) j++;
            else{
                if(flips<k){
                    flips++;
                    j++;
                } 
                else{
                    len=j-i;
                    maxlen=max(maxlen,len);
                    while(nums[i]==1) i++;
                    i++;
                    j++;
                }
            }
        }
        len=j-i;
        maxlen=max(maxlen,len);
        return maxlen-1;
    }
};
