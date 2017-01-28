#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct players {
	char pname[30];
	int goals;
	int asists;
	int pagainstg;
	char team[30];
	struct players *nextp;
}players;

typedef struct team {
	char tname[30];
	players *tplayers;
	int games;
	int wins;
	int loses;
	int draws;
	int tforg;
	int taginstg;
	int points;
	struct team *nextt;
}team;

team* make_node(void) {
	team *p = (team*)malloc(sizeof(team));
	
	p->games = 0;
	p->wins= 0;
	p->draws= 0;
	p->loses= 0; p->tforg= 0; p->taginstg= 0; p->points= 0;
	p->nextt = NULL;
	p->tplayers = NULL;
	return p;
}
players* make_node_player(void) {
	players *p = (players*)malloc(sizeof(players));
	
	p->goals = 0;
	p->asists= 0;
	p->pagainstg= 0;
	p->nextp = NULL;
	return p;
}
void load(FILE *teaminfo, team **teamp) {
	team* tp;
	team* head = *teamp;
	while(!feof(teaminfo)) {
		if(*teamp == NULL) {
			*teamp = make_node();
			fscanf(teaminfo, "%s %d %d %d %d %d %d %d" ,&(*teamp)->tname, &(*teamp)->games, &(*teamp)->wins,&(*teamp)->draws,
			&(*teamp)->loses, &(*teamp)->tforg, &(*teamp)->taginstg, &(*teamp)->points);
		}
	else {
		tp = (*teamp);
		while(tp->nextt != NULL) {
			tp = tp->nextt;
		}				
		tp->nextt = make_node();
		tp = tp->nextt;
			fscanf(teaminfo,"%s %d %d %d %d %d %d %d" ,&tp->tname, &tp->games, &tp->wins, 
			&tp->draws, &tp->loses, &tp->tforg, &tp->taginstg, &tp->points);
		}
	}
	fclose(teaminfo);
}

void save(FILE *tinfo, FILE *pinfo, team *p) {
	players *pp;
	team *tp;
	tp = p;
	tinfo = fopen("teaminfo.txt", "w");
	pinfo = fopen("pinfo.txt","w");
	while(tp != NULL) {
		pp = tp->tplayers;
		while(pp != NULL) {
			if((tp->nextt == NULL && pp->nextp == NULL)|| (tp->nextt==NULL && pp==NULL)) {
			fprintf(pinfo, "%s %d %d %d %s", pp->pname, pp->goals, 
				pp->asists, pp->pagainstg, pp->team);
			} else {
				fprintf(pinfo, "%s %d %d %d %s\n", pp->pname, pp->goals, 
				pp->asists, pp->pagainstg, pp->team);
			}
		pp = pp->nextp;
		}
		
		tp = tp->nextt;
	}
	fclose(pinfo);
	tp = p;
	while(tp != NULL) {
		if(tp->nextt ==NULL) {
		fprintf(tinfo, "%s %d %d %d %d %d %d %d", tp->tname, tp->games, tp->wins, tp->draws, tp->loses,
			tp->tforg, tp->taginstg, tp->points);
		}
		else {
			fprintf(tinfo, "%s %d %d %d %d %d %d %d\n", tp->tname, tp->games, tp->wins, tp->draws, tp->loses,
			tp->tforg, tp->taginstg, tp->points);
		}

		tp = tp->nextt;
	}
	fclose(tinfo);
}

void add_players(FILE *playerinfo, team **p) {
	players *temp;
	players *pntp;
	team *pnt = *p;
	temp = (players*)malloc(sizeof(players));
	temp->nextp = NULL;
	while(!feof(playerinfo)) {
		pnt = *p;
	temp = (players*)malloc(sizeof(players));
	temp->nextp = NULL;
		fscanf(playerinfo,"%s %d %d %d %s", &temp->pname, &temp->goals, &temp->asists, &temp->pagainstg, &temp->team);
	
	while(strcmp(pnt->tname, temp->team))
		pnt = pnt->nextt;
	pntp = pnt->tplayers;
	if(pnt->tplayers == NULL) {
			pnt->tplayers = make_node_player();
			pnt->tplayers = temp;
	}
	else {
		while(pntp->nextp != NULL)
			pntp = pntp->nextp;
		pntp->nextp = make_node_player();
		pntp->nextp = temp;
		}
	}
	fclose(playerinfo);
}

void teamRecord(team **p) {
	char teamname[30];
	team *pnt;
	printf("기록을 변경하고 싶은 팀 이름 : ");
	scanf("%s", teamname);
	pnt = *p;
	while(strcmp(pnt->tname, teamname) !=0)
		pnt = pnt->nextt;
	printf("%s 팀의 현재기록 : \n",pnt->tname);
	printf("=========team==========game===win===drw===lse===gls===ags===pnt\n");
	printf("%20s %5d %5d %5d %5d %5d %5d %5d\n" ,pnt->tname, pnt->games, pnt->wins, 
			pnt->draws, pnt->loses, pnt->tforg, pnt->taginstg, pnt->points);
	printf("경기수/승리/무승부/패배/득점/실점 입력");	
	scanf("%d %d %d %d %d %d" ,&pnt->games, &pnt->wins,&pnt->draws,
			&pnt->loses, &pnt->tforg,&pnt->taginstg);
	pnt->points = pnt->wins*3 + pnt->draws*1;
	printf("변경완료!\n");
	
}

void playerRecord(team **p) {
	char playername[30];
	team *pnt;
	int index = 0;
	players *pp;
	printf("기록을 변경하고 싶은 선수 이름 : ");
	scanf("%s", playername);
	pnt = *p;
	while(1) {
		pp = pnt->tplayers;
		while(strcmp(pp->pname, playername)!=0 ) {
		pp = pp->nextp;
		if(pp == NULL)
			break;
		}
		if(pp != NULL && strcmp(pp->pname, playername) == 0){
			break;}
		pnt = pnt->nextt;
	}
	printf("%s 선수의 현재기록\n",pp->pname);
	printf("====name========GOALS=======ASISTS=======GAGINST=======team====\n");
	printf("%s %d %d %d %s\n", pp->pname, pp->goals, pp->asists, pp->pagainstg, pp->team);
	printf("골/도움/실점/팀 입력\n");
	scanf("%d %d %d %s",&pp->goals, &pp->asists, &pp->pagainstg, &pp->team);
	printf("변경완료!\n");
}

void add_team(team **p) {
	char teamname[30];
	team *tp = *p;
	team *temp;
	while(tp->nextt !=NULL) 
		tp = tp->nextt;
	printf("추가할 팀의 이름을 쓰세요 : ");
	scanf("%s", teamname);
	temp = make_node();
	strcpy(temp->tname ,teamname);
	tp->nextt = temp;
	
}

void delete_team(team **p) {
	char teamname[30];
	team *tp = *p;
	team *tempp = *p;
	printf("삭제할 팀의 이름을 쓰세요 : ");
	scanf("%s", teamname);
	while(strcmp(teamname, tp->tname)!=0) 
		tp = tp->nextt;
	if(tp == p) {
		*p = (*p)->nextt;
		free(tp);
	} else if(tp->nextt == NULL) {
		
		while(tempp->nextt != tp)
			tempp = tempp->nextt;
		free(tp);
		tempp->nextt = NULL;
	} else {
		while(tempp->nextt != tp)
			tempp = tempp->nextt;
		tempp->nextt = tp->nextt;
		free(tp);
	}
}