class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>ng;

        stack<int>stk;

        for(int i:nums2){

            while(!stk.empty() && stk.top() < i){

                ng[stk.top()] = i;
                stk.pop();
            }
            
            stk.push(i);
        }


        vector<int>res;

        for(int num:nums1){
            res.push_back(ng.count(num) ? ng[num] : -1);

        }

        return res;
    }
};