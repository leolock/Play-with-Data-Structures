#ifndef BSTMAP_H
#define BSTMAP_H


#include <iostream>
#include "Map.h"
#include <cassert>

template<typename Key, typename Value>
class BSTMap : public Map<Key, Value>{
private:
    struct Node{
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node(Key key, Value value){
            this->key = key;
            this->value = value;
            this->left = this->right = nullptr;
        }

        Node(Node *node){
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;
        }
    };

    Node *root;
    int size;
public:
    BSTMap(){
        root = nullptr;
        size = 0;
    }
    ~BSTMap(){
        destroy(root);
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size == 0;
    }

    bool contains(Key key){
        return getNode(root, key) != nullptr;
    }
    Value *get(Key key){
        Node *node = getNode(root, key);
        return node == nullptr ? nullptr : &(node->value);
    }

    void add(Key key, Value value){
        root = add(root, key, value);
    }
    void set(Key key, Value value){
        Node *node = getNode(root, key);
        if (node != nullptr) {
            node->value = value;
        }
    }

    Value *remove(Key key){
        Node *node = getNode(root, key);
        if (node != nullptr) {
            root = remove(root, key);
            return &(node->value);
        }
        return nullptr;
    }
private:
    Node *getNode(Node *node, Key key) {
        if (node == nullptr) {
            return nullptr;
        }
        if (key == node->key) {
            return node;
        } else if (key < node->key) {
            return getNode(node->left, key);
        } else {
            return getNode(node->right, key);
        }
    }

    Node *add(Node *node, Key key, Value value){
        if(node == nullptr){
            size++;
            return new Node(key, value);
        }
        if(key == node->key){
            node->value = value;
        }
        else if(key < node->key){
            node->left = add(node->left, key, value);
        }
        else{
            node->right =  add(node->right, key, value);
        }
        return node;
    }
    void destroy(Node *node){
        if(node != nullptr){
            destroy(node->left);
            destroy(node->right);
            delete(node);
            size--;
        }
    }
    Node *minimum(Node *node){
        if(node->left == nullptr)
            return node;
        return minimum(node->left);
    }
    Node *maximun(Node *node){
        if(node->right == nullptr)
            return node;
        return node->right;
    }

    Node *removeMin(Node *node){
        if(node->left == nullptr){
            Node *rightNode = node->right;
            
            delete node;
            size--;
            return rightNode;
        }
        node->left = removeMin(node->left);
        return node;
    }

    Node *removeMax(Node *node){
        if(node->right == nullptr){
            Node *leftNode = node->left;
            
            delete node;
            size--;
            return leftNode;
        }
        node->right = removeMax(node->right);
        return node;
    }

    Node *remove(Node *node, Key key){
        if(node == nullptr) return nullptr;
        if(key < node->key){
            node->left = remove(node->left, key);
            return node;
        }
        else if(key >node->key){
            node->right = remove(node->right, key);
            return node;
        }
        else{
            if(node->left == nullptr){
                return removeMax(node);
            }
            if(node->right == nullptr){
                return removeMin(node);
            }
            
            Node *successor = new Node(minimum(node->right));
            size++;

            successor->right = removeMin(node->right);
            successor->left = node->left;

            delete node;
            size--;
            return successor;
        }
    }
};

#endif // BSTMAP_H