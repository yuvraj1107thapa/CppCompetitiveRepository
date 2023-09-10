/*
By Yuvraj Thapa
*/
#include "iostream"
#include "chrono"
#include "time.h"
using namespace std;
using namespace std::chrono;

void bubbleSort(int arr[], int n) {
    bool swapped = true;
    for(int i = 0; i < n - 1 and swapped ; i++) {
        swapped = false;
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j+1], arr[j]);
                swapped = true;
            }
        }
    }
    return;
}

int main(int argc, char* argv[])
{

    // int max = 1000, min = 1;
    // int range = max - min + 1;
    // int avg_result[30] = {0};
    // int best_result[30] = {0};
    // int worst_result[30] = {0};
    // int size[30] = {10, 50, 100, 250, 500, 750, 1000,1200, 1500, 2000, 5000, 6000, 7500,10000, 20000, 25000, 30000,45000, 50000, 75000, 85000, 95000, 100000, 150000, 250000, 400000, 500000,750000, 900000, 1000000};
    // for(int i = 0; i < 20; i++) {
    //     srand(time(0));
    //     int arr[size[i]];
    //     for(int j = 0; j < size[i]; j++) {
    //         arr[j] = (rand()%range)+min;
    //     }
    //     auto start = high_resolution_clock::now();
    //     bubbleSort(arr, size[i]);
    //     auto stop = high_resolution_clock::now();
    //     auto duration = duration_cast<microseconds>(stop - start);
    //     cout<<duration.count()<<", ";
    // }
    // cout<<endl;
    //
    // for(int i = 0; i < 30; i++) {
    //     srand(time(0));
    //     int arr[size[i]];
    //     for(int j = 0; j < size[i]; j++) {
    //         arr[j] = j+1;
    //     }
    //     auto start = high_resolution_clock::now();
    //     bubbleSort(arr, size[i]);
    //     auto stop = high_resolution_clock::now();
    //     auto duration = duration_cast<microseconds>(stop - start);
    //     cout<<duration.count()<<" ,";
    // }
    // cout<<endl;
    //
    // for(int i = 0; i < 20; i++) {
    //     srand(time(0));
    //     int arr[size[i]];
    //     for(int j = 0; j < size[i]; j++) {
    //         arr[j] = size[i] - j + 1;
    //     }
    //     auto start = high_resolution_clock::now();
    //     bubbleSort(arr, size[i]);
    //     auto stop = high_resolution_clock::now();
    //     auto duration = duration_cast<microseconds>(stop - start);
    //     cout<<duration.count()<<" ,";
    // }
    cout<<endl;
    return 0;
}
