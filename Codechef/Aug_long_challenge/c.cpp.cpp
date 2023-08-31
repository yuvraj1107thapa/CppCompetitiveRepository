#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k, l;
        cin >> n >> k >> l;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr, arr + n, greater<int>());
        long long ans = 0;
        int i = 0;
        while(i < n) { 
            if(i%k+1 == l) {
                ans+=arr[i];
            }
            i++;
        }
        cout << ans << endl;
    }

    return 0;
}
