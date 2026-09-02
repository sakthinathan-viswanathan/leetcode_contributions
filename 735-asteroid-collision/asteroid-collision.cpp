class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        int n = asteroids.size();

        vector<int>res;

        stack<int>stk;

        for(int i=0;i<n;i++){

            if(asteroids[i] > 0)
            {
                stk.push(asteroids[i]);
            }
            else{

                bool destroid = false;

                while(!stk.empty() && stk.top() > 0)
                {

                    if(stk.top() < -asteroids[i]){
                       stk.pop();
                    }
                    else if(stk.top() == -asteroids[i]){
                        stk.pop();
                        destroid = true;
                        break;
                    }
                    else
                    {
                        destroid = true;
                        break;
                    }
                  
                }

                if(!destroid){
                    stk.push(asteroids[i]);
                }
            }
            
        }


        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }

        reverse(res.begin(),res.end());

        return res;
    }
};