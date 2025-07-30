#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<fstream>
using namespace std;
ofstream fout("growth1.dat");

double partition(double A[],int l,int u, int B[])
{
double v,temp, v2, temp2;
int i,j;
v=A[l];
v2 = B[l];
i=l;
j=u+1;
do
{
	do
	i++;
	while(A[i]<v && i<=u);
	do
	j--;
	while(v<A[j]);
    if (i<j)
    {
        temp=A[i];
        A[i]=A[j];
        A[j]=temp;
        
        temp2 = B[i];
        B[i] = B[j];
        B[j] = temp2;
    }
}
	while (i<j);
    
    
	A[l] = A[j];
    B[l] = B[j];
	A[j] = v;
    B[j] = v2;
    
return (j);
}
double rand_partition ( double A[ ] , int l , int u, int B[] ) {
    //chooses position of pivot randomly by using rand() function .
     int random = l + rand( )%(u-l +1 ) ;

      swap (A[random] , A[l] ) ;        //swap pivot with 1st element.
      swap (B[random], B[l]);
      
     return partition(A, l ,u, B) ;       //call the above partition function
}

void sort(double A[],int l,int u, int B[])
{
int j ;
if (l<u)
{
	j=rand_partition(A,l,u, B);
	sort(A,l,j-1, B);
	sort(A,j+1,u, B);
}
}

int main() 	  // main function
{  
   double ran_select[100000];  double ran_prime[100000] ;
   int indx[100000] ;          double phi_n[100000] ;
   double phi[100000];        double ran_time[100000] ;
  
    for(int i=0 ; i<=90000 ; i++)
   {   
       phi_n[i]=0 ;
                      }  
      int seed   ;    //  generate random numbers
   srand(time(NULL))   ;
   
   for(int N=0 ; N<50 ; N++)  { // ensemble average
   
  
     int ran_num=2 ;                                        
     double b ;
     ran_select[0]=0 ;   
     indx[0]=0  ;
     indx[1]=1  ;
    
 
     int c1=rand() ;
   double x1=(double)c1/(double)RAND_MAX ;          
      	ran_select[1]=x1 ;          
       
      cout<<"N="<<N<<"  "<<"x1="<<x1<<endl ;
  
   
   for( int m=1 ; m<=90000 ; m++ )  {   // repeated tasks

    double sum=0  ;
    int gap_count=0 ;
    double left_point[50000] ; // left point
    double right_point[50000] ; // right point
    double num_prime[100000] ;  
    double num_x[100000] ;       // arrays added velocity 
  
   // num_prime[1]=x1 ;   
     sort(ran_select,0,ran_num-1,indx) ;
  


   for(int f=1; f<=ran_num-1 ; f++)  {    b=0 ; //  added velocity
                                           
              for(int l=indx[f] ; l<=m ; l++)  {
                    b+=0.1/pow(l,2) ;  }
                      num_x[f]=b ;      
                                          }           
                                         

       // count gap_number

        if(ran_select[1]>num_x[1]) {      gap_count=gap_count+1   ;
                                      left_point[gap_count]=0  ;
                                      right_point[gap_count]=ran_select[1]-num_x[1]  ;                                        
                                   }                                      
      for( int i=2 ; i<=ran_num-1 ; i++ )                             {                       
        // choose these gap size which is greater than sigma between continuonus number
          if((ran_select[i]-ran_select[i-1])>(num_x[i]+num_x[i-1]))
                                                                          { gap_count=gap_count+1 ;
                                                               left_point[gap_count]=ran_select[i-1]+num_x[i-1] ;
                                                               right_point[gap_count]=ran_select[i]-num_x[i] ;   
                                                                           }
                                                                              }    
         if( 1-ran_select[ran_num-1]>num_x[ran_num-1] )    {                          gap_count=gap_count+1 ;
                                                               left_point[gap_count]=ran_select[ran_num-1]+num_x[ran_num-1] ;   
                                                              right_point[gap_count]=1 ;                                        
                                                          } 
       for (int i=1 ; i<=gap_count; i++) { 
                                            ran_time[i]=(right_point[i]-left_point[i]) ;            
                                           }
       for (int j=1 ; j<=gap_count ; j++)
       sum+=ran_time[j] ;
        
    // generate random number
     int c2=rand() ;
     double x4=(double)c2/(double)RAND_MAX ;          
  
        		
        for( int i=1; i<=gap_count ; i++ )    {   
                                                if( left_point[i]<x4  && right_point[i]>x4 )
                                                {     ran_num=ran_num+1 ; 
                                                    ran_select[ran_num-1]=x4 ;   
                                                //   num_prime[m+1]=x4 ;
                                                    indx[ran_num-1]=m+1 ;                                                  
                                                
                                                   } 
                                                }
     
       phi[m]=sum ;
      ran_prime[m]=gap_count ;
   
   }
         
      for(int k=1 ; k<=90000 ; k++)
        phi_n[k]+=phi[k] ;
         
         }
   


    for(int i=1 ; i<=90000  ; i++)
   cout<<log(i)<<"  "<<log(phi_n[i]/50)<<endl;





return 0; }



