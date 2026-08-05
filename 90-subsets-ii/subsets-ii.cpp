class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        vector<int>cur;

        vector<vector<int>>res;

        backtrack(0,nums,cur,res);


        return res;
        
    }

    void backtrack(int start,vector<int> &nums,vector<int> &cur,vector<vector<int>> &res){

        res.push_back(cur);

        for(int i=start;i<nums.size();i++){

            if(start < i && nums[i] == nums[i-1]){
                continue;
            }

            cur.push_back(nums[i]);

            backtrack(i+1,nums,cur,res);

            cur.pop_back();
        }
    }


};