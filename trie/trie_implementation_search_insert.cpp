// simple implementation of trie, performs operation of insertion, searching and prefix searching;


#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[26];
    bool flag=false;

    bool containsKey(char ch){
        return (links[ch-'a'] != NULL);
    }

    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        flag=true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie{
    Node* root;
public:
    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word){
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i]))
                return false;
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool prefix(string word){
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i]))
                return false;
            node = node->get(word[i]);
        }
        return true;
    }
};

int main(){

    int n = 5;
    vector<int>type = {1, 1, 2, 3, 2};
    vector<string>value = {"hello", "help", "help", "hel", "hel"};
    Trie trie;
    for (int i = 0; i < n; i++) {
        if (type[i] == 1) {
            trie.insert(value[i]);
        } else if (type[i] == 2) {
            if (trie.search(value[i])) {
                cout << "true" << "\n";
            } else {
                cout << "false" << "\n";
            }
        } else {
            if (trie.prefix(value[i])) {
                cout << "true" << "\n";
            } else {
                cout << "false" << "\n";
            }
        }
    }
    return 0;
}
