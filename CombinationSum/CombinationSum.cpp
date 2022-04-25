#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

vector<vector<int> > findNumbers(int* ar, int ar_count, int sum, vector<vector<int> > res, vector<int>& r, size_t i)
{	
	if (sum == 0) {// if we get exact answer
		res.push_back(r);
	} else {
		while (i < ar_count && sum >= ar[i]) {	// Recur for all remaining elements that have value smaller than sum.	
			r.push_back(ar[i]); // Add every element in the array starting from i which can contribute to the sum add
			res = findNumbers(ar, ar_count, sum - ar[i], res, r, i);// recursive call for next numbers
			r.pop_back();// Remove number from list (backtracking)
			i++;
		}
	}
	return res;
}

vector<vector<int> > combinationSum(int* ar, int ar_count, int sum)
{
	qsort(ar, ar_count, sizeof(int), compare);
	vector<int> r;
	vector<vector<int> > res = findNumbers(ar, ar_count, sum, res, r, 0);
	return res;
}

int main()
{
	int n = 4;
	int* ar = (int*)calloc(n, sizeof(int));
	ar[0] = 2, ar[1] = 4, ar[2] = 6, ar[3] = 8;

	int sum = 8; // set value of sum
	vector<vector<int> > res = combinationSum(ar, n, sum);
	for (size_t i = 0; i < res.size(); i++) {
		if (res[i].size() > 0) {
			printf(" ( ");
			for (size_t j = 0; j < res[i].size(); j++)
			{
				printf("%d ", res[i][j]);
			}
			printf(")");
		}
	}
	return 0;
}
