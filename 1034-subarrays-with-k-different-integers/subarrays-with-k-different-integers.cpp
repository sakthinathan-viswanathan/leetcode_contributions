class Solution {
public:

    int findSubarray(vector<int>& nums,int k){

        int n = nums.size();

        unordered_map<int,int>mp;

        int res = 0;

        int left = 0;
        for(int right = 0;right<n;right++)
        {

            mp[nums[right]]++;

            while(mp.size() > k){

                mp[nums[left]]--;

                if(mp[nums[left]] == 0){
                    mp.erase(nums[left]);
                }

                left++;
            }

            res += (right-left+1);

        }

        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return findSubarray(nums,k) - findSubarray(nums,k-1);
        
    }
};