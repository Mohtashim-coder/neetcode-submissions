class LRUCache {

private:
    // Doubly Linked List Node
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> cache;  // key->Node pointer

    Node* head; // most recently used
    Node* tail; // least recently used

    // Helper: remove node from linked list
    void removeNode(Node* node)
    {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Helper: Add node right after head (most recent)
    void addToFront(Node* node)
    {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    // Helper: Move existing node to front
    void moveToFront(Node* node)
    {
        removeNode(node);
        addToFront(node);
    }

    // Helper: remove least recently used node
    void removeLRU()
    {
        Node* lru = tail->prev;
        removeNode(lru);
        cache.erase(lru->key);
        delete lru;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);   // Dummy head
        tail = new Node(-1, -1);   // Dummy tail
        head->next = tail;
        tail->prev = head;

    }
    
    int get(int key) {
        if(cache.find(key) == cache.end())
        {
            return -1;
        }
        Node* node = cache[key];
        moveToFront(node);  // Mark as recently used
        return node->value;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end())
        {
            // key exists: update value and move to front
            Node* node = cache[key];
            node->value = value;
            moveToFront(node);
        }

        else{
            // Key doesn't exist create new node
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addToFront(newNode);

            // if cache exceeds capacity, remove lru
            if(cache.size() > capacity)
            {
                removeLRU();
            }
        }
    }
};
