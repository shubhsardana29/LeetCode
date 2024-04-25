class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int>freq(26,0); 
        for(int i=s.size()-1;i>=0;i--){
            int curr = s[i]-'a' ; 
            int maxi = 0 ; 
            for(int j=curr;j<=k+curr && j<26;j++){
                maxi = max(maxi,freq[j]); 
            }
            for(int j = curr-1;j>=curr-k && j>=0;j--){
                maxi = max(maxi,freq[j]) ; 
            }
            freq[curr] = maxi+1; 
        }
        int ans = freq[0] ; 
        for(int i=0;i<26;i++){
            ans = max(freq[i],ans) ; 
        }
        return ans ; 
    }
};