class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long ans = 0;
        vector<int> a(1024);
        a[0] = 1;
        int cur = 0;
        for(int i=0; i<word.size(); i++) {
            cur ^= (1<<(word[i]-'a'));
            ans += a[cur];
            for(int j=0; j<10; j++) {
                ans += a[cur ^ (1<<j)];
            }
            a[cur]++;
        }
        return ans;
    }
};