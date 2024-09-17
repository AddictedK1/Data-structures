#include<iostream>
using namespace std;


class stack  {
    int *arr;
    int top;
    int capacity;
    public:
        stack(int size)  {
            capacity = size;
            arr = new int(capacity);
            top=-1;
        }

        void print()  {
            if(top == -1)  {
                cout<<"stack empty"<<endl;
                return;
            }
            for(int i=0; i<=top; i++)  {
                cout<<arr[i]<<" ";
            }
            cout<<endl;

        }
        

        bool isEmpty()  {
            if(top==-1)  {
                return true;
            }
            return false;
        }

        bool isFull()  {
            if(top+1==capacity)  {
                return true;
            }
            return false;
        }

        int peek()  {
            if(top==-1)  {
                cout<<"stack empty"<<endl;
                return 0;
            }
            return arr[top];
        }

        int pop()  {
            if(top==-1)  {
                cout<<"stack empty"<<endl;
                return 0;
            }
            top--;
            return arr[top+1]; 
        }

        void push(int val)  {
            if((top+1) == capacity)  {
                cout<<"stack full"<<endl;
                return;
            }
            arr[++top] = val;
        }

        int Size()  {
            return (top+1);
        }

};


int main()  {
    // sample test examples
    stack stk(10);
    stk.isEmpty();
    stk.print();
    stk.isFull();
    stk.pop();
    cout<<stk.Size()<<endl;
    stk.push(15);
    stk.push(25);
    stk.push(35);
    stk.print();
    
    return 0;
}
