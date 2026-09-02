class Solution {
public:
    int longest_rectangle(vector<int> &heights){

        
        heights.push_back(0);

        stack<int>stk;

        int max_area = 0;


        for(int i=0;i<heights.size();i++){

            while(!stk.empty() && heights[stk.top()] > heights[i]){

                int height = heights[stk.top()];
                stk.pop();

                int width = stk.empty()?i:i-stk.top()-1;
                max_area = max(max_area,height * width);
            }

            stk.push(i);
        }

        return max_area;

    }
    int maximalRectangle(vector<vector<char>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();


        vector<int>heights(m,0);

        int max_area = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(matrix[i][j] == '1'){
                    heights[j] += 1;
                }
                else
                {
                   heights[j] = 0 ;
                }
            }

            max_area = max(max_area,longest_rectangle(heights));
        }

        return max_area;
        
    }
};