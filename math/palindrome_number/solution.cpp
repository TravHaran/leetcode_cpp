class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        long div = 1;
        // get the most significant divisor that is still less than or equal to x
        while(x >= 10*div){
            div *= 10;
        }
        int right;
        int left;
        while(x > 0){
            right = x % 10; // get rightmost digit
            left = x / div; // get leftmost digit
            if(left != right) return false;
            //remove left
            x %= div;
            //remove right
            x /= 10;
            //update divisor by chopping off two digits
            div /= 100; 
        }
        return true;
    }
};