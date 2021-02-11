/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 02/09/2021 at 09:58 PM
 * 
 * DoubleLinkedList.h
 * 
 * -----------------------------------------------------------------------------
 */

#pragma once
#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Structure definitions */

typedef struct List {
	struct Link *first;
	struct Link *last;
} List;

typedef struct Link {
	struct Link *pre;
	struct Link *suc;
} Link;


/* Name structure from 27.9 */
typedef struct Name {
	Link link;
	char *p;
} Name;

/* Function declarations */
void init_list(List *list); /* Initialize list to empty. */
void init_link(Link *link); /* initialize link to empty. */
List *create(void);        /* Make a new empty list on the free store. */
void clear(List *list); /* Free all elements of list. */
void destroy(List *list); /* Free all elements of list and then free the list. */

void push_back(List *list, Link *p); /* Add p and the end of the list. */
void push_front(List *list, Link *p); /* Add p at the front of the list. */

void insert(List *list, Link *p, Link *q); /* Insert q before p in list. */
Link* erase(List *list, Link *p); /* Remove p from list. */

Link* advance(Link *p, int n); /* Return link n "Hops" before or after p. */

Name* make_name(char *str);


#endif
