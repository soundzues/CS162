#include "list.hpp"
#include <iostream>
using namespace std;
//put the implementation of your assigned functions here

int sumEvenNodes(node *head)
{
	int sum;
	node *cur;
	cur = head;
	
	while(cur != NULL)
	{
		if(cur->data % 2 == 0)
		{
			sum = sum + cur->data;
		}
		cur = cur->next;
		
	}
	return sum;
}

void removeOddNodes(node *&head)
{
	node *cur, *prev;
	cur = head;
	prev = NULL;

	while(cur != NULL)
	{
		if(cur->data % 2 != 0)
		{
			if(cur == head)//node to be removed at head
			{
				head = head->next;
				delete cur;
			}
			else//somewhere else in the list
			{
				prev->next = cur->next;
				delete cur;
			}
		}	
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}

}
