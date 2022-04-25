#include "common.h"

struct Trienode *root;
void init()
{
	root = getNode('/' - 'a');
}

void insert(char *word)
{
	struct Trienode *curr = root;
	int index;
	for (int i = 0; word[i] != '\0'; ++i)
	{
		index = word[i] - 'a';
		if (curr->child[index] == NULL)
			curr->child[index] = getNode(index);
		curr = curr->child[index];
	}
	curr->endsHere += 1;
}

bool Trie_search(char *s, struct Trienode *curr, int pos, int n)
{
	int index = s[pos] - 'a';
	if (s[pos] == '.')
	{
		bool res = false;
		struct Trienode *current = curr;
		for (int i = 0; i < 26; i++)
		{
			if (pos == n - 1 && curr->child[i])
			{
				current = curr->child[i];
				res |= ((current->endsHere > 0) ? true : false);
			}
			else if (curr->child[i] && Trie_search(s, curr->child[i], pos + 1, n))
			{
				return true;
			}
		}
		return res;
	}
	else if (curr->child[index])
	{
		if (pos == n - 1)
		{
			curr = curr->child[index];
			return ((curr->endsHere > 0) ? true : false);
		}
		return Trie_search(s, curr->child[index], pos + 1, n);
	}
	return false;
}

bool search(char *word)
{
	return Trie_search(word, root, 0, strlen(word));
}

int main()
{
	init();
	insert("apple");
	insert("add");
	insert("beer");

	bool check = false;
	check = search("apple");
	printf("Trie %s\n", check ? "has a string apple" : "does not have a string apple");
	check = search("add");
	printf("Trie %s\n", check ? "has a string add" : "does not have a string add");
	check = search("apps");
	printf("Trie %s\n", check ? "has a string apps" : "does not have a string apps");

	check = search("a...e");
	printf("Trie %s %s\n", check ? "has a string" : "does not have a string", "a...e");
	check = search("..d");
	printf("Trie %s %s\n", check ? "has a string" : "does not have a string", "..d");
	check = search("al.s");
	printf("Trie %s %s\n", check ? "has a string" : "does not have a string", "al.s");
	check = search("a..s");
	printf("Trie %s %s\n", check ? "has a string" : "does not have a string", "a..s");
	check = search("b..r");
	printf("Trie %s %s\n", check ? "has a string" : "does not have a string", "b..r");
	return 0;
}
