class Solution {
public:
// method 1: using hash
    string methodUsingHash(string s){
        int count[26]={0};

        for(int i=0;i<s.size();i++){
            count[s[i]-'a']++;
        }

        // find the most freq occuring char
        char most_freq_char;
        int max_freq=INT_MIN;
        for(int i=0;i<26;i++){
            if(count[i]>max_freq) max_freq=count[i], most_freq_char = i+'a';
        }

        // placing most freq char in one go
        int index=0;
        while(max_freq>0 && index<s.size()){
            s[index]= most_freq_char;
            max_freq--; 
            index+=2;
        }

        // if all the elements of most occuring char were not able to place
        if(max_freq!=0){
            return "";
        }

        // if max freq ==0
        count[most_freq_char-'a']=0; 

        // place other remaining characters
        for(int i=0;i<26;i++){
             while(count[i]--){
                index=index >= s.size() ? 1 : index; 
                s[index]=i+'a';
                index+=2;
             }
        }
        return s;
    }
    string reorganizeString(string s) {
        return methodUsingHash(s);
    }
};