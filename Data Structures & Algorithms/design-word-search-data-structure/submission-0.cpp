class WordDictionary {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;
        
        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };
    
    TrieNode* root;
    
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        
        node->isEnd = true;
    }
    
    bool search(string word) {
        return searchHelper(word, 0, root);
    }
    
private:
    bool searchHelper(string& word, int index, TrieNode* node) {
        // Base case: processed all characters
        if (index == word.length()) {
            return node->isEnd;
        }
        
        char c = word[index];
        
        // Case 1: Current character is a dot
        if (c == '.') {
            // Try ALL 26 letters
            for (int i = 0; i < 26; i++) {
                if (node->children[i] && 
                    searchHelper(word, index + 1, node->children[i])) {
                    return true;
                }
            }
            return false;  // No path found
        }
        
        // Case 2: Current character is a letter
        else {
            int idx = c - 'a';
            if (!node->children[idx]) {
                return false;
            }
            return searchHelper(word, index + 1, node->children[idx]);
        }
    }
};