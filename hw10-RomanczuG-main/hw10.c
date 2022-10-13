// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h>
#include "hw10.h"

// DO NOT MODIFY this function --->>>
void printListNode(ListNode * head)
{
  ListNode * p = head;
  printf("printListNode: ");
  while (p != NULL) // the linked list must end with NULL
    {
      printf("%7d ", p -> value);
      p = p -> next;
    }
  printf("\n");
}
// <<<--- until here

// You MUST modify the following functions

#ifdef TEST_CREATELIST
void insert_Node (ListNode ** root, int value);
// create a linked list storing values 0, 1, 2, ... valn - 1
// The first node (head) stores 0, the next node stores 1,
// ..., the last node stores valn - 1
// return the head of the linked listn
// the linked list must end with NULL
ListNode * createList(int valn)
{
  ListNode* temp = malloc(sizeof(ListNode));
  temp->value = 0;
  temp->next = NULL;
  for(int index = 1; index < valn; index++)
  {
    insert_Node(&temp,index);
  }

  return temp;
}

void insert_Node (ListNode ** root, int value)
{
  ListNode * new_node = malloc(sizeof(ListNode));
  if(new_node == NULL)
  {
    exit(1);
  }
  new_node->value = value;
  new_node->next = NULL;

  ListNode * curr = *root;
  while(curr->next != NULL)
  {
    curr = curr->next;
  }
  curr->next = new_node;
}

#endif

#ifdef TEST_ELIMINATE
// eliminate the nodes in the linked list
// starting from the head, move one node at a time and count to valk.
// eliminate that node, keep counting
//
// when reaching the end of the list, continue from the beginning of
// the list
//
// print the values of the nodes to be deleted
void eliminate(ListNode * head, int valk)
{
  #ifdef DEBUG
  ListNode * curr = head;
  for(int instance = 1; instance <= valk; instance++)
  {
    if(head->next == NULL)
    {
      printf("%d\n",head->value);
      free(head);
      return;
    }
    if(instance == valk)
    {
      ListNode * toDelete = curr;

      // this #ifdef ... #endif should be inside the condition *BEFORE* a
      // node' value is printed and it is deleted
      printListNode (toDelete); 

      if(curr->next == NULL)
      {
        curr = head;
      }
      else{
        curr = curr->next;
      }
      //printListNode(toDelete);
      head = deleteNode(head,toDelete);
      //printListNode(head);
      instance = 0;
    }
    else
    {
      if(curr->next == NULL)
      {
        curr = head;
      }
      else{
        curr = curr->next;
      }
    }
    
  }
  #endif
}
#endif

#ifdef TEST_DELETENODE
// head points to the first node in the linked list
// todelete points  to the node to be deleted
//
// delete the node and return the head of the linked list
// release the memory of the deleted node
//
// should check several conditions:
// 1. If head is NULL, the list is empty and this function returns NULL
// 2. If todelete is NULL, nothing can be deleted, return head
// 3. If todelete is not in the list, keep the list unchanged and
//    return head
// It is possible that todelete is the first node in the list (i.e.,
// the head). If this occurs, return the second node of the list.
ListNode * deleteNode(ListNode * head, ListNode * todelete)
{
  printf("%d\n",todelete->value);
  if(head->next == NULL)
  {
    free(todelete);
    return NULL;
  }
  if(todelete->next == head->next){
    head = head->next;
    free(todelete);
    return head;
  }
  ListNode * p = head;
  while (p->next != todelete) // the linked list must end with NULL
  {
    p = p -> next;
  }
  if(todelete->next == NULL)
  {
    p->next = NULL;
  }
  else
  {
    p->next = p -> next -> next;
  }
  free(todelete);
  return head;
}
#endif


