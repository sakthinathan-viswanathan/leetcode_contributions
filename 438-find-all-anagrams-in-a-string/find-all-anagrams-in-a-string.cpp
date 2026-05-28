class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        int n = s.length();
        int m = p.length();

        unordered_map<char,int>freq;

        for(char c:p){
            freq[c]++;
        }

        vector<int>res;

        int left = 0;
        for(int right = 0;right<n;right++){
            
            freq[s[right]]--;

            if(freq[s[right]] == 0){
                freq.erase(s[right]);
            }

            if((right-left +1 ) == m){

                if(freq.empty()){

                    res.push_back(left);

                }

    
                freq[s[left]]++;

                if(freq[s[left]] == 0){
                    freq.erase(s[left]);
                }

                left++;
            }

        }

        return res;
        
    }
};