#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "tree.h"


#ifndef BUILDTREE_OFF

TreeNode * helper(Scanner * s);
TreeNode * buildExpressionTree(Scanner * s) {
        if(s->buf == NULL)
        {
                exit(1);
        }
        TreeNode * temp = helper(s);
        Token tempT = nextToken(s);
        if(tempT.type != T_EOF)
        {
                exit(1);
        }
        return(temp);
}

TreeNode * helper(Scanner * s)
{
        Token tempT = nextToken(s);
        if(tempT.type == T_VAL)
        {
                TreeNode * node = buildTreeNode(tempT);
                return node;
        }
        else if (tempT.type == T_LPAREN)
        {
                TreeNode * leftNode = helper(s);
                Token operand = nextToken(s);
                TreeNode * rightNode = helper(s);
                Token rightP = nextToken(s);
                if(rightP.type == T_RPAREN)
                {
                        TreeNode * tempNode = buildTreeNode(operand);
                        tempNode->left = leftNode;
                        tempNode->right = rightNode;
                        return(tempNode);
                }
        }
        exit(1);
}

#endif

#ifndef POSTFIX_OFF
void makePostFix(TreeNode * t, FILE * fptr) {
	
        if( t == NULL)
        {
                return;
        }
        makePostFix(t->left, fptr);
        makePostFix(t->right, fptr);
        if(t->t.type == T_ADD)
        {
                fprintf(fptr, "+ ");
        }
        else if(t->t.type == T_SUB)
        {
                fprintf(fptr, "- ");
        }
        else if(t->t.type == T_DIV)
        {
                fprintf(fptr, "/ ");
        }
        else if(t->t.type == T_MUL)
        {
                fprintf(fptr, "* ");
        }
        else
        {
                fprintf(fptr, "%f ",t->t.value);
        }
}
#endif
