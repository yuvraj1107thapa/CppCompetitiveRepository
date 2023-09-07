#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        long long n, x, y;
        cin >> n >> x >> y;
        long long count_x = 0;
        long long  count_y = 0;
        for(int i = 1; i < n; i++) {
            if(i%x == 0 and i%y != 0) {
                count_x++;
            } else if(i%x != 0 and i%y == 0){
                count_y++;
            }
        }
        long long ans= 0;
        while(count_x) {
            ans+=n--;
            count_x--;
        }
        ans-=count_y;
        cout << ans << endl;
     }
    return 0;
}
