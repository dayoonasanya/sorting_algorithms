#ifndef _DECK_H
#define _DECK_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TOTAL 52


/**
 * struct card_s - card.
 *
 * @value: value.
 * @kind: kind.
 */

typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;


/**
 * struct deck_node_s - card.
 *
 * @card: card.
 * @prev: prev.
 * @next: next.
 */


typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

/**
 * enum kind_e - enum.
 * @SPADE: spade.
 * @HEART: heart.
 * @CLUB: Clubs suit.
 * @DIAMOND: Diamonds suit.
 */

typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

void sort_deck(deck_node_t **deck);

#endif /*_DECK_H*/
