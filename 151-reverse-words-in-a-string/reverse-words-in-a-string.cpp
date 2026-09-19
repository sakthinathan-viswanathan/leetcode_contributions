class Solution {
public:
    string reverseWords(string s) {

        string current = "";

        vector<string> words;

        for (char c : s) {
            if (c == ' ') {

                if(!current.empty()){

                words.push_back(current);
                current.clear();

                }

            } else {
                current += c;
            }
        }

        if (!current.empty()) {
            words.push_back(current);
        }

        string res = "";
        if(words.empty()){

            return res;
        }

        for (int i = words.size() - 1; i >= 0; i--) {
            res += words[i];

            if (i > 0) {
                res += " ";
            }
        }

        return res;
    }
};