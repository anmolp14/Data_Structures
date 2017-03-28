#include<iostream>
#include<time.h>
long int m,a,b;

using namespace std;
void print( long int m[3][3] ) 
{ for( int i=0 ; i< 3 ; i++ )
	{   for(int j=0 ; j< 3 ; j++ )
		{
			cout << m[i][j] << ' ' ;

		}
		cout << endl;
	}
}  
void mat_mul( long int M1[3][3] , long int M2[3][3] )
{	long int M3[3][3] = {{0,0,0},{0,0,0},{0,0,0}} ; 


	for( int i=0 ; i< 3 ; i++ )
	{   for(int j=0 ; j< 3 ; j++ )
		{ 
			for ( int k=0 ;k<3 ; k++    )
			{
				M3[i][j] = ( M3[i][j] +  M1[i][k] * M2 [k][j]) % m ;
			}
		} 

	}
	for( int l=0 ; l< 3 ; l++ )
	{   for(int u=0 ; u< 3 ; u++ )
		{
			M1[l][u] =    M3[l][u]  ;

		}
	}

	return;

}

void  Mat_pow(long int M[3][3] , long long int n )
{


	if(n==1)
		return;
	else if( n%2 == 0 )
	{
		Mat_pow( M , n/2 );
		mat_mul ( M , M ) ;


	}

	else{ long int L[3][3]= { {a,b,1},
		{1, 0 ,0},{0,0,1}} ;

		Mat_pow( M , n/2) ;
		mat_mul ( M , M ) ; 
		mat_mul ( M , L ) ;

	}

	return ; 



}
int main()
{//clock_t start , end;
	//	double cpu_time_used ;
	//	//	start = clock();
	int t;
	cin >> t;
	for( int w=0 ; w < t ; w++)
	{
		long int c;
		long long int n, num;
		cin >> a >> b >> c >> n >> m;
		if( n==1 || n==2 )
		{cout << 1 ;
		}
		else {long int M[3][3]= { {a,b,1},
			{1, 0 ,0},{0,0,1}} ;
			Mat_pow ( M , n-2 ); 
			cout << (M[0][0] + M[0][1] + M[0][2] * c )%m ;


		} 

		if( w != t-1 )
			cout << endl;
	} 
	//	end = clock();
	//	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

	//	cout << "time = " << cpu_time_used;



	return 0;

}  
