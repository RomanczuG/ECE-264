#ifndef SORTED_H
#define SORTED_H

#define ASCII_SIZE 256
#include <stdbool.h>

/* An example of a TreeNode and ListNode structure. You don't have to use exactly this */
typedef struct TreeNode {
  bool isleaf;
  int chr;
  long count;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode;

typedef struct ListNode {
   TreeNode *tree;
   struct ListNode *next;
} ListNode;

TreeNode * buildTreeNode(bool isleaf, int chr, long count);
ListNode * buildListNode (TreeNode * tree);
ListNode * insertNewValue(ListNode * head, ListNode * newNode);
ListNode * createASCIIList(long * asciiCount);
bool firstBig(TreeNode * ptr1, TreeNode * ptr2);
void printListNode(char * filename , ListNode * head);
void destroyTree(TreeNode * root);
void destroyList(ListNode * head);

int writeBit(FILE * fptr, unsigned char bit, unsigned char * whichbit, unsigned char * curbyte);
int zeroValue(FILE * fptr, unsigned char * whichbit, unsigned char * curbyte);
void writeChar(FILE * fptr, unsigned char * whichbit, unsigned char * curbyte, unsigned int chr);
#endif
