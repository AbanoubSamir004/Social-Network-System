#include "user.h"

user::user()
{
    func = new treap();
}
user::user(string username,string name,string email)
{
    this->username=username;
    this->name=name;
    this->email=email;
    func = new treap();
}
void user::addFriend (user* friendd)
{
    root = func->add(root,friendd);
}
void user::removeFriend(user *friendd)
{
    root = func->deletenode(root,friendd);
}

string user::getUsername() {
    return username;
}
string user::getName() {
    return name;
}
string user::getEmail() {
    return email;
}

void user::ListAllFriends() {
    if (root==NULL)
        cout<<"Your Friends List is Empty"<<endl;
    else
        func->InOrder(root);
}

bool user::peopleYouMayKnow(user* friendd) {
    if (func->searchtreapforFriends(root,friendd))
        return true;
    return false;
}


bool user :: searchFriend(string username)
{
    node* n1;
    n1=func->searchByUsername(root,username);
    if(n1 == NULL)
    {
        cout<<"Not Found"<<endl;
        return false;
    }
    else{
        cout<<"Username : "<< n1->key->getUsername()<<", "<<"Name : "<<n1->key->getName()<<", "<<"Email : "<<n1->key->getEmail()<<endl;
        return true;
    }
}
node* user :: search(string username) {
    node *n1;
    n1 = func->searchByUsername(root, username);
    return n1;
}
