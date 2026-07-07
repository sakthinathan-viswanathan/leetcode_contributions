class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int n = nums.size();

        unordered_map<int,int>mp;

        int left = 0;
        int ans = 0;

        for(int right = 0;right<n;right++){

            mp[nums[right]]++;

            while(mp[0] > k){
                ans = max(ans,(right-left));

                mp[nums[left]]--;

                if(mp[nums[left]] == 0){
                    mp.erase(nums[left]);
                }

                left++;
            }
        }

        ans = max(ans,(n-left));

        return ans;
        
    }
};