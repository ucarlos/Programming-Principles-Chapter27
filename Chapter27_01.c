/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 02/11/2021 at 12:04 AM
 * 
 * Chapter27_01.c
 * Implement versions of strlen(), strcmp(), and strcpy().
 * -----------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>

uint64_t my_strlen(char *str) {
	char *p;
	for (p = str; *p; p++)
		continue;

	return (p - str);
}

int32_t my_strcmp(char *str1, char *str2) {
	/* Loop continues until str1 or str2 points to a null character. */
	for (; *str1 && *str2; str1++, str2++) {
		/* string1 comes before string2 */
		if (*str1 < *str2)
			return -1;
		else if (*str1 > *str2)
			return 1;
		else
			continue;
		
	}

	/* Both strings are equal. */
	return 0;
}

char* my_strcpy(char *dest, const char *src) {
	/* Same implementation from Chapter27_Try_02.cc. */
	bool check;

	while ((check = (*dest++ = *src++)))
		continue;

	return dest;
}


int main(void) {
	const char *str1 = "Hello World!";
	const char *str2 = "I think, therefore I am.";
	char str3[1024];
	
	printf("Size of str1: %"PRIu64"\n", my_strlen(str1));
	printf("str1 and str2 comparison: %d\n", my_strcmp(str1, str2));
	puts("Now copying str2 to str3...");
	my_strcpy(str3, str2);
	printf("Output of str3: ");
	puts(str3);


}
