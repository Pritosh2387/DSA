#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    Node* links[26];
    Node() {
        for (int i = 0; i < 26; i++)
            links[i] = NULL;
    }
};
class Solution {
public:
    int countSubs(string& s) {
        Node* root = new Node();
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            Node* node = root;
            for (int j = i; j < s.size(); j++) {
                int idx = s[j] - 'a';
                if (node->links[idx] == NULL) {
                    node->links[idx] = new Node();
                    cnt++;
                }
                node = node->links[idx];
            }
        }
        return cnt;
    }
};