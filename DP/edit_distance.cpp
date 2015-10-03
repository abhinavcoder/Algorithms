/* Code for minimum edit distance : with equal cost of substitution  */

#include <iostream>
#include <cstring>

using namespace std ; 

int min(int a, int b) {
   return a < b ? a : b;
}
 
// Returns Minimum among a, b, c
int Minimum(int a, int b, int c)
{
    return min(min(a, b), c);
}

int edit_dist(char *X , char *Y , int n , int m)
{
  int D[n+1][m+1] ;
  int del , insert , subs ;
  for(int i = 0 ; i <= n ; i ++)
  	D[i][0] = i ;

  for(int j = 0 ; j <= m ; j++)
  	D[0][j] = j; 

  for(int i = 1 ; i <= n ; i++) {
  	for(int j = 1 ; j <= m ; j++) {
  		del = D[i-1][j] + 1 ;
  		insert = D[i][j-1] + 1 ;
  		if(X[i-1]!=Y[i-1])
  		{
  			subs = D[i-1][j-1] +1 ;
  		    D[i][j] = Minimum(del , insert , subs ) ;
        }
   		else
  			D[i][j] = D[i-1][j-1];

  	}
  }
 return D[n][m] ;
}

int main()
{
 
 char X[] = "ABHINAV" ; 
 char Y[] = "AHHINZS" ;

 int n = strlen(X) ;
 int m = strlen(Y) ;

 int dist = edit_dist(X , Y , n , m ) ;
 cout<<dist<<endl ;
return 0 ;	
}