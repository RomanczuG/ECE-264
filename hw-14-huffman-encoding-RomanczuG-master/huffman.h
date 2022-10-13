#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "sorted.h"

ListNode * HuffmanTree(ListNode * head);
TreeNode * combine(TreeNode * tr1, TreeNode * tr2);
int treeS(TreeNode * root);
void printH(FILE * huffmanfile, FILE * headerfile, char * huffman, TreeNode * root, int level, unsigned char * whichbit, unsigned char * curbyte);
void printHeader(TreeNode *root, char * huffmanfile, char * headerfile);
#endif
