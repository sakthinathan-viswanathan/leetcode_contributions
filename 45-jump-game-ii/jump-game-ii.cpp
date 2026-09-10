class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();

        if(n<=1){
            return 0;
        }
        if(nums[0] == 0){
            return -1;
        }

       int jump = 1;
       int step = nums[0];

       int max_reach = nums[0];

       for(int i=1;i<n;i++){

        if(i == n-1){
            return jump;
        }

        max_reach = max(max_reach,nums[i] + i);
        step--;

        if(step == 0){
            jump++;

           if(i >= max_reach)
           {
            return -1;
           }

           step = max_reach - i;
        }


       }

       return -1;


        
    }
};