
class Solution {
public:
    bool isGood(std::vector<int>& nums) {
        if (nums.size() < 2) {
            return false;
        }

        std::sort(nums.begin(), nums.end());

        int n = nums.size() - 1;

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] != i + 1) {
                return false;
            }
        }

        return nums[n - 1] == n && nums[n] == n;
    }
};