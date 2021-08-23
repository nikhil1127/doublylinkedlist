// Doubly Linked List
//In a linked list the last pointer is always pointing towards null where as it is different in case of circular linked lists
//Here we are going to discuss only on linked lists
#include<iostream>
#include<windows.h>
using namespace std;
class dlist
{
    int info;//Information stored at the address pointed by the pointer
    dlist* next;//pointer to access next element name can be anything here to easily understand the traversing across list I took next and prev and info
    dlist* prev;//pointer to access previous element
public:
    dlist* insert_end(dlist*);
    dlist* delete_end(dlist*);
    void disp(dlist*);
    dlist* insert_pos(dlist*,int);
    dlist* delete_pos(dlist*,int);
    dlist* insert_after(dlist *,int);
    dlist* insert_before(dlist *,int);
    dlist* rev(dlist*);
    dlist* sortlist(dlist*);
};


void dlist::disp(dlist* start)
{
    dlist *cur=start;

    if(cur == NULL)
    {
        cout<<" Empty\n";
        start = NULL;
    }
    //To access the next address or previous address in c++ we use "->"
    cout<<"List is:  ";
    while (cur->next!=NULL)
    {
        cout<<cur->info<<"<->";//accessing information stored at pointer cur using "->"
        cur=cur->next;
    }
    cout<<cur->info<<"<->N";
}


dlist* dlist::insert_end(dlist* start)
{
    dlist *temp=new dlist;
    cout<<"\nEnter element: ";
    cin>>temp->info;
    temp->next=NULL;
    temp->prev=NULL;
    if(start==NULL)//for list is empty
    {
        start=temp;
        return start;
    }
    dlist *cur=start;//assigning start to a temporary pointer 'cur' and traversing across list
    while(cur->next!=NULL)
        cur=cur->next;
    cur->next=temp;
    temp->prev=cur;
    //cur->N so cur->next = temp means cur->temp and temp->prev = cur means cur<->temp and as temp->next = NULL then cur<->temp<->N
    return start;
}


dlist *dlist::delete_end(dlist *start)
{
    if(start==NULL)
    {
        cout<<"\n\tNothing to delete(List is Empty)\n";
        return start;
    }
    if(start->next==NULL)
    {
        delete(start);
        start=NULL;
        return start;
    }
    dlist *cur=start;
    while(cur->next!=NULL)
    {
        cur=cur->next;
    }
    (cur->prev)->next=NULL;
    delete(cur);
    return start;
}


dlist* dlist::insert_pos(dlist* start,int pos)
{
    int c=1;
    dlist *cur=start;
    if(pos<=0)
    {
        cout<<"\n\tInvalid Position\n";
        return start;
    }
    while(cur!=NULL && c<pos)
    {
        cur=cur->next;
        c++;
    }
    if(cur==NULL)
    {
        cout<<"\n\tPosition exceeds length of list\n";
        return start;
    }
    dlist *temp=new dlist;
    cout<<"Enter element: ";
    cin>>temp->info;
    temp->next=NULL;
    temp->prev=NULL;
    if(pos==1)
    {
        temp->next=start;
        start->prev=temp;
        start=temp;
        return start;
    }
    temp->next=cur;
    temp->prev=cur->prev;
    (cur->prev)->next=temp;
    cur->prev=temp;
    return start;
}


dlist* dlist::delete_pos(dlist* start,int pos)
{
    int c=1;
    dlist *cur=start;
    if(pos<=0)
    {
        cout<<"\n\tInvalid Position\n";
        return start;
    }
    while(cur!=NULL && c<pos)
    {
        cur=cur->next;
        c++;
    }
    if(cur==NULL)
    {
        cout<<"\nPosition exceeds length of list\n";
        return start;
    }
    dlist *k=start;
    if(pos==1)
    {
        start=start->next;
        delete(k);
        //start=start->prev;
        return start;
    }
    if(cur->next==NULL)
    {
        (cur->prev)->next=cur->next;
        delete(cur);
        return start;
    }
    (cur->prev)->next=cur->next;
    (cur->next)->prev=cur->prev;
    delete(cur);
    return start;
}


dlist* dlist::insert_after(dlist *start,int ele)
{
    dlist *cur=start;
    dlist *temp=new dlist;
    cout<<"Enter element to be inserted: ";
    cin>>temp->info;
    temp->next=NULL;
    temp->prev=NULL;
    if(start==NULL)
    {
        cout<<"\nlist is empty so insertion not possible\n";
        return start;
    }
    while(cur!=NULL && cur->info!=ele)
    {
        cur=cur->next;
    }
    if(cur==NULL)
    {
        cout<<"\nThe given element is not present. So insertion not possible\n";
        return start;
    }
    if(cur->next==NULL)
    {
        temp->next=cur->next;
        temp->prev=cur;
        cur->next=temp;
        return start;
    }
    temp->next=cur->next;
    temp->prev=cur;
    (cur->next)->prev=temp;
    cur->next=temp;
    return start;
}


dlist* dlist::insert_before(dlist *start,int ele)
{
    dlist *cur=start;
    dlist *temp=new dlist;
    cout<<"Enter element to be inserted: ";
    cin>>temp->info;
    temp->next=NULL;
    temp->prev=NULL;
    while(cur!=NULL && cur->info!=ele)
        cur=cur->next;
    if(cur==NULL)
    {
        cout<<"\nElement does not present in list so insertion not possible\n";
        return start;
    }
    if(cur->prev==NULL)
    {
        temp->next=cur;
        cur->prev=temp;
        start=temp;
        return start;
    }
    temp->next=cur;
    temp->prev=cur->prev;
    (cur->prev)->next=temp;
    cur->prev=temp;
    return start;
}


dlist* dlist::rev(dlist* start)
{
    dlist  *last,*cur=start,*temp;
    while(cur->next!=NULL)
        cur=cur->next;
    last=cur;
    cur=start;
    while(cur->next!=NULL)
    {
        cur=cur->next;
        temp=(cur->prev)->next;
        (cur->prev)->next=(cur->prev)->prev;
        (cur->prev)->prev=temp;
    }
    temp=cur->next;
    cur->next=cur->prev;
    cur->prev=temp;
    start=last;
    return start;
}

dlist* dlist::sortlist(dlist* start)
{
    dlist *p = start,*q = start;
    int temp;
    while(p!=NULL)
    {
     q=p->next;
      while(q!=NULL)
        {
          if(p->info>q->info)
            {
             temp=q->info;
             q->info=p->info;
             p->info=temp;
            }
          q=q->next;
        }
      p=p->next;
    }
return start;
}


int main()
{
    system("Color E4");
    dlist *start=NULL,a;//start pointer to access list
    cout<<"\t\t\t\t==============================================================="<<endl;
    cout<<"\t\t\t\t           DOUBLE LINKED LIST AND IT'S OPERATIONS              "<<endl;
    cout<<"\t\t\t\t==============================================================="<<endl;
    cout<<"Creating list:...";
    int lim;
    cout<<"\nEnter no of elements: ";
    cin>>lim;
    for(int i=0;i<lim;i++)
    {
        start=a.insert_end(start);
    }
    if(lim <= 0)
    {
        start = NULL;
        cout<<"List is Empty\n";
    }
    else
    {
        cout<<lim<<"  Elements Inserted into double linked list"<<endl;
        a.disp(start);
    }
    char n;
    do
    {
        cout<<"\nEnter \n\t1-insert_end\n\t2-display\n\t3-delete_end\n\t4-insert_pos\n\t5-delete_pos\n\t6-insert_after\n\t7-insert_before\n\t8-reverse\n\t9-sort\n\tE-exit\n\n";
        cin>>n;
        system("cls");
        switch(n)
        {
            case '1':
                //Function to insert element at the end of the list
                start=a.insert_end(start);
                cout<<"Operation Successful....."<<endl;
                break;
            case '2':
                //Function to display List Elements
                a.disp(start);
                break;
            case '3':
                //Function to delete element at the end of the list
                start=a.delete_end(start);
                cout<<"Operation Successful....."<<endl;
                break;
            case '4':
                //Function to insert element at given position
                int pos;
                cout<<"Enter position to insert element: ";
                cin>>pos;
                start=a.insert_pos(start,pos);
                cout<<"Operation Successful....."<<endl;
                break;
            case '5':
                //Function to delete element at given position
                cout<<"Enter position to delete element: ";
                cin>>pos;
                start=a.delete_pos(start,pos);
                cout<<"Operation Successful....."<<endl;
                break;
            case '6':
                //Function to insert element after given element
                a.disp(start);
                cout<<"\nEnter element to which insertion happens after this: ";
                int ele;
                cin>>ele;
                start=a.insert_after(start,ele);
                cout<<"Operation Successful....."<<endl;
                break;
            case '7':
                //Function to delete element after given element
                a.disp(start);
                cout<<"\nEnter element to which insertion happens before this: ";
                cin>>ele;
                start=a.insert_before(start,ele);
                cout<<"Operation Successful....."<<endl;
                break;
            case '8':
                //Function to reverse the list
                start=a.rev(start);
                cout<<"Operation Successful....."<<endl;
                break;
            case '9':
                //Function to sort the list
                start = a.sortlist(start);
                cout<<"Operation Successful....."<<endl;
                break;
            case 'E'://when capital letter is given input
                exit(0);
            case 'e'://when small letter is given input
                exit(0);
            default:
                cout<<"\nEnter Valid Input\n";
                break;
        }
    }while(n!='e' || n!='E');
    return 0;
}
