// Problem link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n=nums.size();
        int st=0, end=(int)nums.size()-1;
        
        if(nums[st]<=nums[end]){
            return nums[st];
        }
        
        while(st<=end){
            int mid=(st+end)/2;
            int prev=(mid+n-1)%n;
            int next=(mid+1)%n;
            if(nums[mid]<=nums[prev] && nums[mid]<=nums[next]){
                return nums[mid];
            }
            else if(nums[0]<=nums[mid]){
                st=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        
        return -1;
    }
};