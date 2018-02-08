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

  void insert(int data)
  {
    Node *newNode = new Node();
    cout<<"Inserting to front: "<<data<<endl;
    newNode->setData(data);
    if(size==0)
    {
      size=size+1;
      head = newNode;
      return;
    }

    Node* temp=head;
    for(int i = 1; i<size; i++)
      temp=temp->getLink();
    temp->setLink(newNode);
    size=size+1;
  }

  void remove()
  {
    if(size==0)
    {
      cout<<"Underflow"<<endl;
      return;
    }
    size--;
    Node* temp=head;
    head = head->getLink();
    cout<<"Removed from Queue: "<<temp->getData()<<endl;
    free(temp);
  }

  void display()
  {
    cout<<"...Contents of Queue[ First to Last ]..."<<endl;
    if(size==0)
    {
      cout<<"Queue is Empty"<<endl;
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

  void searchN(int data)
  {
    cout<<"Searching "<<data<<"..."<<endl;
    if(size==0)
    {
      cout<<"Underflow"<<endl;
      return;
    }
    else if(size==1)
    {
      if(head->getData()==data)
      {
        cout<<"Element found at: "<<size<<endl;
      }
      else
      {
        cout<<"Element never entered the queue"<<endl;
      }
      return;
    }
    Node* curr = head;
    bool present=false;
    for(int i=1;i<=size;i++)
    {
      if(curr->getData()==data)
      {
        present=true;
        cout<<"Element found at: "<<i<<endl;
      }
      curr=curr->getLink();
    }
    if(!present)
      cout<<"Element not found in Queue"<<endl;
    return;
  }

  int getSize()
  {
    return size;
  }
};

int main()
{
  linkedList q;
  for(int i=1;i<=5;i++)
  {
    q.insert(i);
    cout<<endl;
    q.display();
    cout<<endl;
    q.insert(i*i);
  }
  q.display();
  cout<<endl;
  q.remove();
  q.remove();
  q.remove();
  cout<<endl;
  q.searchN(15);
  cout<<endl;
  q.searchN(1);
  cout<<endl;
  q.display();
  cout<<endl;
  cout<<"Size : "<<q.getSize()<<endl;

  return 0;
}
