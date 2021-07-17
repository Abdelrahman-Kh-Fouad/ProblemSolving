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
ll bigger(ll target )
{
	ll l =0 , r = 1e9;
	ll mid =-1;
	ll res =-1;
	while (l <= r )
	{
		mid = l +(r-l)/2;
		if (mid*(mid+1)/2 >=target )
			res = mid , r =mid-1;
		else
			l = mid+1;
	}
	return res ;
}
int main() {

	ll n , d ;
	while(cin>>n>>d)
	{
		--n;
		ll ind = bigger(d+ n*(n+1)/2 );
		cout<<ind<<endl;
	}

	return 0;
}
