// Problem link: class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n=nums.size();
        int j=n/2;
        if(n&1) ++j;
        int tk=0;
        for(int i=0;i<n/2;++i){
            if(j>=n) break;
            if(nums[i]<nums[j]){
                tk+=2;
                ++j;
            }
            else{
                ++j;
                --i;
            }
        }
        return n-tk;
    }
};

class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n=nums.size();
        int j=n/2;
        if(n&1) ++j;
        int tk=0;
        for(int i=0;i<n/2;++i){
            if(j>=n) break;
            if(nums[i]<nums[j]){
                tk+=2;
                ++j;
            }
            else{
                ++j;
                --i;
            }
        }
        return n-tk;
    }
};