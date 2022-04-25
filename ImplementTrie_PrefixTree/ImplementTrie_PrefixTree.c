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
			curr->child[index] = getNode(word[i] - 'a');
		curr->child[index]->count += 1;
		curr = curr->child[index];
	}
	curr->endsHere += 1;
}

bool search(char *word)
{
	struct Trienode *curr = root;
	int index;
	for (int i = 0; word[i] != '\0'; ++i)
	{
		index = word[i] - 'a';
		if (curr->child[index] == NULL)
			return false;
		curr = curr->child[index];
	}
	return (curr->endsHere > 0);
}

bool startsWith(const char* prefix)
{
	struct Trienode *curr = root;
	int index;
	for (int i = 0; prefix[i] != '\0'; ++i)
	{
		index = prefix[i] - 'a';
		if (curr->child[index] == NULL)
			return false;   // String with given prefix absent
		curr = curr->child[index];
	}
	return (curr->count > 0);
}

int main()
{
	init();
	insert("apple");
	insert("add");

	bool check = false;

	check = startsWith("ap");
	printf("Trie %s\n", check ? "has a string with prefix ap" : "does not have a string with prefix ap");

	insert("beer");
	check = search("add");
	printf("Trie %s\n", check ? "has a string add" : "does not have a string add");
	check = search("app");
	printf("Trie %s\n", check ? "has a string app" : "does not have a string app");
	check = startsWith("add");
	printf("Trie %s\n", check ? "has a string with prefix add" : "does not have a string with prefix add");
	check = search("apps");
	printf("Trie %s\n", check ? "has a string apps" : "does not have a string apps");
	return 0;
}
