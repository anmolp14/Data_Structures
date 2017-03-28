#include<iostream>
#include<time.h>
long int m;
long long int  rec_fib( long long int n, long int a , long int b, long int c )

{
	if ( n==1 || n==2 ) 
		return 1;
	else 
		return ((a* rec_fib(n-1,a,b,c))%m + (b* rec_fib(n-2,a,b,c))%m + c%m )%m ;






}
using namespace std;

int main()
{
	int t;
	cin >> t;
	for( int i=0 ;i<t;i++ )
	{

		long int a ,b,c;
		long long int n,num ;

		cin >> a >> b >> c >> n >> m ;

		num = rec_fib ( n,a,b,c )   ;
		cout << (num % m) << endl ;


	}

	return 0;

} 

