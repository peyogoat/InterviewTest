void InsertSort(int arr[],int len)
{
	int i,j;
	int temp;
	for(i = 1; i<len; i++)
	{
		temp = arr[i];
		for(j = i-1; j>0 && arr[j]>temp; j--)
		{
			arr[j+1] = arr[j];
		}
		arr[j+1] = temp;
	}
}

void BubbleSort(int arr[],int len)
{
	int i,j;
	int temp;
	int sym = 1;
	for(i = 0; i<len-1; i++)
	{
		for(j = 0; j<(len-i-1); j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
				sym = 0;
			}
		}
		if(sym)
			break;
		sym = 1;
	}
}