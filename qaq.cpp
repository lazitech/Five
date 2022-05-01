#include<bits/stdc++.h>
#include<windows.h>
#include<ctime>
#include <conio.h>
using namespace std;
#define N 15
#define re register
#define inf 1e9
#define int long long
char chess[100][100];
string aq[101010];
string player1,player2;
int ffx,ffy; 
int a[100][100];
int b[100][100];
int sc[100][100][6][3];//  x坐标  y坐标  方向    a or b 
int sd[10]={0,10,1007,100000,10000000};
bool vis[101][101];
struct qizi
{
	int x,y;
}p[5][303];
int ss[4];
int x=1,y=1,cnt=0,amo,plpl;
inline int read() 
{	
	int f=1,x=0;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')	f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
void init()
{
	amo=0;
	ffx=ffy=0;
	memset(vis,false,sizeof vis);
	memset(a,0,sizeof a);
	memset(b,0,sizeof b);
	memset(sc,0,sizeof sc);
	memset(ss,0,sizeof ss);
	memset(p,0,sizeof p);
	for(int i=0;i<=N+1;i++)
	    for(int j=0;j<=N+1;j++)
	        chess[i][j]=' ';
	for(re int i=0;i<=16;++i)
	{
		p[1][++ss[1]]=(qizi){0,i};
		p[2][++ss[2]]=(qizi){0,i};
	}
	for(re int i=0;i<=16;++i)
	{
		p[1][++ss[1]]=(qizi){16,i};
		p[2][++ss[2]]=(qizi){16,i};
	}
	for(re int i=1;i<=15;++i)
	{
		p[1][++ss[1]]=(qizi){i,0};
		p[2][++ss[2]]=(qizi){i,0};
	}
	for(re int i=1;i<=15;++i)
	{
		p[1][++ss[1]]=(qizi){i,16};
		p[2][++ss[2]]=(qizi){i,16};
	}
}
int kkk(char r)
{
	if(r=='o')	return 1;
	if(r=='x')	return 2;
	if(r==' ')	return 3;
}
void CC(int n){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),n);}
int judge()//1 人赢     2 电脑赢 
{
	int p=0,laz=0;
	//行 
	int p1=0,p2=0;
	for(re int k=1;k<=15;++k)
		for(re int i=1;i<=11;++i) 
		{
			laz=1;
			for(re int j=0;j<5;++j)
			{
				if(chess[k][i+j]!='o')	
				{
					laz=0;
					break;
				}
			}
			if(laz==1)
			{
				for(re int j=0;j<5;++j)
					vis[k][i+j]=true;
			}
			p1|=laz;
			laz=1;
			for(re int j=0;j<5;++j)
			{
				if(chess[k][i+j]!='x')	
				{
					laz=0;
					break;
				}
			}
			p2|=laz;
			if(laz==1)
				for(re int j=0;j<5;++j)
					vis[k][i+j]=true;
		}
	//列
		for(re int k=1;k<=15;++k)
			for(re int i=1;i<=11;++i) 
			{
				laz=1;
				for(re int j=0;j<5;++j)
				{
					if(chess[i+j][k]!='o')	
					{
						laz=0;
						break;
					}
				}
				if(laz==1)
					for(re int j=0;j<5;++j)
						vis[i+j][k]=true; 
				p1|=laz;
				laz=1;
				for(re int j=0;j<5;++j)
				{
					if(chess[i+j][k]!='x')	
					{
						laz=0;
						break;
					}
				}
				if(laz==1)
					for(re int j=0;j<5;++j)
						vis[i+j][k]=true;			
				p2|=laz;
			}
	//主对角线
	for(re int i=1;i<=15;++i)
		for(re int j=1;j<=15;++j)
		{
			laz=1;
			for(re int k=0;k<5;++k)
			{
				if(chess[i+k][j+k]!='o')
				{
					laz=0;
					break;
				}
			}
			if(laz==1)
				for(re int k=0;k<5;++k)
					vis[i+k][j+k]=true;
			p1|=laz;
			laz=1;
			for(re int k=0;k<5;++k)
			{
				if(chess[i+k][j+k]!='x')
				{
					laz=0;
					break;
				}
			}
			if(laz==1)
				for(re int k=0;k<5;++k)
					vis[i+k][j+k]=true;
			p2|=laz;
		}
	//副对角线 
	for(re int i=1;i<=15;++i)
		for(re int j=1;j<=15;++j)
		{
			laz=1;
			for(re int k=0;k<5;++k)
			{
				int X=i+k;
				int Y=j-k;
				if(X<1||X>15||Y<1||Y>15)	
				{
					laz=0;
					break;
				}
				if(chess[X][Y]!='o')
				{
					laz=0;
					break;
				}
			}
			if(laz==1)
			{
				for(re int k=0;k<5;++k)
				{
					int X=i+k;
					int Y=j-k;
					vis[X][Y]=true;
				}
			}
			p1|=laz;
			laz=1;
			for(re int k=0;k<5;++k)
			{
				int X=i+k;
				int Y=j-k;
				if(X<1||X>15||Y<1||Y>15)	
				{
					laz=0;
					break;
				}
				if(chess[X][Y]!='x')
				{
					laz=0;
					break;
				}
			}
			if(laz==1)
			{
				for(re int k=0;k<5;++k)
				{
					int X=i+k;
					int Y=j-k;
					vis[X][Y]=true;
				}
			}
			p2|=laz;
		}
	if(p1==1&&p2==1)
	{
		for(re int i=1;i<=10;++i)
			puts("???????????????????????????????????");
		puts("bug出现了，如果你看到这行字，请截图并通知laz，感谢配合"); 
	}
	if(p1==1)	return 1;
	if(p2==1)	return 2;
	return 0;
} 
void wander(int xx,int yy,char r,int len,int mood)
{
	if(r=='o'&&len==2)	return ; 
	int ans=0,laz=0;
	//行 
	for(re int k=1;k<=15;++k)
		for(re int i=1;i<=15;++i) 
		{
			laz=1;
			for(re int j=0;j<len;++j)
			{
				if(chess[k][i+j]!=r)	
				{
					laz=0;
					break;
				}
			}
			if(mood==1)
				sc[xx][yy][1][kkk(r)]-=laz*sd[len-1];
			else
				sc[xx][yy][1][kkk(r)]+=laz*sd[len-1];
		}
	//列
	for(re int k=1;k<=15;++k)
		for(re int i=1;i<=15;++i) 
		{
			laz=1;
			for(re int j=0;j<len;++j)
			{
				if(chess[i+j][k]!=r)	
				{
					laz=0;
					break;
				}
			}
			if(mood==1)
				sc[xx][yy][2][kkk(r)]-=laz*sd[len-1];
			else
				sc[xx][yy][2][kkk(r)]+=laz*sd[len-1];
		}
	//主对角线
	for(re int i=1;i<=15;++i)
		for(re int j=1;j<=15;++j)
		{
			laz=1;
			for(re int k=0;k<len;++k)
			{
				if(chess[i+k][j+k]!=r)
				{
					laz=0;
					break;
				}
			}
			if(mood==1)
				sc[xx][yy][3][kkk(r)]-=laz*sd[len-1];
			else
				sc[xx][yy][3][kkk(r)]+=laz*sd[len-1];
		}
	//副对角线 	
	for(re int i=1;i<=15;++i)
		for(re int j=1;j<=15;++j)
		{
			laz=1;
			for(re int k=0;k<len;++k)
			{
				int X=i+k;
				int Y=j-k;
				if(X<1||X>15||Y<1||Y>15)	
				{
					laz=0;
					break;
				}
				if(chess[X][Y]!=r)
				{
					laz=0;
					break;
				}
			}
			if(mood==1)
				sc[xx][yy][4][kkk(r)]-=laz*sd[len-1];
			else
				sc[xx][yy][4][kkk(r)]+=laz*sd[len-1];
		}
}
void mark()
{
	for(re int len=2;len<=5;++len)
		for(re int i=1;i<=15;++i)
			for(re int j=1;j<=15;++j)
			{
				if(chess[i][j]!=' ')	continue;
				wander(i,j,'o',len,1);
				chess[i][j]='o';
				wander(i,j,'o',len,2);
				chess[i][j]=' ';
				wander(i,j,'x',len,1);
				chess[i][j]='x';
				wander(i,j,'x',len,2);
				chess[i][j]=' ';
			}
}
void perfect()
{
	for(re int h=1;h<=2;++h)	
	{
		for(re int i=1;i<=ss[h];++i)
		{
			for(re int j=i+1;j<=ss[h];++j)
			{
				if(abs(p[h][i].x-p[h][j].x)>6||abs(p[h][i].y-p[h][j].y)>6)
					continue;
				if(p[h][i].x==p[h][j].x)
				{
					int u1=p[h][i].y;
					int u2=p[h][j].y;
					if(u1>u2)	swap(u1,u2);
					for(re int k=u1;k<=u2;++k)
						if(sc[p[h][i].x][k][1][h^3]<10000000)
							sc[p[h][i].x][k][1][h^3]=0;
				}
				if(p[h][i].y==p[h][j].y)
				{
					
					int u1=p[h][i].x;
					int u2=p[h][j].x;
					if(u1>u2)	swap(u1,u2);
					for(re int k=u1;k<=u2;++k)
						if(sc[k][p[h][i].y][2][h^3]<10000000)
							sc[k][p[h][i].y][2][h^3]=0;
				}
				if((p[h][i].x-p[h][j].x)==(p[h][i].y-p[h][j].y))
				{
					int u1=p[h][i].x;
					int u2=p[h][j].x;
					int t1=p[h][i].y;
					int t2=p[h][j].y;
					if(u1>u2)	swap(u1,u2),swap(t1,t2);
					int o=u2-u1;
					for(re int k=0;k<=o;++k)
						if(sc[u1+k][t1+k][3][h^3]<10000000)
							sc[u1+k][t1+k][3][h^3]=0;
				}
				if((p[h][i].x+p[h][i].y)==(p[h][j].x+p[h][j].y))
				{
					int o=abs(p[h][i].x-p[h][j].x);
					int u1=p[h][i].x;
					int u2=p[h][j].x;
					int t1=p[h][i].y;
					int t2=p[h][j].y;
					if(u1>u2)	swap(u1,u2),swap(t1,t2);
					for(re int k=0;k<=o;++k)
						if(sc[u1+k][t1-k][4][h^3]<10000000)
							sc[u1+k][t1-k][4][h^3]=0;
				}	
			}
		}
	}
}
void work()
{
//	cout<<ffx<<" "<<ffy<<endl;
    cout<<"|";
    for(int i=1;i<N+1;i++) 
        cout<<"---|";
    cout<<endl;
    for(int i=1;i<N+1;i++) 
	{
        for(int j=0;j<N+1;j++) 
		{
            if(j==0)  
			    cout<<'|';
            else
                if(!vis[i][j])
				{
					if((i==ffx)&&(j==ffy))
					{
						CC(10);
						cout<<" "<<chess[i][j]<<" |";
						CC(7);
					}
					else
						cout<<" "<<chess[i][j]<<" |";
				}
				else
				{
					CC(13);
					cout<<" "<<chess[i][j]<<" |";
					CC(7);
				} 
        }
        cout<<endl;
        cout<<"|";
        for(int j=1;j<N+1;j++)
        {
        	if(i==x&&j==y)
        		cout<<"***|";
        	else
        		cout<<"---|";
		}
        cout<<endl;
    }
}
void work2()
{
     cout<<setw(3)<<setfill(' ')<<left<<0;
    for(int i=1;i<N+1;i++) 
        cout<<setw(4)<<setfill(' ')<<right<<i;
    cout<<endl;
    cout<<"   |";
    for(int i=1;i<N+1;i++) 
        cout<<"---|";
    cout<<endl;
    for(int i=1;i<N+1;i++) 
	{
        for(int j=0;j<N+1;j++) 
		{
            if(j==0)  
			    cout<<setw(3)<<setfill(' ')<<left<<i<<'|';
            else
            	if(!vis[i][j])
            	{
            		if((i==ffx)&&(j==ffy))
					{
						CC(10);
						cout<<" "<<chess[i][j]<<" |";
						CC(7);
					}
					else
						cout<<" "<<chess[i][j]<<" |";
				}
				else
				{
					CC(13);
					cout<<" "<<chess[i][j]<<" |";
					CC(7);
				}
        }
        cout<<endl;
        cout<<"   |";
        for(int j=1;j<N+1;j++)
			cout<<"---|";
        cout<<endl;
    }
}
void Save()
{
	FILE * out=fopen("detail.qwq","w");
	for(re int i=1;i<=15;++i)
	{
		for(re int j=1;j<=15;++j)
		{
			if(chess[i][j]==' ')
				fprintf(out,"%c",'_');
			else	
				fprintf(out,"%c",chess[i][j]);
			fprintf(out,"%c",' ');
		}
			fprintf(out,"%c",'\n');
	}
	fclose(out);
}
void WIN()
{
	Save(); 
	putchar((char)519);
	CC(6);
	puts("-------  V           V III CCCCCCCCC TTTTTTTTTT OOOOOOOOO RRRRRR  Y       Y  -------");
	puts(" ------   V         V   I  C             TT     O       O R     R  Y     Y   ------");
	puts("  -----    V       V    I  C             TT     O       O R     R   Y   Y    -----");
	puts("   ----     V     V     I  C             TT     O       O RRRRRR     Y Y     ----");
	puts("    ---      V   V      I  C             TT     O       O R   R       Y      ---");
	puts("     --       V V       I  C             TT     O       O R    R      Y      --");
	puts("      -        V       III CCCCCCCCC     TT     OOOOOOOOO R     R     Y      -");
	CC(7);
}
void LOSE()
{
	Save();
	putchar((char)519);
	CC(3);
	puts("      -  DDDDDDDD    EEEEEEEE  FFFFFFFF EEEEEEEE        A       TTTTTTTTTT  -");
	puts("     --  D       D   E         F        E              A A          TT      --");
	puts("    ---  D        D  E         F        E             A   A         TT      ---");
	puts("   ----  D        D  EEEEEEEE  FFFFFF   EEEEEEEE     A     A        TT      ----");
	puts("  -----  D        D  E         F        E           AAAAAAAAA       TT      -----");
	puts(" ------  D       D   E         F        E          A         A      TT      ------");
	puts("-------  DDDDDDDD    EEEEEEEE  F        EEEEEEEE  A           A     TT      -------");
	CC(7);
} 
void replay(int r)
{
	ss[0]=ss[1]=0;
	init();
	x=y=1;
	cnt=0;
	system("cls");
	if(r==1) work();
	else
		work2();
}
void ssave(int r){
    FILE * out=fopen("data.qwq","w");
    fprintf(out,"%d\n",amo+1);
	for(int i=1;i<=amo;++i)
		fprintf(out,"%s\n",aq[i].c_str());
	fprintf(out,"%d_",cnt);
    time_t now = time(0);
    tm *ltm = localtime(&now);
    fprintf(out,"%d.", 1900 + ltm->tm_year );
    fprintf(out,"%d.", 1 + ltm->tm_mon );
    fprintf(out,"%d_", ltm->tm_mday );
    fprintf(out,"%d:", ltm->tm_hour );
    fprintf(out,"%d_", ltm->tm_min );
	if(r==1) fprintf(out,"%s","VICTORY");
	if(r==2) fprintf(out,"%s","DEFEAT");
	if(r==3) fprintf(out,"%s","DRAW");
	fclose(out);
}
void rread(){
    ifstream in("data.qwq");
	in>>amo;
	for(re int i=1;i<=amo;++i)
		in>>aq[i];
	in.close();
}
void JUDGE(int r,int &pl)
{
	int oo=judge();
	pl=oo;
	if(oo==0&&cnt!=225)	return ;
	if(oo==0&&cnt==225)
	{
		rread();
		putchar((char)519);
		system("cls");
		ssave(3);
		if(r==1) work();
		else	work2();
		CC(15);
		puts("打平了，是不是伤害性不大，侮辱性极强呢qwq");
		CC(7);
	}
	if(oo==1)
	{
		rread();
		system("cls");
		ssave(1);
		if(r==1) work();
		else	work2();
		WIN(); 
	}
	if(oo==2)
	{
		rread();
		system("cls");
		ssave(2);
		if(r==1) work();
		else	work2();
		LOSE();
	}
	puts("Replay or not?");
	puts("1.Yes    2.No");
	cout<<">>>"; 
	int qq=read();
	int ccc=0;
	while((qq!=1)&&(qq!=2))
	{
		ccc++;
		if(ccc==7)
		{
			system("start https://www.bilibili.com/video/BV1GJ411x7h7?from=search");
			system("start https://www.luogu.com.cn/paste/uq03iy91");
		}
		puts("qwq");
		cout<<">>>";
		qq=read();
	}
	if(qq==1)
		replay(r);
	else
		puts("Bye~"),exit(0);
}
void print2()
{
	for(re int i=1;i<=15;++i)
		for(re int j=1;j<=15;++j)
			a[i][j]=sc[i][j][1][1]+sc[i][j][2][1]+sc[i][j][3][1]+sc[i][j][4][1]; 
	for(re int i=1;i<=15;++i)
		for(re int j=1;j<=15;++j)
			b[i][j]=sc[i][j][1][2]+sc[i][j][2][2]+sc[i][j][3][2]+sc[i][j][4][2]; 
	for(re int i=1;i<=15;++i)
		for(re int j=1;j<=15;++j)
			b[i][j]++;
//	for(re int i=1;i<=15;++i,puts(""))
//		for(re int j=1;j<=15;++j)
//			cout<<a[i][j]<<' ';
//	puts("");
//	for(re int i=1;i<=15;++i,puts(""))
//		for(re int j=1;j<=15;++j)
//			cout<<b[i][j]<<' ';
//	puts("");
}
int calc(char e,int r)  //     r=3或4 
{
	int ans=0;
	int laz=0;
	for(re int k=1;k<=15;++k)
		for(re int i=2;i<=15-r;++i) 
		{
			if(chess[k][i-1]!=' ') continue;
			laz=1;
			for(re int j=0;j<r;++j)
			{
				if(chess[k][i+j]!=e)	
				{
					laz=0;
					break;
				}
			}
			if((laz==1)&&(chess[k][i+r]==' '))	ans++;
		}
	//列
		for(re int i=2;i<=15-r;++i) 
			for(re int k=1;k<=15;++k)
			{
				laz=1;
				if(chess[i-1][k]!=' ') continue;
				for(re int j=0;j<r;++j)
				{
					if(chess[i+j][k]!=e)	
					{
						laz=0;
						break;
					}
				}
				if((laz==1)&&(chess[i+r][k]==' ')) ans++;
			}
	//主对角线
	for(re int i=2;i<=15-r;++i)
		for(re int j=2;j<=15-r;++j)
		{
			laz=1;
			if(chess[i-1][j-1]!=' ')	continue;
			for(re int k=0;k<r;++k)
			{
				if(chess[i+k][j+k]!=e)
				{
					laz=0;
					break;
				}
			}
			if((laz==1)&&(chess[i+r][j+r]==' '))	ans++;
		}
	//副对角线 
	for(re int i=2;i<=15-r;++i)
		for(re int j=r+1;j<=14;++j)
		{
			laz=1;
			if(chess[i-1][j+1]!=' ')	continue;
			for(re int k=0;k<r;++k)
			{
				int X=i+k;
				int Y=j-k;
				if(X<1||X>15||Y<1||Y>15)	
				{
					laz=0;
					break;
				}
				if(chess[X][Y]!=e)
				{
					laz=0;
					break;
				}
			}
			if(laz==1)
				if(chess[i+r][j-r]==' ')	
					ans++;
		}
	return ans;
}
bool calc2(char e)
{
	for(re int i=2;i<=14;++i)
		for(re int j=2;j<=11;++j)
	 		if((chess[i][j]==e)&&(chess[i][j+1]==e)&&(chess[i][j+2]==' ')&&(chess[i][j+3]==e))	
				return true;
	for(re int j=2;j<=11;++j)
		for(re int i=2;i<=14;++i)
	 		if((chess[j][i]==e)&&(chess[j+1][i]==e)&&(chess[j+2][i]==' ')&&(chess[j+3][i]==e))	
				return true;
	for(re int i=2;i<=11;++i)
		for(re int j=2;j<=11;++j)
			if((chess[i][j]==e)&&(chess[i+1][j+1]==e)&&(chess[i+2][j+2]==' ')&&(chess[i+3][j+3]==e))	
				return true;
	for(re int i=2;i<=11;++i)
		for(re int j=5;j<=14;++j)
			if((chess[i][j]==e)&&(chess[i+1][j-1]==e)&&(chess[i+2][j-2]==' ')&&(chess[i+3][j-3]==e))	
				return true;
	return false;
} 
void force()
{
	int laz=0;
	for(re int i=1;i<=15;++i)
		for(re int j=1;j<=15;++j)
		{
			if(chess[i][j]!=' ')	continue;
			int u1=calc('o',3);
			int t1=calc('o',4);
			bool e1=calc2('o');
			chess[i][j]='o';
			int u2=calc('o',3);
			int t2=calc('o',4);
			bool e2=calc2('o');
			if((u2-u1>=1)&&(e1==false)&&(e2==true))	
				a[i][j]+=150000;
			if(u2-u1>=2)	
				a[i][j]+=150000;
			if(t2-t1>=1)	
				a[i][j]+=500000;	
			chess[i][j]=' ';
			u1=u2=t1=t2=0;
			e1=e2=false;
			u1=calc('x',3);
			t1=calc('x',4);
			e1=calc2('x');
			chess[i][j]='x';
			u2=calc('x',3);
			t2=calc('x',4);
			e2=calc2('x');
			if((u2-u1>=1)&&(e1==false)&&(e2==true))	
				b[i][j]+=150000;
			if(u2-u1>=2)	
				b[i][j]+=150000;
			if(t2-t1>=1)	
				b[i][j]+=500000;	
			chess[i][j]=' ';
		}
//		
//	for(re int k=1;k<=15;++k)
//		for(re int i=2;i<=12;++i) 
//		{
//			if(chess[k][i-1]!=' ') continue;
//			laz=1;
//			for(re int j=0;j<3;++j)
//			{
//				if(chess[k][i+j]!='o')	
//				{
//					laz=0;
//					break;
//				}
//			}
//			if((laz==1)&&(chess[k][i+3]==' '))	
//				a[k][i+3]+=99997,a[k][i-1]+=99997;
//		}
//	//列
//		for(re int k=1;k<=15;++k)
//			for(re int i=2;i<=12;++i) 
//			{
//				laz=1;
//				if(chess[i-1][k]!=' ') continue;
//				for(re int j=0;j<3;++j)
//				{
//					if(chess[i+j][k]!='o')	
//					{
//						laz=0;
//						break;
//					}
//				}
//				if((laz==1)&&(chess[i+3][k]==' ')) 
//					a[i+3][k]+=99997,a[i-1][k]+=99997;
//			}
//	//主对角线
//	for(re int i=2;i<=14;++i)
//		for(re int j=2;j<=14;++j)
//		{
//			laz=1;
//			if(chess[i-1][j-1]!=' ')	continue;
//			for(re int k=0;k<3;++k)
//			{
//				if(chess[i+k][j+k]!='o')
//				{
//					laz=0;
//					break;
//				}
//			}
//			if((laz==1)&&(chess[i+3][j+3]==' '))
//				a[i+3][j+3]+=99997,a[i-1][j-1]+=99997;
//		}
//	//副对角线 
//	for(re int i=2;i<=12;++i)
//		for(re int j=4;j<=14;++j)
//		{
//			laz=1;
//			if(chess[i-1][j+1]!=' ')	continue;
//			for(re int k=0;k<3;++k)
//			{
//				int X=i+k;
//				int Y=j-k;
//				if(X<1||X>15||Y<1||Y>15)	
//				{
//					laz=0;
//					break;
//				}
//				if(chess[X][Y]!='o')
//				{
//					laz=0;
//					break;
//				}
//			}
//			if(laz==1)
//				if(chess[i+3][j-3]==' ')	
//					a[i-1][j+1]+=99997,a[i+3][j-3]+=99997;
//		}
}
int dx[10]={0,-1,-1,-1,0,1,1,1,0};
int dy[10]={0,-1,0,1,1,1,0,-1,-1};
void battle()
{
//	int X,Y;
//	do
//	{
//		X=rand()%15+1;
//		Y=rand()%15+1;
//	}while(chess[X][Y]!=' ');
//	chess[xx][yy]='x';	
	memset(a,0,sizeof a);
	memset(b,0,sizeof b);
	memset(sc,0,sizeof sc);	
	mark();
	perfect();
	print2();
	force();
	for(re int i=1;i<=15;++i)
		for(re int j=1;j<=15;++j)	
		{
			if(chess[i][j]!=' ')	continue;
			for(re int k=1;k<=8;++k)
			{
				int xx=i+dx[k];
				int yy=j+dy[k];
				if(xx<1||xx>15||yy<1||yy>15)	continue;
				if(chess[xx][yy]=='o')	
				{
					a[i][j]++;
					break;
				}
			} 	
		}
	for(re int i=1;i<=15;++i)
		for(re int j=1;j<=15;++j)	
			a[i][j]*=11;
	for(re int i=1;i<=15;++i)
		for(re int j=1;j<=15;++j)	
			a[i][j]+=(b[i][j]*12);
	for(re int i=1;i<=15;++i)
		for(re int j=1;j<=15;++j)	
			if(chess[i][j]!=' ')
				a[i][j]=0;
//	for(re int i=1;i<=15;++i,puts(""))                         ///////////////////////////////////
//		for(re int j=1;j<=15;++j)	                          ///////////////////////////////////
//			cout<<a[i][j]<<' ';                              ///////////////////////////////////
	int X,Y;
	X=Y=1;
	for(re int i=1;i<=15;++i)
		for(re int j=1;j<=15;++j)
		{
			if(chess[i][j]!=' ')	continue;
			if(a[i][j]>a[X][Y])	
			{
				X=i,Y=j;
			}
		}
	p[2][++ss[2]]=(qizi){X,Y};
	chess[X][Y]='x';
	cnt++;
	ffx=X,ffy=Y;
}
void main1()
{
	int n,last;
	init();
	work();	
	do
	{
		n = getch();
		if(n==0x1b)                    //按下Esc来replay 
		{
			puts("Replay?");
			puts("1.Yes    2.No");
			cout<<">>>";
			int qq=read();
			while((qq!=1)&&(qq!=2))
			{
				puts("qwq");
				cout<<">>>";
				qq=read();
			}
			if(qq==1)
				replay(1);
			else
			{
				system("cls");
				work();
			}
			continue;
		}
		if(n==32)
		{
			if(chess[x][y]!=' ')	continue;
			chess[x][y]='o';
			cnt++;
			p[1][++ss[1]]=(qizi){x,y};
			JUDGE(1ll,plpl);
			system("cls");
			if(plpl)	continue;
			battle();
			work();	
			JUDGE(1ll,plpl);
			last=n;
			continue;	
		} 
    	if(last!=224)	
    	{
    		last=n;
    		continue;
		}
		if(n==72&&x!=1)	 x--;//,puts("上移"); 
    	if(n==80&&x!=15) x++;//,puts("下移");
    	if(n==75&&y!=1)  y--;//,puts("左移");
    	if(n==77&&y!=15) y++;//,puts("右移");
		last=n;
		system("cls");
		work();	
	}while(n!=0x03);
}
void main2()
{
	
	init();
	work2();
	puts("请输入坐标：");
	puts("例如，要在第五列第六行落子，就输入'5' '空格' '6' '回车'");
	puts("特别的，输入“0 0”以退出,输入“-1 -1”以重新开始"); 
	int xc,yc;
	do
	{
		cout<<">>>";
		xc=read();
		yc=read();
		if(xc==-1&&yc==-1)	
		{
			puts("Replay?");
			puts("1.Yes    2.No");
			cout<<">>>";
			int qq=read();
			while((qq!=1)&&(qq!=2))
			{
				puts("qwq");
				cout<<">>>";
				qq=read();
			}
			if(qq==1)
				replay(2);
			continue;
		} 
		if(chess[xc][yc]!=' ')
			puts("QAQ");
		else
			if(xc<1||xc>15||yc<1||yc>15)	
				puts("qwq");
			else
			{
				chess[xc][yc]='o';
				cnt++;
				p[1][++ss[1]]=(qizi){xc,yc};
				JUDGE(2,plpl);
				system("cls");
				if(plpl)	continue;
				battle();
				work2();
				JUDGE(2,plpl);
				puts("请输入坐标：");
			}
	}while(xc!=0&&yc!=0);
}
void main3()
{
	int op=0;
	int n,last;
	init();
	work();	
	do
	{
		n = getch();
		if(n==0x1b)                    //按下Esc来replay 
		{
			puts("Replay?");
			puts("1.Yes    2.No");
			cout<<">>>";
			int qq=read();
			while((qq!=1)&&(qq!=2))
			{
				puts("qwq");
				cout<<">>>";
				qq=read();
			}
			if(qq==1)
				replay(1);
			else
			{
				system("cls");
				work();
			}
			continue;
		}
		if(n==32)
		{
			if(chess[x][y]!=' ')	continue;
			if(op==0) chess[x][y]='o',op^=1;
			else	  chess[x][y]='x',op^=1;
			system("cls");
			work();	
			int oo=judge();
			bool qp=false;
			if(oo)
			{
				qp=true;
				if(oo==1)	cout<<player1<<" win !"<<endl;
				else		cout<<player2<<" win !"<<endl;
				puts("Replay or not?");
				puts("1.Yes    2.No");
				cout<<">>>"; 
				int qq=read();
				int cnt=0;
				while((qq!=1)&&(qq!=2))
				{
					puts("qwq");
					cout<<">>>";
					qq=read();
				}
				if(qq==1)
					replay(1);
				else
					puts("Bye~"),exit(0);
			}
			if(qp)	continue;
			last=n;
			continue;	
		} 
    	if(last!=224)	
    	{
    		last=n;
    		continue;
		}
		if(n==72&&x!=1)	 x--;//,puts("上移"); 
    	if(n==80&&x!=15) x++;//,puts("下移");
    	if(n==75&&y!=1)  y--;//,puts("左移");
    	if(n==77&&y!=15) y++;//,puts("右移");
		last=n;
		system("cls");
		work();	
	}while(n!=0x03);
}
void main4()
{
	int op=0;
	init();
	work2();
	puts("请输入坐标：");
	puts("例如，要在第五列第六行落子，就输入'5' '空格' '6' '回车'");
	puts("特别的，输入“0 0”以退出,输入“-1 -1”以重新开始"); 
	int xc,yc;
	do
	{
		cout<<">>>";
		xc=read();
		yc=read();
		if(xc==-1&&yc==-1)	
		{
			puts("Replay?");
			puts("1.Yes    2.No");
			cout<<">>>";
			int qq=read();
			while((qq!=1)&&(qq!=2))
			{
				puts("qwq");
				cout<<">>>";
				qq=read();
			}
			if(qq==1)
				replay(2);
			continue;
		} 
		if(chess[xc][yc]!=' ')
			puts("QAQ");
		else
			if(xc<1||xc>15||yc<1||yc>15)	
				puts("qwq");
			else
			{
				bool qp=false;
				if(op==0) chess[xc][yc]='o',op^=1;
				else      chess[xc][yc]='x',op^=1;
				system("cls");
				work2();
				int oo=judge();
				if(oo)
				{
					qp=true;
					if(oo==1)	cout<<player1<<" win !"<<endl;
					else		cout<<player2<<" win !"<<endl;
					puts("Replay or not?");
					puts("1.Yes    2.No");
					cout<<">>>"; 
					int qq=read();
					int cnt=0;
					while((qq!=1)&&(qq!=2))
					{
						puts("qwq");
						cout<<">>>";
						qq=read();
					}
					if(qq==1)
						replay(2);
					else
						puts("Bye~"),exit(0);
				}
				if(qp)	continue;
				puts("请输入坐标：");
			}
	}while(xc!=0&&yc!=0);
}
void human_vs_win()
{
	puts("请选择操作方式："); 
	puts("输入 1 或 2 以继续"); 
	cout<<">>>";
	int qq=read();
	while((qq!=1)&&(qq!=2))
	{
		puts("qwq");
		cout<<">>>";
		qq=read();
	}
	if(qq==1)
	{
		puts("1.上下左右键操纵，Esc键以重新开始，Ctrl+C以结束"); 	
		main1();
	}
	else
	{
		puts("2.手动输入坐标"); 
		main2();
	}
}
void pvp()
{
	puts("请输入A玩家昵称:");
	cout<<">>>";
	cin>>player1;
	puts("请输入B玩家昵称:");	 
	cout<<">>>";
	cin>>player2;
	puts("");
	puts("说明：");
	puts("对于第一局：A玩家先手；");
	puts("对于之后的对局，上一局负者先手。"); 
	puts("但是,");
	puts("A玩家执o棋,B玩家执x棋,这个对应关系始终不变。"); 
	puts("");
	puts("请选择操作方式："); 
	puts("输入 1 或 2 以继续"); 
	cout<<">>>";
	int qq=read();
	while((qq!=1)&&(qq!=2))
	{
		puts("qwq");
		cout<<">>>";
		qq=read();
	}
	if(qq==1)
	{
		puts("1.上下左右键操纵，Esc键以重新开始，Ctrl+C以结束"); 	
		main3();
	}
	else
	{
		puts("2.手动输入坐标"); 
		main4();
	}
}
void red(){CC(12);}
void black(){CC(10);}
void welcome()
{
     int i;
     for(i=0;i<30;i++)
     {
        system("cls");
        CC(rand()%15+1);
        cout<<"* * * * * * * * * * * * *"<<endl;
        cout<<"                         "<<endl;
        cout<<"*    Five Five Five!    *"<<endl;
        cout<<"       made by ";
        if(i%3==0) CC(rand()%15+1);
        cout<<"l";
        if(i%3==1) CC(rand()%15+1);
        cout<<"a";
        if(i%3==2) CC(rand()%15+1);
        cout<<"z";
        cout<<"       "<<endl;
        cout<<"*   3 seconds to begin  *"<<endl;
        cout<<"                         "<<endl;
        cout<<"* * * * * * * * * * * * *"<<endl;
        for(int j=0;j<1000000;j++);
        system("cls");
        cout<<"   * * * * * * * * * * * "<<endl;
        cout<<"*                       *"<<endl;
        cout<<"     Five Five Five!     "<<endl;
        cout<<"*      made by ";
        if(i%3==0) CC(rand()%15+1);
        cout<<"l";
        if(i%3==1) CC(rand()%15+1);
        cout<<"a";
        if(i%3==2) CC(rand()%15+1);
        cout<<"z";
        cout<<"      *"<<endl;
        cout<<"    3 seconds to begin   "<<endl;
        cout<<"*                       *"<<endl;
        cout<<" * * * * * * * * * * * * "<<endl;
        for(int j=0;j<1000000;j++);
     }
     CC(7);
}
void laz()
{
	system("cls");
	puts("[1]人人对战");
    puts("[2]人机对战");
    puts("[3]我的战绩");
	puts("[4]qwq");
	puts("[5]退出");
	cout<<">>>";    
    int qq=read();
   	while((qq!=1)&&(qq!=2)&&(qq!=3)&&(qq!=4)&&(qq!=5))
	{
		puts("qwq");
		cout<<">>>";
		qq=read();
	}
	
  		if(qq==1)
  		{
  			system("cls");
  			puts("咕咕咕，好麻烦，不写了，摆烂辣qwq");
  			system("pause");
  			system("cls");
			puts("是假的，laz最终还是写了");
			system("pause");
  			pvp();
			laz(); 
		}
		if(qq==2)
		{
			system("cls");
			human_vs_win();
			laz();
		}
  		if(qq==3)
  		{ 
  			system("cls");
  			rread(); 
  			int w,l,d;
  			w=l=d=0;
			for(re int i=1;i<=amo;++i)	
			{
				cout<<aq[i]<<endl;
				if(aq[i][aq[i].size()-1]=='Y')	w++;
				if(aq[i][aq[i].size()-1]=='T')	l++;
				if(aq[i][aq[i].size()-1]=='W')	d++;
			}
			cout<<"共"<<(w+l+d)<<"局"<<endl;
			cout<<"胜"<<w<<"负"<<l<<"平"<<d<<endl;
			printf("胜率：%.2f%\n",(double)(100.0*w/(w+l+d))); 
			l=l+w+d; 
			double rating=(double)(1.0*w/(l*1.0));
			rating=1.0*w*rating;
			printf("Rating：%.2f ",rating); 
			if(rating<=0.999)
				puts("Newbie");
			if((rating>0.999)&&(rating<=1.999))
			{
				CC(2);
				puts("Pupil");
				CC(7);
			}
			if((rating>1.999)&&(rating<=2.999))
			{
				CC(10);
				puts("Specialist");
				CC(7);
			}
			if((rating>2.999)&&(rating<=3.999))
			{
				CC(1);
				puts("Expert");
				CC(7);
			} 
			if((rating>3.999)&&(rating<=4.999))
			{
				CC(13);
				puts("Candidate master");
				CC(7);
			}
			if((rating>4.999)&&(rating<=5.999))
			{
				CC(6);
				puts("Master");
				CC(7);
			}
			if((rating>5.999)&&(rating<=6.999))
			{
				CC(14);
				puts("International master");
				CC(7);	
			}
			if((rating>6.999)&&(rating<=7.999))
			{
				CC(12);
				puts("Grandmaster");
				CC(7);	
			}
			if((rating>7.999)&&(rating<=9.999))
			{
				CC(4);
				puts("International grandmaster");
				CC(7);
			}	
			if(rating>9.999)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
				puts("Legendary grandmaster");
				CC(7);	
			}
			system("pause");
			laz(); 
		}
		if(qq==4)
		{
  			system("cls");
	  	  	cout<<"感谢 ";
			CC(13);
			cout<<"wdz、Fox_index、Hywel、pwx ";
			CC(7);
			puts("等的支持！");
  	  		puts("");
		//	for(re int i=1;i<=10;++i)
		//		puts("wdztxdy!");
			puts("");
			puts("laz设置了一处彩蛋，你发现了吗？qwq");
			puts("");
			system("pause");
			laz(); 
  		}
		if(qq==5)
		{
    		puts("Bye~");
    		exit(0);
    	}
}
void initi()
{
    FILE * out=fopen("data.qwq","w");
    fprintf(out,"%d\n",0);
	fclose(out);
}
signed main()
{
	FILE * in=fopen("data.qwq","r");
    if (in==NULL){
    	puts("正在初始化…"); 
        initi();
        system("start https://www.luogu.com.cn/paste/0lzgm8e7");
        puts("初始化已完成，请重新开始qwq");
        system("pause"); 
        exit(0);
    }
    //================================================ welcome
    CC(7);
    srand(time(0));
    welcome();
    int cur=1;
  	system("cls");
  	CC(7);
  	cout<<"* * * * * * * * * * * * *"<<endl;
    cout<<"                         "<<endl;
    cout<<"*    Five Five Five!    *"<<endl; //23 
    cout<<"       made by ";
    CC(13);
    cout<<"l";CC(7);
    CC(13);
    cout<<"a";CC(7);
    CC(13);
    cout<<"z";CC(7);
    cout<<"       "<<endl;
    cout<<"*   3 seconds to begin  *"<<endl;
    cout<<"                         "<<endl;
    cout<<"* * * * * * * * * * * * *"<<endl;
	system("pause");
    //================================================
	laz();
	puts("Bye~"); 
    return 0ll;
}
//1.0     2022.01.30 22:22   230行代码  
//2.0     2022.01.31 16:51   527行代码
//3.0     2022.02.01 16:14   782行代码 
//4.0     2022.02.02 13:05   1111行代码 
//5.0     2022.02.03 14:23   1422行代码 
//6.0     2022.02.03 21:49   1478行代码 
/*
V           V IIIII  CCCCCCCCCCC TTTTTTTTTTT  OOOOOOOOO  RRRRRR   Y       Y
 V         V    I    C                T       O       O  R     R   Y     Y
  V       V     I    C                T       O       O  R     R    Y   Y
   V     V      I    C                T       O       O  RRRRRR      Y Y
    V   V       I    C                T       O       O  R   R        Y
     V V        I    C                T       O       O  R    R       Y
      V       IIIII  CCCCCCCCCCC      T       OOOOOOOOO  R     R      Y
      
DDDDDDDD    EEEEEEEE  FFFFFFFF EEEEEEEE        A       TTTTTTTTTT
D       D   E         F        E              A A          TT    
D        D  E         F        E             A   A         TT     
D        D  EEEEEEEE  FFFFFF   EEEEEEEE     A     A        TT     
D        D  E         F        E           AAAAAAAAA       TT     
D       D   E         F        E          A         A      TT    
DDDDDDDD    EEEEEEEE  F        EEEEEEEE  A           A     TT     
*/
