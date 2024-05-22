class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        if(s.empty()) return ans;

        vector<string>tempAns;
        solve(0,s,tempAns,ans);
        return ans;
    }
    void solve(int index,string& s,vector<string>&tempAns,vector<vector<string>>&ans){
        if(index==s.size()){
            ans.push_back(tempAns);
            return;
        }
        for(int end=index;end<s.size();end++){
            if(isPalindrome(s,index,end)){
                tempAns.push_back(s.substr(index,end-index+1));
                solve(end+1,s,tempAns,ans);
                tempAns.pop_back();
            }
        }
    }
    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};