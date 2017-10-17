#include<iostream>
#include<fstream>
using namespace std;
typedef char VertexType;
typedef int EdgeType;
#define MAXVEX 100 //最大顶点数
#define INFINITY 65535//最大值
typedef struct
{

	VertexType *vexs;//顶点信息
	EdgeType arc[MAXVEX][MAXVEX];//邻接矩阵
	int numVertexes, numEdges;//顶点数量、边数量
}MGraph;


/* 邻接矩阵的深度优先遍历和广度优先遍历所用辅助数组
记录图中的节点是否被访问过 */
int visited[MAXVEX] = { 0 };
int j = 1;
int *maxJ;
VertexType getValue(MGraph* G,int v)
{
  if(v!=-1)
    return G->vexs[v];
  else
    return -1;
}
int getFirstNeighbor(MGraph*G,int v)
{
  if(v!=-1)
  {
    for(int col=0;col<G->numVertexes;col++)
    {
      if(G->arc[v][col]>0)
        return col;
    }
  }
}
int getNextNeighbor(MGraph*G,int v,int w)
{
  if(v!=-1&&w!=-1)
  {
    for(int col=w+1;col<G->numVertexes;col++)
    {
      if(G->arc[v][col]>0)
        return col;
    }
  }
  return -1;
}

void visit(VertexType m)
{
  cout<<m;
}
//邻接矩阵的深度优先递归算法，针对每一个定点进行深度优先遍历
void DFS(MGraph* G, int i,int visited[],int j,int h,bool flag)
{
  int k = h;
	visited[i] = 1;
  VertexType m = getValue(G,i);
  int w = getFirstNeighbor(G,i);
  while(w!=-1)
  {
    if(!visited[w])
    {
      j++;
      DFS(G,w,visited,j,h,flag);
      visited[w] = 0;
      j--;
    }
    w = getNextNeighbor(G,i,w);
  }
	if(flag)
	{
    if(j>maxJ[k])
      maxJ[k] = j;
  }
	//s输出重心节点
	else
	{
		if(j==maxJ[k])
		{
			int f=0,r;
			if(j%2==0)//判断中间节点数的个数
			{
				while(f<j/2)
				{
					w = getFirstNeighbor(G,i);
					i = w;
					f++;
					if(f==j/2-1)
					{
						 r = w;
					}
				}
				cout<<"point:"<<w<<" "<<r<<endl;
		  }
			else
			{
        while(f<j/2)
				{
					w = getFirstNeighbor(G,i);
					i = w;
					f++;
				}
				cout<<"point:"<<w<<endl;
			}
		}
	}
}
int main()
{
	MGraph *G = new MGraph;

	fstream f;
	f.open("D:\\test\\tree.txt", ios::in);
	if (f.fail()) {
		cout << "打开文件失败" << endl;
		exit(1);
	}
	char s[100];

	//省略Nodenum
	for (int i = 0; i < 2; i++)
		f >> s;

	//取顶点数
	int node;
	f >> node;
	G->numVertexes=node;
  maxJ = new int[G->numVertexes];
  for(int i=0;i<G->numVertexes;i++)
    maxJ[i] = 1;
  G->vexs = new VertexType[G->numVertexes];
	//邻接矩阵初始化
	for (int i = 0; i < G->numVertexes; i++)
  {
		for (int j = 0; j < G->numVertexes; j++)
   {

			G->arc[i][j] = 0;
		}
	}

	//将数据放入矩阵里
	for (int i = 0; i < G->numVertexes; i++)
  {
		char ch=0;
    char num2;
    f>>num2;
    G->vexs[i] = num2;
		while (ch!=':')
			ch = f.get();
		while (1) {
			int num;
			f >> num;
			G->arc[i][num] = 1;
			G->arc[num][i] = 1;
			char sym;
			sym = f.get();
			if (sym == '\n' || f.eof())break;
		}
	}

	//输出叶子节点数
	int count = 0;
	for(int i=0;i<G->numVertexes;i++)
	{
		int num=0;
		for(int j=0;j<G->numVertexes;j++)
		{
			if(G->arc[i][j]>0)
				num++;
		}
		if(num==1)
			count++;
	}
	cout<<"nodeNum:"<<count<<endl;
	//输出直径长度
  for(int i=0;i<G->numVertexes;i++)
  {
    int visited[G->numVertexes] = {0};
		int j=1;
    DFS(G,i,visited,j,i,true);
  }
	int result = 0;
	for(int i=1;i<G->numVertexes;i++)
	{
		if(maxJ[i]>maxJ[result])
			result = i;
	}
  cout<<"lengh:"<<maxJ[result]-1<<endl;
	//输出重心节点
	int visited[G->numVertexes] = {0};
	int j = 1;
	DFS(G,result,visited,j,result,false);
}
