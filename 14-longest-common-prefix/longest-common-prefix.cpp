class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string first = strs[0];
        int n = strs.size();
        string last = strs[n-1];
        int i=0;
        while(i<first.length() && i<last.length() && first[i]==last[i]){
            i++;
        }
        string prefix = first.substr(0,i);
        return (!prefix.empty() ? prefix : ""); 
    }
};