class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        int key = nums[0];
        map<int, vector<int>> m;
        
        for (int i = 0; i < n; i++) {
            m[nums[i]].push_back(nums[i]);
            int temp = -1;
            int sz = 0;
            
            for (int j = 0; j < i; j++) {
                if (nums[j] % nums[i] == 0 || nums[i] % nums[j] == 0) {
                    if (sz < m[nums[j]].size()) {
                        sz = m[nums[j]].size();
                        temp = nums[j];
                    }
                }
            }
            
            if (temp != -1) {
                for (auto c : m[temp]) {
                    m[nums[i]].push_back(c);
                }
            }
            
            if (m[nums[i]].size() > ans) {
                key = nums[i];
                ans = m[nums[i]].size();
            }
        }
        
        vector<int> res;
        for (auto i : m[key]) {
            res.push_back(i);
        }
        return res;
    }
};