#include <string.h>
#include <stdio.h>

int main(void)
{
	const char *s1 = "abcdefg";
	const char *s2 = "eqqqqqqfg";

	printf("%s\n", strpbrk(s1, s2));
	return (0);
}
