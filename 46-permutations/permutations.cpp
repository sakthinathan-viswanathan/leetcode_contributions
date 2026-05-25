class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>>result;
        vector<int>current;
        backtrack(nums,result,current);

        return result;
    }

    void backtrack(vector<int>& nums,vector<vector<int>>& result,vector<int>& current){

        if(current.size() == nums.size()){
            result.push_back(current);
            return;
        }

        for(int i:nums){

           if(find(current.begin(),current.end(),i) != current.end()){
            continue;
           }
            current.push_back(i);
            backtrack(nums,result,current);
            current.pop_back();
        }
    }
};