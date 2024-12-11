// Problem link: https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:
    // function for checking can eat in time
    bool f(vector<int>& piles, int h, int k) {
        int hours = 0;
        for(int i = 0; i < piles.size(); i++) {
            int count = piles[i] / k;
            hours += count;
            if(piles[i] % k != 0) hours++;
        }   
        std::cout<<k<<" --- "<<hours<<endl;
        return hours <= h ? true : false;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int max_pile = 0;
        for(int i = 0; i < piles.size(); i++) {
            max_pile = max(max_pile, piles[i]);
        }
        int start = 1, end = max_pile;
        while(start<=end) {
            int mid = (start + end) / 2;
            if(f(piles, h, mid)) end = mid - 1;
            else start = mid + 1;
        }
        return start;
    }
};