vector<long> ans;
sort(viewers.begin(), viewers.end());
vector<int> prefix;
int t = 0;
for(int i = viewers.size(); i>=0; i--) {
    t += viewers[i];
    prefix.push_back(t);
}
for(int i = 0; i < queries.size(); i++) {
    int q = queries[i];
    ans.push_back(prefix[q-1]);
}
return ans;