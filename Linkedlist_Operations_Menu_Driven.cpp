// Data structure 
// Singly linkedlist

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
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

        int countNodes()  {
            Node* temp = head;
            int nodes=0;
            while(temp!=nullptr)  {
                nodes++;
                temp = temp->Next;
            }
            return nodes;
        }

        vector<int> countEvenOdds()  {
            Node* temp = head;
            vector<int> evenOdd(2);  // [even, odd]
            while(temp!=nullptr)  {
                if(temp->data % 2) evenOdd[1]++;
                else evenOdd[0]++; 
                temp = temp->Next;
            }
            return evenOdd;
        }

        vector<Node*> splitEvenOdds()  {
            LinkedList evens;
            LinkedList odds;    
            Node* temp = head; 
            while(temp!=nullptr)  {
                if(temp->data % 2) odds.insert_first(temp->data);
                else evens.insert_first(temp->data);
                temp = temp->Next;
            }

            vector<Node*> vec;   // [odd,even]
            vec.push_back(evens.head);
            vec.push_back(odds.head);
            return vec;
        }

};

int main()  {

    LinkedList list;
    
    int user;
    cout<<"enter 0 to quit or enter anything to enter Menu : ";
    cin>>user;
    
    while(user)  {
        cout<<"🔷 enter 1 to add an element"<<endl;
        cout<<"🔷 enter 2 to delete element"<<endl; 
        cout<<"🔷 enter 3 search an element"<<endl; 
        cout<<"🔷 enter 4 to print linkedlist"<<endl;
        cout<<"🔷 OR enter 0 QUITT"<<endl;  
        cout<<"➡️ ";
        cin>>user;
        cout<<"➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖"<<endl;
        if(user == 0)  {
            return 0;
        }else if(user == 1)  {
            int val;
            int idx;
            cout<<"🔷 enter 1 to add first"<<endl;
            cout<<"🔷 enter 2 to add last"<<endl; 
            cout<<"🔷 enter 3 to add by position"<<endl;
            cin>>user;
            if(user == 1)  {
                cout<<"enter value : ";
                cin>>val;
                list.insert_first(val); 
            }else if(user == 2)  {
                cout<<"enter value : ";
                cin>>val;
                list.insert_last(val);
            }else if(user == 3)  {
                cout<<"enter value : ";
                cin>>val;
                cout<<"enter index : ";
                cin>>idx;
                list.insert(val, idx);
            }else {
                cout<<"enter a valid operation 😑 "<<endl;
            }

        }else if(user == 2)  {
            int val;
            int idx;
            cout<<"🔷 enter 1 to delete first"<<endl;
            cout<<"🔷 enter 2 to delete last"<<endl; 
            cout<<"🔷 enter 3 to delete by position"<<endl;
            cin>>user;
            if(user == 1)  {
                list.delete_first(); 
            }else if(user == 2)  {
                list.delete_last();
            }else if(user == 3)  {
                cout<<"enter index : ";
                cin>>idx;
                list.remove(idx);
            }else {
                cout<<"enter a valid operation 😑 "<<endl;
            }
        }else if(user == 3)  {
            int val;
            cout<<"enter a value to search : ";
            cin>>val;
            list.search(val);
        }else if(user == 4)  {
            cout<<"linkedlist --> ";
            list.display();
        }else {
            cout<<"enter an valid value..."<<endl;
        }

    }
    cout<<"original linkedlist ==>  10 15 65 78 45 21 12"<<endl;
    cout<<"nodes ==> 7"<<endl;
    cout<<"even nodes ==> 10 78 12"<<endl;
    cout<<"odd nodes ==> 15 65 45"<<endl;
                                                                
    return 0;
}
