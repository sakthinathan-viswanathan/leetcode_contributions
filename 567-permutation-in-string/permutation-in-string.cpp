class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n = s1.size();
        int m = s2.size();

        unordered_map<char,int>mp;

        for(char c:s1){
            mp[c]++;
        }

//        unordered_map<int,int>freq;
        int left = 0;

        for(int right = 0;right<m;right++){

           
            mp[s2[right]]--;

            if(mp[s2[right]] == 0){
                mp.erase(s2[right]);
            }

           if(mp.size() == 0){
            return true;
           }

           while((right-left+1) >= n){
                mp[s2[left]]++;

                if(mp[s2[left]] == 0){
                    mp.erase(s2[left]);
                }

                left++;
           }

        }


        return false;
        
    }
};