class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (valToIndex.count(val)) {
            return false; // Value already exists
        }

        nums.push_back(val);
        valToIndex[val] = nums.size() - 1; // Update index mapping
        return true;
    }
    
    bool remove(int val) {
        if (!valToIndex.count(val)) {
            return false; // Value not found
        }

        int index = valToIndex[val];
        int lastVal = nums.back();

        // Swap the value to be removed with the last value
        nums[index] = lastVal;
        valToIndex[lastVal] = index; // Update index mapping for swapped value

        nums.pop_back(); // Remove the last element (which is now the value to be removed)
        valToIndex.erase(val);

        return true;
    }
    
    int getRandom() {
        // Use a uniform distribution to generate a random index within nums
        uniform_int_distribution<int> dist(0, nums.size() - 1);
        int randomIndex = dist(rng);
        return nums[randomIndex];
    }

    private:
    vector<int> nums;          // Stores the elements
    unordered_map<int, int> valToIndex; // Maps values to their indices for quick removal
    mt19937 rng;              // Random number generator for getRandom()
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */