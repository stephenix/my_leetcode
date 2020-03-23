#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        int sign = 1;
        int ret = 0;
        int cur = 0;
        for (int i = 0; i < s.length(); i ++) {
            if (IsNum(s, i)) {
                cur = 10 * cur + s[i] - '0';
            } else {
                if (s[i] == '+') {
                    ret += cur * sign;
                    cur = 0;
                    sign = 1;
                } else if (s[i] == '-') {
                    ret += cur * sign;
                    cur = 0;
                    sign = -1;
                } else if (s[i] == '(') {
                    nums.push(ret);
                    nums.push(sign);
                    ret = 0;
                    sign = 1;
                } else if (s[i] == ')'){
                    ret += sign * cur;
                    sign = nums.top();
                    nums.pop();
                    ret = sign * ret + nums.top();
                    nums.pop();
                    sign = 1;
                    cur = 0;
                }
            }
        }
        return ret + cur * sign;
    }
    bool IsNum(string s, int index) {
        if (s[index] >= '0' && s[index] <= '9')
            return true;
        else
            return false;
    }
};

int main() {
    string s = "11 - (6 + 1)";
    Solution sol;
    cout << sol.calculate(s) << endl;
    return 0;
}
