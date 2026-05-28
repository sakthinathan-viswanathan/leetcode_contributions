class Solution {
public:
    string largestEven(string s) {

        int n = s.length();

        while(!s.empty()){
            
            char c = s.back();

            if((c-'0') % 2 == 0){
                return s;
            }

            s.pop_back();
        }      

        return "";
    }
};