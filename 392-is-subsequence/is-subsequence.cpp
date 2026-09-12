class Solution {
public:
    bool isSubsequence(string s, string t) {
    int l=0;
    for(int i=0;i<t.length();i++){
        if(s[l]==t[i]){
            l++;
        }
    }

    return l==s.length();

    }
};