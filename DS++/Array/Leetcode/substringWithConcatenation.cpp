// Problem link: https://leetcode.com/problems/substring-with-concatenation-of-all-words/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        unordered_map<string, int> m;
        for(auto i: words){
            m[i]++;
        }
        
        int wordSize=words[0].size();
        int range=s.size()-wordSize*words.size();
            
        unordered_map<string, int> temp;
        vector<int> ans;
        for(int i=0; i<range+1; i++){
            temp.clear();
            int count=0;
            for(int j=i; j<s.size(); j+=wordSize){
                string str=s.substr(j, wordSize);
                if(!m.count(str)){
                    break;
                }
                temp[str]++;
                if(temp[str]>m[str]){
                    break;
                }
                count++;
                if(count==words.size()){
                    ans.push_back(i);
                }
            }
        }
        
        return ans;
    }
};