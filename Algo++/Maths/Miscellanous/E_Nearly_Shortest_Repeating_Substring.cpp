#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int calculateFrequency(const string& str, vector<int>& freq) {
    for (char c : str) {
        freq[c - 'a']++;
    }
    return *max_element(freq.begin(), freq.end());
}

int findShortestRepeatingSubstring(const string& str) {
    int n = str.length();
    vector<int> freq(26, 0);
    int maxFreq = calculateFrequency(str, freq);
    int shortestLength = n;

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            bool isValid = true;
            for (int j = i; j < n; j++) {
                if (str[j] != str[j % i]) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                shortestLength = min(shortestLength, i);
            }
        }
    }

    return shortestLength;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        string str;
        cin >> n >> str;

        int shortestLength = findShortestRepeatingSubstring(str);
        cout << shortestLength << endl;
    }

    return 0;
}
