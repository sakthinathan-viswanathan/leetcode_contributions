class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {


        int n = heights.size();

        stack<int>stk;
        heights.push_back(0);

        int max_len = 0;

        for(int i=0;i<=n;i++){

            while(!stk.empty() && heights[i] < heights[stk.top()]){

                int h = heights[stk.top()];
                stk.pop();

                int w = stk.empty()?i:i-stk.top()-1;

                max_len = max(max_len,w * h);
            }

            stk.push(i);
        }

        return max_len;


    }
};