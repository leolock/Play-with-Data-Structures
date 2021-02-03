#ifndef TRIE_H
#define TRIE_H

#include <map>
#include <string>

class Trie{
private:
    class Node{
    public:
        bool isWord;
        std::map<char, Node> next;

        Node(bool isWord){
            this->isWord = isWord;
        }

        Node() : isWord(false), next() {}
    };
    Node *root;
    int size;
public:
    Trie(){
        root = new Node();
        size = 0;
    }

    int getSize(){
        return size;
    }

    void add(std::string word){
        Node *cur = root;
        for(int i=0;i<word.size();++i){
            char c = word[i];
            if(cur->next.find(c) == cur->next.end()){
                cur->next.insert(std::pair<char, Node>(c, Node()));
            }
            cur = &cur->next.find(c)->second;
        }
        if(!cur->isWord){
            cur->isWord = true;
            size ++;
        }
    }

    bool contains(std::string word){
        Node *cur = root;
        for(int i = 0;i<word.size();++i){
            char c = word[i];
            if(cur->next.find(c) == cur->next.end()){
                return false;
            }
            cur = &cur->next.find(c)->second;
        }
        return cur->isWord;
    }

    bool isPrefix(std::string prefix){
        Node *cur = root;
        for(int i=0;i<prefix.size();++i){
            char c = prefix[i];
            if(cur->next.find(c) == cur->next.end()){
                return false;
            }
            cur = &cur->next.find(c)->second;
        }
        return true;
    }
};
#endif // TRIE_H