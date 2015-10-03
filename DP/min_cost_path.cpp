#include <iostream>

using namespace std ;

int minimum(int a , int b )
{
	return (a < b)?a:b ;
}

int min_cost_path(int cost[][3] , int n, int m )
{
    int tc[n][m] ;
     tc[0][0] = cost[0][0];
 
     /* Initialize first column of total cost(tc) array */
     for (int i = 1; i < m; i++)
        tc[i][0] = tc[i-1][0] + cost[i][0];
 
     /* Initialize first row of tc array */
     for (int j = 1; j < n; j++)
        tc[0][j] = tc[0][j-1] + cost[0][j];
 
     /* Construct rest of the tc array */
     for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            tc[i][j] = minimum(minimum(tc[i-1][j-1], tc[i-1][j]), tc[i][j-1]) + cost[i][j];
 
     return tc[m-1][n-1];

}

int main()
{

int cost[3][3] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };

int costl = min_cost_path( cost , 3, 3) ;
cout<<costl<<endl;
return 0 ;	

}