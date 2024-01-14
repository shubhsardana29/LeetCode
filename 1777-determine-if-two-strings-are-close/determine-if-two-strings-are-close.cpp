class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if (n!=m) return false;

        //operations
        vector<int> freq1(26);
        vector<int> freq2(26);
       for(int i=0;i<n;i++){
            freq1[word1[i]-97]++;
        }
        for(int i=0;i<m;i++){
            freq2[word2[i]-97]++;
        }
        for(int i=0;i<26;i++){
            if ((freq1[i] && !freq2[i]) || (freq2[i] && !freq1[i])) return false; 
        }
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        for (int i = 0; i < 26; i++)
        if (freq1[i] != freq2[i])
            return false;
     

    return true;



        

        
    }
};