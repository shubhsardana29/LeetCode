class Solution {
public:

    void removeOccuRecursive(string&s, string&part){
        int pos = s.find(part);
        if(pos!=string::npos){
            string left= s.substr(0,pos);
            string right= s.substr(pos+part.size(),s.size());
            s= left+right;

            removeOccuRecursive(s,part);
        }
        else{
            // base case
            return;
        }
    }
    string removeOccuIterative(string&s, string&part){
        int pos = s.find(part);
        while(pos!=string::npos){
            s.erase(pos,part.size());
            pos = s.find(part);
        }
        return s;
    }
    string removeOccurrences(string s, string part) {
        //string ans=removeOccuIterative(s,part);
        removeOccuRecursive(s,part);
        return s;
    }
};