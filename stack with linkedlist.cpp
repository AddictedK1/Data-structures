#include<iostream>
using namespace std;

class Node  {
    

    public:
        int data;
        Node* next;
        Node(int val)  {
            data=val;
            next=nullptr;
        }
};

class stack  {
    Node* head;
    public:
        stack()  {
            head=nullptr;
        }

        void display()  {
            if(head == nullptr)  {
                cout<<"stack Empty"<<endl;
                return;
            }

            Node* temp = head;
            while(temp != nullptr)  {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }

        void push(int val)  {
            Node* NewNode = new Node(val);
            if(head == nullptr)  {
                head = NewNode;
                return;
            }
            NewNode->next = head;
            head = NewNode; 
        }


        int pop()  {
            if(head == nullptr)  {
                cout<<"stack Empty"<<endl;
                return -1;
            }
            int popped = head->data;
            head = head->next;
            return popped;
        }

        int peek()  {
            if(head == nullptr)  {
                cout<<"stack Empty"<<endl;
                return -1;
            }
            return head->data;
            
        }

        bool isEmpty()  {
            if(head!=nullptr) return false;
            return true;
        }

        int Size()  {
            if(head == nullptr)  {
                return 0;
            }
            Node* temp = head;
            int size = 0;
            while(temp!=nullptr)  {
                size++;
                temp = temp->next;
            }
            return size;
        }

};


int main()  {
    // test examples...
    stack mystack;

    cout<<mystack.isEmpty()<<endl;
    mystack.push(10);
    mystack.push(15);
    mystack.push(20);
    mystack.push(25);
    cout<<mystack.Size()<<endl;
    mystack.display();
    cout<<mystack.pop()<<endl;
    cout<<mystack.peek()<<endl;
    mystack.pop();
    mystack.pop();
    mystack.pop();
    mystack.display();
    cout<<mystack.pop()<<endl;
    cout<<mystack.Size()<<endl;
    return 0;
}
