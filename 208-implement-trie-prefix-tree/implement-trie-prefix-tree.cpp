struct Node{
    Node *links[26];
    bool isEnd = false;
    Node(){
        for(int i=0;i<26;i++) links[i] = NULL;
        isEnd = false;
    }
};

Node *root;

class Trie {
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for(auto ch: word){
            if(curr->links[ch-'a'] == NULL){
                curr->links[ch-'a'] = new Node();
            }
            curr = curr->links[ch-'a'];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        Node * curr = root;
        for(auto ch: word){
            if(curr->links[ch-'a']==NULL) return false;
            curr = curr->links[ch-'a'];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node * curr = root;
        for(auto ch: prefix){
            if(curr->links[ch-'a']==NULL) return false;
            curr = curr->links[ch-'a'];
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