class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        std::unordered_map<int, int> fmap;
        int n = nums.size();
        int operations = 0;

        for (int i = 0; i < n; ++i) {
            fmap[nums[i]]++;
        }

        for (const auto& it : fmap) {
            int freq = it.second;
            if(freq==1) return -1;
            // check if the frequency is divisible by 3.
            
            //If true: freq / 3: If the frequency is divisible by 3, then the number of operations is equal to the frequency divided by 3.

            // If false: freq / 3 + 1: If the frequency is not divisible by 3, then the number of operations is equal to the frequency divided by 3 plus 1. This additional operation is needed to account for the remaining elements that cannot form a group of three.
            operations += (freq % 3 == 0) ? freq / 3 : freq / 3 + 1;
        }

        return operations;
    }
};
