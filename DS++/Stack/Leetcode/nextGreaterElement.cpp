#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
        
        vector<int> ans;
        stack<int> st;
        for(int i=nums.size()-1; i>=0; i--){
            st.push(nums[i]);
        }
        
        for(int i=nums.size()-1; i>=0; i--){
            while(!st.empty() && st.top() <= nums[i]){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(st.top());
            }
            st.push(nums[i]);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }

int main(){
    
    vector<int> nums;
    int n;
    cin >> n;
    int temp;
    for(int i=0; i<n; i++){
        cin >> temp;
        nums.push_back(temp);
    }

    vector<int> ans=nextGreaterElements(nums);
    for(auto i: ans){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}