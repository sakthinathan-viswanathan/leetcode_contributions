class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();

        long long sum = 0;
        long long res = 0;

        unordered_map<int,int>mp;

        int left = 0;

        for(int right = 0;right<n;right++){
            sum += nums[right];
            mp[nums[right]]++;

            if(right-left+1 == k){
                if(mp.size() == k){
                    res = max(res,sum);
                }

                mp[nums[left]]--;
                sum -= nums[left];
                if(mp[nums[left]] == 0)
                {
                    mp.erase(nums[left]);
                }
                left++;

            }
        }
        
        return res;
    }
};