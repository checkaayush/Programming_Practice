#include<stdio.h>
int main()
{
	int t, i, j, k, check[501]={0};
	long long n;

	scanf("%d",&t);

	while(t--)
	{
		scanf("%lld",&n);
		
		int a[n+1], b[n+1], size_check = 501;
		// Take input, Increment check array for given intervals 
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a[i],&b[i]);

			//if(i==0) size_check = b[i];
			
			//if(size_check < b[i])
			//	size_check = b[i];

			for(j=a[i];j<=b[i];j++)
				check[j]++;
		}

		//size_check++;

		//Print check
		/*	for(k=0;k<12;k++)
				printf("%d ",check[k]);
			printf("\n");*/
		

		long long int numBombs = 0; int index;
		while(1)
		{
			//Place bomb at index
			index = indexOfMaxElement(check, size_check);
			//printf("index = %d\n",index);

			if(index == -1)
			{
				break;
			}
			else
			{
				//Decrement intervals which contain index
				for(i=0;i<n;i++)
				{
					if(index <= b[i] && index >= a[i])
					{
						for(j=a[i];j<=b[i];j++)
						{
							check[j]--;
						}
					}
				}

				numBombs++;
				//Print check
				/*for(k=0;k<10;k++)
					printf("%d ",check[k]);
				printf("\n");*/
				
			}
		}

		printf("%lld\n",numBombs);
	}	

	return 0;
}

int indexOfMaxElement( int* array, int size )
{
	int i, maxElement = array[0], index=0;
	
	for(i=1;i<size;i++)
	{
		if(array[i]>maxElement)
		{
			maxElement = array[i];
			index = i;
		}
	}

	if(maxElement == 0)
		return -1;
	else
		return index;
}