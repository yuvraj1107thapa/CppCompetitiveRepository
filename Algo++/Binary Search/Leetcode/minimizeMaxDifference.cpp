// Problem link: https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/

class Solution {
public:
    bool isValid(vector<int>& nums, int mid, int p) {
        int i = 0, count = 0;
        while(i < nums.size()-1) {
            if(abs(nums[i]-nums[i+1]) <= mid) {
                count++;
                i+=2;
            } else {
                i++;
            }
            if(count == p) return true;
        }
        return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        int st = 0, end = nums[nums.size()-1] - nums[0];
        while(st <= end) {
            int mid = st+(end-st)/2;
            if(isValid(nums, mid, p)) {
                ans = mid;
                end = mid-1;
            } else {
                st = mid+1;
            }
        }
        return ans;
    }
};