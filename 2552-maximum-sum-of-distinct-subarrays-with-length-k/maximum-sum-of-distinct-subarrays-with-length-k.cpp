class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();

        unordered_map<int,int>mp;

        long long sum = 0;
        long long res = 0;

        int left = 0;
        for(int right = 0;right<n;right++){

            mp[nums[right]]++;
            sum += nums[right];

            if(right-left+1 == k){
                if(mp.size() == k){
                    res = max(res,sum);
                }

                mp[nums[left]]--;
                sum -= nums[left];

                if(mp[nums[left]] == 0){
                    mp.erase(nums[left]);
                }

                left++;
            }
        }
        return res; 
    }
};