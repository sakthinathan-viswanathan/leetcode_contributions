class Solution {
public:

    void backtrack(int start, vector<int>& cur,
                   vector<vector<int>>& res,
                   vector<int>& nums) {

        res.push_back(cur);

        for(int i = start; i < nums.size(); i++) {

            // Skip duplicate choices at the same level
            if(i > start && nums[i] == nums[i-1])
                continue;

            cur.push_back(nums[i]);

            backtrack(i + 1, cur, res, nums);

            cur.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> cur;

        backtrack(0, cur, res, nums);

        return res;
    }
};