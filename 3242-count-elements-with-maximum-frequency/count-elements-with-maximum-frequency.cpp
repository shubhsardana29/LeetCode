class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>freq;
        int maxFreq = 0;
        for(auto i:nums){
            freq[i]++;
            maxFreq=max(maxFreq,freq[i]);
        }
        int maxFreqEleCnt = 0;
        for (auto entry : freq) {
            int currEleFreq = entry.second;
            if (currEleFreq == maxFreq) {
                maxFreqEleCnt++;
            }
        }
        return maxFreq * maxFreqEleCnt;
    }
};