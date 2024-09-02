// Data structure
// Doubly-Linkedlist
#include<iostream>
using namespace std;

// Declaring class node for doubly linkedlist {Prev,Data,Next}
class Node{
    public:
        int Data;   // u can change the datatype of the node 
        Node* Next;
        Node* Prev;

        Node(int val)  {
            Data = val;
            Next = nullptr;
            Prev = nullptr;
        }
};

// making class linkedlist to create linkedlist
class Dlinkedlist{
        // head pointer that point towards first node
        Node* head;
    
    public:
        // initialize head as nullptr using constructor
        Dlinkedlist()  {
            head=nullptr;
        }
        // function to print linkedlist
        void display()  {
            if(head==nullptr) {
                cout<<"linkedlist empty"<<endl;
                return;
            }
            Node* temp=head;  
            while(temp!=nullptr)  {
                cout<<temp->Data<<" ";
                temp=temp->Next;
            }
            cout<<endl;
        }
        // searches element by passed value / key and returns position 
        int search(int key)  {
            if(head==nullptr){
                cout<<"linkedlist is empty"<<endl;
                return -1;
            }
            Node* temp = head;
            int position=1;
            while(temp!=nullptr)  {
                if(temp->Data==key)  {
                    return position; 
                }
                position++;
                temp=temp->Next;
            }
            cout<<"element not found in linkedlist"<<endl;
            return -1;
        }

        void insert_begin(int key)  {
            Node* NewNode = new Node(key);
            // if linkedlist is empty
            if(head==nullptr)  {
                head = NewNode;
                return;
            }
            // if linkedlist is not empty
            NewNode->Next = head;
            head->Prev = NewNode;
            head = NewNode;
        }
        void insert_end(int key)  {
            Node* NewNode = new Node(key);
            if(head==nullptr)  {
                head = NewNode;
                return;
            }

            Node* temp = head;
            while(temp->Next!=nullptr)  {
                temp=temp->Next;
            }
            temp->Next = NewNode;
            NewNode->Prev = temp;
        }

        // inserts in the linkedlist at passed position
        void insert(int pos, int key)  {
            Node* NewNode = new Node(key);
            // if position == begining == (1)
            if(pos==1) {
                // empty ----> head == NewNode
                if(head == nullptr)  {
                    head = NewNode;
                    return; 
                }
                // if node present at pos 1 then insert.
                else{
                    NewNode->Next = head;
                    head->Prev = NewNode;
                    head = NewNode;
                    return;
                }
            }
            Node* temp = head;
            // traverse till position - 1     
            int count=2;
            while(temp->Next != nullptr && count<pos)  {
                temp=temp->Next;
                count++;
            }
            // end node of linkedlist
            if(temp->Next == nullptr)  {
                // if insertion is at the end (pos = size + 1)
                // then insert at end
                if(count == pos)  {
                    temp->Next = NewNode;
                    NewNode->Prev = temp;
                    return;
                }else{
                    cout<<"reached at the end of linkedlist cant insert :/ "<<endl;
                    return;
                }
            }
            // if reached pos && linkedlist is not empty
            // simple insertion
            else{
                temp->Next->Prev = NewNode;
                NewNode->Next = temp->Next;
                NewNode->Prev = temp;
                temp->Next = NewNode;
                return;
            }  
        }
        // delete first node
        void delete_first()  {
            if(head == nullptr)  {
                cout<<"linkedlist empty , Nothing to delete "<<endl;
                return;
            }else if(head->Next == nullptr)  {
                head = nullptr;
                return;
            }
            head->Next->Prev = nullptr;
            head = head->Next;                
        }
        // deletes last node
        void delete_last()  {
            if(head == nullptr)  {
                cout<<"linkedlist empty , Nothing to delete "<<endl;
                return;
            }
            // travel till last node
            Node* temp = head;
            while(temp->Next != nullptr)  {
                temp=temp->Next;
            }
            // remove last node
            temp->Prev->Next = nullptr;
            temp->Prev = nullptr;
        }
        
        // deletes nodes in linkedlist by position
        void remove(int pos)  {
            if(head == nullptr)  {
                cout<<"linkedlist empty , Nothing to delete "<<endl;
                return;
            }else if(pos == 1)  {
                if(head->Next == nullptr)  {
                    head = nullptr;
                    return;
                }else{
                    head->Next->Prev = nullptr;
                    head = head->Next; 
                    return;
                }
            }
            Node* temp = head;
            int count=1;
            
            while(temp->Next != nullptr && count<pos)  {
                temp=temp->Next;
                count++;
            }
            // reached at end
            if(temp->Next == nullptr)  {
                // pos == last node
                if(count == pos)  {
                    temp->Prev->Next = nullptr;
                    temp->Prev = nullptr;
                    return;
                }else{
                    cout<<"reached at end of the linkedlist , Nothing to delete "<<endl;
                    return;
                }
            }else{
                temp->Next->Prev = temp->Prev;
                temp->Prev->Next = temp->Next;
                temp->Next = nullptr;
                temp->Prev = nullptr;
            }

        }

};


int main()  {
    Dlinkedlist list1;
    // test examples
    list1.insert_begin(5);
    list1.insert_end(10);
    list1.insert_end(15);
    list1.insert_end(20);
    list1.insert_end(25);
    list1.insert_end(30);
    list1.insert_end(35);
    cout<<"displays linkedlist"<<endl;
    list1.display();
    cout<<"search for node with value 20"<<endl;
    cout<<"position returned : "<<list1.search(20)<<endl;
    list1.insert(7,99);
    cout<<"insertes node at pos 7 with val 99"<<endl;
    list1.display();
    list1.delete_first();
    cout<<"deletes first node"<<endl;
    list1.display();
    list1.delete_last();
    cout<<"deletes last node"<<endl;
    list1.display();
    list1.remove(2);
    cout<<"deletes node at position 2"<<endl;
    list1.display();
    
    
    return 0;
}

// starr 🌟 my repo please!! 
