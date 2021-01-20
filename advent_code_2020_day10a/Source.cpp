#include <cstdio>
#include <algorithm>

int values[100];
int main() {

	FILE *fin = fopen("input.txt", "r");
	if (!fin) {
		fprintf(stderr, "Can't open input file\n");
		return 1;
	}

	int nvalues = 0;
	int val;
	while (fscanf(fin, "%d", &val) == 1)
	{
		values[nvalues] = val;
		nvalues++;
	}
	fclose(fin);

	std::sort(values, values + nvalues);

	int ndiff1 = 0;
	int ndiff3 = 1; //built-in

	int prev;
	int curr = 0;
	for (int i = 0; i < nvalues; i++) {
		prev = curr;
		curr = values[i];
		int diff = curr - prev;
		if (diff == 1)
			ndiff1++;
		else if (diff == 3)
			ndiff3++;
	}

	printf("%d\n", ndiff1*ndiff3);

	return 0;
}