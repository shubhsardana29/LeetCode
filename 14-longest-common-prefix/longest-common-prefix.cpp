class TrieNode{
public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char val){
        this->data = val;
        for(int i=0; i<26; i++){
            children[i]=NULL;
        }
        this->isTerminal=false;
        this->childCount=0;
    }
};
class Solution {
public:
    void insertionHelper(TrieNode* root, string word){
        if(word.size()==0){
            root->isTerminal=true;
            return ;
        }
        char ch=word[0];
        int idx= ch-'a';
        TrieNode *child=NULL;
        if(root->children[idx]==NULL){
            //absent
            child = new TrieNode(word[0]);
            root->children[idx]=child;
            root->childCount++;
        }
        else{
            //present
            child= root->children[idx];
        }
        insertionHelper(child, word.substr(1));


    }
    void findLCP(string& ans,TrieNode* root){
        //base case
        if(root->isTerminal==true) return;
        
        
        TrieNode* child;
        if(root->childCount==1){
            for (int i = 0; i < 26; ++i) {
                if (root->children[i] != NULL) {
                    child = root->children[i];
                    break;  // exit the loop once a non-null child is found
                }
            }
            //ans m store krwa do
            ans.push_back(child->data);
            
        }
        else{
            return;
        }
        //baaki recursion se
        findLCP(ans,child);

    }
    string longestCommonPrefix(vector<string>& strs) {
        // make trie
        TrieNode* root = new TrieNode('-');
        //insert all char of string in trie
        for(auto str:strs){
            insertionHelper(root,str);
        }
        string ans;
        findLCP(ans,root);
        return ans;
    }
};