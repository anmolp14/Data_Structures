#include<iostream>
#include<time.h>
long int m=81;
unsigned long long int  rec_fib( unsigned long long int n, long int a , long int b, long int c )

{
	if ( n==1 || n==2 ) 
		return 1;
	else 
		return ((a* rec_fib(n-1,a,b,c))%m + (b* rec_fib(n-2,a,b,c))%m + c%m )%m ;






}
using namespace std;

int main()
{
	long int a=51 ,b=61,c=71;
	 
	for( unsigned long long int i=1; i<= 1000 ; i++ ) 
	{	
		cout << i << "  ";
		clock_t start , end;
		double cpu_time_used ;
		start = clock();
		unsigned long long int n=i,num ;


		num = rec_fib ( n,a,b,c )   ;
		//cout << (num % m) << endl ;


		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

		cout <<  cpu_time_used << endl ;

	}
	return 0;

} 

