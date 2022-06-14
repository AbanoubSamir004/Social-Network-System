#ifndef MYLIST_H
#define MYLIST_H
#include <iostream>
using namespace std;
template <class t>
class mylist
{
public:
    class Node
    {
    public:
        t data;
        Node *next;
        Node *prev;
        Node()
        {
            this->next= NULL;
            this->prev= NULL;
        }
        Node(t data)
        {
            this->data=data;
            this->next=NULL;
            this->prev= NULL;
        }
    };





private:
    Node*head;
    Node*tail;
    int size;
public:
    friend class Node;
    class iterator
    {
        friend class mylist<t>;
        friend class Node;
    private:
        Node*node=new Node;
    public:
        iterator()
        {
            node=NULL;
        }
        iterator(Node *node):node(node) {}

        bool operator==(const iterator&itr)
        {
            return node==itr.node;
        }
        t& operator*()const
        {
            return node->data;
        }
        t value()
        {
            return node->data;
        }
        Node* next()
        {
            return node->next;
        }
        void operator++()
        {
            if(node->next==NULL)
            {
                cout<<"out"<<endl;
            }
            else
                node= node->next;
        }
        bool operator!=(iterator itr)
        {
            return node!=itr.node;
        }
        void operator=(iterator it)
        {
            node = it.node;
        }
        void operator--()
        {
            if(node->prev==NULL)
            {
                cout<<"out"<<endl;
            }
            node=node->prev;
        }
    };
    mylist()
    {
        Node* dummy = new Node();
        head= tail = dummy;
        size=0;
    }

    iterator begin()const
    {
        return iterator(head);
    }
    iterator  end()const
    {
        return iterator(tail);
    }
    int Size()
    {
        return size;
    }
    void insert(t value, iterator position)
    {
        Node* newnode;
        newnode = new Node(value);

        if(position.node == head)
        {
            newnode->prev = NULL;

            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
        else
        {
            position.node->prev->next = newnode;
            newnode->prev = position.node->prev;
            newnode->next = position.node;
            position.node->prev = newnode;
        }
        size++;
    }
    mylist<t>& operator = (mylist<t>list)
    {
        swap(*this,list);
        return *this;
    }
    iterator erase(iterator position)
    {
        if(position.node==head)
        {
            Node*newnode=head;
            head=newnode->next;
            delete newnode;
            size--;
            return head;
        }
        else
        {
            position.node->next->prev=position.node->prev;
            Node*newnode=position.node->next;
            position.node->prev->next=newnode;
            size--;
            return newnode;
        }
    }
    friend ostream &operator<<(ostream &os, const mylist &mylist)
    {

        Node  *node =mylist.head;
        os<<"List : "<<endl;
        while (node != mylist.tail)
        {
            os << node->data <<' '<<endl;
            node = node->next;
        }
        return os;
    }

    ~mylist()
    {
        while (head->next != NULL)
        {
            Node *node = head;
            head = head->next;
            delete node;
        }
        delete head;
    }
};

#endif // MYLIST_H
