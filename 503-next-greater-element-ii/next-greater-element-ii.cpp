class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();

        stack<int>stk;

        vector<int>res(n);

        for(int i = n*2-1;i>=0;i--){

            while(!stk.empty() && stk.top() <= nums[i%n]){
                stk.pop();
            }

            if(stk.empty()){
                res[i%n] = -1;
            }
            else{
                res[i % n] = stk.top();
            }

            stk.push(nums[i%n]);
        }


        return res;
        
    }
};