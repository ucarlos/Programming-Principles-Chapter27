/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 01/30/2021 at 10:58 PM
 * 
 * Dumb_Cat.cc
 * 
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

char* bad_cat(const char *id, const char *addr) {
	// Adds two characters for the null character and '@'.

	int id_size = strlen(id);
	int addr_size = strlen(addr);
	int size = strlen(id) + strlen(addr) + 2;
	
	char *result = (char *) malloc(size);
	// copy id to result
	strncpy(result, id, strlen(id));
	// append '@'
	result[id_size + 1] = '@';
	// Now copy addr to result
	strncpy(result + id_size, addr, addr_size);

	// Append a null character:
	result[size - 1] = '\0';

	return result;
}


int main(void) {
	const char *str1 = "Hello";
	const char *str2 = " World!";

	char *result = bad_cat(str1, str2);
	cout << "Result: \"" << result << "\"\n";
	

	free(result);
}
