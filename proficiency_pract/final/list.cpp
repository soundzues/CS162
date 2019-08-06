#include "list.h"

//put the implementation of your assigned functions here

int sumOfList(node *head)
{
	int sum = 0; //accumaltion
	node *cur = head;//not creating a new node just starting at the head
	//traverse the list and add the data members
	while(cur != nullptr)
	{
		sum += cur->data;
		cur = cur->next;
	}
	return sum;
}
void insert(node *& head, int position, int newInt)
{
	node *temp = new node; //create new temporary node
	int count = 0;
	node *prev, *cur;
	temp->data = newInt;
	temp->next = NULL;
	if(position <= 0)//goes in the begining
	{
		temp->next = head;
		head = temp;
	}
	else//temp goes in the list or at the end
	{
		prev = cur = head;
		while(cur != NULL)
		{
			if(count == position)
			{
				temp->next = cur;
				prev->next = temp;
				break;
			}
			else
			{
				count++;
				prev = cur;
				cur = cur->next;
				
			}
		}
	}
	if(cur == NULL)
	{
		prev->next = temp;
	}
}
