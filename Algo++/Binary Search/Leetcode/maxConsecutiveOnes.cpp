// Problem link: https://leetcode.com/problems/max-consecutive-ones-iii/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int countOnes=0;
        int start=0, end=0, ans=0;
        while(end<nums.size()){
            if(nums[end]==1){
                countOnes++;
            }
            if((end-start+1)-countOnes>k){
                if(nums[start]==0){
                    start++;
                }
                else{
                    while(start<end){
                        if(nums[start]==0){
                            break;
                        }
                        countOnes--;
                        start++;
                    }
                    start++;
                }
            }
            ans=max(ans, end-start+1);
            end++;
        }
        
        return ans;
    }
};