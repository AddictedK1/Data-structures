#include<iostream>
using namespace std;

class Node  {
    public:
        int data;
        Node* next;
        Node(int val)  {
            data = val;
            next = nullptr; 
        }

};


class Queue  {
    Node* head;
    Node* tail;

    public:
        // default constructor
        Queue()  {
            head = nullptr;
            tail = nullptr;
        }

        int length()  {
            if(head==nullptr)  return 0;
            int count=0;
            Node* temp = head;
            while(temp!=nullptr)  {
                temp = temp->next;
                count++;
            }
            return count;
        }


        void display()  {
            if(head == nullptr)  {
                cout<<"Queue Empty"<<endl;
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
                tail = NewNode;
            }else{
                tail->next = NewNode;
                tail = NewNode;
            }
        }

        int pop()  {
            if(head == nullptr)  {
                cout<<"Queue empty"<<endl;
                return -1;
            }else if(head == tail)  {
                int popped = head->data;
                head = nullptr;
                tail = nullptr;
                return popped;   
            }else{
                int popped = head->data;
                head = head->next;
                return popped;
            }
            
        }

        int peekfirst()  {
            if(head == nullptr)  {
                cout<<"Queue Empty"<<endl;
                return -1;
            }else{
                return head->data;
            }
        }

        int peeklast()  {
            if(head == nullptr)  {
                cout<<"Queue Empty"<<endl;
                return -1;
            }else{
                return tail->data;
            }
        }

        bool isEmpty()  {
            if(head==nullptr)  return true;
            else  return false;
        }

};


int main()  {
    Queue test;
    test.pop();
    test.push(10);
    test.peekfirst();
    test.peeklast();
    test.push(20);
    test.push(30);
    test.push(33);
    test.push(44);
    test.push(60);
    test.push(90);
    test.push(99);
    test.display();
    test.pop();
    test.pop();
    test.display();
    cout<<test.length()<<endl;

    return 0;
}
