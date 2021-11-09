/*
             CodEcstasy
            SUST SWE-19
*/
#include <iostream>
#include <vector>
#define ll long long
#define s second
#define f first
#define fora(i,n) for(int i=0 ; i<n ; i++)
#define ford(i,n) for(int i=n-1 ; i>=0 ; i--)
#define b begin
#define e end
#define all(v) (v).begin(),(v).end()
#define pb push_back
using namespace std;

void merge(vector <int> &arr, int l, int mid, int r) {
	int arrsz1=mid-l+1,arrsz2=r-mid;
	int temp1[arrsz1],temp2[arrsz2];
	for(int i=0 ; i<arrsz1 ; i++)
		temp1[i]=arr[l+i];
	for(int i=0 ; i<arrsz2 ; i++)
		temp2[i]=arr[mid+1+i];
	int i=0,j=0,pt=l;
	while(i<arrsz1 && j<arrsz2) {
		if(temp1[i] <= temp2[j])
			arr[pt++]=temp1[i++];
		else
			arr[pt++]=temp2[j++];
	}
	while(i<arrsz1)
		arr[pt++]=temp1[i++];
	while(j<arrsz2)
		arr[pt++]=temp2[j++];
}

void mergesort(vector <int> &arr, int l, int r) {
	if(l >= r) {
		return;
	}
	int mid = ((l+r) >> 1);
	//cout << mid << endl;
	mergesort(arr,l,mid);
	mergesort(arr,mid+1,r);
	merge(arr,l,mid,r);
}

int main() 
{
    int n;
	cin >> n;
	vector <int> v(n);
	for(int i=0 ; i<n ; i++)
		cin >> v[i];
	mergesort(v,0,n-1);

	for(int i=0 ; i<n ; i++)
		cout << v[i] << " \n"[i==n-1];
}