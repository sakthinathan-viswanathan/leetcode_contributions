class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        int count = 1;
        int cand = nums[0];

        for(int i=1;i<n;i++){

            
            if(cand == nums[i]){
                count++;
            
            }
            else if(count == 0){
                cand = nums[i];
                count =1;
            }
            else
            {
                count--;
            }
        }


        return cand;
        
    }
};