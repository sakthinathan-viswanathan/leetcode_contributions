class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int n = nums.size();

        int res = 0;
        int count = 0;
        int zero = 0;
 
        int left = 0;
        for(int right = 0;right<n;right++){

            if(nums[right] == 1){
                count++;
            }
            else
            {
                zero++;
            }

            while(zero == 1){

                if(nums[left] == 1){
                    count--;
                }
                else
                {
                    zero--;
                }

                left++;
            }

            res = max(res,count);

        }

        return res;
        
    }
};