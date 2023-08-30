#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v;
        int power = 1;
        while(power < n) {
            v.push_back(power);
            power*=2;
        }
        int last = v[v.size()-1];
        int rem = n-last;
        string binary="";
        while(rem) {
            binary +=(rem%2+'0');
            rem/=2;
        }
        for(int i = 0; i < binary.size(); i++) {
            if(binary[i] == '1') {
                v.push_back(n-pow(2, i));
                n-=pow(2, i);
            }
        }
        cout << v.size() << endl;
        for(int i = v.size()-1; i>=0; i--) {
            cout << v[i] << " ";
        }
    }   

    return 0;
}
