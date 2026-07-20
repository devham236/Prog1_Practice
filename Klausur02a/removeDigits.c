// run make removeDigits && ./removeDigits
/*
	Methode soll Zahlen aus dem String entfernen.
	Es dürfen nur xmalloc und isDigit benutzt werden.
*/
#include "base.h"

bool isDigit(char c)
{
	return c <= '9' && c >= '0';
}

char *removeDigits(char *s)
{
	if (s[0] == '\n')
	{
		return s;
	}

	int count = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		char c = s[i];

		if (!isDigit(c))
		{
			count++;
		}
	}

	char *result = xmalloc(count + 1);

	int j = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		char c = s[i];

		if (!isDigit(c))
		{
			result[j] = c;
			j++;
		}
	}

	result[j] = '\0';

	return result;
}

void test_removeDigits(void)
{
	test_equal_s(removeDigits(""), "");
	test_equal_s(removeDigits("x"), "x");
	test_equal_s(removeDigits("11"), "");
	test_equal_s(removeDigits("1x1x"), "xx");
	test_equal_s(removeDigits("111x111"), "x");
	test_equal_s(removeDigits("1a2b3c4"), "abc");
	test_equal_s(removeDigits("101191xk"), "xk");
}

int main(void)
{
	test_removeDigits();
	return 0;
}