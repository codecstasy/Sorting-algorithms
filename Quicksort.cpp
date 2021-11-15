#include <iostream>
#define sz 1000
using namespace std;

int partition(int ar[], int l, int r) {
	bool dir=true;
	while(l < r) {
		if(ar[l] > ar[r]) {
			swap(ar[l],ar[r]);
			dir ^= true;
		}
		if(dir) r--;
		else l++;
	}
	return l;
}

void quicksort(int ar[], int l, int r) {
	if(l >= r)
		return;
	int pivot = partition(ar,l,r);
	quicksort(ar,l,pivot-1);
	quicksort(ar,pivot+1,r);
}

int main() {
	int n;
	cin >> n;
	int ar[sz];
	for(int i=0 ; i<n ; i++)
		cin >> ar[i];
	quicksort(ar,0,n-1);

	cout << "Sorted array : ";
	for(int i=0 ; i<n ; i++) {
		cout << ar[i] << " \n"[i==n-1];
	}
}