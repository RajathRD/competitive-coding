//
//  Linked_list_pointers.cpp
//  
//
//  Created by Ragavendra Dani & Pushpender Singh on 3/17/16.
//
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>

#define MAX_NUM 10
using namespace std;

struct nodeType
{
    int info;
    struct nodeType *link;

}*first;

class list
{
public:
    
    nodeType* createNode(int);
    void create_node();
    void insertNode();
    void deleteNode();
    void searchNode();
    void displayNode();
    list()
    {	
        first = NULL;
    }
};

nodeType *list::createNode(int data)
{
    struct nodeType *temp;
    temp = new(struct nodeType);
    
    if (temp == NULL)
    {
        cout<<"No Memory allocated"<< endl;
    }
    else
    {
        temp->info = data;
        temp->link = NULL;
        return temp;
    }
}
void list::create_node()
{
    int value=rand()% 10000 +1;
    
    struct nodeType *temp, *p;
    temp = createNode(value);
    if (first == NULL)
    {
        first = temp;
        first->link = NULL;
    }
    else
    {
        p = first;
        first = temp;
        first->link = p;
    }
    cout<<"Element Inserted at beginning"<<endl;
}


void list::insertNode()
{
    int value, count = 0, position;
    
    cout<<"Enter the value to be inserted:"<<endl;
    cin>>value;
    
    struct nodeType *temp, *s, *ptr, *newNode;
    temp = createNode(value);
    
    cout<<"Enter the position the node will be inserted:"<<endl;
    cin>>position;
    
    s = first;
    while(s != NULL)
    {    s = s -> link;
        count++;
    }
    if (position == 1)
    {
        if (first == NULL)
        {
            first = newNode;
            first->link = NULL;
        }
        else
        {
            ptr = first;
            first = newNode;
            first->link = ptr;
        }
    }
    else if (position > 1  && position <= count)
    {
        s = first;
        for (int i = 1; i < position; i++)
        {
            ptr = s;
            s = s->link;
        }
        ptr->link = temp;
        temp->link = s;
    }
    else
    {
        cout<<"Positon out of range"<<endl;
    }
}

void list::deleteNode()
{
    int position, counter = 0;
    if (first == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    cout<<"Enter the position of value to be deleted: ";
    cin>>position;
    struct nodeType *s, *ptr;
    s = first;
    if (position == 1)
    {
        first = s->link;
    }
    else
    {
        while (s != NULL)
        {
            s = s->link;
            counter++;
        }
        if (position > 0 && position <= counter)
        {
            s = first;
            for (int i = 1;i < position;i++)
            {
                ptr = s;
                s = s->link;
            }
            ptr->link = s->link;
        }
        else
        {
            cout<<"Position out of range"<<endl;
        }
        free(s);
        cout<<"Element Deleted"<<endl;
    }
}
void list::searchNode()
{
    int value, position = 0;
    bool flag = false;
    if (first == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    cout<<"Enter the value to be searched: ";
    cin>>value;
    struct nodeType *s;
    s = first;
    while (s != NULL)
    {
        position++;
        if (s->info == value)
        {
            flag = true;
            cout<<"Element "<<value<<" is found at position "<<position<<endl;
        }
        s = s->link;
    }
    if (!flag)
        cout<<"Element "<<value<<" not found in the list"<<endl;
}

void list::displayNode()
{
    struct nodeType *temp;
    if (first == NULL)
    {
        cout<<"The List is Empty"<<endl;
        return;
    }
    temp = first;
    cout<<"Elements of list are: "<<endl;
    while (temp != NULL)
    {
        cout<<temp->info<<"->";
        temp = temp->link;
    }
    cout<<"NULL"<<endl;
}


int main()
{
    int choice,len=MAX_NUM;
    list ll;
    cout<<"List being created..."<<endl;
    cout<<"List created"<<endl;
    for(int i=0;i<len;i++)
    {ll.create_node();
}	
    ll.displayNode();
    while (1)
    {
        cout<<endl<<"---------------------------------"<<endl;
        cout<<endl<<"Operations on singly linked list"<<endl;
        cout<<endl<<"---------------------------------"<<endl;
        cout<<"1.Insert Node at beginning"<<endl;
        cout<<"2.Insert node at position"<<endl;
        cout<<"3.Delete a Particular Node"<<endl;
        cout<<"4.Search Element"<<endl;
        cout<<"5.Display Linked List"<<endl;
        cout<<"6.Exit "<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Inserting Node at Beginning: "<<endl;
                ll.create_node();
                cout<<endl;
                break;
           
            case 2:
                cout<<"Inserting Node at a given position:"<<endl;
                ll.insertNode();
                cout<<endl;
                break;
           
            case 3:
                cout<<"Delete a particular node: "<<endl;
                ll.deleteNode();
                break;
            
            case 4:
                cout<<"Search element in Link List: "<<endl;
                ll.searchNode();
                cout<<endl;
                break;
            case 5:
                cout<<"Display elements of link list"<<endl;
                ll.displayNode();
                cout<<endl;
                break;
            
            case 6:
                cout<<"Exiting..."<<endl;
                exit(1);
                
                break;
                
            default:
                cout<<"Wrong choice"<<endl;
        }
    }
    return 0;
}

