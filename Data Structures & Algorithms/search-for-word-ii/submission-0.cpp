class Solution {
private:
    struct TrieNode
    {
        TrieNode* children[26];
        string word;

        TrieNode()
        {
            word = "";
            for(int i=0; i<26; i++)
            {
                children[i] = nullptr;
            }
        }
    };
    TrieNode* root;
    vector<string> result;

    void insertword(string word)
    {
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
        node->word = word;
    }

    void dfs(vector<vector<char>> &board, int i, int j, TrieNode* node)
    {
        // check boundries
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
        {
            return;
        }

        char c = board[i][j];
        int index = c - 'a';

        // if cell is visited and not matching child
        if(c == '#' || !node->children[index])
        {
            return;
        }
        
        // move to child node
        node = node->children[index];

        // if we found a word
        if(node->word != "")
        {
            result.push_back(node->word);
            node->word = "";
        }

        // mark as visited
        board[i][j] = '#';

        // explore all four direction
        dfs(board, i+1, j, node);
        dfs(board, i-1, j, node);
        dfs(board, i, j+1, node);
        dfs(board, i, j-1, node);

        // Backtrack: unmark
        board[i][j] = c;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        root = new TrieNode();
        int m = board.size();
        int n = board[0].size();

        for(string word : words)
        {
            insertword(word);
        }

        // start DFS from each cell
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                dfs(board, i, j, root);
            }
        }
        return result;
    }
};
