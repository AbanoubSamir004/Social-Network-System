
#include <iostream>
#include <fstream>
#include <algorithm>
#include "mylist.h"
#include "user.h"
using namespace std;
#ifndef DS_PROJECT_APPLICATION_H
#define DS_PROJECT_APPLICATION_H


class Application {
public:
    void ApplicationMenu() {
        mylist<user> userList;
        fstream infile("all-users.in", ios::in);
        string s;
        string userName;
        string name;
        string mail;
        while (getline(infile, s)) {
            int i;
            userName = name = mail = "";
            for (i = 0; i < s.size(); i++) ///loop to get the username
            {
                if (s[i] == ',') {
                    break;
                }
                userName += s[i];

            }
            i += 2;
            for (; i < s.size(); i++) ///loop to get the name
            {

                if (s[i] == ',') {
                    break;
                }
                name += s[i];

            }
            i += 2;

            for (; i < s.size(); i++) ///loop to get the email
            {

                if (s[i] == ',') {
                    break;
                }
                mail += s[i];

            }
            userList.insert(user(userName, name, mail), userList.end()); /// put username and name and mail in userList
        }
        infile.close();
        infile.open("all-users-relations.in", ios::in);

        string u1;
        string u2;


        while (getline(infile, s)) {
            int i;
            u1 = u2 = "";
            for (i = 0; i < s.size(); i++) /// string for user1's name
            {

                if (s[i] == ',') {
                    break;
                }
                u1 += s[i];

            }
            i += 2;
            for (; i < s.size(); i++) /// user1's friend name
            {
                u2 += s[i];
            }

            user *us1 = NULL;
            user *us2 = NULL;
            for (mylist<user>::iterator j = userList.begin(); j != userList.end(); ++j) {
                if ((*j).getUsername() == u1) {
                    us1 = &(*j);
                }

                if ((*j).getUsername() == u2) {
                    us2 = &(*j);
                }
            }

            if (us1 != NULL && us2 != NULL) {
                us1->addFriend(us2);
                us2->addFriend(us1);

            }
        }
        infile.close();

        //------------------------------Application-----------------------------
        bool check = 0;
        string loginUsername;
        user *loggedInUser;
        cout << "Login" << endl;
        cout << "Exit" << endl;
        while (true) {
            string options;
            cin >> options;
            if (options == "Login") {
                cout << "------------------------------LOGIN-----------------------------" << endl;
                cout << "Type your username to be logged in " << endl;
                cin >> loginUsername;
                for (mylist<user>::iterator j = userList.begin(); j != userList.end(); ++j) {
                    if ((*j).getUsername() == loginUsername) {
                        check = 1;
                        loggedInUser = &(*j);
                    }
                }

                if (check == 1) {
                    cout << "Login successful" << endl;

                    while (true) {
                        cout << "----------------------- applications -----------------------" << endl;
                        cout << "1-List all friends " << endl;
                        cout << "2-Search by username " << endl;
                        cout << "3-Add friend " << endl;
                        cout << "4-Remove friend " << endl;
                        cout << "5-people you may know " << endl;
                        cout << "6-logout " << endl;
                        int choice;
                        cin >> choice;
                        if (choice == 1)  ///list all friends
                            loggedInUser->ListAllFriends();

                        else if (choice == 2) /// search by user name
                        {
                            cout << "Please Enter a username: " << endl;
                            string Username;
                            cin >> Username;
                            if(loggedInUser->searchFriend(Username)){
                                cout << "Do you Need to Remove this Friend?" << endl;
                                cout << "1-Yes" << endl;
                                cout << "2-No" << endl;
                                int input;
                                cin >> input;
                                if (input == 1) {
                                    user* user3 = NULL;
                                    for (mylist<user>::iterator j = userList.begin(); j != userList.end(); ++j) {
                                        if ((*j).getUsername() == Username) {
                                            user3 = &(*j);
                                            loggedInUser->removeFriend(user3);
                                            user3->removeFriend(loggedInUser);
                                            cout << "Done" << endl;
                                            break;
                                        }
                                    }
                                }
                            }
                        }

                        else if (choice == 3) /// add friend
                        {
                            cout << "Please Enter a username: " << endl;
                            string Username;
                            cin >> Username;
                            node *node1 = loggedInUser->search(Username);
                            if (node1 == NULL) {
                                user *us = NULL;
                                for (mylist<user>::iterator j = userList.begin(); j != userList.end(); ++j) {
                                    if ((*j).getUsername() == Username) {
                                        us = &(*j);
                                        loggedInUser->addFriend(us);
                                        cout << "You Are Now Friends" << endl;

                                    }
                                }
                                us->addFriend(loggedInUser);
                            }
                            else
                                cout << "You are already friends" << endl;
                        }

                        else if (choice == 4) {/// remove friend
                            cout << "Please Enter a username: " << endl;
                            string Username;
                            cin >> Username;
                            node *node1 = loggedInUser->search(Username);
                            user *us2 = NULL;
                            if (node1 != NULL) {
                                for (mylist<user>::iterator j = userList.begin(); j != userList.end(); ++j) {
                                    if ((*j).getUsername() == Username) {
                                        us2 = &(*j);
                                        loggedInUser->removeFriend(us2);
                                        cout << "Done" << endl;
                                    }
                                }
                                us2->removeFriend(loggedInUser);
                            } else
                                cout << "You are already Not friends" << endl;
                        }

                        else if (choice == 5) { /// people you may know
                            user *user1 = NULL;
                            int counter = 0;
                            for (mylist<user>::iterator j = userList.begin(); j != userList.end(); ++j) {
                                if ((*j).getUsername() != loginUsername) {
                                    user1 = &(*j);
                                    if (loggedInUser->peopleYouMayKnow(user1) && counter < 5) {
                                        cout << (*j) << endl;
                                        counter++;
                                    }
                                }
                            }
                        }
                        else if (choice == 6)///logout
                            break;
                        else
                            cout<<"Please Choose A Number Between 1 And 6 "<<endl;
                    }
                }
                else
                    cout << "Invalid Username / Try Again " << endl;
            }
            else if(options=="Exit")
                break;
            cout << "Login" << endl;
            cout << "Exit" << endl;
        }
    }

};

#endif //DS_PROJECT_APPLICATION_H
