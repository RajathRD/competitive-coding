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

  void insertBegin(int data)
  {
    Node *newNode = new Node();
    cout<<"Inserting: "<<data<<endl;
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

  void insertEnd(int data)
  {
    Node *newNode = new Node();
    cout<<"Inserting: "<<data<<endl;
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

  void delBegin()
  {
    if(size==0)
    {
      cout<<"Underflow"<<endl;
      return;
    }
    size--;
    Node* temp=head;
    head = head->getLink();
    cout<<"Deleted: "<<temp->getData()<<endl;
    free(temp);
  }

  void delEnd()
  {
    if(size==0)
    {
      cout<<"Underflow"<<endl;
      return;
    }
    else if(size==1)
    {
      cout<<"Deleted: "<<head->getData()<<endl;
      free(head);
      head=NULL;
      return;
    }
    size--;
    Node* temp=head;
    for(int i=0; i<size-1; i++)
    {
      temp=temp->getLink();
    }
    Node* toDelete = temp->getLink();
    cout<<"Deleted: "<<toDelete->getData()<<endl;
    temp->setLink(NULL);
    free(toDelete);
  }

  void display()
  {
    cout<<"...Contents of Linked List..."<<endl;
    if(size==0)
    {
      cout<<"List is Empty"<<endl;
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
        cout<<"Element not found"<<endl;
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
      cout<<"Element not found"<<endl;
    return;
  }

  int getSize()
  {
    return size;
  }
};

int main()
{
  linkedList list;
  for(int i=1;i<=5;i++)
  {
    list.insertBegin(i);
    list.insertEnd(i*i);
  }
  list.display();
  cout<<endl;
  list.delEnd();
  list.delEnd();
  list.delBegin();
  cout<<endl;
  list.searchN(15);
  cout<<endl;
  list.searchN(1);
  cout<<endl;
  list.display();
  cout<<endl;
  cout<<"Size : "<<list.getSize()<<endl;

  return 0;
}
