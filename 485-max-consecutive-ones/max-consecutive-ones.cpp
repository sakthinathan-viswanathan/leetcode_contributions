class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int n = nums.size();

        int res = 0;

        int left = 0;
        int i = 0;
        for( i=0;i<n;i++){

            if(nums[i] != 1){
                res = max((i-left),res);
                cout<<left<<" "<<i<<endl;
                left = i+1;
            }
        }

          res = max((i-left),res);
        
        return res;
    }
};