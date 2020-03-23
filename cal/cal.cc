#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        stack<char> opers; 
        bool cal = false;
        int start = 0;
        int cur = 0;
        int num1 = 0, num2 = 0;
        char op = ' ';
        int j = 0;
        for (int i = 0; i < s.length(); ) {
            if (s[i] == ' ' || s[i] == '.') {
                ++ i;
            } else if (IsNum(s, i)) {
                j = i;
                while (j < s.length() && IsNum(s, j))
                    ++ j;
                num2 = GetNum(s, i, j);
                if (cal || (s[j] == ')' && nums.size() >= 1)) {
                    op = opers.top();
                    opers.pop();
                    num1 = nums.top();
                    nums.pop();
                    cout << "num1: " << num1 << " num2: " << num2 << endl;
                    num2 = Cal(num1, num2, op); 
                }
                nums.push(num2);
                cal = true;
                i = j;
            } else {
                if (IsOper(s, i)) {
                    opers.push(s[i]);
                } else if (s[i] == '(') {
                    cal = false;
                } else {

                }
                ++ i;
            }
        }
        while (!nums.empty() && !opers.empty()) {
            num1 = nums.top();
            nums.pop();
            num2 = nums.top();
            nums.pop();
            op = opers.top();
            opers.pop();
            num2 = Cal(num2, num1, op);
            nums.push(num2);
        }
        return nums.top();
    }
    int Cal(int num1, int num2, char c) {
        if (c == '+')
            return (num1 + num2);
        else if (c == '-')
            return (num1 - num2);
    }
    bool IsOper(string s, int index) {
        if (s[index] == '+' || s[index] == '-' )
            return true;
        else
            return false;
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
