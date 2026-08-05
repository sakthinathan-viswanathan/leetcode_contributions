class Solution {
public:

    void backtrack(vector<int> &cur,int ind,vector<vector<int>> & res,vector<int> &nums){


        if(ind == nums.size()){

            res.push_back(cur);
            return ;
        }

        cur.push_back(nums[ind]);
        backtrack(cur,ind+1,res,nums);

        cur.pop_back();
        backtrack(cur,ind+1,res,nums);

    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int>cur;

        vector<vector<int>>res;


        backtrack(cur,0,res,nums);
        
        return res;
    }
};