class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int wordsize = words[0].size();
        int arrlen = words.size();
        int windowsize = wordsize*arrlen;
        int  strlen = s.length();

        unordered_map<string,int> freqMap;
        


        for(string str:words){
            freqMap[str]++;
        }

        for(int i=0 ;i<wordsize;i++){

            int count=0;
            int left=i;
            unordered_map<string,int> seen;

            for(int j=i;j <= strlen-wordsize;j+=wordsize){

                string word = s.substr(j,wordsize);

                if(freqMap.find(word) != freqMap.end()){
                seen[word]++;
                count++;

                while(seen[word] > freqMap[word]){
                    string leftword = s.substr(left,wordsize);
                    seen[leftword]--;
                    left += wordsize;
                    count--;
                }

                if(count == arrlen){
                    result.push_back(left);
                    string leftword = s.substr(left,wordsize);
                    seen[leftword]--;
                    left += wordsize;
                    count--;
                }

                    
                }
                else{
                    count=0;
                    seen.clear();
                    left = j + wordsize;
                }
            }


        }

        return result;
        
    }
};