#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        vector<vector<char>> g(n, vector<char>(m));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> g[i][j];
            }
        }

        vector<vector<long long>> L(m), U(n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (g[i][j] == 'L') {
                    L[j].push_back(i);
                } else if (g[i][j] == 'U') {
                    U[i].push_back(j);
                }
            }
        }

        bool flag = true;

        for (const auto &l : L) {
            if (l.size() & 1) {
                flag = false;
                break;
            }
        }

        for (const auto &u : U) {
            if (u.size() & 1) {
                flag = false;
                break;
            }
        }

        if (not flag) {
            cout << -1 << endl;
            continue;
        }

        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < L[j].size(); k += 2) {
                int i1 = L[j][k];
                int i2 = L[j][k + 1];
                g[i1][j] = 'W';
                g[i2][j] = 'B';
                g[i1][j + 1] = 'B';
                g[i2][j + 1] = 'W';
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < U[i].size(); k += 2) {
                int j1 = U[i][k];
                int j2 = U[i][k + 1];
                g[i][j1] = 'W';
                g[i][j2] = 'B';
                g[i + 1][j1] = 'B';
                g[i + 1][j2] = 'W';
            }
        }

        for (const auto &row : g) {
            for (char c : row) {
                cout << c;
            }
            cout << endl;
        }
    }

    return 0;
}
