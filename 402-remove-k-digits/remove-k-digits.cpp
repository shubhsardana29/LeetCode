class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n=num.size();
        for(int i=0;i<n;i++)
        {
            while(!st.empty() and st.top()-'0'>num[i]-'0' and k>0)
            {
                 st.pop();
                 k--;
            }
            st.push(num[i]);
        }
        while(k-- and !st.empty())
        st.pop();
        string s="";
        while(!st.empty())
        {
            s.push_back(st.top());
            st.pop();
        }
        reverse(s.begin(),s.end());
        int j=0;
        while(s[j]=='0' and s.size()>1)
        {
            j++;
        }
        if(j!=0 and j<s.size())
            return s.substr(j);
        if(j==s.size())
            return "0";
        if(s=="")
            return "0";
        return s;
    }
};