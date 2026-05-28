class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int>mp;

        int res = 0;

        int left = 0;
        for(int right = 0;right<n;right++){

            mp[nums[right]]++;

            while(mp.size() > 2){


                mp[nums[left]]--;

                if(mp[nums[left]] == 0){
                    mp.erase(nums[left]);
                }

                left++;

            }

            res = max(res,right-left+1);
        }

        return res;
        
    }
};