class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();

        unordered_map<char,int>mp;

        int res = 0;

        int left = 0;
        for(int i=0;i<n;i++){
            mp[s[i]]++;

            while(mp[s[i]] > 1){
                mp[s[left]]--;
                left++;
            }

            res = max(res,(i-left+1));
        }

        return res;
        
    }
};