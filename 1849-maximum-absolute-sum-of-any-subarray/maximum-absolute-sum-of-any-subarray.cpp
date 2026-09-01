class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int prefix = 0;
        int mx = 0, mn = 0;

        for (int x : nums) {
            prefix += x;
            mx = max(mx, prefix);
            mn = min(mn, prefix);
        }

        return mx - mn;
    }
};