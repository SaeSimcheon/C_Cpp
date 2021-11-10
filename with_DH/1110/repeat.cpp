#include <stdio.h>
int a[1010][1010],chk[1010],q[1010],n;
void dfs(int p){
	int i;
    printf("%d\n",p);
    return;
	printf("%d ",p);
	chk[p]=1;
	for(i=1;i<=n;++i)if(a[p][i]&&!chk[i])dfs(i);
}
void bfs(int p){
	int i,f=0,r=1;
	chk[q[1]=p]=1;
	while(f<r){
		p=q[++f];
		printf("%d ",p);
		for(i=1;i<=n;++i)if(a[p][i]&&!chk[i])chk[q[++r]=i]=1;
	}
}
int main(){
    freopen("input.txt", "rt", stdin);
	int i,m,p,x,y;
    
    
	scanf("%d%d%d",&n,&m,&p);
    printf("pis %d ",p);
	for(i=1;i<=m;++i)scanf("%d%d",&x,&y),a[x][y]=a[y][x]=1;
	dfs(p);
	puts("");
	for(i=1;i<=n;++i)chk[i]=0;
	bfs(p);
	return 0;
}