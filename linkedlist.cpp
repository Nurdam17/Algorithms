#include <bits/stdc++.h>
using namespace std;

struct Node{
    int value;
    Node *next;

    Node(int v, Node *n){
        value=v;
        next=n;
    }
};

class Onelinked_list{
public:
    Node *head, *tail;
    int elementcount;
public:
    Onelinked_list(){
        head=nullptr;
        tail=nullptr;
        elementcount=0;
    }
    //Destructor
    ~Onelinked_list(){
        while(!empty()){
            popfront();
        }
    }
    //getting node
    Node *getnode(int index){
        Node *n=head;
        for(int i=0;i<index;i++){
            n=n->next;
        }
        return n;
    }

    int &operator [](int index){
        return getnode(index)->value;
    }
    //getting size
    int size() const{
        return elementcount;
    }
    //check if list is empty
    bool empty() const{
        return elementcount==0;
    }
    //insert new element to front of list
    void pushfront(int value){
        head=new Node(value,head);
        elementcount++;
        if(tail==nullptr){
            tail=head;
        }
    }
    //deleting element in front of list
    void popfront(){
        Node *nextHead=head->next;
        delete head;
        head=nextHead;
        elementcount--;
        if(head==nullptr){
            tail=nullptr;
        }
    }
    //to print list in terminal
    void print() const{
        for(Node *n=head;n;n=n->next){
            cout<<n->value<<' ';
        }
        cout<<endl;
    }
    //insert element after certain element
    void insertafter(Node *elem, int value){
        elem->next=new Node(value, elem->next);
        elementcount++;
        if(tail==elem){
            tail=tail->next;
        }
    }
    //erase element after certain element
    void eraseafter(Node *elem){
        Node *nextelem=elem->next;
        elem->next=nextelem->next;
        delete nextelem;
        elementcount--;
        if(tail==nextelem){
            tail=elem;
        }
    }
    //insert element to the end
    void pushback(int value){
        if(empty()){
            pushfront(value);
        }
        else{
            insertafter(tail,value);
        }
    }
};

int main(){
    Onelinked_list l;
    //example
    // l.pushfront(1);
    // l.pushfront(2);
    // l.print();
    // l.insertafter(l.getnode(0),9);
    // l.print();
    // l.eraseafter(l.getnode(1));
    // l.print();
    // l.pushback(3);
    // l.print();
    return 0;
}