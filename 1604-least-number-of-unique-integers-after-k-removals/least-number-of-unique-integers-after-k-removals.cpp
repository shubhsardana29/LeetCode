class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int>freq;
        for(auto i:arr){
            freq[i]++;
        }
        int n = freq.size();
        vector<int>unique;
        for(auto [key,val]:freq){
            unique.push_back(val);
        }
        sort(unique.begin(),unique.end());
        for(auto j:unique){
            k=k-j;
            if (k < 0) break;
            n--;
        }
         return n;
    }
};