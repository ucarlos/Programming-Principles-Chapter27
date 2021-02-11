/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 02/09/2021 at 10:15 PM
 * 
 * DoubleLinkedList.c
 * Definition of DoubleLinkedList.h.
 * -----------------------------------------------------------------------------
 */

#include "DoubleLinkedList.h"


/**
 * Initialize list to the empty list.
 * @param list A pointer to a struct List
 * @returns void
 */
void init_list(List *list) {
	assert(list); /* Give a run-time system error if list pointer is null. */
	list->first = list->last = NULL;
	
}


void init_link(Link *link) {
	assert(link);
	link->pre = link->suc = NULL;

}

/**
 * Make a new empty List.
 * @param void
 * @returns List*
 */
struct List* create(void) {
	List *list = calloc(1, sizeof(struct List));
	init_list(list);
	return list;	   
}

/**
 * Free all elements of the list.
 * @param list 
 */
void clear(List *list) {
	assert(list); {
		Link *curr = list->first;

		/* Free all members of List */
		while (curr) {
			Link *next = curr->suc;
			free(curr);
			curr = next;
		}

		/* Now clear first and last pointers. */
		list->first = list->last = NULL;

	}

}


/**
 * Free all elements of list and then free the list.
 * @param list A pointer to list.
 * @returns void
 */

void destroy(List *list) {
	assert(list);
	
	clear(list);
	free(list);
}


/**
 * Add p to the end of a list.
 * @param list A pointer to a List struct.
 * @param p A pointer to a Link struct.
 * @returns void
 */

void push_back(List *list, Link *p) {
	/* Does not handle situations where p is null however. */
	assert(list); {
		Link *last = list->last;
		
		if (last) { /* Add p after last. */
			last->suc = p;
			p->pre = last;

		}
		else { /* p is the first element. */
			list->first = p;
			p->pre = NULL;
		}

		list->last = p; /* Now p is the new last element. */
		p->suc = NULL;
	}

}


/**
 * Remove p from list and return a pointer to the link after p.
 * @param list A pointer to a List struct.
 * @param p A pointer to a Link struct.
 * @returns pointer to the link after p.
 */
Link* erase(List *list, Link *p) {
	assert(list);
	if (p == NULL) /* OK to erase(0). */
		return NULL;

	if (p == list->first) {
		if (p->suc) {
			list->first = p->suc; /* The successor becomes first. */
			p->suc->pre = NULL;
			return p->suc;			
		}
		else {
			list->first = list->last = NULL; /* The list becomes empty. */
			return NULL;
		}

	}
	else if (p == list->last) {
		if (p->pre) { /* If p has a predecessor */
			list->last = p->pre; /* The predecessor becomes last. */
			p->pre->suc = NULL;
			return p->pre;
			/* Return here. */
		}
		else {
			/* The list becomes empty. */
			list->first = list->last = NULL; 
			return NULL;
		}

	}
	else {
		p->suc->pre = p->pre;
		p->pre->suc = p->suc;
		return p->suc;

	}
   	
}

Name * make_name(char *str) {
	struct Name *p = (Name*) malloc(sizeof(struct Name));
	p->p = str;
	return p;

}


/**
 * Advance a Link pointer by a specified number.
 * @param p A pointer to a Link structure.
 * @param n value to increment or decrement a pointer.
 * @returns A Link pointer that either points to the specified increment/decrement or null.
 */
Link *advance(Link *p, int n) {
	/* Handle null link pointer and when n is zero. */
	if (!p)
		return NULL;
	else if (!n)
		return p;

	
	Link *curr = p;
	int i;
	/* Increment/decrement to a value held by n or stop when null occurs. */
	if (n < 0)
		for (i = 0; i > n && p != NULL; i--)
			p = p->pre;
	else
		for (i = 0; i < n && p != NULL; i++)
			p = p->suc;

	return p;
}
