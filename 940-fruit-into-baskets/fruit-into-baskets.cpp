class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int n = fruits.size();

        int left = 0;
        unordered_map<int,int>mp;

        int res = 0;

        for(int right=0;right<n;right++){

            mp[fruits[right]]++;

            if(mp.size() > 2){
                
                mp[fruits[left]]--;
                if(mp[fruits[left]]== 0){
                    mp.erase(fruits[left]);
                }
                    left++;
            }

            res = max(res,(right-left+1));
        }
        
        return res;
    }
};