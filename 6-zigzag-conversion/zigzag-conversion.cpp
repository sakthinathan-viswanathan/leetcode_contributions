class Solution {
public:
    string convert(string s, int numRows) {

      if(numRows==1 || s.size()<=numRows){
        return s;
      }


      vector<string>ans(min(numRows,int( s.size())));

      int currRow=0;
      bool rowReachedEnd=false;

      for(char c:s){
        ans[currRow]+=c;

        if(currRow==0 || currRow==numRows-1 ){
            rowReachedEnd=!rowReachedEnd;
        }

        currRow += rowReachedEnd?1:-1;


      }
        string res="";
        for(string word: ans){
            res+=word;
        }
        return res;
    }
};