/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

struct Node{
    Node* links[26];
    bool flag=false;
    bool keyExists(char ch)
    {
        if(links[ch-'a']!=NULL)
        return true;
        return false;
    }
    void put( char ch, Node* node)
    {
        links[ch-'a']=node;
    }
    Node* getKey(char ch)
    {
        return links[ch-'a'];
    }

};

class Trie {
    private:
    Node* root;

public:

    /** Initialize your data structure here. */
    Trie() {
        root=new Node();

    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->keyExists(word[i]))
            {
                node->put(word[i],new Node());
            }
            node=node->getKey(word[i]);
        }
        node->flag=true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* node=root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->keyExists(word[i]))
            {
                return false;
            }
            node=node->getKey(word[i]);
        }
        if(node->flag==true) return true;
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        Node* node=root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->keyExists(word[i]))
            {
                return false;
            }
            node=node->getKey(word[i]);
        }
        return true;
        // return false;
    }
};