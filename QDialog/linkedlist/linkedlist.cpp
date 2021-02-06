#include "linkedlist.h"
#include <QStringList>
#include <QDebug>

Linkedlist::Linkedlist(int value)
{
    if (this->head == NULL)
    {
        this->head = new Node(value);
        this->tail = this->head;
        this->size++;
        cout << "created new Linkedlist with value: " << this->head->value << endl;
    }
    else{
        cout << "Linked list is already created" << endl;
    }
}

void Linkedlist::addNode(int value){
    if (this->head != NULL)
    {
        Node * node = new Node(value);
        this->tail->next = node;
        this->tail = node;
        this->size++;
        cout << "Added new node in the Linkedlist with value: " << node->value << endl;
    }
    else{
        cout << "Please create the Linked list first" << endl;
    }
}

void Linkedlist::deleteNode()
{
    if(head == tail){
        delete(head);
        head = NULL;

    }
    else {

        Node * itrnode = new Node();
        itrnode = this->head;
        for (itrnode = this->head; itrnode->next != tail; itrnode = itrnode->next);
        itrnode->next = NULL;
        delete(tail);
        tail = itrnode ;
    }
}

bool Linkedlist::isEmpty()
{
    if (this->head == NULL)
        return true;

    return false;
}

void Linkedlist::addNode(int index, int value){
    Node * itrnode = new Node();

    itrnode = this->head;
    for (int i = 1 ; i <= size; i++){
        if (i == index-1){
            Node * node = new Node(value);
            node->next = itrnode->next;
            itrnode->next = node;
            this->size++;
            break;
        }

        itrnode = itrnode->next ;
    }
}


QStringList Linkedlist::traverse(){

    Node * itrnode = new Node();

    QStringList valueList;

    itrnode = this->head;
    for (int i = 1 ; i <= size; i++){
        cout << "iteration: " << i << endl;
        if(itrnode->next != NULL){
            cout << "index: " << i << " value: " << itrnode->value << endl;
            valueList.append(QString::number(itrnode->value));
        }
        else if(itrnode == tail){
            cout << "index: " << i << " value: " << itrnode->value << endl;
            valueList.append(QString::number(itrnode->value));
        }
        itrnode = itrnode->next ;
    }
    return valueList;
}
