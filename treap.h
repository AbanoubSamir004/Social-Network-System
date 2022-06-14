#ifndef TREAP_H
#define TREAP_H
#include "user.h"
#include <iostream>
#include <algorithm>
using namespace std;

class user;

class node
{
public:
    int priority;
    user* key;
    node* left;
    node* right;
    node()
    {
        left = right = NULL;
        key= NULL;
        priority = rand()%(100-1)+1;
    }
    node(user* key)
    {
        this->key = key;
        left = right = NULL;
        priority = rand()%(100-1)+1;
    }
};

class treap
{

public:
    treap();
    node* add(node* rot, user* key);
    node* rightrotation(node* y );
    node* leftrotation(node *x);
    node* searchtreap(node* rot, user* key);
    bool searchtreapforFriends(node* rot,user* key);
    node* searchByUsername(node* rot,string username);
    node* deletenode(node* rot, user* key);
    void InOrder(node* rot);

};

#endif // TREAP_H
