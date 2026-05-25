class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        

        int n = nums.size();

        if(n == 0){
            return 0;
        }

        int left = 0;
        int max_len = 1;

        for(int right = 1;right<n;right++){

            if(nums[right-1] >= nums[right]){
                left = right;
            }

            max_len = max(max_len,right-left+1);
        }

        return max_len;
    }
};