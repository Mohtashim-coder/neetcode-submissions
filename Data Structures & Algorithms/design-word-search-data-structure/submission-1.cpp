class WordDictionary {

private:
    struct TrieNode
    {
        TrieNode* children[26];
        bool isEnd;

        TrieNode()
        {
            isEnd = false;
            for(int i=0; i<26; i++)
            {
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

        for(char c : word)
        {
            int index = c - 'a';
            if(!node->children[index])
            {
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
    bool searchHelper(string &word, int index, TrieNode* node)
    {
        if(index == word.size())
        {
            return node->isEnd;
        }

        char c = word[index];

        // case 1: Dot - try all 26 cases
        if(c == '.')
        {
            for(int i=0; i<26; i++)
            {
                if(node->children[i] && searchHelper(word, index + 1, node->children[i]))
                {
                    return true;
                }
            }
            return false;
        }

        // case 2: Regular letter
        int idx = c - 'a';
        if(!node->children[idx])
        {
            return false;
        }

        return searchHelper(word, index + 1, node->children[idx]);
    }
};
