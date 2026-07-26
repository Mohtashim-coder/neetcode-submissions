class PrefixTree {
private:
    struct TrieNode{
        unordered_map<char, TrieNode*> children; // 26 lower case letters
        bool isEnd;             // mark end of a word

        TrieNode()
        {
            isEnd = false;
            // for(int i=0; i<26; i++)
            // {
            //     children[i] = nullptr;
            // }
        }
    }; 

    TrieNode* root;

public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;

        for(char c : word)
        {
            int index = c - 'a';

            // if child does'nt exist create it
            if(!node->children[index])
            {
                node->children[index] = new TrieNode();
            }

            // Move to child
            node = node->children[index];
        }
        // Mark end of word
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        
        for(char c : word)
        {
            int index = c - 'a';
            
            // if child does'nt exist word not found
            if(!node->children[index])
            {
                return false;
            }

            node = node->children[index];
        }
        // word exist only if it's marked as end
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode *node = root;

        for(char c : prefix)
        {
            int index = c - 'a';
            // if child does'nt exist, no word with this prefix
            if(!node->children[index])
            {
                return false;
            }

            node = node->children[index];
        }

        // Reached the end of prefix -> it exists
        return true;
    }
};
