#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<fstream>
using namespace std;
ofstream fout("growth_n.dat");

double partition(double A[],int l,int u, int B[])   //sorting array(ran_select[]) & array(index[])
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

void sort(double A[],int l,int u, int B[])  //sorting
{
int j ;
if (l<u)
{
	j=rand_partition(A,l,u, B);
	sort(A,l,j-1, B);
	sort(A,j+1,u, B);
}
}
int* counting( double a[],int c )  //  counting gap between 0.001 interval
{   a[c];
         
   int* d=new int[20000];
   for(int i=1 ; i<=10000; i++)   {  int count=0 ;
     for (int j=1 ; j<=c ; j++)   {   
           
          if(((i-1)*0.000001)<a[j] && a[j]<(i*0.000001))  { 
          
               count++ 	;                      }
                                
                                  }
         d[i]=count/0.000001 ;
                                   }    
                     return d ;                 }                       

int main() 	  // main function
{ 

 
  double ran_select[100000]   ;       int indx[100000]         ;
  double ran_prime[100000]    ;       double ran1_time[20000]   ;    
  double growth_left[90000] ;       double ran2_time[20000]   ;
  double growth_right[90000];       double ran3_time[20000]   ;
  double phi1_n[20000]         ;       double ran4_time[20000]   ;
  double phi2_n[20000]         ;       double phi3_n[20000]      ;
  double phi4_n[20000]         ;    
 
   
  for(int i=1 ; i<=10000 ; i++)       // ensemble array initializing
   {   
       phi1_n[i]=0   ;
       phi2_n[i]=0   ;
       phi3_n[i]=0   ;
       phi4_n[i]=0  ;               }  
    
    int e=10000 ;
    int n=5000  ;
    int seed   ;    //  generate random numbers
   srand(time(NULL))   ;
   
  for( int N=0 ; N<n; N++) {  // ensemble average
       
   for(int i=0 ; i<=10000 ; i++)   // velocity initializing
     {     
       growth_left[i]=0 ;
       growth_right[i]=0 ;
                      }  
   
     
     
     int ran_num=3 ;                                        
     double b ;
     ran_select[0]=0 ;
     ran_select[2]=1 ;   
     indx[0]=0  ;           // index= what time random generate
     indx[1]=1  ;
     indx[2]=2  ;
    cout<< "N=" << N << endl;
 
    int c1=rand() ;                             // first random number
    double x1=(double)c1/(double)RAND_MAX ;          
      	ran_select[1]=x1 ;          
     
    for( int m=1 ; m<=10000 ; m++ )  {   // time counter

    double sum=0  ;
    int gap_count=0 ;
    double left_point[50000] ; // left point
    double right_point[50000] ;  // right point
    double gap_size[5000]    ;
    double num_x[50000]     ;  // arrays added velocity_right 
    double num_y[50000]     ;  // arrays added velocity_left
     
     sort(ran_select,0,ran_num-1,indx) ;
  


    for(int f=1; f<ran_num ; f++)  {     //  added velocity
                                       b=0;
                                   growth_left[0]=0 ;  // to find interval size between two seeds 
                     
                    b=(ran_select[f]-ran_select[f-1]-growth_right[indx[f]]-growth_left[indx[f-1]]) ;
                   
                    growth_right[indx[f]]+=0.1*pow(b,2) ;  //right side growth
                    growth_left[indx[f-1]]+=0.1*pow(b,2) ; // left side growth
                   
                        growth_right[2]=0 ;
                   
                    num_x[f]=growth_right[indx[f]] ;      //growth sorted by sorting random number 
                    num_y[f]=growth_left[indx[f-1]] ;
                                   
                                    }           
                   
 
       // count gap_number

        if(ran_select[1]>num_x[1]) {      gap_count=gap_count+1   ;  // first sorting random number
                                      left_point[gap_count]=0  ;
                                      right_point[gap_count]=ran_select[1]-num_x[1]  ;                                        
                                   }                                      
       for( int i=2 ; i<=ran_num-1 ; i++ )                             {                    // up to second last   
        // choose these gap size which is greater than sigma between continuonus number
          
          if((ran_select[i]-ran_select[i-1])>(num_x[i]+num_y[i]))
                                                                     {     gap_count=gap_count+1 ;
                                                               left_point[gap_count]=ran_select[i-1]+num_y[i] ;
                                                               right_point[gap_count]=ran_select[i]-num_x[i] ;   
                                                                           }
                                                                              }    
         if (( 1-ran_select[ran_num-2])>num_y[ran_num-1] )    {             // last gap count
                                                                      gap_count=gap_count+1 ;
                                                              left_point[gap_count]=ran_select[ran_num-1]+num_y[ran_num-1] ;   
                                                              right_point[gap_count]=1 ;                                        
                                                          } 
       for (int i=1 ; i<=gap_count; i++) {      //summing total gap size 
                                          gap_size[i]=(right_point[i]-left_point[i]) ;            
                                           }
   
     
       
     // generate random number
     
     int c2=rand() ;
     double x4=(double)c2/(double)RAND_MAX ;          
  
      // checking random in gap size
      
     for( int i=1; i<=gap_count ; i++ )    {   
                                                if( left_point[i]<x4  && right_point[i]>x4 )
                                                {     ran_num=ran_num+1 ; 
                                                    ran_select[ran_num-1]=x4 ;   
                                              
                                                   indx[ran_num-1]=m+2 ;                                                  
                                                
                                                   } 
                                                }
                                               
       
           if(m==7000)  {                          // time=7000
       int* e1=counting(gap_size,gap_count)  ;
       for( int i=1 ; i<=e  ; i++ )
         ran1_time[i]=e1[i]  ;            
                         }  
                                         
         else if(m==8000)  {                       //time=8000
       int* f=counting(gap_size,gap_count)  ;
       for( int i=1 ; i<=e  ; i++ )
         ran2_time[i]=f[i]  ; }                                  
                                         
            else if(m==9000)  {                    //time=9000
       int* h=counting(gap_size,gap_count)  ;
       for( int i=1 ; i<=e  ; i++ )
         ran3_time[i]=h[i]  ; }   
                                      
           else if(m==10000)  {                      //time=10000
       int* t=counting(gap_size,gap_count)  ;
       for( int i=1 ; i<=e  ; i++ )
         ran4_time[i]=t[i]  ; }    
                                                                   
                                            }        
         
      for( int i=1 ; i<=e  ; i++ )          // summing ensemble 
        phi1_n[i]+=ran1_time[i]  ;  
       
        for( int i=1 ; i<=e  ; i++ )
        phi2_n[i]+=ran2_time[i]  ;  
         
          for( int i=1 ; i<=e  ; i++ )
        phi3_n[i]+=ran3_time[i]  ;  
        
        for( int i=1 ; i<=e  ; i++ )
        phi4_n[i]+=ran4_time[i]  ;  
                                                    
                 
                                         }
                                           
   // cout << "ran_num=" << ran_num << endl ;  
   
   for( int i=0 ; i<=e ; i++ )
   fout<<(i*0.000001*7000)<<"    "<<(i*0.000001*8000)<<"  "<<(i*0.000001*9000)<<"   "<<(i*0.000001*10000) <<log((phi1_n[i]/n)/4975576.468) << "  " <<log((phi2_n[i]/n)/6278349.787) <<"   " <<log((phi3_n[i]/n)/7707892.988) << "    "<<log((phi4_n[i]/n)/9260395.772) << endl ;
       
       
       return 0 ; }
       

