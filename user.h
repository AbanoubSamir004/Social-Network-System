#ifndef USER_H
#define USER_H
using namespace std;
#include <iostream>
#include "treap.h"

class node;
class treap;

class user
{
private:
    string username;
    string name;
    string email;
    friend class treap;
    node* root = NULL;
    treap* func = NULL;
public:
    user();
    user(string username,string name,string email);
    string getUsername();
    string getName();
    string getEmail();
    void addFriend(user* friendd);
    void removeFriend(user* friendd);
    void ListAllFriends();
    bool peopleYouMayKnow(user* friendd);
    bool searchFriend(string username);
    node* search(string username);
    friend ostream& operator<<(ostream& os, const user& u) {
        os << "Username: " << u.username << " Name: " << u.name;
        return os;
    }
};
#endif // USER_H
