/*
 * ------------------------------------------------------------------------------
 * Created by Ulysses Carlos on 02/09/2021 at 06:18 PM
 *
 * Chapter27_Drill_02.c
 * Define two variables holding "Hello" and "World!" respectively; concatenate
 * them with a space in between; and output them as Hello World!
 * ------------------------------------------------------------------------------
 */

#include <stdio.h>
#include <string.h>


int main(void) {
	const char *str1 = "Hello";
	const char *str2 = "World!";

	unsigned long str1_length = strlen(str1);
	unsigned long str2_length = strlen(str2);
    /* 2 Extra bytes for the spaces, and 1 byte for the null terminator. */
	char str3[str1_length + 3 + str2_length];
	strcat(str3, str1);
	strcat(str3 + str1_length, " ");
	strcat(str3 + str1_length + 1, str2);
	

	printf("String 1: %s\nString 2: %s\nString 3: %s\n", str1, str2, str3);

	


}
