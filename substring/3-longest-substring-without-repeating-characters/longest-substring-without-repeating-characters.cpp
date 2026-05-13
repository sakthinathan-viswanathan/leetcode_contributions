class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.length();
        int max_len = 0;

      
       unordered_map<int,int>mp;


        int left = 0;
        for(int right = 0;right < n;right++){
            mp[s[right]]++;
            while(mp[s[right]] > 1){
                mp[s[left]]--;
                left++;
            }
            max_len = max(max_len,right-left+1);
        }

        return max_len;
        
    }
};