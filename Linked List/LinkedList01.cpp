// Create linklist  and insert, delete, update, reverse, display
#include <iostream>
using namespace std;

// For create nodes
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
// For make a chaning
class linkList
{

    Node *head;

public:
    linkList()
    {
        head = NULL;
    }
    void insert_at_back(int data);
    void insert_at_front(int data);
    void insert_at_Mid(int key, int data);
    void updateNode(int key, int data);
    void ReverseLL();
    void MiddleNode();
    void deleteNode(int Key);
    void display();
};
// insert node last of linklist
void linkList::insert_at_back(int data)
{
    // if LinkList is Empty
    if (head == NULL)
    {
        head = new Node(data);
        return;
    }
    // Linklist exist some node insert node at end;

    // use transverse method for insert node at end of linklist

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new Node(data);
}

// insert node at mid of linklist
void linkList::insert_at_Mid(int key, int data)
{
    Node *NewNode = new Node(data);
    Node *prev;
    Node *current;
    prev = head;
    current = prev->next;

    // if Linklist is empty
    if (head == NULL)
    {
        cout << "LinkList is empty!" << endl;
        return;
    }

    // if key is at 1st node
    if (head->data == key)
    {
        NewNode->next = current;
        prev->next = NewNode;
        return;
    }

    while (current != NULL && current->data != key)
    {
        prev = current;
        current = current->next;
    }
    // if key is not found
    if (current == NULL)
    {
        cout << "your key *" << key << "* Not Exist in LinkList" << endl;
        delete NewNode;
        return;
    }
    NewNode->next = current;
    prev->next = NewNode;
}

// insert node at front of linklist
void linkList::insert_at_front(int data)
{
    Node *NewNode = new Node(data);
    NewNode->next = head;
    head = NewNode;
}

// updateNode Vaue
void linkList::updateNode(int key, int data)
{
    Node *temp;
    temp = head;
    while (temp != NULL && temp->data != key)
    {

        temp = temp->next;
    }

    if (temp != NULL)
    {
        temp->data = data;
        return;
    }
    cout << key << ": Key Not found!!" << endl;
}

// Reverse linklist.
void linkList::ReverseLL()
{
    Node *prev;
    Node *Current;
    Node *next;
    next, prev = NULL;
    Current = head;
    while (Current != NULL)
    {
        next = Current->next;
        Current->next = prev;
        prev = Current;
        Current = next;
    }
    head = prev;
}

// Middle Node
void linkList::MiddleNode()
{
    if (head == NULL)
    {
        cout << "LinkedList Is Empty!" << endl;
        return;
    }

    Node* fast;
    Node* slow;
    fast=slow=head;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<"Middle Node: "<< slow->data<<endl;

}

// Delete node
void linkList::deleteNode(int key)
{

    // if LinkList is Empty
    if (head == NULL)
    {
        cout << "LinkList is empty" << endl;
        return;
    }

    // if key in first node
    if (head->data == key)
    {
        head = head->next;
        return;
    }

    // if LinkList has Multipl Nodes
    Node *temp = head;
    Node *PrevTemp = head;
    while (temp->data != key)
    {

        PrevTemp = temp;
        temp = temp->next;
    }

    PrevTemp->next = temp->next;
    delete temp;
}

// display all node of linklist
void linkList::display()
{
    // if linklist is empty
    if (head == NULL)
    {
        cout << "linklist is empty !" << endl;
    }

    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    linkList ll;
    ll.insert_at_back(13);
    ll.insert_at_back(23);
    ll.insert_at_back(33);
    ll.insert_at_back(43);
    //ll.insert_at_front(03);

    // cout << "before insert" << endl;
    // ll.display();
    // cout << endl;

    // ll.insert_at_Mid(34, 24);
    // cout << "After insert" << endl;
    // ll.display();
    // cout << endl;

    ll.MiddleNode();

    return 0;
}