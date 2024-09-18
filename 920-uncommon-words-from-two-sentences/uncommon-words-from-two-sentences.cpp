class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string s = s1 + " " + s2;
        stringstream str(s);
        unordered_map<string,int> mp;
        string res;
        while(str>>res){
            mp[res]++;
        }

        vector<string> ans;
        for(auto& it:mp){ 
            if(it.second==1){
                ans.push_back(it.first);       
            }
        }

        return ans;
    }
};