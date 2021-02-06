#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <QStringList>

using namespace std;

class Node {

public:
    int value;
    Node * next;

    Node(int val){
        this->value= val;
        this->next = NULL;
    }
    Node(){
        ;
    }
};

class Linkedlist{

    int size = 0;
    Node * head = NULL;
    Node * tail = NULL;


public:

    Linkedlist(int value);

    QStringList traverse();

    void addNode(int index, int value);

    void addNode(int value);

    void deleteNode();

    void deleteByIndex(int index);

    void deleteByValue(int value);

    bool isEmpty();


};




#endif // LINKEDLIST_H
