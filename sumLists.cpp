#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

// Node for linked list
class Node
{
    public:
        string data;
        Node *next; // next link
};

class LinkedList
{
    private: // Node pointers to head and tail
        Node *head;
        Node *tail;

    public:
        LinkedList()
        {
            head = NULL;
            tail = NULL;
        }

        void print()
        {
            Node *temp; // pointer temp
            temp = head; // have temp reference the head

            while(temp != NULL) // Loops to end of list
            {
                cout << temp -> data << " "; // prints data stored in temp pointer
                temp = temp -> next; // make temp now equal the following node
            }

            cout << endl;
       
        }

        int asInt()
        {
            Node *temp;
            temp = head;

            /*
            1. store node value to var
            2. add var to list string var
            loop until temp is null, end of list
            3. cast string to int
            4. return int
            */

            string currentStringVal;
            string listAsString = " ";
            int numInList;

            while(temp != NULL)
            {
                currentStringVal = temp -> data; // string value in current node
                listAsString = listAsString + currentStringVal;
                temp = temp -> next; // move temp to next node
            }

            // Cast 
            stringstream toInt(listAsString);
            toInt >> numInList;

            return numInList;
        }

        void addElement(string value)
        {
            Node *temp = new Node; // creates a temporary pointer referencing a new node
            temp -> data = value; // set value at temp address to passed value
            temp -> next = NULL; // links to NULL, end of list

            if(head == NULL) // if list is empty
            {
                // Since there is only one node, it is both the head and tail of the linked list
                head = temp;
                tail = temp; 
            }
            else // otherwise
            {
                tail -> next = temp; // new node is added after old tail
                tail = tail -> next; // making this new node the tail
            }
        }

        void addReversedOrder(int value)
        {
            Node *temp = new Node;
            temp -> data = value;
            temp -> next = NULL;

            Node *prevHead = new Node;

            if(head == NULL)
            {
                head = temp;
                tail = temp;
            }
            else
            {
                prevHead = head; // Place holder for what was previously the head
                head = temp; // Set new input at front of list
                head -> next = prevHead;
                prevHead -> next = tail;
            }
        }
    
};

// void genRandomList(LinkedList ll, int size)
// {
//     int num;

//     for (int i = 0; i < size; i++)
//     {
//         num = rand() % 10 + 1; // generates number 1 - 10
//         ll.addElement(num);
//     } 
// }

int main()
{
    LinkedList list1;
    LinkedList list2;

    list1.addElement("6");
    list1.addElement("1");
    list1.addElement("7");

    cout << "  ";
    list1.print();


    list2.addElement("1");
    list2.addElement("9");
    list2.addElement("3");

    cout << "+ ";
    list2.print();

    cout << "Sum of Lists: " << list1.asInt() + list2.asInt() << endl;

    return 0;
}