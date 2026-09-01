#include <iostream>

using namespace std;

struct TrieNode {
  TrieNode *children[26];
  bool isEnd;

  TrieNode() {
    for (int i = 0; i < 26; i++) {
      this->children[i] = nullptr;
    }
    this->isEnd = false;
  }

  // add key and value key is ch and value is node
  void put(char &ch, TrieNode *node) {
    if (this->children[ch - 'a'] == nullptr) {
      this->children[ch - 'a'] = node;
    }
  }
  // check for non null node presence
  bool contains(char &ch) {
    return (this->children[ch - 'a'] != nullptr);
  }
};

class Trie {
private:
  TrieNode *root;

public:
  Trie() {
    this->root = new TrieNode();
  }

  void insert(string word) {
    TrieNode *node = this->root;
    for (char &ch : word) {
      if (!node->contains(ch)) {
        node->put(ch, new TrieNode());
      }
      node = node->children[ch - 'a'];
    }
    node->isEnd = true;
  }

  bool searchWord(string word) {
    TrieNode *node = this->root;
    for (char &ch : word) {
      if (!node->contains(ch)) {
        return false;
      }
      node = node->children[ch - 'a'];
    }
    return node->isEnd;
  }

  bool searchPrefix(string prefix) {
    TrieNode *node = this->root;
    for (char &ch : prefix) {
      if (!node->contains(ch)) {
        return false;
      }
      node = node->children[ch - 'a'];
    }
    return true;
  }
};

int main() {
  Trie trie;

  trie.insert("apple");
  trie.insert("app");
  trie.insert("bat");
  trie.insert("ball");

  cout << boolalpha;

  cout << "searchWord(\"apple\"): " << trie.searchWord("apple") << endl; // true

  cout << "searchWord(\"app\"): " << trie.searchWord("app") << endl; // true

  cout << "searchWord(\"ap\"): " << trie.searchWord("ap") << endl; // false

  cout << "searchWord(\"apply\"): " << trie.searchWord("apply") << endl; // false

  cout << "searchWord(\"bat\"): " << trie.searchWord("bat") << endl; // true

  cout << "searchWord(\"ball\"): " << trie.searchWord("ball") << endl; // true

  cout << "searchWord(\"ba\"): " << trie.searchWord("ba") << endl; // false

  cout << "\n--- Prefix tests ---\n";

  cout << "searchPrefix(\"ap\"): " << trie.searchPrefix("ap") << endl; // true

  cout << "searchPrefix(\"app\"): " << trie.searchPrefix("app") << endl; // true

  cout << "searchPrefix(\"apple\"): " << trie.searchPrefix("apple") << endl; // true

  cout << "searchPrefix(\"bat\"): " << trie.searchPrefix("bat") << endl; // true

  cout << "searchPrefix(\"ba\"): " << trie.searchPrefix("ba") << endl; // true

  cout << "searchPrefix(\"cat\"): " << trie.searchPrefix("cat") << endl; // false

  return 0;
}