class Solution {
    // Time: O(N), Space: O(1)
public:
    int climbStairs(int n) {
        // compute the result of the fibonacci sequence for the number of stairs
        return fib(n);
    }

    int fib(int n){
        int first = 0; 
        int second = 1;
        int sum;
        if(n==0) return first;
        for(int i = 1; i <= n; i++){
            sum = first + second;
            first = second;
            second = sum;
        }
        return sum;
    }
};