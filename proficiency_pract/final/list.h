//list.h
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cstring>
#include <cctype>


struct node
{
    int data;
    node * next;
};

/* These functions are already written and can be called to test out your code */
void build(node * & head);  //supplied. The resulting list will have from 10 to 20 nodes.
void display(node * head);  //supplied
void destroy(node * &head); //supplied

/* *****************YOUR TURN! ******************************** */
//Write your function prototype here:
int sumOfList(node *head);//first prototype in header file
void insert(node *& head, int position, int newInt);
#endif
