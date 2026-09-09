class Solution {
public:
    bool wordPattern(string pattern, string s) {
        

        unordered_map<char,string> charTostring;
        unordered_map<string,char> stringTochar;

        vector<string> words;
        stringstream iss(s);

        string word;
        while(iss >> word){
            words.push_back(word);
        }

        if(pattern.length() != words.size()){
            return false;
        }


        for(int i=0;i<pattern.length();i++){
            string str = words[i];
            char c = pattern[i];

            if(charTostring.count(c) == 0){
                charTostring[c]=str;
            }
            else{
                if(charTostring[c] != str){
                    return false;
                }
            }

             if(stringTochar.count(str) == 0){
                stringTochar[str]=c;
            }
            else{
                if(stringTochar[str] != c){
                    return false;
                }
            }
         }
         return true;


    }
};