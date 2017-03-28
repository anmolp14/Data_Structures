#include<iostream>

using namespace std;

int main()
{
	int t ;
	cin >> t;
	for( int i =0;i<t;i++)
	{
		long int a , b, c , m;
		unsigned long long int n ,temp, num,n1,n2 ;
		cin >> a >> b >> c >> n >> m;

		if ( n == 1 || n==2 )
			cout <<  1  ;
		else {
			n1 = 1; n2 =1 ;
			for( unsigned long long int i=0 ; i < n-2 ; i++ )
			{
				temp = n1;
				n1 = (a * n1 + b * n2 + c)%m  ;
				n2 = temp%m    ; 



			}

			cout << ( n1%m ) << endl ;



		}





	}
	return 0;

} 

