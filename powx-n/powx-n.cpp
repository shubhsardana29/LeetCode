class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) {
            return 0;
        }
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return x;
        }
        if (n == -1) {
            return 1 / x;
        }
        double smallPowerAns = myPow(x, n / 2);
        if (!(n & 1)) {
            return smallPowerAns * smallPowerAns;
        } else {
            if (n > 0) {
                return x * smallPowerAns * smallPowerAns;
            } else {
                return (1 / x) * smallPowerAns * smallPowerAns;
            }
        }
    }
};

