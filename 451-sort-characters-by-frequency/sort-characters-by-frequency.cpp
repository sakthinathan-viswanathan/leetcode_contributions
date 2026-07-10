class Solution {
public:
    struct compare{
        bool operator()(pair<int,char> &a,pair<int,char> &b)
        const{

            if(a.first == b.first){
                return a.second > b.second;
            }

            return a.first < b.first;
        }
    };
    string frequencySort(string s) {

        int n = s.size();

        unordered_map<char,int>mp;

        for(char c:s){
            mp[c]++;
        }


        priority_queue<
        pair<int,char>,
        vector<pair<int,char>>,
        compare>min_pq;


        for(auto& i:mp){
            min_pq.push({i.second,i.first});
        }

        string res = "";

        while(!min_pq.empty()) {

            auto [freq, ch] = min_pq.top();
            min_pq.pop();

            res.append(freq, ch);
        }

        return res;
    }
};