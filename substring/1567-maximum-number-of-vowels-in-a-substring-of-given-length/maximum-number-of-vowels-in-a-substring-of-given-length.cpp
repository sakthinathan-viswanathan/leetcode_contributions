class Solution {
public:

    bool isVowel(char ch){

    return ch=='a' ||
           ch=='e' ||
           ch=='i' ||
           ch=='o' ||
           ch=='u';
    }

    int maxVowels(string s, int k) {

        int n = s.length();

        int ans = 0;
        int count = 0;

        int left = 0;
        for(int right=0;right<n;right++){

            if(isVowel(s[right])){
                count++;
            }

            if((right-left+1) == k){

                ans = max(count,ans);

                if(isVowel(s[left])){
                    count--;
                }
                left++;
            }
        }

        return ans;
        
    }
};