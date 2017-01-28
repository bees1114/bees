#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define INF 9999
#define MAX_SIZE 60


typedef struct station
{
    char name[30] ;
    int num;
    int trans;
    int line;
    int weight[60];
    int count;
    
}station;

station metro[60];
int distance[60];
int visit[60];
int point[60];

int name_matching(char * name);
void init_dvp(int start);
int find_shortest_path(int start, int end);
int metro_fee (int distance);
void set_metro();

int main(int argc, const char * argv[]) {
    
    char start[30];
    char end[30];
    int start_num;
    int end_num;
    int distance;
	char temp[30] ="중앙";
     
    printf("출발역을 입력하세요 : ");
    scanf("%s",start);
    printf("도착역을 입력하세요 : ");
    scanf("%s",end);
    printf("중앙:::::%d\n",strcmp(start,temp));
    set_metro();
   
   
    start_num = name_matching(start);
    end_num = name_matching(end);
    printf("start : %d, end : %d", start_num, end_num);
    init_dvp(start_num);
    
    distance = find_shortest_path(start_num, end_num);
    printf("%d",distance);
    int fee = metro_fee(distance);
    printf("%d\n",fee);
    return 0;
}

void set_metro()
{
    int i,j,k,trans,count,num;
    int weight;
    FILE *fp = fopen("/Users/dohuni/Desktop/metro.txt","r");
    
    num=0;
    for(i=1;i<=6;i++)
    {
        for(j=0;j<10;j++)
        {
            trans=0;count=0;
            fscanf(fp,"%s",metro[num].name);
            //metro[num].name=num;
            for(k=0;k<MAX_SIZE;k++)
            {
                fscanf(fp,"%d",&weight);
                if(weight <=20)
                    metro[num].weight[k] = weight;
                else
                    metro[num].weight[k] = INF;
                
                if(metro[num].weight[k]==0)
                    trans++;
                if(metro[num].weight[k]<INF)
                    count++;
            }
            metro[num].num = num;
            metro[num].trans = trans>1 ? 1 : 0;
            metro[num].line = i;
            metro[num].count = count;
            num++;
        }
    }
    for(i=0; i<MAX_SIZE; i++)
    {
        printf("%s %d\n",metro[i].name,metro[i].weight[0]);
    }
}

int name_matching(char * st_name)
{
    int i;
    printf("%s",st_name);
    printf("      %d",strcmp(st_name,"중앙"));
    for(i=0; i<MAX_SIZE; i++)
    {
        if(!strcmp(st_name, metro[i].name))
            break;
    }
    return i;
}

void init_dvp(int start)
{
    int i;
    for(i=0;i<MAX_SIZE;i++)
    {
        distance[i] = metro[start].weight[i];
        visit[i]=0;
        point[i]=-1;
    }
    
}

int find_shortest_path(int start, int end)
{
    int i,j,min,v;
    
    distance[start] =0;
    visit[start] =1;

    for(i=0;i<MAX_SIZE;i++)
    {
        min = INF;
        for(j=0;j<MAX_SIZE;j++)
        {
            if(visit[j]==0 && min>distance[j])
            {
                min= distance[j];
                v = j;
            }
        }
        visit[v]=1;
        for(j=0;j<MAX_SIZE;j++)
        {
            if(distance[j] > distance[v]+metro[v].weight[j])
            {
                distance[j] = distance[v]+metro[v].weight[j];
            }
        }
    }
    
    return distance[end];
}

int metro_fee (int distance)
{
    int fee = 1250;
     distance -= 1000;
    
    while(distance>0)
    {
        fee +=80;
        distance-=1000;
    }
    return fee;
}