#include <iostream>
using namespace std;
class Node//defines the structure of each Node of the tree
{
    public:
    int data;//stores the data
    Node* left;//pointer to the next node on the left
    Node* right;//pointer to the next node on the right
    Node* previous;
    public:
    Node(int val)//parameterized constructor to assign the passed values
    {
        data=val;//data stoes the passed integer arguement
        left=NULL;//pointer to the next Node on the left NULL by deafult
        right=NULL;//pointer to the next Node on the right NULL by default
        previous=NULL;
    }//end of parametrized constructor
};//end of class Node
class BinarySearchTree
{
    private:
    Node* root;//data memeber pointing to the root of the tree
    public:
    BinarySearchTree()//default constructor
    {
        root=NULL;//assigns NULl to root
    }//end of default constructor
    void insert(int value)//function to call the method to insert a value into the tree
    {
        insert(root,value);//using root which is a private memeber
    }//end of the dummy function
    void insert(Node* current,int value)//function to insert a value into the tree
    {
        if(current==NULL)//if the subtree is empty
        root=new Node(value);//the new node is added to it
        else
        {
            if(current->data>value)//it is checked whether the new node should be placed to the left of the current node
            {
                if(current->left==NULL)//if there are no nodes to the left
                {
                    current->left=new Node(value);//the new node is inserted there
                    current->left->previous=current;
                }
                else
                insert(current->left,value);//the left subtree is traversed to place the new node
            }
            else//else it is placed to the right of the current node
            {
                if(current->right==NULL)//if there are no nodes to the right
                {
                    current->right=new Node(value);//the new node is inserted there
                    current->right->previous=current;
                }
                else
                insert(current->right,value);//the right subtree is traversed to place the new node
            }
        }
    }//end of the function to insert a node in the tree
    Node* search(int num)//function to call the method to insert a value into the tree
    {
        return search(root,num);//using root which is a private memeber
    }//end of the dummy function
    Node* search(Node* current,int num)//function to search if an element is present in the tree
    {
        if(current==NULL)//if the subtree is empty
        return current;//then the tree has been searched and element is not found
        else
        {
            if(current->data==num)//if the value to be search equals the value at the current node
            return current;//the address of the current node is returned
            else if(current->data>num)//if the element to be searched for is less than the value at the current node
            return search(current->left,num);//the left subtree is traversed to find the element
            else
            return search(current->right,num);//the right subtree is traversed to find the element
        }
    }//end of the function to search for an element in the tree
    void display()//function to call the method to display the tree horizontally
    {
        display(root,0);//using root which is a private memeber
        cout<<endl;
    }//end of the dummy function
    void display(Node* current,int space)//function to display the tree horizontally
    {
        if(current!=NULL)//if the end of the subtree has not been reached
        {
            display(current->right,++space);//the right subtree is displayed with an increased tab space
            cout<<endl;//a new line to print the current node value
            for(int i=1;i<space;i++)//for loop to print the correct number of
            cout<<"\t";//tab spaces
            cout<<current->data<<endl;//the value at the root of the current subtree is displayed
            display(current->left,space);//the left subtree is displayed
        }
    }//end of function to display the tree horizontally
    int count()//function to call the method to count the elements of the tree 
    {
        return count(root);//using the private method root
    }//end of dummy function
    int count(Node* current)//function to count the elements of the tree
    {
        if(current!=NULL)//if the node has some value
        return (1+count(current->left)+count(current->right));//one is added to the number of nodes in the tree and the number of nodes in the left subtree and the right subtree are added
        else//if the node does not exist
        return 0;//end of the tree and 0 is returned
    }//end of function to count the number of nodes in the tree
    int height()//function to call the method to find the height of the tree 
    {
        return height(root);//using the private method root
    }//end of dummy function
    int height(Node* current)//function to find the height of the tree 
    {
        if(current==NULL)//if the end of the tree is reached
        return 0;//base case and xero is returned
        else 
        {
            int leftHeight=height(current->left);//height of the left subtree is calculated
            int rightHeight=height(current->right);//height of the right subtree is calculated
            if(leftHeight>rightHeight)//they are compared
            return (1+leftHeight);//and the maximum among them is returned after adding one to it
            else
            return (1+rightHeight);//for the current level
        }
    }//end of the function to find the height of the tree 
    int rangeSearch(int k1,int k2)//function to call the method to print all elements of the tree between k1 and k2
    {
        return rangeSearch(root,k1,k2);//using the private method root
        cout<<endl;
    }//end of dummy function
    int rangeSearch(Node* current,int k1,int k2)//function to print all elements of the tree between k1 and k2
    {
        if(current!=NULL)//if the end of the tree is not reached
        {
            if(current->data>k1&&current->data<k2)//and the data in the node is within the range
	    {
           	cout<<current->data<<", ";//it is printed
            	return (1+rangeSearch(current->left,k1,k2)+rangeSearch(current->right,k1,k2));//and counted along with those in its left subtree and the right subtree
	    }
	    else//otherwise
	    return rangeSearch(current->left,k1,k2)+rangeSearch(current->right,k1,k2);//elements in the range of its left subtree and right subtree and counted 
	}
        else//if the end of the tree is reached
        return 0;//base case 
    }//emd of the function to print all elements of the tree between k1 and k2
};
int main()//main function
{
    BinarySearchTree b1;//binary search tree object is created
    int choice=0;
    int value=0;
    cout<<"Enter 1 till the user wants to input elements into the tree else 0.\n";
    do
    {
        cout<<"Enter your choice.\n";
        cin>>choice;
        if(choice==1)
        {
            cout<<"Enter the value to be inserted into the tree.\n";
            cin>>value;
            b1.insert(value);
        }
    }while(choice!=0);
    b1.display();
    cout<<"The number of nodes in the tree is "<<b1.count()<<endl;
    cout<<"The height of the tree is "<<b1.height()<<endl;
    int i,j=0;
    cout<<"Enter the two boundary values.\n";
    cin>>i;
    cin>>j;
    value=b1.rangeSearch(i,j);
    cout<<"There are "<<value<<" elements between "<<i<<" and "<<j<<endl;
}
