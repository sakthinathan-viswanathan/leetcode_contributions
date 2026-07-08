class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();

        unordered_map<char,int>freq;

        for(int c:s){
            freq[c]++;
        }

        vector<vector<char>>bucket(n+1);

        for(auto &i:freq){
            bucket[i.second].push_back(i.first);
        }

        string ans = "";

        for(int i=bucket.size()-1;i>=0;i--){
            for(char num:bucket[i]){

               ans.append(i,num);
            }
        }

        return ans;
    }

};