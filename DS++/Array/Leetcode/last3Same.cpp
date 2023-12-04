// Problem link: https://leetcode.com/problems/largest-3-same-digit-number-in-string

class Solution {
public:
    string largestGoodInteger(string num) {
        string result = "";
        for (int i = 0; i <= num.size() - 3; ++i) {
            if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
                string goodInteger = num.substr(i, 3);
                if (goodInteger > result) {
                    result = goodInteger;
                }
            }
        }
        return result;
    }
};