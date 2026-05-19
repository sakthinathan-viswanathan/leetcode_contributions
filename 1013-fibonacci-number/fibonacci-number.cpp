class Solution {
public:
    int recursion(int n){

        if(n <= 1){
            return n;
        }

        return recursion(n-1) + recursion(n-2);
    }
    int fib(int n) {

      return recursion(n);
        
    }
};