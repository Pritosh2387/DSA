#include<bits/stdc++.h>
using namespace std;
struct Node {
    Node* links[26] = {nullptr};
    bool flag = false;
    ~Node() {
        for (int i = 0; i < 26; i++) {
            delete links[i];
        }
    }
};
class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    ~Trie() {
        delete root;
    }
    void insert(string word) {
        Node* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (node->links[idx] == nullptr)
                node->links[idx] = new Node();
            node = node->links[idx];
        }
        node->flag = true;
    }
    bool search(string word) {
        Node* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (node->links[idx] == nullptr)
                return false;
            node = node->links[idx];
        }
        return node->flag;
    }
    bool startsWith(string prefix) {
        Node* node = root;
        for (char ch : prefix) {
            int idx = ch - 'a';
            if (node->links[idx] == nullptr)
                return false;
            node = node->links[idx];
        }
        return true;
    }
    bool check(string &s) {
        Node* node = root;
        for (char c : s) {
            int idx = c - 'a';
            if (node->links[idx] == nullptr)
                return false;
            node = node->links[idx];
            if (node->flag == false)
                return false;
        }
        return true;
    }
};
string completeString(int n, vector<string> &a) {
    Trie t;
    for (auto &word : a)
        t.insert(word);
    string ans = "";
    for (auto &word : a) {
        if (t.check(word)) {
            if (word.length() > ans.length())
                ans = word;
            else if (word.length() == ans.length() && word < ans)
                ans = word;
        }
    }
    if (ans == "")
        return "None";
    return ans;
}