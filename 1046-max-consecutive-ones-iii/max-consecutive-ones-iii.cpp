class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int n = nums.size();

        unordered_map<int,int>mp;

        int res = 0;

        int l = 0,r=0;
        for(r = 0;r<n;r++){

            mp[nums[r]]++;

            while(mp[0] > k){

                res = max(res,(r-l));

                mp[nums[l]]--;

                if(mp.find(nums[l]) == 0){
                    mp.erase(nums[l]);
                }

                l++;

            }
        }

        res = max(res,(r-l));

        return res;
        
    }
};