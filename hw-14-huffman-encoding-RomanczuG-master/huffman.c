#include <stdio.h>
#include <stdlib.h>
#include "huffman.h"
#include "sorted.h"

ListNode * HuffmanTree(ListNode * head)
{
  ListNode * ln1 = NULL;
  ListNode * ln2 = NULL;
  while(head -> next -> next !=  NULL)
  {
    ln1 = head;
    ln2 = head -> next;
    ListNode * newNode = buildListNode(combine(ln1 -> tree, ln2 -> tree));
    head = head -> next ->  next;
    insertNewValue(head, newNode);
    free(ln1);
    free(ln2);
  }
  if(head -> next !=  NULL)
  {
    ln1 = head -> next;
    head -> tree =combine(head -> tree, ln1 -> tree);
    head -> next = NULL;
    free(ln1);
  }
  return head;
}

TreeNode * combine(TreeNode * tr1, TreeNode * tr2)
{
  TreeNode * trn = buildTreeNode(0, 0, tr1 -> count + tr2 -> count);
  trn -> left = tr1;
  trn -> right = tr2;
  return trn;
}

int treeS(TreeNode * root)
{
  if(root -> left == NULL && root -> right == NULL)
  {
    return 1;
  }

  int size = treeS(root -> left) + treeS(root -> right);
  return size;
}

void printH(FILE * filehuffman, FILE * fileheader, char * huffman, TreeNode * root, int level, unsigned char * whichbit, unsigned char * curbyte)
{
  if(root -> isleaf)
  {
    huffman[level] = '\0';
    fprintf(filehuffman, "%c:%s\n", root -> chr, huffman);

    writeBit(fileheader, 1, whichbit, curbyte);
    writeChar(fileheader, whichbit, curbyte, root -> chr);
    return;
  }
  writeBit(fileheader, 0, whichbit, curbyte);

  huffman[level] = '0';
  printH(filehuffman, fileheader, huffman, root -> left, level + 1, whichbit, curbyte);
  huffman[level] = '1';
  printH(filehuffman, fileheader, huffman, root -> right, level + 1, whichbit, curbyte);
}

void printHeader(TreeNode *root, char * huffmanfile, char * headerfile)
{
  FILE * fileHuff = fopen(huffmanfile,"w");
  FILE * fileHead = fopen(headerfile, "w");
  int level = 0;
  unsigned char whichbit = 0;
  unsigned char curbyte = 0;
  if(fileHuff == NULL)
  {
    return;
  }
  if(fileHead == NULL)
  {
    return;
  }

  char * huffman = malloc(treeS(root) * sizeof(char));
  
  printH(fileHuff, fileHead, huffman, root, level, &whichbit, &curbyte);
  writeBit(fileHead, 0,  &whichbit, &curbyte);
  zeroValue(fileHead, &whichbit, &curbyte);

  free(huffman);
  fclose(fileHuff);
  fclose(fileHead);
}


