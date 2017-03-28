#include<iostream>
#include<time.h>

using namespace std;

int main()
{	long int a=51 , b=61, c=71 , m=81;
//	cin >> a >> b >> c >> m;
for(unsigned long long	int i =486000000 ; i < 1000010000; i+=100000 )
{    cout << i << "  " ;
	clock_t start , end;
	double cpu_time_used ;
	start = clock();
        
	unsigned long long int n = i ,temp, num,n1,n2 ;

	if ( n == 1 || n==2 )
		cout <<  1  ;
	else {
		n1 = 1; n2 =1 ;
		for( unsigned long long int j=0 ; j < n-2 ; j++ )
		{
			temp = n1;
			n1 = (a * n1 + b * n2 + c)%m  ;
			n2 = temp%m    ; 



		}

	}
// cout << ( n1%m ) << endl ;

		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

		cout <<  cpu_time_used << endl;

	}






	return 0;

} 

