class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>ans;
       for (int i = 0; i < nums.size(); ++i) {
           nums[i]=nums[i]*nums[i];
       } 
       radixSort(nums);
       return nums;
    }
    void radixSort(vector<int>& arr) {
        int max = getMax(arr);

        for (int exp = 1; max / exp > 0; exp *= 10) {
            countSort(arr, exp);
        }
    }
    int getMax(vector<int>& arr) {
        int maxi = INT_MIN;
        for (int i = 0; i < arr.size(); i++) {
           maxi=max(arr[i],maxi);
        }
        return maxi;
    }
    void countSort(vector<int>& arr, int exp) {
        vector<int> output(arr.size());
        vector<int> count(10, 0);

        for (int i = 0; i < arr.size(); i++) {
            count[(arr[i] / exp) % 10]++;
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for (int i = arr.size() - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (int i = 0; i < arr.size(); i++) {
            arr[i] = output[i];
        }
    }
};