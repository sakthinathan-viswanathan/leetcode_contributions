class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        int n = nums.size();

        vector<int>res;

        sort(nums.begin(),nums.end());

        for(int i=1;i<n;i++){
            if(nums[i-1] == nums[i]){
                res.push_back(nums[i]);
            }
        }

        return res;
    }
};