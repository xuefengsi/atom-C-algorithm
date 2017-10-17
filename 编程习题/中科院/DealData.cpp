#include<iostream>
#include<algorithm>
#include<fstream>
#define M 200
#define N 128*128*128
//#define N 1000
using namespace std;
int a[N][3];
int image[M][M]={0};
int result[M][M];
int main()
{
  int i;
  // read
  ifstream fin;
  fin.open("53.out");
  for(i=0;i<N;i++)
  {
    for(int j=0;j<4;j++)
    {
      float temp;
      fin>>temp;
      if(j>=1&&j<3)
        a[i][j-1] = int(temp/500);
    }
    cout<<a[i][0]<<endl;
  }
// process
  for(i=0;i<N;i++)
  {
      int j=0;
      image[a[i][j]][a[i][j+1]] += 1;
      image[a[i][j]+1][a[i][j+1]] += 1;
      image[a[i][j]][a[i][j+1]+1] += 1;
      image[a[i][j]+1][a[i][j+1]+1] += 1;
  }
  cout<<image[0][0]<<endl;

  int Max,Min;
  Max=Min=image[0][0];
  for(i=0;i<M;i++)
  {
    for(int j=0;j<M;j++)
    {
      if(image[i][j]>Max)
        Max = image[i][j];
      else if(image[i][j]<Min)
        Min = image[i][j];
    }
  }
  cout<<Max<<endl;
  for(i=0;i<M;i++)
  {
    for(int j=0;j<M;j++)
    {
      result[i][j] = int(255*float((image[i][j]-Min))/float((Max-Min)));
    }
  }
  cout<<result[0][0]<<endl;
  ofstream in;
  in.open("dealData2.txt",ios::trunc);
  for(i=0;i<M;i++)
  {
    for(int j=0;j<M;j++)
    {
      if(j==M-1)
        in<<result[i][j]<<"\n";
      else
        in<<result[i][j]<<"\t";
    }
  }
  fin.close();
}
