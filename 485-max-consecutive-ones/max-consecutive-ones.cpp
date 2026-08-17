class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {


        int n = nums.size();

        int l = 0;

        int res = 0,r = 0;

        for(r = 0;r<n;r++){

            if(nums[r] != 1){

                res = max((r-l),res);

                l = r+1;
            }
        }

        res = max((r-l),res);


        return res;
        
    }
};