#include "common.h"
bool isValidParentheses(const char* s) {
	struct stack* open = createStack(20);
	struct stack* star = createStack(20);
	int len = strlen(s);
	for (int i = 0; s[i] != '\0'; ++i)
	{
		if (s[i] == '(')
			push(open, i);
		else if (s[i] == '*')
			push(star, i);
		else
		{
			if (!isEmpty(open))
				pop(open);
			else if (!isEmpty(star))
				pop(star);
			else
				return false;
		}
	}

	//Now process leftover opening brackets
	while (!isEmpty(open))
	{
		if (isEmpty(star))
			return false;
		else if (peek(open) < peek(star))
		{
			pop(open);
			pop(star);
		}
		else    //CASE: open.top() > star.top()
			return false;
	}
	return true;
}

void printValidity(bool isValid)
{
	if (isValid)
		printf("\nThis is Balanced Expression");
	else
		printf("\nThis is Not Balanced Expression");
}

int main()
{
	printValidity(isValidParentheses("(*(*))"));
	printValidity(isValidParentheses(")(*"));// Failure case 1
	printValidity(isValidParentheses("())"));// Failure case 2
	printValidity(isValidParentheses("(())("));// Failure case 3
}
