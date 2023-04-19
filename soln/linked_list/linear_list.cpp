/*Implement a Linked List class (Don’t forget to add copy constructor) which performs
the following operations:
Concatenate (+), Reverse ( ! ), Compare (==), Copy (=), Subscript ([ ]) –
check and display message when index is more than the size of the list,
Allocation/Deallocation (new, delete) – using avail list, Input-Output (>>,<<)*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class sll
{
    int size;
    Node *head;

public:
    sll()
    {
        head = NULL;
    }
    friend istream &operator>>(istream &in, sll &s);
    friend ostream &operator<<(ostream &out, sll &s);
    sll operator+(sll &l1)
    {
        sll temp;
        temp.head = head;
        Node *d = temp.head;
        while (d->next != NULL)
        {
            d = d->next;
        }
        d->next = l1.head;
        return temp;
    }

    void operator[](int i){
       if(i>=size){
        cout<<"index is out of bound "<<endl;
        exit(0);
       }
       Node*temp=head;

       while(i--){
          temp=temp->next;
       }
       cout<<temp->data<<endl;
    }

    sll operator!()
    {
        sll temp;
        temp.head = head;
        Node *prev = NULL;
        Node *ptr = head;
        Node *curr = head->next;
        while (curr)
        {
            ptr->next = prev;
            prev = ptr;
            ptr = curr;
            curr = curr->next;
        }

        ptr->next = prev;

        temp.head = ptr;
        return temp;
    }

   bool operator==(sll &s){
         if(size!=s.size)return false;
         Node*ptr1=head;
         Node*ptr2=s.head;
         while(ptr1!=NULL){
            if(ptr1->data!=ptr2->data)return false;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
         }
         return true;
        
    }
};

istream &operator>>(istream &in, sll &s)
{
    cout << "Enter size of linked list" << endl;
    in >> s.size;
    cout << "Enter value" << endl;
    Node *newnode = new Node();
    in >> newnode->data;
    newnode->next = NULL;
    s.head = newnode;
    for (int i = 1; i < s.size; i++)
    {
        Node *temp = new Node();
        in >> temp->data;
        temp->next = NULL;
        newnode->next = temp;
        newnode = newnode->next;
    }

    return in;
}

ostream &operator<<(ostream &out, sll &s)
{
    Node *temp = s.head;
    while (temp != NULL)
    {
        out << temp->data << " ";
        temp = temp->next;
    }
    return out;
}

int main()
{
    sll l1, l2, l3, l4;
    cin >> l1;
    cout << l1 << endl;
    cin >> l2;
    cout << l2 << endl;
    l3 = l1 + l2;
    cout << l3 << endl;
    l4 = (!l1);
    cout<<endl;
    cout << l4 << endl;
    bool ans=(l1==l2);
    cout<<ans;
    l1[3];
}