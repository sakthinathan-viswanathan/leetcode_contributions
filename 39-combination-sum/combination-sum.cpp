class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {


        sort(nums.begin(), nums.end());
        
        vector<int>cur;
        vector<vector<int>>res;

        backtrack(0,0,nums,cur,res,target);

        return res;
    }

    void backtrack(int start,int sum,vector<int> &nums,vector<int> &cur,vector<vector<int>> &res
    ,int target){

        if(sum == target){
            res.push_back(cur);
            return ;
        }

        
        for(int i=start;i<nums.size();i++){

            if(sum + nums[i] > target){
                break;
            }

            cur.push_back(nums[i]);

            backtrack(i,sum + nums[i],nums,cur,res,target);

            cur.pop_back();
        }
    }
};