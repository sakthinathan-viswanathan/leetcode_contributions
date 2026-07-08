class Solution {
public:
    string minWindow(string s, string t) {

        int n = s.size();

        int m = t.size();

        unordered_map<int,int>freq;

        for(char c:t){
            freq[c]++;
        }
        
        int min_len = INT_MAX;
        int count = m;
        int start = 0;
        int left = 0;

        for(int right = 0;right<n;right++){

            if(freq[s[right]] > 0){
                count--;
            }

            freq[s[right]]--;


            while(count == 0){
                if(right-left+1 < min_len){
                    min_len = (right-left+1);
                    start = left;
                }

                freq[s[left]]++;

                if(freq[s[left]] > 0){
                    count++;
                }

                left++;
            }
        }        

        return min_len == INT_MAX?"":s.substr(start,min_len);
    }
};