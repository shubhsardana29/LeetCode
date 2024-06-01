class Solution {
public:
    int scoreOfString(string s) {
        int i=0;
        int j;
        int sum=0;
        while(j!=s.size()){
            j=i+1;
            int diff= abs(s[j]-s[i]);
            sum+=diff;
            i++;
            j++;
        }
        return sum;
    }
};