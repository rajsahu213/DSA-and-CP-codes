#include<bits/stdc++.h>
using namespace std;

int partition(int a[],int low,int high)
{
	int p=a[low];
	int l=low+1;
	int h=high;
	while(l<=h)
	{
		while(a[l]<p&&l<high)
		{
			l++;
		}
		while(a[h]>p&&h>0)
		{
			h--;
		}
		if(l<h)swap(a[l],a[h]);
	}
	swap(a[low],a[h]);
	return h;
}

void quick_sort(int a[],int low,int high)
{
	if(low<high)
	{
		int j=partition(a,low,high);
		quick_sort(a,low,j-1);
		quick_sort(a,j+1,high);
	}
}

void bubble_sort(int a[],int i,int j,int n)
{
	if(i==n-1)
	{
		return;
	}
	if(j==(n-i-1))
	{
		i++;j=0;
	}
	if(a[j+1]<a[j])swap(a[j+1],a[j]);
	bubble_sort(a,i,j+1,n);
}

void selection_sort_recc(int a[],int i,int j,int n,int &min)
{
	if(i==n-1)return;
	if(j==n)
	{
		swap(a[i],a[min]);
		i++;
		j=i+1;
		min=i;
	}
	if(a[j]<a[min])min=j;
	selection_sort_recc(a,i,++j,n,min);
}

void selection_sort(int a[],int n)
{
	int min=0;
	for(int i=0;i<n;i++)
	{
		min=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[min])min=j;
		}
		swap(a[i],a[min]);
	}
}

void bubble_sort_iter(int a[],int n)
{
	int last;
	for(int i=0;i<n;i++)
	{
		last=n-i-1;
		for(int j=0;j<last;j++)
		{
			if(a[j+1]<a[j])swap(a[j+1],a[j]);
		}
	}
}

void insertion_sort(int a[],int p)
{
	int n,val;
	for(int i=0;i<p-1;i++)
	{
		n=i+1;
		val=a[i+1];
		while(val<a[n-1]&&n>0)
		{
			a[n]=a[n-1];
			n--;
		}
		a[n]=val;
	}
}


void merge(int a[],int low,int high)
{
	int mid=low+(high-low)/2;
	int i=low;
	int j=mid+1;
	int k=low;
	int temp[high+1];
	while(i<=mid&&j<=high)
	{
		if(a[i]<a[j])temp[k++]=a[i++];
		else temp[k++]=a[j++];
	}
	while(i<=mid)temp[k++]=a[i++];
	while(j<=high)temp[k++]=a[j++];
	for(int i=low;i<=high;i++)
	{
		a[i]=temp[i];
	}
}

void merge_sort(int a[],int low,int high)
{
	if(low<high)
	{
		int mid=low+(high-low)/2;
		merge_sort(a,low,mid);
		merge_sort(a,mid+1,high);
		merge(a,low,high);
	}
}

void radix_sort(vector<int> &a)
{
    int k=1;
    for(int bits=0;bits<32;bits++){
        vector<vector<int>> temp(10);
        for(int i=0;i<a.size();i++){
            int x,d=a[i],times=bits+1;
            while(times--){
                x=d%10;d=d/10;
            }
            temp[x].push_back(a[i]);
        }
        int l=0;
        for(int i=0;i<10;i++){
            for(int j=0;j<temp[i].size();j++){
                a[l++]=temp[i][j];
            }
        }
    }
}

int main()
{
	int n=9;
	int a[9]={36,18,12,40,63,72,45,54,60};
	int low=0,high=8;
	// quick_sort(a,low,high);
	// bubble_sort(a,0,0,n);
	// selection_sort(a,n);
	// bubble_sort_iter(a,n);
	// merge_sort(a,low,high);
	// insertion_sort(a,n);
	// selection_sort_recc(a,low,1,n,low);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}