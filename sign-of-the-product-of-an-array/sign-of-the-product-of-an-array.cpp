class Solution {
public:
    int arraySign(vector<int>& nums) {
        int countNegNo = 0;
        for (int num : nums) {
            if (num == 0) {
                return 0;
            }
            if (num < 0) {
                countNegNo++;
            }
        }
        if(countNegNo % 2==0){
            return 1;
        }
    return -1;
    }
};