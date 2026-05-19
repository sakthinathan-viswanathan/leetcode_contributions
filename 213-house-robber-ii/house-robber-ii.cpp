class Solution {
public:
    vector<int> dp;

    int recursion(vector<int>& nums, int n) {

        if (n < 0) {
            return 0;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        return dp[n] = max(recursion(nums, n - 1), recursion(nums, n - 2) + nums[n]);
    }

    vector<int> findarray(int st, int end, vector<int>& nums) {

        vector<int> res;
        for (int i = st; i < end; i++) {
            res.push_back(nums[i]);
        }

        return res;
    }
    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1){
            return nums[0];
        }

        vector<int> skip_first = findarray(1, n, nums);

        vector<int> skip_last = findarray(0, n - 1, nums);


        dp.assign(n - 1, -1);
        int max_first = recursion(skip_first, n - 2);
        
        dp.assign(n - 1, -1);
        int max_last = recursion(skip_last, n - 2);

        return max(max_first, max_last);
    }
};