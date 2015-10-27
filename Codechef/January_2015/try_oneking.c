#include <stdio.h>
#include <stdlib.h>

struct Interval{
	int start;
	int end;
};

typedef int (*compfn)(const void*, const void*);
int  compare(struct Interval *, struct Interval *);
//using namespace std;

int max(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int compare(struct Interval *elem1, struct Interval *elem2)
{
   if ( elem1->start < elem2->start)
      return -1;

   else if (elem1->start > elem2->start)
      return 1;

   else
      return 0;
}

int main()
{
	int t;
	long long i,j,k,n, numBombs, maximum;

	scanf("%d",&t);

	while(t--)
	{
		scanf("%lld",&n);

		struct Interval pairs[n+1];

		for(i=0;i<n;i++)
		{
			scanf("%d%d",&pairs[i].start,&pairs[i].end);
		}

		//sort(pairs, pairs+n);
		qsort((void *)pairs, n, sizeof(struct Interval), (compfn)compare);

		//Print check
				/*for(i=0;i<n;i++)
				{
					printf("%d %d\n",pairs[i].start, pairs[i].end);
				}*/
		//
		numBombs = 1; maximum = pairs[0].end;
		for(i=1;i<n;i++)
		{
			if(maximum >= pairs[i].start)// If overlapping
			{
				maximum = max(pairs[i].end, maximum);// Find maximum
			}
			else
			{
				maximum = pairs[i].end;
				numBombs++;
			}
		}


		printf("%lld\n", numBombs);
	}

	return 0;
}