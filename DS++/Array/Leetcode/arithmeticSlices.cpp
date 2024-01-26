class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        vector<unordered_map<long long,long long>> mp(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                long long diff=(long long)nums[i]-(long long)nums[j];
                if(diff<=INT_MIN || diff>=INT_MAX)
                {
                    continue;
                }
                long long seq=0;
                if(mp[j].find(diff)!=mp[j].end())
                {
                    seq=mp[j][diff];
                }
                mp[i][diff]+=seq+1;
                ans+=seq;
            }
        }
        return (int)ans;
    }
}