class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while (left < right) {
            right &= (right - 1); // Set the rightmost 1 bit to 0
        }
        return right;
    }
};
