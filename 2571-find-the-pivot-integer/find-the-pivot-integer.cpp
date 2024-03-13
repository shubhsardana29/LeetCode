class Solution {
public:
    int pivotInteger(int n) {
        if (n == 1)
            return 1;
        int sum = (n + 1) * n / 2;
        int pivot = sqrt(sum);  
        if (pivot * pivot == sum)
            return pivot;
        else
            return -1;  
    }
};
