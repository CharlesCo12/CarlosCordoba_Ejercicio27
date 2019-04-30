#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

void laplace(int nmax, float err, string filename);

int main(){
    laplace(101,0.01,"datos.dat");
    return 0;
}

void laplace(int nmax, float err, string filename){
  float delta = 0.01;
  float *v_old;
  float *v_new;
  ofstream outfile;
  outfile.open(filename);
  v_old = new float[nmax,nmax];
  v_new = new float[nmax,nmax];
    
  for(int i=0;i<nmax;i++){
      for(int j=0;j<nmax;j++){
          if(20<=i<=80 && j==40){v_old[i,j]=-100;}
          if(20<=i<=80 && j==60){v_old[i,j]=100;}
      }      
  }
    
  float miss=100;
  while(miss>err){    
    for(int i=1;i<nmax-1;i++){
      for(int j=1;j<nmax-1;j++){
          if((20<=i<=80 && j==40)||(20<=i<=80 && j==60)){}
          else{
              v_new[i,j]=(v_old[i-1,j]+v_old[i+1,j]+v_old[i,j-1]+v_old[i,j+1])/4;
          }
      }
    }  
    miss=0;
    int cont = 0;
    for(int i=1;i<nmax-1;i++){
        for(int j=1;j<nmax-1;j++){
            cont=cont+1;
            miss = miss + abs(v_old[i,j] - v_new[i,j]);
        }
      }
    miss = miss/cont;
      
    for(int i=0;i<nmax;i++){
      for(int j=0;j<nmax;j++){
          v_old[i,j]=v_new[i,j];
      }      
  }
  }
  for(int i=0;i<nmax;i++){
      for(int j=0;j<nmax;j++){
          outfile << v_new[i,j] << " ";
          if(j==nmax-1){outfile<<endl;}
      }      
  }
  outfile.close();
}