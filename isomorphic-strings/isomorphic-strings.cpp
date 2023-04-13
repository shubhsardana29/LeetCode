class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        int arr1[200] = {};
        int arr2[200] = {};

        for (int i = 0;i<s.size();i++){
            char n1 = s[i];
            char n2 = t[i];

            if(arr1[n1]!=arr2[n2]){
                return false;
            }
            arr1[n1] = i+1;
            arr2[n2] = i+1;
        }
        return true;
    }
};