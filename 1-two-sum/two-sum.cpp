class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();

        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){

            int diff = target - nums[i];
            
            if(mp.find(diff) == mp.end()){
                mp[nums[i]] = i;
            }
            else
            {
                return {i,mp[diff]};
            }
        }
        

        return {-1,-1};
    }
};