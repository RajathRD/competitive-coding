#include<iostream>
#include<stdlib.h>

using namespace std;

class Node{
  int data;
  Node *link;
  public:

  Node()
  {
    link=NULL;
    data=0;
  }

  void setData(int x)
  {
    data=x;
  }

  void setLink(Node* x)
  {
    link=x;
  }

  int getData()
  {
    return data;
  }

  Node* getLink()
  {
    return link;
  }
};

class linkedList
{
  Node* head;
  int size;

  public:
  linkedList()
  {
    head=NULL;
    size=0;
  }

  void push(int data)
  {
    Node *newNode = new Node();
    cout<<"Pushing: "<<data<<endl;
    newNode->setData(data);
    size=size+1;
    if(size==0)
    {
      head = newNode;
      return;
    }
    newNode->setLink(head);
    head = newNode;
  }

  void pop()
  {
    if(size==0)
    {
      cout<<"Underflow"<<endl;
      return;
    }
    size--;
    Node* temp=head;
    head = head->getLink();
    cout<<"Popped: "<<temp->getData()<<endl;
    free(temp);
  }

  void display()
  {
    cout<<"...Contents of Stack[ Top to bottom ]..."<<endl;
    if(size==0)
    {
      cout<<"Stack is Empty"<<endl;
      return;
    }
    Node* current = head;
    for(int i=0; i<size; i++)
    {
      cout<<current->getData()<<" ";
      current = current->getLink();
    }
    cout<<"\n";
  }

  int getSize()
  {
    return size;
  }
};

int main()
{
  linkedList stack;
  for(int i=1;i<=5;i++)
  {
    stack.push(i);
    cout<<endl;
    stack.display();
    stack.push(i*i);
  }
  stack.display();
  cout<<endl;
  stack.pop();
  stack.pop();
  stack.pop();
  cout<<endl;
  stack.display();
  cout<<endl;
  cout<<"Size : "<<stack.getSize()<<endl;

  return 0;
}
