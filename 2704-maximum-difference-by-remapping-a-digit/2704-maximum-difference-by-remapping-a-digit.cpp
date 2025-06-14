class Solution {
public:
    int minMaxDifference(int num) {
        string str1 = to_string(num);
        string str2 = str1;

        int idx = str1.find_first_not_of('9');
        if(idx != string::npos){
            char ch = str1[idx];
            replace(begin(str1), end(str1), ch, '9');
        }

        char ch = str2[0];
        
        replace(begin(str2), end(str2), ch, '0');

        return stoi(str1) - stoi(str2);
    }
};