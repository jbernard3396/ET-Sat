#include <stdio.h>
#include <stdlib.h>
struct RGB
{
	int R;
	int G;
	int B;
};

struct RGB input_image[5] = {
	{1,2,3},
	{2,2,3},
	{3,2,3},
	{4,2,3},
	{5,2,3}
};

struct RGB * get_omitted(struct RGB orig_image[], int size, float compress_rate)
{
	struct RGB * omitted_image = (struct RGB *) calloc( int(size*compress_rate) + 1, sizeof(struct RGB));
	int idx = 0;
	for (int i=0; i<size; i++)
	{
		//FIXME
		if (i%2==0)
		{
			omitted_image[idx] = orig_image[i];
			idx++;
		}
	}
	return omitted_image;
}


int main()
{
	struct RGB * catcher = get_omitted(input_image, 5);
	for (int i=0; i<5; i++)
	{
		printf("Catcher[%d]: %d, %d, %d\n", i, catcher[i].R, catcher[i].G, catcher[i].B);
	}
	free(catcher);
	return 0;
}
