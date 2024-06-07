class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isTerminal;

    TrieNode() : isTerminal(false) {}
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }
    
    void insert(const string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->isTerminal = true;
    }
    
    string getShortestPrefix(const string& word) {
        TrieNode* current = root;
        string prefix = "";
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                break;
            }
            prefix += ch;
            current = current->children[ch];
            if (current->isTerminal) {
                return prefix;
            }
        }
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for (const string& root : dictionary) {
            trie.insert(root);
        }
        
        istringstream iss(sentence);
        string word;
        string result = "";
        bool first = true;

        while (iss >> word) {
            if (!first) {
                result += " ";
            }
            result += trie.getShortestPrefix(word);
            first = false;
        }
        
        return result;
    }
};
