class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        backtrack(0, nums, res);
        return res;
    }

private:
    void backtrack(int ind, vector<int>& nums, vector<vector<int>>& res) {
        if (ind == nums.size()) {
            res.push_back(nums);
            return;
        }

        unordered_set<int> used;  

        for (int i = ind; i < nums.size(); i++) {
            if (used.count(nums[i])) continue;
            used.insert(nums[i]);

            swap(nums[ind], nums[i]);
            backtrack(ind + 1, nums, res);
            swap(nums[ind], nums[i]);
        }
    }
};
