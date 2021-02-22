/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 01/30/2021 at 11:44 PM
 *
 * Chapter27_Try_02.cc
 *
 * Is this implementation of strcpy() correct? Explain why.
 *
 * Answer: 
 * The while loop continues if the statement (*dest++ = *source) is nonzero or
 * not. When the source string writes a null character (\0 or 0), that is
 * evaluated as false and the loop ends.
 * -----------------------------------------------------------------------------
 */

#include <iostream>
using namespace std;

char *strcpy(char *dest, const char *source) {
	bool check;
	// Here's a more understandable loop
	// The loop continues if check is nonzero (No null character)
	while ((check = (*dest++ = *source++)))
		continue;

	// Terse loop
	// while (*dest++ = *source++);
	
	return dest;
	
}

int main(void) {
	char str1[1000];
	const char *str2 = "Hello World!";
	strcpy(str1, str2);

	cout << "Result: " << str1 << "\n";
	

}

