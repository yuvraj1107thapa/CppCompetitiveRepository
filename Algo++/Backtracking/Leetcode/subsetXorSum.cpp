#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<int> nums, vector<vector<int>>& subsets, vector<int> ds, int idx){
         
        if(idx==nums.size()){
            subsets.push_back(ds);
            return;
        }
        
        dfs(nums, subsets, ds, idx+1);
        ds.push_back(nums[idx]);
        dfs(nums, subsets, ds, idx+1);
    }
    
    int subsetXORSum(vector<int>& nums) {
        
        vector<vector<int>> subsets;
        vector<int> ds;
        dfs(nums, subsets, ds, 0);
        int ans=0, xorSum=0;
        for(int i=0; i<subsets.size(); i++){
            xorSum=0;
            for(int j=0; j<subsets[i].size(); j++){
                xorSum=xorSum^subsets[i][j];
            }
            ans+=xorSum;
        }
        
        return ans;
    }
};

int main(){

	vector<string> temp;
	temp.push_back(to_string(-1));
	cout << temp[0] << endl;

	return 0;
}