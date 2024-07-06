class Solution {
public:
    int passThePillow(int n, int time) {
        int cycle = 2*(n - 1);
        int val = time % cycle;
        return val <= n-1 ? val + 1 : (cycle - val + 1);
    }
};