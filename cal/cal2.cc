#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        int sign = 1;
        int ret = 0;
        int j = 0;
        int cur = 0;
        for (int i = 0; i < s.length(); ) {
            if (s[i] == ' ' || s[i] == '.') {
                ++ i;
            } else if (IsNum(s, i)) {
                j = i;
                while (j < s.length() && IsNum(s, j))
                    ++ j;
                cur = GetNum(s, i, j);
                ret += sign * cur;
                i = j;
            } else {
                if (s[i] == '+') {
                    sign = 1;
                } else if (s[i] == '-') {
                    sign = -1;
                } else if (s[i] == '(') {
                    nums.push(ret);
                    nums.push(sign);
                    ret = 0;
                    sign = 1;
                } else {
                    sign = nums.top();
                    nums.pop();
                    ret = sign * ret + nums.top();
                    nums.pop();
                    sign = 1;
                }
                ++ i;
            }
        }
        return ret;
    }
    bool IsNum(string s, int index) {
        if (s[index] >= '0' && s[index] <= '9')
            return true;
        else
            return false;
    }
    int GetNum(string s, int start, int end) {
        int ret = 0;
        for (int i = start; i < end; i ++) {
            ret = ret * 10 + s[i] - '0';
        }
        return ret;
    }
};

int main() {
    Solution sol;
    string s1 = "1 + 1";
    string s2 = "(9-1)- (4 - 2)";
    //string s2 = "2-1+2";
    //string s3 = "(1+(4+5+2)-3)+(6+8)";
    //string s3 = "(1+(4+5+2))"; 
    string s3 = "(7)-(0)+(4)";
    //int ret = sol.calculate(s1);
    //cout << ret << endl;
    //cout << sol.calculate(s2) << endl;;
    cout << sol.calculate(s3) << endl;;

    return 0;
}
