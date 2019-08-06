//linked list - 8/6/2018, download the real file from d2l
#include <iostream>
using namespace std;
//think linedlist as train and cupler
struct node
{
	int number;
	node *next;//or link - acts as a cupler 
};

//prototypes
void print(node n)//does not need to be a reference
{
	node *cur = n; <- points to first node;
	if(n == nullptr)
	{
		cout << "The list is empty" << endl;
	}
	else
	{//we need to be able to move current down the linked list   
		while(cur != nullptr) //moving until we reach the last
		{
			cout << cur->number << endl;
			cur = cur->next; //move down to the next node, on last node cur = nullptr
		}
	}
}
void addANode(node *&n)//refrence because we want it to edit, BUILDING LIST BACKWARD
{
	int num;
	node *temp;
	cout <<"What number do you want to the list? ";
	cin >> num;//specify which number each node is going to store?
	if(n == nullptr){//the list is empty, to set head and point it to the first node, add first node
	{
		n = new node;
		n->number = num;//adding one node to the lined list
		n->next = nullptr;
	}
	else //there is at lease one node in the list.
	{//places the note at the head. building list backwards
		temp = new node;
		temp->number = num;
		temp->next = n;//temp-> next points to head
		n = temp;//now head points to temp, temp is the new node
		//
	}
}

void addANodeTail(node *&n)//IF USE TAIL - BUILD LINKED LIST FORWARD
{
	int num;
	node *temp;
	node *cur = n;//current is pointing to head pointer
	node *prev = n;//point to the same node as cur
	if(n == nullptr)//list is empty
	{
		n = new node;
		n->number = num
		n->next = nullptr;
	}
	else //at least one node.
	{
		while(cur->next != nullptr)
		{
		/*single pointer way to itreate through
			cur = cur->next; 
		*/
		//to itrate through using 2 pointers
			prev = cur;
			cur = cur->next;
		
		}//after loop current points to the tail.
		temp = new node;
		temp->number = num;
		cur->next = temp;
		temp->next = NULL;
	
	}
}
void free(node *n)
{
	node *temp;
	while(n != nullptr)
	{
		temp = n;
		n = n->next;
		delete n;
		
	}
}

void addANodeSorted(node *&n)
{
	int num;
	node *temp, *prev, *cur;//to keep track of the nodes
	cout <<"What number do you want to the list? ";
	cin >> num;//specify which number each node is going to store?
	if(n == nullptr){//the list is empty, to set head and point it to the first node, add first node
	{
		n = new node;
		n->number = num;//adding one node to the lined list
		n->next = nullptr;
	}
	else //there is at lease one node in the list.
	{//places the note at the head. building list backwards
		temp = new node;
		temp->number = num;
		if(temp->number < n->number)
		{
			temp->next = n;
			n = temp;
		}
	}
}
int main()
{
/*
	node *m = new node[10]// node pointers
	node *n = new node;
	n->number = 5;//n.number won't work since you need to de reference it , use (*n).number/n->number
*/
	node *head = nullptr ;//create head of linked list
//	print(head)//list is empty
	
	addAnode(head);// in gdb -> *head = address of struct node
	addAnode(head);
	addAnode(head);
	
	print(head)// will print the number stored inside the linked list
	
	
	return 0;
}
