// Problem link : https://leetcode.com/problems/koko-eating-bananas/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool possible(vector<int>& piles, int h, int maxi) {
        long long k = 0;
        for(int i = 0; i < piles.size(); i++) {
            int temp = piles[i];
            if(temp <= maxi) k++;
            else {
                // for(int i = 0; i < temp; i += maxi) {
                //     k++;
                // }
                if(temp % maxi == 0) {
                    k += temp/maxi;
                } else {
                    k += temp/maxi+1;
                }
            }
        }
        return k > h ? false : true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = 0;
        int lo = 1, hi = 1e9+5;
        // for(auto &element: piles) {
        //     hi += element;
        // }
        while(lo <= hi) {
            int mid = lo + (hi - lo) /2;
            if(possible(piles, h, mid)) {
                ans = mid;
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
        return ans;
    }
};