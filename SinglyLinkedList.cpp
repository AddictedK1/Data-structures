// Data structure 
// Singly linkedlist

#include<iostream>
#include<vector>
using namespace std;
// declaring node class {Data,Next}
class Node{
    public:
        int data;
        Node* Next;
        Node(int val)  {
            data=val;
            Next = nullptr;
        }
};

class LinkedList{
        // first node address will be in head
        Node* head;  // private

    public:
        // initialize head with null initially 
        LinkedList()  {
            head=nullptr;
        }
         // to print linkedlist   
        void display()  {
            if(head==nullptr){
                cout<<"linkedlist is empty"<<endl;
                return;
            }  
            Node* temp = head;
            while(temp!=nullptr)  {
                cout<<temp->data<<" ";
                temp=temp->Next;
            }
            cout<<endl;
        }
        // searches for passed element and returns its position if exists
        int search(int key)  {
            if(head==nullptr){
                cout<<"linkedlist is empty"<<endl;
                return -1;
            }
            Node* temp = head;
            int position=1;
            while(temp!=nullptr)  {
                if(temp->data==key)  {
                    return position; 
                }
                temp=temp->Next;
                position++;
            }
            cout<<"key not found"<<endl;
            return -1;
        }

        // adds node in the beginning of linkedlist
        void insert_first(int data)  {
            Node* NewNode = new Node(data);
            if(head == nullptr)  {
                head = NewNode;
                return;
            }
            NewNode->Next = head;
            head = NewNode;
        }
        // adds node in the linkedlist at last 
        void insert_last(int data)  {
            Node* NewNode = new Node(data);
            if(head==nullptr)  {
                head = NewNode;
                return;
            }
            Node* temp = head;
            while (temp->Next != nullptr)  {
                temp = temp->Next;
            }
            temp->Next = NewNode; 
        }
        // inserts element at passed position
        void insert(int val, int pos)  {

            if(pos == 1)  {
                Node* NewNode = new Node(val);
                if(head == nullptr)  {
                    head = NewNode;
                    return;
                }else{
                    NewNode->Next = head;
                    head = NewNode;
                    return;
                }
            }
            Node* NewNode = new Node(val);
            Node* temp = head;
            int count=2;
            while(temp->Next != nullptr && count<pos)  {
                temp = temp->Next;
            }
            if(temp->Next == nullptr)  {
                if(count == pos-1)  {
                    temp->Next = NewNode;
                    return;
                }else{
                    cout<<"reached at the end of the linkedlist"<<endl;
                    return;
                }
            }else{
                NewNode = temp->Next;
                temp = NewNode;
            }
        }

        void delete_first()  {
            if(head == nullptr)  {
                cout<<"empty linkedlist, nothing to delete"<<endl;
                return;
            }
            head = head->Next;
        }

        void delete_last()  {
            if(head == nullptr)  {
                cout<<"empty linkedlist, nothing to delete"<<endl;
                return;
            }
            if(head->Next == nullptr)  {
                head = nullptr;
                return;
            }
            Node* temp = head;
            while(temp->Next->Next != nullptr)  {
                temp=temp->Next;
            }
            temp->Next = nullptr;
        }
            // removes to node from passed position
        void remove(int pos)  {
            if(head == nullptr)  {
                cout<<"empty linkedlist, nothing to delete"<<endl;
                return;
            }
            if(pos == 1)  {
                head = head->Next;
                return;
            }
            Node* temp=head;
            int count=2;
            while(temp->Next != nullptr && count<pos)  {        
                temp=temp->Next; 
                count++;
            }
            if(temp->Next == nullptr)  {
                cout<<"reached at the end of the linked list "<<endl;
                return;
            }else  {
                temp->Next = temp->Next->Next;
                return;
            }
        
        }
        
};

int main()  {
    // test examples
    // for reference 
    LinkedList list;
    list.insert_first(15);
    list.insert_first(25);
    list.insert_first(404);
    list.insert_first(420);
    list.insert_first(88);
    list.display();
    cout<<"Key found at position : "<<list.search(25)<<endl;
    list.display();
    list.insert_last(55);
    list.display();

    list.delete_first();
    list.display();
    list.delete_last();
    list.display();

    list.remove(2);
    list.display();

    return 0;
}
