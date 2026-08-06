class Solution {
public:
    vector<vector<string>> partition(string s) {

        vector<string>cur;

        vector<vector<string>>res;

        backtrack(0,cur,res,s);
        
        return res;
    }

    void backtrack(int start,vector<string> &cur,vector<vector<string>> &res,string s){


        if(start == s.size()){
            res.push_back(cur);
            return ;
        }

        for(int i=start;i<s.size();i++){

            string part = s.substr(start,i-start+1);

            if(!isPalindrome(part)){
                continue;
            }

            cur.push_back(part);

            backtrack(i+1,cur,res,s);

            cur.pop_back();
        }
        
    }


    bool isPalindrome(string str){

        int l = 0;
        int r = str.size()-1;


        while(l < r){
            if(str[l] == str[r]){
                l++;
                r--;
            }
            else
            {
                return false;
            }
        }


        return true;
    }
};