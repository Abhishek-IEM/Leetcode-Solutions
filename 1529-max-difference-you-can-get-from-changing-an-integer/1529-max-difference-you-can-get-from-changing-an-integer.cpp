class Solution {
public:
    int maxDiff(int num) {
        string a = to_string(num);
        string b = a;

        int idx = a.find_first_not_of('9');
        if(idx != string::npos){
            char ch = a[idx];
            replace(begin(a), end(a),ch, '9');
        }

        for(int i = 0; i < b.length(); i++)
        {
            char ch = b[i];
            if(i == 0){
                if(ch != '1'){
                    replace(begin(b), end(b),ch, '1');
                    break;
                }
            }
            else if(ch != '0' && ch != b[0]){
                replace(begin(b), end(b),ch, '0');
                break;
            }
        }
        return stoi(a) - stoi(b);
    }
};