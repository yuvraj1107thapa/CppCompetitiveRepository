#include <bits/stdc++.h>
using namespace std;

// Algorithm
// two pointers algorithm
// 1. 5 variables: leftHeight, rightHeight, leftPtr=0, rightPtr=arraySize()-1, distance for area between containers
// 2. Run while till leftPtr<rightPtr
// 3. leftHeight=leftPtrHeight, rightHeight=rightPtrHeight
// 4. Update distance with rightPtr index - leftPtr index
// 5. Update answer with max of previous answer or min of leftHeight or rightHeight multiply by distance
// 6. If leftHeight<rightHeight, update leftPtr by 1, else update rightPtr by -1

//Container with most water
int maxArea(vector<int> &height){

    int maxWater=0, distance=0;
    int lHeight=0, rHeight=0;
    int l=0, r=height.size()-1;
    while(l<r){
        lHeight=max(lHeight, height[l]);
        rHeight=max(rHeight, height[r]);
        distance=r-l;
        maxWater=max(maxWater, min(lHeight, rHeight)*distance);
        if(lHeight<rHeight) l++;
        else r--;
    }

    return maxWater;
}

// Algorithm
// two pointers algorithm
// 1. 4 variables: leftHeight, rightHeight, leftPtr=0, rightPtr=arraySize()-1,
// 2. Run while till leftPtr<rightPtr
// 3. Check which ptr Height is smaller, as have to update smaller ptr
// 4. If leftPtr height < rightPtr height, if currentPtr height > previous leftptr height update it, 
//    else update answer with adding previous leftPtr height - current height to answer, increment leftPtr;
// 5. Else rightPtr height < leftPtr height, updation will done in rightPtr and its lHeight
// 6. After loop, answer will have the unit in which water can store.

//Rainwater harvesting
int rainwaterHarvest(vector<int> &height){

    int maxWater=0;
    int leftMax=0, rightMax=0;
    int l=0, r=height.size()-1;
    while(l<r){
        if(height[l]<=height[r]){
            if(leftMax<=height[l]){
                leftMax=height[l];
            } else{
                maxWater+=leftMax-height[l];
            }
            l++;
        }
        else{
            if(rightMax<=height[r]){
                rightMax=height[r];
            } else{
                maxWater+=rightMax-height[r];
            }
            r--;
        }
    }

    return maxWater;
}

int main(){
    
    vector<int> height={1,8,6,2,5,4,8,3,7};
    cout << maxArea(height) << endl;

    return 0;
}

    // vector<int> maxL, maxR;
    // maxL.push_back(height[0]);
    // for(int i=1; i<height.size(); i++){
    //     maxL.push_back(max(maxL[i-1], height[i]));
    // }
    // maxR.push_back(height[height.size()-1]);
    // int k=0;
    // for(int i=height.size()-2; i>=0; i--){
    //     maxR.push_back(max(height[i], maxR[k++]));
    // }
    // reverse(maxR.begin(), maxR.end());
   
    // int unit=0;
    // for(int i=0; i<height.size(); i++){
    //     unit+=min(maxL[i], maxR[i])-height[i];
    // }

    // return unit;