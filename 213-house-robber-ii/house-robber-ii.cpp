class Solution {
public:

    vector<int> dp;

    int recursion(vector<int>& nums, int n) {

        // Base case
        if (n < 0) {
            return 0;
        }

        // Memoization
        if (dp[n] != -1) {
            return dp[n];
        }

        // Skip current OR rob current
        return dp[n] = max(
            recursion(nums, n - 1),
            recursion(nums, n - 2) + nums[n]
        );
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

        // Edge case
        if (n == 1) {
            return nums[0];
        }

        // Case 1: Skip first house
        vector<int> skip_first = findarray(1, n, nums);

        // Case 2: Skip last house
        vector<int> skip_last = findarray(0, n - 1, nums);

        // Solve case 1
        dp.assign(n - 1, -1);
        int max_first = recursion(skip_first, n - 2);

        // Solve case 2
        dp.assign(n - 1, -1);
        int max_last = recursion(skip_last, n - 2);

        return max(max_first, max_last);
    }
};