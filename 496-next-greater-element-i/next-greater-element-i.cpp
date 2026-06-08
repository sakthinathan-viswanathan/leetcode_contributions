class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

       int n = nums1.size();
       int m = nums2.size();

       vector<int>res;

       stack<int>stk;

       unordered_map<int,int>mp;

       for(int i=m-1;i>=0;i--){

        while(!stk.empty() && stk.top() <= nums2[i])
        {
            stk.pop();
        }

        if(stk.empty()){
            mp[nums2[i]] = -1;
        }
        else
        {
            mp[nums2[i]] = stk.top();
        }

        stk.push(nums2[i]);
       }


       for(int i:nums1){
        res.push_back(mp[i]);
       }


       return res;
    }
};