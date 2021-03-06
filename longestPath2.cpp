# include <iostream>
# include <cstdio>
# include <vector>
# include <algorithm>
# include <cstdlib>
# include <map>
# include <queue>
#define MAX 100009
int max(int a,int b)
{
	if(a>=b)
		return a;
	else
		return b;
}
using namespace std;
int total=0;
bool check[MAX]={false};

int dfs(vector <int> V[],int root)
{
    int m,m1=-1,m2=-1;
    check[root]=1;
    for(int i=0;i<V[root].size();i++)
    {
        if(!check[V[root][i]])
            m=dfs(V,V[root][i]);
        if(m>=m1)
        {
            m2=m1;
            m1=m;
        }
        else if(m>m2)
            m2=m;
    }
    total=max(total,m1+m2+2);
    return (m1+1);
}
int main(void)
{
    int n,a,b;
    scanf("%d",&n);
    vector <int> V[n+5];
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        V[a].push_back(b);
        V[b].push_back(a);
    }
   int lon= dfs(V,1);
    cout<<total<<endl;
    return 0;
}
        
