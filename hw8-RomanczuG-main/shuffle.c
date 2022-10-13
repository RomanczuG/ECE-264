#include "shuffle.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


static void printDeck(CardDeck deck)
{
  int ind;
  for (ind = 0; ind < deck.size; ind ++)
    {
      printf("%c ", deck.cards[ind]);
    }
  printf("\n");
}

void divide(CardDeck origDeck, CardDeck * leftDeck, CardDeck * rightDeck)
{
  int indexL;
  int indexR;
  int index;
  int numberOfPairs = origDeck.size - 1;
  for(index = 0; index < numberOfPairs; index++)
  {
    for(indexL = 0; indexL < leftDeck[index].size ; indexL++)
    {
      leftDeck[index].cards[indexL] = origDeck.cards[indexL];
    }
    for(indexR = indexL; indexR < origDeck.size; indexR++)
    {
      rightDeck[index].cards[indexR - indexL] = origDeck.cards[indexR];
    }
  }
  

}

void helper(CardDeck destination, CardDeck leftDeck, CardDeck rightDeck, int indexL, int indexR, int index, int round)
{
  if(leftDeck.size == 0)
  {
    while (rightDeck.size >0)
    {
      destination.cards[index] = rightDeck.cards[indexR];
      rightDeck.size --;
      destination.size ++;
      indexR++;
      index++;
    }
    shuffle(destination, round - 1);
  }
  else if(rightDeck.size == 0)
  {
    while (leftDeck.size > 0)
    {
      destination.cards[index] = leftDeck.cards[indexL];
      leftDeck.size --;
      destination.size ++;
      indexL++;
      index++;
    }
    shuffle(destination, round - 1);
  }
  else
  {
    destination.cards[index] = leftDeck.cards[indexL];
    leftDeck.size --;
    destination.size ++;
    helper(destination,leftDeck,rightDeck,indexL+1,indexR,index+1, round);
    destination.cards[index] = rightDeck.cards[indexR];
    leftDeck.size ++;
    rightDeck.size --;
    helper(destination,leftDeck,rightDeck,indexL,indexR+1,index+1, round);
  }
}

void interleave(CardDeck leftDeck, CardDeck rightdeck, int round)
{
    CardDeck destination;
    destination.size = 0;
    helper(destination,leftDeck,rightdeck, 0,0,0, round);
}
void shuffle(CardDeck origDeck, int round)
{
    if(round > 0)
    {
        int numberCardsL = origDeck.size-1;
        int numberCardsR = origDeck.size-1;

        CardDeck * CardsL = malloc(sizeof(CardDeck) * numberCardsL);
        CardDeck * CardsR = malloc(sizeof(CardDeck) * numberCardsR);

        for (int i = 0; i < numberCardsL; i++)
        {
        CardsL[i].size = i + 1;
        CardsR[i].size = numberCardsL - i;
        }

        divide(origDeck, CardsL, CardsR);

        for (int index = 0; index < numberCardsL; index++)
        {
          interleave(CardsL[index], CardsR[index], round);
        }
        free(CardsR);
        free(CardsL);
    }
    else
    {
      printDeck(origDeck);
    }
}
