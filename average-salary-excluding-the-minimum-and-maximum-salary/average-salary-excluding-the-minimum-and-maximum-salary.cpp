class Solution {
public:
    double average(vector<int>& salary) {
       int minSalary = INT_MAX;
    int maxSalary = INT_MIN;
    int sum = 0;
    int n= salary.size();

    for (int salary : salary) {
        sum += salary;
        minSalary = min(minSalary, salary);
        maxSalary = max(maxSalary, salary);
    }

    return (sum - minSalary - maxSalary) / static_cast<double>(n - 2);
    }
};