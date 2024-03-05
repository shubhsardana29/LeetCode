class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        int left= 0;
        int right = n-1;
        
        while(left < right && s[left]==s[right]){
            char ch = s[left];
            while(left <= right && s[left]==ch){
                left++;
            }
            while(left<=right && s[right]==ch){
                right--;
            }
        }
        return right-left+1;
    }
};