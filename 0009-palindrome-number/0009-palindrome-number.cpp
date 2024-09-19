class Solution {
public:
    bool isPalindrome(int x) {
        long long ans=x;
        long long rev=0,d;
        while(x>0)
        {
            d=x%10;
            rev=rev*10+d;
            x/=10;
        }
        if(ans==rev) return true;
        else return false;
    }
};