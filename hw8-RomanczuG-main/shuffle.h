// ***
// *** DO NOT modify this file
// ***

#ifndef SHUFFLE_H
#define SHUFFLE_H
#include <stdlib.h>

#define MAX_SIZE 13

typedef struct {
  char cards[MAX_SIZE];
  int size;
} CardDeck;

void shuffle (CardDeck origDeck, int round);
void divide(CardDeck origDeck, CardDeck* leftDeck, CardDeck* rightDeck);
void interleave(CardDeck leftDeck, CardDeck rightDeck, int round);
void helper(CardDeck destination, CardDeck leftDeck, CardDeck rightDeck, int indexL, int indexR, int index, int round);

#endif
