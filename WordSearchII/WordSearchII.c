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
	strcpy(curr->word, word);
}

void solve(char** board, 
	int i, int j,				// location on the board
	int r, int c,				// board dimension
	char** ans, int* ans_count, // found words
	struct Trienode* curr)
{
	int index = board[i][j] - 'a';
	// if current node is visited or does not have a character return immediately
	if (board[i][j] == '$' || curr->child[index] == NULL)
	{
		return;
	}

	curr = curr->child[index];
	if (curr->endsHere > 0)
	{
		// suppose ab and abc both need to be found. we should not stop at ab.
		strcpy(ans[(*ans_count)++], curr->word);
		(curr->endsHere)--;
	}

	char ch = board[i][j];
	board[i][j] = '$'; // mark current node as visited

	if (i > 0)
	{
		solve(board, i - 1, j, r, c, ans, ans_count, curr);
	}
	if (i < (r - 1))
	{
		solve(board, i + 1, j, r, c, ans, ans_count, curr);
	}
	if (j > 0)
	{
		solve(board, i, j - 1, r, c, ans, ans_count, curr);
	}
	if (j < (c - 1))
	{
		solve(board, i, j + 1, r, c, ans, ans_count, curr);
	}

	board[i][j] = ch; // restore the value to mark it as unvisited
}

void findWords(char** board, int r, int c, char** words, int w_count)
{
	char** ans = (char**)malloc(w_count * sizeof(char*));
	for (int i = 0; i < w_count; i++)
	{
		ans[i] = (char*)calloc(MAXWORDLEN, sizeof(char));
	}
	int a_index = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			solve(board, i, j, r, c, ans, &a_index, root);
		}
	}
	printf("Found words:\n");
	for (int i = 0; i < a_index; i++)
	{
		printf("%s\n", ans[i]);
	}
	for (int i = 0; i < w_count; i++)
	{
		free(ans[i]);
	}
	free(ans);
}

int main()
{
	init();

	int r = 4, c = 4;
	char** board = (char**)malloc((r+1) * sizeof(char*));
	for (int i = 0; i < (r+1); i++)
	{
		board[i] = (char*)calloc((c+1), sizeof(char));
	}

	board[0][0] = 'o';// ['o','a','a','n'],
	board[0][1] = 'a';
	board[0][2] = 'a';
	board[0][3] = 'n';

	board[1][0] = 'e';// ['e','t','a','e'],
	board[1][1] = 't';
	board[1][2] = 'a';
	board[1][3] = 'e';

	board[2][0] = 'i';// ['i','h','k','r'],
	board[2][1] = 'h';
	board[2][2] = 'k';
	board[2][3] = 'r';

	board[3][0] = 'i';// ['i','f','l','v']
	board[3][1] = 'f';
	board[3][2] = 'l';
	board[3][3] = 'v';

	char** words = (char**)malloc((r + 1) * sizeof(char*));
	for (int i = 0; i < (r + 1); i++)
	{
		words[i] = (char*)calloc((c + 1), sizeof(char));
	}

	strcpy(words[0], "oath");
	strcpy(words[1], "pea");
	strcpy(words[2], "eat");
	strcpy(words[3], "rain");
	int word_count = 4;
	for (int k = 0; k < word_count; k++)
	{
		insert(words[k]);
	}

	findWords(board, r, c, words, word_count);
	for (int i = 0; i < (r + 1); i++)
	{
		free(words[i]);
		free(board[i]);
	}
	free(words);
	free(board);
	return 0;
}
