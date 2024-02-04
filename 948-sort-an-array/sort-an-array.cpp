class Solution {
public:
    void heapify(vector<int>& nums, int n, int index) {
        int leftIndex = 2 * index + 1; // 0-based indexing correction
        int rightIndex = 2 * index + 2; // 0-based indexing correction
        int largestKaIndex = index;

        // Compare with the values at leftIndex and rightIndex,
        if (leftIndex < n && nums[leftIndex] > nums[largestKaIndex])
            largestKaIndex = leftIndex;
        if (rightIndex < n && nums[rightIndex] > nums[largestKaIndex])
            largestKaIndex = rightIndex;

        if (index != largestKaIndex) {
            swap(nums[index], nums[largestKaIndex]);
            index = largestKaIndex;
            heapify(nums, n, index);
        }
    }

    void heapsort(vector<int>& nums, int n) {
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(nums, n, i);
        }
        
        // for (int i = n - 1; i > 0; i--) {
        //     swap(nums[0], nums[i]);
        //     heapify(nums, i, 0);
        // }
        while(n>0){
            swap(nums[0],nums[n-1]);
            n--;
            heapify(nums,n,0);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(nums, n, i);
        }

        heapsort(nums, n);

        return nums;
    }
};
