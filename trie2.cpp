#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node* a[26] = {nullptr};
    int s = 0;
    int e = 0;
};
class Trie{
    Node* root;
public:
    Trie(){
        root = new Node;
    }
    void insert(string &word){
        Node* node = root;
        for(char c : word){
            int i = c-'a';
            if(node->a[i] == nullptr)
                node->a[i] = new Node;
            node = node->a[i];
            node->s++;
        }
        node->e++;
    }
    int countWordsEqualTo(string &word){
        Node* node = root;
        for(char c : word){
            int i = c-'a';
            if(node->a[i] == nullptr)
                return 0;
            node = node->a[i];
        }
       return node->e;
    }
    int countWordsStartingWith(string &word){
        Node* node = root;
        for(char c : word){
            int i = c-'a';
            if(node->a[i] == nullptr)
                return 0;
            node = node->a[i];
        }
        return node->s;
    }
    void erase(string &word){
        Node* node = root;
        for(char c : word){
            int i = c-'a';
            if(node->a[i] == nullptr)
                return;
            node = node->a[i];
            node->s--;
        }
        node->e--;
    }
};