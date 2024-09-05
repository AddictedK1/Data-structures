#include<iostream>
using namespace std;

class Node  {
    public:
        int data;
        Node* Next;
        Node* Prev;
        Node(int val)  {
            data = val;
            Next = nullptr;
            Prev = nullptr;
        }

};

class DlinkedlistWTail  {
        Node* head;
        Node* tail;
        int size; 
    public:
        DlinkedlistWTail()  {
            head = nullptr;
            tail = nullptr;
            size = 0;
        }
        void print()  {
            Node* temp = head;
            while(temp!=nullptr)  {
                cout<<temp->data<<" ";
                temp = temp->Next;
            }
            cout<<endl;
        }

        void printRev()  {
            Node* temp = tail;
            while(temp!=nullptr)  {
                cout<<temp->data<<" ";
                temp = temp->Prev;
            }
            cout<<endl;
        }

        void addfirst(int val)  {
            Node* NewNode = new Node(val);
            if(head == nullptr)  {
                head = NewNode;
                tail = NewNode;
                size++;
                return;
            }
                NewNode->Next = head;
                head->Prev = NewNode;
                head = NewNode;
                size++;
        }

        void addlast(int val)  {
            Node* NewNode = new Node(val);
            if(head == nullptr)  {
                head = NewNode;
                tail = NewNode;
                size++;
                return;
            }
            tail->Next = NewNode;
            NewNode->Prev = tail;
            tail = NewNode;
            size++;
        }

        //  insert at position passed
        void insert(int pos, int val)  {
            if(pos>0 && pos<=size+1)  {   
            if(head == nullptr)  {
                Node* NewNode = new Node(val); 
                
                if(pos==1)  {
                    head = NewNode;
                    tail = NewNode;
                    size++;
                    return;
                }else{
                    cout<<"linkedlist empty, enter a valid position "<<endl;
                    return;
                }
            }else{
                if(pos==1)  {
                    Node* NewNode = new Node(val); 
                    head->Prev = NewNode;
                    NewNode->Next = head;
                    head = NewNode;
                    size++;
                    return;
                }
                if(pos==size+1)  {
                    Node* NewNode = new Node(val);
                    tail->Next = NewNode;
                    NewNode->Prev = tail;
                    tail = NewNode;
                    size++;
                    return;
                }
            }
            if(pos<=(size/2))  {
                Node* NewNode = new Node(val);
                Node* temp = head;
                int count=2;
                while(count<pos)  {
                    temp=temp->Next;
                    count++;
                }
                temp->Next->Prev = NewNode;
                NewNode->Next = temp->Next;
                NewNode->Prev = temp;
                temp->Next = NewNode;
                size++;
                return;
            
            }else{
                Node* NewNode = new Node(val);
                Node* temp = tail;
                int count=size-pos;
                while(count>0)  {
                    temp = temp->Prev;
                    count--;
                }
                NewNode->Prev = temp->Prev;
                temp->Prev->Next = NewNode;
                NewNode->Next = temp;
                temp->Prev = NewNode;
                size++;
                return;

            }

        }else if(pos>size+1)  {
            cout<<"reached at the end of the linkedlist, enter a valid position to insert on"<<endl;
            return;
        }
        
        
        }  // end of insert function. 


        void remove_first()  {
            if(head==nullptr)  {
                cout<<"linkedlist is empty, nothing to delete"<<endl;
                return;
            }else if(head == tail)  {
                head=nullptr;
                tail=nullptr;
                size--;
                return;
            }else{
                head = head->Next;
                head->Prev = nullptr;
                size--;
            }
        }


        void remove_last()  {
            if(head==nullptr)  {
                cout<<"linkedlist is empty, nothing to delete"<<endl;
                return;
            }else if(head == tail)  {
                head=nullptr;
                tail=nullptr;
                size--;
                return;
            }else{
                tail = tail->Prev;
                tail->Next = nullptr;
                size--;
            }
        }

        void remove(int pos)  {
            if(pos>size)  {
                cout<<"reaches at end of linkedlist, nothing to delete"<<endl;
                return;
            }
            if(pos<1)  {
                cout<<"enter a valid node position to remove"<<endl;
                return;
            }
            
            if(head == nullptr)  {
                cout<<"linkedlist empty, nothing to remove"<<endl;
                return;
            }
            if(pos==1)  {
                if(head == tail)  {
                    head=nullptr;
                    tail=nullptr;
                    size--;
                    return;
                }else{
                    head=head->Next;
                    head->Prev = nullptr;
                    size--;
                    return;
                }
            }
            if(pos==size)  {
                tail = tail->Prev;
                tail->Next = nullptr;
                size--;
                return;
            }
            Node* temp;
            int count;
            if(pos > (size/2))  {
                temp = tail;
                count=(size-pos);
                while(count--)  {
                    temp = temp->Prev;
                }
                temp->Next->Prev = temp->Prev;
                temp->Prev->Next = temp->Next;
                temp->Next = nullptr;
                temp->Prev = nullptr;
                size--;

            }else{
                temp = head; 
                count = pos;
                while(--count)  {
                    temp = temp->Next;
                }
                temp->Next->Prev = temp->Prev;
                temp->Prev->Next = temp->Next;
                temp->Next = nullptr;
                temp->Prev = nullptr;
                size--;

            }
            
            
        }



};



int main()  {
    DlinkedlistWTail mylist;
    mylist.addfirst(15);
    mylist.addfirst(25);
    mylist.addlast(35);
    mylist.insert(3,55);
    mylist.insert(5,66);
    mylist.insert(1,77);
    mylist.print();
    mylist.remove_first();
    mylist.remove_last();
    mylist.print();
    mylist.remove(2);
    mylist.print();
    mylist.remove(1);
    mylist.print();
    mylist.remove(2);
    mylist.print();
    
    return 0;
}
