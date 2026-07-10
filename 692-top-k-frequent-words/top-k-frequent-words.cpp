class Solution {
public:
    struct Compare {
        bool operator()(pair<int, string> &a, pair<int, string> &b) {
            if (a.first == b.first){
                cout<<"a.second "<<a.second<<" b.second "<<b.second<<endl;
                return a.second < b.second;

            }
                
            cout<<"a.first "<<a.first<<" b.first "<<b.first<<endl;                         
                                            
            return a.first > b.first;      
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> mp;

        for (string &s : words)
            mp[s]++;

        priority_queue<
            pair<int, string>,
            vector<pair<int, string>>,
            Compare
        > pq;

        for (auto &i : mp) {
            pq.push({i.second, i.first});

            if (pq.size() > k)
                pq.pop();
        }

        vector<string> res;

        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};