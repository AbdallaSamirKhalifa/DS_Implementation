#pragma once
#include<iostream>
using namespace std;
template < class T>
class clsDblLinkedList
{
protected:
    int _Size=0;

public:
    
    class Node {
    public:
        T value;
        Node* prev;
        Node* next;
        
    };
    Node* head = NULL;

    void InsertAtBeginning( T value) {

        /*
        1-Crete New Node
        2-Set New Node's Value
        3-Set New Node Prev Pointer To Null
        4-(if The Head Is Not Empty )Set The Head Prev pointer to the new node
        5-Set The New Node As The New Head Of The List
        */

        Node* new_node = new Node();
        Node* Prev = head;
        new_node->value = value;
        new_node->next = head;
        new_node->prev = NULL;

        if (head != NULL) {
            head->prev = new_node;
        }

        head = new_node;
        _Size++;

    }

    Node* Find( T value) {
      
        Node* Current = head;
        while (Current != NULL) {
           
            if (Current->value == value)
            {
                return Current;
            }
           
            Current = Current->next;
        }
        return NULL;
    }

    void InsertAfter(Node* Current ,T value) {
        if (Current == NULL)return;
        /*
        1-Create New Node
        2-Set The New Node Value
        3-Set The New Node next Pointer To Current next Pointer Node
        4-Set New Node Prev Pointer To Current Node
        5-(If The Current Node NEcyt Pointer Not Empty)Set The Next prev PointerTo The New Node
        6-set The Current Next Pointer To TheNew Node
        */
        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = Current->next;
        newNode->prev = Current;

        if (Current->next != NULL)
            Current->next->prev = newNode;
        Current->next = newNode;
        _Size++;

    }

    void InsertAtEnd(T value) {

            /*
     1-Create New Node
     2-Set New Node's Value
     3-Set The New Node's Next Pointer To Null
     4-if head Is Empty Set The New Node's Prev Pointer To NUll And Set The New Node As The Head Of The List (Other Than This go To The Next Lines)
     5-Creat A Current Node And Assign It To The Head Of The List
     6-Find The LAst Node
     7-Set The New Node's Prev Pointer To The Current Node
     8-Set The Current Node next Pointer To The New Node
    */
        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = NULL;

        if (head == NULL) {
            newNode->prev = NULL;
            head = newNode;
            _Size++;
            return;
        }

        Node* Current = head;
        while (Current->next != NULL) {
            Current = Current->next;
        }
        Current->next = newNode;
        newNode->prev = Current;
        _Size++;


    }

    void Delete(T value) {
        if (head == NULL)return;
        Node* Current = head;
        if (Current->value == value) {
            head = head->next;

            if (head != NULL)
                head->prev = NULL;
            delete Current;
            _Size--;
            return;
        }
        while (Current->next != NULL && Current->value != value) {
            Current = Current->next;
        }
        if (Current->value != value)return;

        if (Current->prev != NULL)
            Current->prev->next = Current->next;

        if (Current->next != NULL)
            Current->next->prev = Current->prev;

        delete Current;
        _Size--;


    }

    void DeleteNode( Node*& NodeToDelete)
    {
            /*
        1-Set the next pointer of the previous node to the next pointer of the current node.
        2-Set the previous pointer of the next node to the previous pointer of the current node.
        3-Delete the current node.
        */

        if (head == NULL || NodeToDelete == NULL)return;

        if (head == NodeToDelete)
        {
            head = NodeToDelete->next;
        }

        if (NodeToDelete->next != NULL)
        {
            NodeToDelete->next->prev = NodeToDelete->prev;
        }

        if (NodeToDelete->prev != NULL)
        {
            NodeToDelete->prev->next = NodeToDelete->next;
        }
        
        delete NodeToDelete;
        _Size--;

    }

    void DeleteFirstNode() {
        if (head == NULL)return;
            /*
        1-Creat a temp Node As The Head Of The List
        2-Set The Next Node As The New Head Of The List
        3-if The Head is Not Empty Set The Haed Previous Pointer To NULL
        4-Delete The Temp node
        */

        Node* temp = head;
        head = head->next;

        if (head != NULL)
            head->prev = NULL;

        delete temp;
        _Size--;

    }

    void DeleteLastNode() {
        if (head == NULL)return;
        /*
        1-if The Head Is The Only Node (Delete The Head And return)
        2-Find The Node Before Last Node
        3-Create A Temp As The Last Node
        4-Set The Next Pointer Of The Node Before Last With NULL
        5-Delete The Temp Node
        */
        if (head->next == NULL) {
            delete head;
            _Size--;
            head = NULL;
            return;
        }

        Node* Current = head;
        while (Current->next->next != NULL)
        {
            Current = Current->next;
        }
        Node* temp = Current->next;
        Current->next = NULL;
        delete temp;
        _Size--;
    }

    void PrintList()
    {
        Node* Current = head;
        cout << "\n";
        while (Current!= NULL) {
            cout << Current->value << "  ";
            Current = Current->next;
        }
    }

    int Size() {

        return _Size;
    }

    bool IsEmpty() {
        return (_Size == 0);
    }

    void Clear() {
        while (_Size > 0) {
            DeleteFirstNode();
    }
    }

    void Reverse() {
        Node* Current = head;
        Node* temp = nullptr;
        while (Current != nullptr) {
            temp = Current->prev;
            Current->prev = Current->next;
            Current->next = temp;
            Current = Current->prev;
        }
        if (temp != nullptr)
            head = temp->prev;

    }

    Node* GetNode(int index) {
        if (index > _Size - 1 || index < 0)return NULL;

        Node* Current = head;
        while ( Current != NULL && Current->next != NULL)
        {
            if (index == 0)
                break;

            Current = Current->next;
            index--;

        }
        return Current;
    }

    T GetItem(int index) {
        Node* node = GetNode(index);
        if (node == NULL)
            return NULL;
        else
        return node->value;
    }

    bool UpdateItem(int Index, T NewValue) {
       
        Node* ItemNode = GetNode(Index);

        if (ItemNode != NULL)
        {
            ItemNode->value = NewValue;
            return true;
        }
        return false;
    }

    bool InsertAfter(int Index, T value) {
        Node* ItemNode = GetNode(Index);
        if(ItemNode!=NULL)
        {
            InsertAfter(ItemNode, value);
            return true;
        }
        return false;
    }
};

