 #include <bits/stdc++.h>
 using namespace std;


 void swap(vector<int> &arr, int i, int j){
    
        int temp=arr[j];
        arr[j]=arr[i];
        arr[i]=temp;
    
    }
    
    void threeWayPartition(vector<int> &arr,int a, int b)
    {
        // code here 
        int st=0, mid=0, end=arr.size()-1;
        while(mid<=end){
            if(arr[mid]<a){
                swap(arr, mid, st);
                st++; mid++;
            }
            else if(arr[mid]>a && arr[mid]<b){
                mid++;
            }
            else{
                swap(arr, mid, end);
                end--;
            }
        }
  
    }

    void threeWayPartition2(vector<int> &nums,int a, int b)
    {
        // code here 
        int st=0, end=nums.size()-1;
        for(int i=0; i<=end; i++){
            if(nums[i]<a){
                swap(nums, st, i);
                st++;
            }
            else if(nums[i]>b){
                swap(nums, end, i);
                end--;
                i--;
            }
        }

    }

    int main(){
                     // mid
                     // st                    
                     //                              end
    vector<int> nums={76, 8, 75, 22, 59, 96, 30, 38, 36};

    threeWayPartition(nums, 44, 62);
    for(auto x: nums){
        cout << x << " ";
    }

    return 0;
    }