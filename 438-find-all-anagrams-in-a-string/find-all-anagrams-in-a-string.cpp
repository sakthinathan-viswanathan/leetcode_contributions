class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        int n = s.size();

        int k = p.size();

        unordered_map<char,int>freq;

        for(char c:p){
            freq[c]++;
        }

        vector<int>res;


        int left = 0;
        for(int i=0;i<n;i++){
            
                freq[s[i]]--;

                if(freq[s[i]] == 0){
                    freq.erase(s[i]);
                }

                if(i - left + 1 == k){

                    if(freq.size() == 0){
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