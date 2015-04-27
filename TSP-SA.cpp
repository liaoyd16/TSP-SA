#include "iostream"
#include "fstream"
#include "string.h"
#include "stdlib.h"
#include "math.h"
#include "limits.h"
#include "time.h"
using namespace std;

class TSP {

private:
char distance_type[30];
int n;
double *x, *y;
double **adjacency_matrix;
int *curr_path, *new_path, *min_path;
double temparature;
clock_t tStart;

public:
 TSP();
 ~TSP();
 void SimulatedAnnealing();
 void readFile();
 void init();
 void retraceMinPath();
 int generateRandomNumber();
 void swap(int, int, int*);
 int getCost(int*);
 void two_opt(int, int, int*);
};

 TSP::TSP()
 {
  temparature=1000000000000000000;
  tStart=clock();
 }

 TSP::~TSP()
 {
 }

 void TSP::SimulatedAnnealing()
 {
  int r1, r2, i;
  double c1, c2, gain, randum_number, prob;
  readFile(); 
  init();

  while(1)
  {
   i=100;
   while(--i)
   {
    for(int i=1;i<n;i++)    
    new_path[i]=curr_path[i];  

    r1=generateRandomNumber();
    r2=generateRandomNumber();
//  swap(r1, r2, new_path);
    two_opt(r1, r2, new_path);

    gain=getCost(new_path) - getCost(curr_path);
    randum_number=(double) (rand()/ (double) RAND_MAX);

    prob=1/(1+ pow(M_E, (gain/temparature)));
    if(prob > 	randum_number)
     for(int i=1;i<n;i++)    
    curr_path[i]=new_path[i];
   
    if(getCost(new_path) < getCost(min_path) )
    {
     for(int i=1;i<n;i++)    
      min_path[i]=new_path[i];
     retraceMinPath();
    }
   }
   temparature*=0.999;
//   cout<<temparature<<endl;
  }
 }

 void TSP::two_opt(int r1, int r2, int *new_path)
 {
  int i, j, k, limit, temp;

//for(i=0;i<n+1;i++) cout<<new_path[i]<<" ";cout<<"   :   ";

  if(r1 > r2)
  {
   temp=r1;
   r1=r2;
   r2=temp;
  }
  limit=floor((r2-r1+1)/2);
  i=r1, j=r2;


  for(k=0;k<limit+1;k++)
   swap(i++, j--, new_path);

//for(i=0;i<n+1;i++) cout<<new_path[i]<<" ";cout<<endl;
 }


 void TSP::init()
 {
  curr_path=new int[n+1];
  curr_path[0]=curr_path[n]=0;
  for(int i=1;i<n;i++)
   curr_path[i]=i;

  new_path=new int[n+1];
  new_path[0]=new_path[n]=0;
  for(int i=1;i<n;i++)
   new_path[i]=i;

  min_path=new int[n+1];
  min_path[0]=min_path[n]=0;
  for(int i=1;i<n;i++)
   min_path[i]=i;
 }

 int TSP::getCost(int *path)
 {
  int cost=0;
  for(int i=0;i<n;i++)
   cost+=adjacency_matrix[path[i]][path[i+1]];
  return cost;
 }


 void TSP::readFile()
 {
  int i, j;
  
  cin>>distance_type;  if(strcmp(distance_type, "non")==0)  cin>>distance_type;
  cin>>n;
 
  x=new double[n]; y=new double[n];

  adjacency_matrix=new double*[n];
  for(i=0;i<n;i++)
   adjacency_matrix[i]=new double[n]; 

  for(i=0;i<n;i++)
  {
   cin>>x[i]>>y[i];
  }
 
  for(i=0;i<n;i++)
  {
   for(j=0;j<n;j++)
   {
    cin>>adjacency_matrix[i][j];
   }
  }
 }

 int TSP::generateRandomNumber()
 {
  return (rand()%(n-1))+1;
 }
  
 void TSP::swap(int r1, int r2, int *new_path)
 {
  int temp=new_path[r1];
  new_path[r1]=new_path[r2];
  new_path[r2]=temp;
 }

 void TSP::retraceMinPath()
 {
  printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
  cout<<"The shortest cost obtained so far is "<<getCost(min_path)<<endl;
  for(int i=0;i<n;i++)
   cout<<min_path[i]+1<<" ";cout<<endl;
 }

 int main()
 {
  TSP t;
  t.SimulatedAnnealing();
  return 0;
 }
