// Problem link: https://leetcode.com/problems/assign-cookies/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0;
        int i = 0, j = 0;
        while(i < g.size() and j < s.size()) {
            if(s[j] < g[i]) {
                j++;
            } else {
                ans++;
                i++; 
                j++;
            }
        }
        return ans;
    }
};