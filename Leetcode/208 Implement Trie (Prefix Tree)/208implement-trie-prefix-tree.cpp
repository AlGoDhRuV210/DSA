struct Node {
    Node* links[26] = {nullptr};
    bool flag = false;
    

    bool containskey(int c) { return (links[c] != nullptr); }

    void put(int c) { links[c] = new Node; }
};
class Trie {
private:
    Node* root;

public:
    Trie() { root = new Node(); }

    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containskey(word[i] - 'a')) {
                node->put(word[i] - 'a');
            }
            node = node->links[word[i] - 'a'];
        }
        node->flag = true;
    }

    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containskey(word[i] - 'a')) {
                return false;
            }
            node = node->links[word[i] - 'a'];
        }
        return node->flag;
    }

    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (!node->containskey(prefix[i] - 'a')) {
                return false;
            }
            node = node->links[prefix[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */