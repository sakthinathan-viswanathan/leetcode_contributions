class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        
        vector<string>res;
        vector<string>cur;

        backtrack(0,res,cur,s);

        return res;
    }

    void backtrack(int start,vector<string> &res,vector<string> &cur,string &s){

        if(cur.size() == 4){

            if(start == s.size())
                res.push_back(cur[0]+'.'+cur[1]+'.'+cur[2]+'.'+cur[3]);
            return ;
        }


        for(int len = 1;len <= 3;len++){
            
            if(start + len > s.size()) 
            break;

            string part = s.substr(start,len); 

            if(part.size() > 1 && part[0] == '0'){
                break;
            }


            if(stoi(part) > 255){
                continue;
            }

            cur.push_back(part);

            backtrack(start+len,res,cur,s);

            cur.pop_back();
            
        }
    }
};