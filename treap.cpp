#include "treap.h"

treap:: treap() {
}

node* treap::rightrotation(node* y )
{
    node* x = y->left;
    node* a = x->right;
    x->right = y;
    y->left = a;
    return x;
}


node* treap::leftrotation(node *x)
{
    node* y = x->right;
    node* a = y->left;
    y->left = x;
    x->right = a;
    return y;
}
node* treap::searchtreap(node* rot, user* key)
{
    if(rot->key->getUsername() == key->getUsername() || rot == NULL)
        return rot;
    if(key->getUsername()<rot->key->getUsername())
        return searchtreap(rot->left, key);
    return searchtreap(rot->right, key);
}


node* treap::add(node* rot, user* key)
{
    if(rot == NULL)
        return new node(key);
    if(key->getUsername() < rot->key->getUsername())
    {
        rot->left = add(rot->left, key);
        if(rot->left->priority> rot->priority)
            rot =  rightrotation(rot);
    }
    else if(key->getUsername() > rot->key->getUsername())
    {
        rot->right = add(rot->right, key);
        if(rot->right->priority > rot->priority)
            rot = leftrotation(rot);
    }
    return rot;
}


node* treap::deletenode(node* rot, user* key)
{

    if(key->getUsername() < rot->key->getUsername())
    {
        rot->left = deletenode(rot->left, key);
    }
    else if(key->getUsername() > rot->key->getUsername())
    {
        rot->right = deletenode(rot->right, key);
    }
    else if (rot->left == NULL)
    {
        node* temp = rot->right;
        delete(rot);
        rot = temp;
    }
    else if(rot->right == NULL)
    {
        node* tmp = rot->left;
        delete(rot);
        rot = tmp;
    }
    else if(rot->left->priority < rot->right->priority)
    {
        rot = leftrotation(rot);
        rot->left = deletenode(rot->left, key);
    }
    else
    {
        rot = rightrotation(rot);
        rot->right = deletenode(rot->right, key);
    }
    return rot;

}

void treap::InOrder(node* rot) {
    if (rot == NULL)return;
    InOrder(rot->left);
    cout << *(rot->key) << "\n";
    InOrder(rot->right);
}

bool treap::searchtreapforFriends(node *rot, user *key) {
    // if the key is not present in the tree
    if (rot == NULL) {
        return true;
    }
    // if the key is found

    // if the key is less than the root node, search in the left subtree
    if (key->getUsername() < rot->key->getUsername()) {
        return searchtreapforFriends(rot->left, key);
    }
    // otherwise, search in the right subtree
    if (key->getUsername() > rot->key->getUsername())
        return searchtreapforFriends(rot->right, key);

    return false;
}
node* treap::searchByUsername(node* root, string username)
{
    if (root == NULL)
        return NULL;
    if(root->key->getUsername() == username)
        return root;
    if(root->key->getUsername()<username)
        return searchByUsername(root->right,  username);
    if(root->key->getUsername()>username){
        return searchByUsername(root->left,  username);
    }
    return NULL;
}

