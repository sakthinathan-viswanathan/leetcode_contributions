class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.length()!=t.length()){
            return false;
        }

        string ss = s;
        transform(ss.begin(), ss.end(), ss.begin(), ::tolower);

        string st = t;
        transform(st.begin(), st.end(), st.begin(), ::tolower);

        unordered_map<char,int>mp;

        for(char c:s){
            mp[c]++;
        }

        for(int i=0;i<t.size();i++){

            if(mp.find(t[i]) != mp.end()){
                mp[t[i]]--;

                if(mp[t[i]] == 0){
                    mp.erase(t[i]);
                }
            }
            else
            {
                return false;
            }

        }


        return true;
    }
};