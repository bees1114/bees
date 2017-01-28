#include <stdio.h>
#include <stdlib.h>
#include "team.h"

void print(team *pnt);
void printAllPlayers(team *pnt);
void printClubPlayers(team *pnt);
int main(void) {
	FILE *teaminfo = fopen("teaminfo.txt", "r");
	FILE *playersinfo = fopen("pinfo.txt", "r");
	team *hteam= NULL;
	team *tp;
	int select = 0, select1 = 0;
	load(teaminfo, &hteam);
	add_players(playersinfo, &hteam);
	
	printf("Baclayce Premier League!!!\n");
	while(select != 6) {
	printf("1. ���߰�/����\n2. �����߰�/����\n3. ����Ϻ���\n4. ������Ϻ���\n5. ����Ȳ����\n6. ������Ȳ����\n7. ��������\n8. ����");
	scanf("%d", &select);
	switch(select) {
	case 1:
		printf("1. ���߰�\n2. ������");
		scanf("%d", &select);
		switch(select) {
		case 1:
			add_team(&hteam);
			break;
		case 2:
			delete_team(&hteam);
			break;
		default:
			break;
		}
		break;
	case 2:
		break;
	case 3:
		teamRecord(&hteam);
		break;
	case 4:
		playerRecord(&hteam);
		break;
	case 5:
		print(hteam);
		break;
	case 6:
		printf("1. ��ü ��������\n2. Ŭ�� ��������\n");
		scanf("%d", &select);
		select == 1? printAllPlayers(hteam) : 	printClubPlayers(hteam);
		break;
	case 7:
		save(teaminfo, playersinfo, hteam);
		break;
	case 8:
		return 0;
		}
	}
}

void print(team *pnt) {
	team *p;
	p = pnt;
	printf("=========team==========game===win===drw===lse===gls===ags===pnt\n");
	while(p != NULL) {
		printf("%20s %5d %5d %5d %5d %5d %5d %5d\n" ,p->tname, p->games, p->wins, 
			p->draws, p->loses, p->tforg, p->taginstg, p->points);
	p = p->nextt;
	}
}

void printAllPlayers(team *pnt) {
	team *p;
	players *pp;
	p = pnt; 
	printf("====name========GOALS=======ASISTS=======GAGINST=======team====\n");
	while(p!=NULL) {
		pp = p->tplayers;
		while(pp!=NULL) {
			printf("%20s %5d %5d %5d %20s\n", pp->pname, pp->goals, pp->asists, pp->pagainstg, pp->team);
			pp = pp->nextp;
		}
		p = p->nextt;
	}
}


void printClubPlayers(team *pnt) {
	team *p;
	players *pp;
	char *teamname;
	teamname = (char*)malloc(sizeof(char)*30);
	p = pnt;
	printf("� �� ������ ����� ���Ͻʴϱ� : ");
	scanf("%s", teamname);
	while(strcmp(p->tname, teamname))
		p = p->nextt;
	printf("====name========GOALS=======ASISTS=======GAGINST=======team====\n");
		pp = p->tplayers;
		while(pp!=NULL) {
			printf("%20s %5d %5d %5d %20s\n", pp->pname, pp->goals, pp->asists, pp->pagainstg, pp->team);
			pp = pp->nextp;
	}
}