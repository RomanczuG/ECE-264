#include <stdlib.h>
#include <stdio.h>
#include "sorted.h"

TreeNode * buildTreeNode(bool isleaf, int chr, long count)
{
  TreeNode * temp = malloc(sizeof(TreeNode));
  temp -> isleaf = isleaf;
  temp -> chr = chr;
  temp -> count = count;
  temp -> left = NULL;
  temp -> right = NULL;
  return temp;
}

ListNode * buildListNode (TreeNode * tree)
{
  ListNode * newListNode = malloc(sizeof(ListNode));
  newListNode -> tree = tree;
  newListNode -> next = NULL;

  return newListNode;
}

bool firstBig(TreeNode * ptr1, TreeNode * ptr2)
{
  if(ptr1 -> count > ptr2 -> count)
  {
    return true;
  }
  if (ptr1 -> count == ptr2 -> count && ptr2 -> isleaf && ptr1 -> chr > ptr2 -> chr)
  {
    return true;
  }
  if (ptr1 -> count == ptr2 -> count && !ptr1 -> isleaf)
  {
    return true;
  }
  return false;
}

ListNode * insertNewValue(ListNode * head, ListNode * newNode)
{
  if(head == NULL)
  {
    head = newNode;
    return head;
  }

  if(head -> next == NULL)
  {
    if(firstBig(head -> tree, newNode -> tree))
    {
      newNode -> next = head;
      head = newNode;
    }
    else
    {
      head -> next = newNode;
    }
    return head;
  }
  ListNode * temp = head;
  ListNode * p = head -> next;

  if (!newNode -> tree -> isleaf)
  {
    while(p != NULL)
    {
      if(newNode -> tree -> count < p -> tree -> count)
      {
        newNode -> next = p;
        temp -> next = newNode;
        return head;
      }
      temp = temp -> next;
      p = p -> next;
    }
    temp -> next = newNode;
    return head;
  }
  if(firstBig(head -> tree, newNode -> tree))
  {
    newNode -> next = head;
    head = newNode;
    return head;
  }
  while(p != NULL)
  {
    if(firstBig(newNode -> tree, temp -> tree) && firstBig(p -> tree, newNode -> tree))
    {
      newNode -> next = p;
      temp -> next = newNode;
      return head;

    }
    temp = temp -> next;
    p = p->next;

  }
  temp -> next = newNode;
  return head;
}
ListNode * createASCIIList(long * asciiCount)
{
  int charV = 0;
  ListNode * head = NULL;
  ListNode * temp = NULL;
  while (charV < ASCII_SIZE)
  {
    if(asciiCount[charV] > 0)
    {
      temp = buildListNode(buildTreeNode(true, charV, asciiCount[charV]));
      head = insertNewValue(head, temp);
    }
    charV++;
  }
  free(asciiCount);
  return head;
}
void printListNode(char * filename , ListNode * head)
{
  FILE * outFile = fopen(filename, "w");
  if(outFile == NULL)
  {
    return;
  }
  ListNode * temp = head;
  while (temp != NULL)
  {
    fprintf(outFile, "%c:%ld\n", temp -> tree -> chr, temp -> tree -> count);
    temp = temp -> next;
  }
  fclose(outFile);
}

void destroyTree(TreeNode * root)
{
  if(root == NULL)
  {
    return;
  }
  destroyTree(root -> left);
  destroyTree(root -> right);
  free(root);
}
void destroyList(ListNode * head)
{
  ListNode * temp = NULL;
  while(head != NULL)
  {
    temp = head;
    head = head -> next;
    destroyTree(temp -> tree);
    free(temp);
  }
}

int zeroValue(FILE * fptr, unsigned char * whichbit,
	    unsigned char * curbyte)
{
  int rtv;
  while ((* whichbit) != 0)
    {
      rtv = writeBit(fptr, 0, whichbit, curbyte);
      if (rtv == -1)
				{
				  return -1;
				}
    }
  return rtv;
}

void writeChar(FILE * fptr, unsigned char * whichbit, unsigned char * curbyte, unsigned int chr)
{
	unsigned char mask = 0x80;
	while(mask > 0)
	{
		writeBit(fptr, (chr & mask) == mask, whichbit, curbyte);
		mask >>= 1;
	}
}

int writeBit(FILE * fptr, unsigned char bit,
	     unsigned char * whichbit,
	     unsigned char * curbyte)
{
  if ((* whichbit) == 0)
    {
      * curbyte = 0;
    }
  unsigned char temp = bit << (7 - (* whichbit));
  * curbyte |= temp;
  int value = 0;
  if ((* whichbit) == 7)
    {
      int ret;
      ret = fwrite(curbyte, sizeof(unsigned char), 1, fptr);
      if (ret == 1)
				{
				  value = 1;
				}
			else
				{
				  value = -1;
				}
    }
  * whichbit = ((* whichbit) + 1) % 8; 
  return value;
}

