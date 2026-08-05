class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(),candidates.end());

        vector<int>cur;

        vector<vector<int>>res;

        backtrack(0,0,cur,res,target,candidates);

        return res;
    }


    void backtrack(int start,int sum,vector<int> &cur,vector<vector<int>> &res,int tar,vector<int> &candidates){


        if(sum == tar){
            res.push_back(cur);
            return;
        }
        

        for(int i=start;i<candidates.size();i++){
            
            if(start < i && candidates[i] == candidates[i-1]){
                continue;
            }

            if(sum + candidates[i] > tar){
                break;
            }

            cur.push_back(candidates[i]);

            backtrack(i+1,sum + candidates[i],cur,res,tar,candidates);

            cur.pop_back();

        }
    }
};