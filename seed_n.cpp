#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<fstream>
using namespace std;
ofstream fout("seed_n.dat");

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
int* counting( double a[],int c )
{   a[c];
         
   int* d=new int[2000];
   for(int i=1 ; i<=10; i++)   {  int count=0 ;
     for (int j=1 ; j<c ; j++)   {   
           
          if(((i-1)*0.1) <a[j] && a[j]<(i*0.1))  { 
          
               count++ 	;                      }
                                
                                  }
         d[i]=count ;
                                   }    
                     return d ;                 }                       

int main() 	  // main function
{ 

 
  double ran_select[100000]   ;       int indx[100000]         ;
  double ran_prime[100000]    ;       double ran1_time[2000]   ;    
  double velocity_left[90000] ;       double ran2_time[2000]   ;
  double velocity_right[90000];       double ran3_time[2000]   ;
  double phi1_n[90000]         ;       double ran4_time[2000]   ;
  double phi2_n[90000]         ;       double phi3_n[2000]      ;
  double phi4_n[2000]         ;     
 
   
  for(int i=1 ; i<=2000 ; i++)
   {   
       phi1_n[i]=0   ;
       phi2_n[i]=0   ;
       phi3_n[i]=0   ;
       phi4_n[i]=0  ;               }  
   
 
    int seed   ;    //  generate random numbers
   srand(time(NULL))   ;
   
   for( int N=0 ; N<20; N++) {
       
   for(int i=0 ; i<=10000 ; i++)
   {   
       velocity_left[i]=0 ;
       velocity_right[i]=0 ;
                      }  
   
     
     
     int ran_num=3 ;                                        
     double b ;
     ran_select[0]=0 ;
     ran_select[2]=1 ;   
     indx[0]=0  ;
     indx[1]=1  ;
     indx[2]=2  ;
    cout<< "N=" << N << endl;
 
    int c1=rand() ;
    double x1=(double)c1/(double)RAND_MAX ;          
      	ran_select[1]=x1 ;          
     
    for( int m=1 ; m<=90000 ; m++ )  {   // repeated tasks

    double sum=0  ;
    int gap_count=0 ;
    double left_point[50000] ; // left point
    double right_point[50000] ;  // right point
   
    double num_x[50000]     ;  // arrays added velocity 
    double num_y[50000]     ;
     
     sort(ran_select,0,ran_num-1,indx) ;
  


    for(int f=1; f<ran_num ; f++)  {     //  added velocity
                                       b=0;
                                   velocity_left[0]=0 ;
                     
                    b=(ran_select[f]-ran_select[f-1]-velocity_right[indx[i]]-velocity_left[indx[i-1]]) ;
                   
                    velocity_right[indx[f]]+=0.1*pow(b,2) ;  
                    velocity_left[indx[f-1]]+=0.1*pow(b,2) ; 
                   
                        velocity_right[2]=0 ;
                   
                    num_x[f]=velocity_right[indx[f]] ;      
                    num_y[f]=velocity_left[indx[f-1]] ;
                                   
                                    }           
                   
 
       // count gap_number

        if(ran_select[1]>num_x[1]) {      gap_count=gap_count+1   ;
                                      left_point[gap_count]=0  ;
                                      right_point[gap_count]=ran_select[1]-num_x[1]  ;                                        
                                   }                                      
       for( int i=2 ; i<ran_num-1 ; i++ )                             {                       
        // choose these gap size which is greater than sigma between continuonus number
          
          if((ran_select[i]-ran_select[i-1])>(num_x[i]+num_y[i]))
                                                                     {     gap_count=gap_count+1 ;
                                                               left_point[gap_count]=ran_select[i-1]+num_y[i] ;
                                                               right_point[gap_count]=ran_select[i]-num_x[i] ;   
                                                                           }
                                                                              }    
         if (( 1-ran_select[ran_num-2])>num_y[ran_num-1] )    {             
                                                                      gap_count=gap_count+1 ;
                                                              left_point[gap_count]=ran_select[ran_num-2]+num_y[ran_num-1] ;   
                                                              right_point[gap_count]=1 ;                                        
                                                              } 
       for (int i=1 ; i<=gap_count; i++) { 
                                            sum+=(right_point[i]-left_point[i]) ;            
                                           }
   
     
     // generate random number
     int c2=rand() ;
     double x4=(double)c2/(double)RAND_MAX ;          
  
        		
     for( int i=1; i<=gap_count ; i++ )    {   
                                                if( left_point[i]<x4  && right_point[i]>x4 )
                                                {     ran_num=ran_num+1 ; 
                                                    ran_select[ran_num-1]=x4 ;   
                                              
                                                   indx[ran_num-1]=m+2 ;                                                  
                                                
                                                   } 
                                                }
       
       phi1_n[m]=sum ;  }
       /*    if(m==1000)  {
       int* e=counting(right_point,gap_count)  ;
       for( int i=1 ; i<=10  ; i++ )
         ran1_time[i]=e[i]  ;
         cout<<"gap_count="<<gap_count<<endl ; }  
                                         
         else if(m==2000)  {
       int* f=counting(right_point,gap_count)  ;
       for( int i=1 ; i<=10  ; i++ )
         ran2_time[i]=f[i]  ; 
         cout<<"gap_count="<<gap_count<<endl ; }                                  
                                         
            else if(m==3000)  {
       int* h=counting(right_point,gap_count)  ;
       for( int i=1 ; i<=10  ; i++ )
         ran3_time[i]=h[i]  ; 
         cout<<"gap_count="<<gap_count<<endl ; }   
                                      
           else if(m==4000)  {
       int* t=counting(right_point,gap_count)  ;
       for( int i=1 ; i<=10  ; i++ )
         ran4_time[i]=t[i]  ; 
         cout<<"gap_count="<<gap_count<<endl ; }    
                                         
                                            }        
   for( int i=1 ; i<=10  ; i++ )
   cout<< "ran4_time[" << i << "]=" << ran4_time[i] <<"      "<< "ran1_time[" << i << "]=" << ran1_time[i] <<endl;
   
         
      for( int i=1 ; i<=1000  ; i++ )
        phi1_n[i]+=ran1_time[i]  ;  
       
        for( int i=1 ; i<=1000  ; i++ )
        phi2_n[i]+=ran2_time[i]  ;  
         
          for( int i=1 ; i<=1000  ; i++ )
        phi3_n[i]+=ran3_time[i]  ;  
        
        for( int i=1 ; i<=1000  ; i++ )
        phi4_n[i]+=ran4_time[i]  ;  
        
                 
                                         }*/
                                           
   // cout << "ran_num=" << ran_num << endl ;  
   
  /* for( int i=0 ; i<=1000  ; i++ )
   fout<< (i*0.001*1000) <<"  "<< (i*0.001*2000) << "  "<< (i*0.001*3000) <<"  "<< (i*0.001*4000) <<"  " << phi1_n[i]/50000<< "   " << phi2_n[i]/50000 << "   " << phi3_n[i]/50000 << "   " << phi4_n[i]/50000 << endl ;
    */   
       for( int i=1 ; i<=90000 ; i++ ) 
       phi2_n[i]+=phi1_n[i]   ;
          
                                    }       
       
       
        for( int i=1 ; i<=90000 ; i++ ) 
        fout << log(i) << "  " << log(phi2_n[i]/20) << endl ;     
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       return 0 ; }
       
