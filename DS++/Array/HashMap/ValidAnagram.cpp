class Solution {
public:
    bool isAnagram(string s, string t) {
        
        // sort both the given strings
        sort(s.begin(), s.end());
        sort(t.begin(),t.end());
        // if size of first string is not equal to second string, then they can not be anangram. so,return false.
        
        if(s.size()!=t.size()) return false;
        // if size of both strings are equal, then check if elements on all indexes are same or not, if elements of both strings on any index are not equal, return false 
        for(int i=0; i<s.size();i++){
            if(s[i]!=t[i]){
                return false;
            }
        }
        // if any of the false condition is not  executed, it means strings are anagram of each other, return true.
        return true;
    }
};