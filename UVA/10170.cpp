//============================================================================
// Name        : uva10170.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(ll target )
{
	return (- 1 + ceil (sqrt(1+(8*target))))/2;
}
ll bigger(ll target , vector<ll> &sums )
{
	ll l =0 , r = sums.size()-1;
	ll mid =-1;
	ll res =-1;
	while (l <= r )
	{
		mid = l +(r-l)/2;
		if (sums[mid] >=target )
			res = mid , r =mid-1;
		else
			l = mid+1;
	}
	return res ;
}
int main() {
	vector<ll>sum;;
	for (ll tmp =1  ;(tmp*(tmp+1)/2)<= (1e15) ;tmp++)
		sum.push_back(tmp*(tmp+1)/2);

	ll n , d ;
	while(cin>>n>>d)
	{
		--n;
		ll ind = bigger(d+ n*(n+1)/2 ,sum)+1;
		cout<<ind<<endl;
	}

	return 0;
}
