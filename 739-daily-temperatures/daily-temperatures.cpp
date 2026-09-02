class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();

        stack<int>stk;

        vector<int>res(n,0);

        for(int i=0;i<n;i++){

            while(!stk.empty() && temperatures[stk.top()] < temperatures[i]){

                int ind = stk.top();
                stk.pop();

                res[ind] = i - ind;
            }

            stk.push(i);
        }

        return res;
        
    }
};