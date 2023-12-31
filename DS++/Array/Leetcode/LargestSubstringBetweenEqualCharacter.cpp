class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans = -1;
        for(int i = 0; i < s.size(); i++) {
            int index = i;
            for(int j = i+1; j < s.size(); j++) {
                if(s[j] == s[i]) index = j;
            }
            if(index != i) {
                ans = max(ans, index - i - 1);
            }
        }
        return ans;
    }
};