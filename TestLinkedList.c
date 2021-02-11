/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 02/10/2021 at 10:53 PM
 * 
 * TestLinkedList.c
 * 
 * -----------------------------------------------------------------------------
 */

#include "DoubleLinkedList.h"

int main(void) {
	int count = 0;
	/* Initialize the list. */
	struct List names;
	init_list(&names);
	
	struct Link *curr;

	/* Make a few names and add them to the list. */
	push_back(&names, (struct Link*)make_name("Norah"));
	push_back(&names, (struct Link*)make_name("Annemarie"));
	push_back(&names, (struct Link*)make_name("Kris"));

	/* Remove the second name (with index 1): */
	erase(&names, advance(names.first, 1));

	/* Write out all names */
	
	curr = names.first;
	for (; curr != NULL; curr = curr->suc) {
		count++;
		printf("Element %d: %s\n", count, ((struct Name*)curr)->p);
	}

}
