class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> t(2501, 0);
        vector<int> ans;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                t[grid[i][j]]++;
            }
        }
        int missing_num = -1, repeated = -1;
        int n = grid.size()*grid.size();
        for(int i = 1; i <= n; i++) {
            if(t[i] == 2) repeated = i;
            if(t[i] == 0) missing_num = i;
        }
        ans.push_back(repeated);
        ans.push_back(missing_num);
        return ans;
    }
};