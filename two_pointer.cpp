#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (ll) (1e9+7)

void merge_two_sorted_vec(){
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n), b(m), c(n+m);
	for(auto &it: a) cin >> it;
	for(auto &it: b) cin >> it;

	ll i=0, j=0, k=0;
	while(i<n && j<m){
		if(a[i]<b[j]){
			c[k]=a[i], i++, k++;
		}
		else{
			c[k]=b[j], j++, k++;
		}
	}
	while(i<n){
		c[k]=a[i], i++, k++;
	}
	while(j<m){
		c[k]=b[i], j++, k++;
	}
}


void for_a_find_how_many_are_less_than_in_b(){
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n), b(m);
	vector<ll> ans(n);
	for(auto &it: a) cin >> it;
	for(auto &it: b) cin >> it;

	ll i=0, j=0;
	while(i<n){
		while(j<m && b[j]<a[i]){
			j++;
		}
		ans[i]=j;
		i++;
	}
}

int main()
{


	return 0;
}
