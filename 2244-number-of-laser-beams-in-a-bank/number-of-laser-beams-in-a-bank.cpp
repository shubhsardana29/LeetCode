class Solution {
private:
    int countOnes(const std::string& str) {
        return std::count(str.begin(), str.end(), '1');
    }

public:
    int numberOfBeams(vector<string>& bank) {
        int totalBeams = 0;
        int previousOnesCount = 0;

        for (const auto& str : bank) {
            int onesCount = countOnes(str);

            if (onesCount > 0) {
                totalBeams += previousOnesCount * onesCount;
                previousOnesCount = onesCount;
            }
        }

        return totalBeams;

    }
};