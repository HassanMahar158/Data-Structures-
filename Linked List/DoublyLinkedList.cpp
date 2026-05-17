#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node *prevous;
    Node(int data)
    {
        this->data = data;
        next = prevous = NULL;
    }
};

// Linkedlist Class
class DoublyLL
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLL()
    {
        head = tail = NULL;
    }

    // Push node at front of linklist
    void Push_Front(int data);

    // Push node at back of linklist
    void Push_back(int data);

    // Delete Node by Value
    void Delete_by_val(int key);

    // Dispaly all node of linklist
    void display();
};

void DoublyLL::Push_Front(int data)
{

    if (head == NULL)
    {
        Node *NewNode = new Node(data);
        head = tail = NewNode;
        return;
    }
    Node *NewNode = new Node(data);
    NewNode->next = head;
    head->prevous = NewNode;
    head = NewNode;
}

void DoublyLL::Push_back(int data)
{

    if (head == NULL)
    {
        Node *NewNode = new Node(data);
        head = tail = NewNode;
        return;
    }
    Node *NewNode = new Node(data);
    tail->next = NewNode;
    NewNode->prevous = tail;
    tail = NewNode;
}

void DoublyLL::Delete_by_val(int key)
{

    // Linked List Is empty
    if (head == NULL)
    {
        cout << "LinkedList Has NO Node, Empty LinkedList" << endl;
        return;
    }
    Node *temp;
    Node *prevTemp;
    temp = prevTemp = head;

    if (head->data == key)
    {
        Node *del = head;
        head->next->prevous = head->prevous;
        head = head->next;
        return;
    }

    while (temp != NULL && temp->data != key)
    {
        prevTemp = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Key is not Found!" << endl;
        return;
    }
    int val=key;
    Node *del = temp;
    prevTemp->next = temp->next;
    tail = prevTemp;
    delete del;
    cout<<"Value: *"<<val<< "* is Deleted"<<endl;
}

// Display All Node from doubly LinkedList
void DoublyLL::display()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    DoublyLL dll;
    cout << "Push Front" << endl;
    dll.Push_Front(12);
    dll.Push_Front(11);
    dll.Push_Front(10);
    dll.display();
    cout<<endl;
    

    cout << "Push Back" <<endl;
    dll.Push_back(13);
    dll.Push_back(14);
    dll.Push_back(15);
    dll.Push_back(16);
    dll.display();
    cout<<endl;

    cout << "Before Delete" << endl;
    dll.display();
    cout<<endl;

    dll.Delete_by_val(16);
    cout << "After Delete" << endl;
    dll.display();
    cout<<endl;

    return 0;
}