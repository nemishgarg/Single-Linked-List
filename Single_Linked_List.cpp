#include<iostream>
#include<cstdlib>

using namespace std;
struct node
{
    int data;
    struct node* link;
};
node* root = NULL;

/*Function to create a new node using dynamic allocation*/
node* getnode(void)
{
    node* ptr;
    ptr = new node;
    return (ptr);
}

/*Function to free a node*/
void freenode(node* ptr)
{
    delete(ptr);
}

/*Function to add a node at the end of the list*/
void append(void)
{
    node* temp;
    temp = getnode();
    cout<<"Enter the data you want to insert :\n";
    cin>>temp->data;
    if(root==NULL)
    {
        root = temp;
    }
    else
    {
        node* ptr = root;
        while(ptr->link!=NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = temp;
    }
    cout<<"Element inserted successfully!!!\n";
}

/*Function to add a node at the beginning of the list*/
void AddAtBegin(void)
{
    node* temp;
    temp = getnode();
    cout<<"Enter the data you want to insert :\n";
    cin>>temp->data;
    temp->link = root;
    root = temp;
    cout<<"Element inserted successfully!!!\n";
}

/*Function to find location of node after which we want to insert the element*/
node* nodeforInsertion(int data)
{
    node* loc;
    node* save;
    node* ptr;
    save = root;
    ptr = root->link;
    if(root==NULL)
    {
        loc = NULL;
        return loc;
    }
    if(data<root->data)
    {
        loc = NULL;
        return loc;
    }
    while(ptr!=NULL)
    {
        if(data<ptr->data)
        {
            loc = save;
            return loc;
        }
        save = ptr;
        ptr = ptr->link;
    }
    loc = save;
    return loc;
}

/*Function to add a node in between two nodes*/
void AddBetween(void)
{
    node* temp;
    node* loc;
    temp = getnode();
    cout<<"Enter the data you want to insert :\n";
    cin>>temp->data;
    loc = nodeforInsertion(temp->data);
    if(loc==NULL)
    {
        temp->link = root;
        root = temp;
    }
    else
    {
        temp->link = loc->link;
        loc->link = temp;
    }
    cout<<"Element inserted successfully!!!\n";
}

/*Function to find location of node which we want to delete and location of previous node*/
void nodeforDeletion(int ele,node** loc,node** locp)
{
    node* save;
    node* ptr;
    save = root;
    ptr = root->link;
    if(root==NULL)
    {
        *loc = NULL;
        *locp = NULL;
        return;
    }
    if(ele==root->data)
    {
        *loc = root;
        *locp = NULL;
        return;
    }
    while(ptr!=NULL)
    {
        if(ele==ptr->data)
        {
            *loc = ptr;
            *locp = save;
            return;
        }
        save = ptr;
        ptr = ptr->link;
    }
    *loc = NULL;
    return;
}

/*Function to delete a node*/
void deleteNode(node* loc,node* locp)
{
    if(loc==NULL)
    {
         cout<<"Element is not found to delete\n";
         return;
    }
    if(locp==NULL)
    {
        root=root->link;
        freenode(loc);
        cout<<"Item deleted successfully!!!\n";
    }
    else
    {
        locp->link = loc->link;
        freenode(loc);
        cout<<"Item deleted successfully!!!\n";
    }
}

/*Function to display the list in forward direction*/
void display(void)
{
    node* temp = root;
    if(temp==NULL)
    {
        cout<<"No elements to display\n";
    }
    else
    {
         while(temp!=NULL)
         {
            cout<<temp->data;
            temp = temp->link;
            if(temp!=NULL)
            {
                cout<<"-->";
            }
         }
         cout<<endl;
    }
}

/*Function to find the length of the list*/
int length(void)
{
    int len = 0;
    node* temp = root;
    while(temp!=NULL)
    {
        len++;
        temp = temp->link;
    }
    return(len);
}

/*Function to search a element in list*/
node* search(int item)
{
    node* loc;
    node* ptr = root;
    while(ptr!=NULL)
    {
        if(ptr->data==item)
        {
            return(ptr);
        }
        else
        {
            ptr = ptr->link;
        }
    }
    return(NULL);
}

/*Function to reverse the list*/
void reverse()
{
    node *current = root;
    node *prev = NULL, *link = NULL;
    while (current != NULL)
    {
        // Store next
        link = current->link;
        // Reverse current node's pointer
        current->link = prev;
        // Move pointers one position ahead.
        prev = current;
        current = link;
    }
    root = prev;
    cout<<"List reversed successfully!!!\n";
}

int main()
{
    int ch;
    while(1)
    {
        cout<<"Press 1 to append a node to list\n";
        cout<<"Press 2 to insert a node in beginning\n";
        cout<<"Press 3 to insert a node in between two nodes\n";
        cout<<"Press 4 to delete a node\n";
        cout<<"Press 5 to display the list\n";
        cout<<"Press 6 to find the length of list\n";
        cout<<"Press 7 to search an element in list\n";
        cout<<"Press 8 to reverse the list\n";
        cout<<"Press 9 to exit from program\n\n";
        cout<<"Enter your choice : ";
        cin>>ch;
        cout<<endl;
        switch(ch)
        {
            case 1:
                append();
                cout<<endl;
                break;
            case 2:
                AddAtBegin();
                cout<<endl;
                break;
            case 3:
                AddBetween();
                cout<<endl;
                break;
            case 4:
                node* loc;
                node* locp;
                int item;
                cout<<"Enter the data you want to delete : \n";
                cin>>item;
                nodeforDeletion(item,&loc,&locp);
                deleteNode(loc,locp);
                cout<<endl;
                break;
            case 5:
                display();
                cout<<endl;
                break;
            case 6:
                int len;
                len = length();
                cout<<"Size of linked list is : "<<len<<endl;
                cout<<endl;
                break;
            case 7:
                int finditem;
                cout<<"Enter the element you want to search : \n";
                cin>>finditem;
                node* location;
                location = search(finditem);
                if(location==NULL)
                {
                    cout<<"Search is unsuccessful, element not found\n";
                }
                else
                {
                    cout<<"Search is successful, element found\n";
                }
                cout<<endl;
                break;
            case 8:
                reverse();
                cout<<endl;
                break;
            case 9:
                exit(0);
            default:
                cout<<"Please enter correct choice\n";
                cout<<endl;
        }
    }
    return 0;
}
