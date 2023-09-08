// Problem link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n=nums.size();
        int st=0, end=(int)nums.size()-1;
       
        while(st<=end){
            int mid=(st+end)/2;
            if(nums[mid]>nums[end]){
                st=mid+1;
            }
            else if(nums[mid]<nums[end]){
                end=mid;
            }
            else{
                end--;
            }
        }
        
        return nums[st];
    }
};