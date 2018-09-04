#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>


#define DEBUG 0

#define NUM_TEAMS 32
#define NUM_PLAYERS 10


struct Player
{
    int offensive;
    int defensive;
    int number;
    int team;
    char line[100];
    char* first;
    char* last;
}Player;

struct Team
{
    Player team_players[];
    char* Team_name;
}Team;



void  draftPlayers()
 {
     //struct Team pla_obj;
     char c[1000];
    FILE *fptr;
     Player* players;

    if ((fptr = fopen("players.txt", "r")) != NULL)
    {
             int number_of_lines = 0;

          char s[100]; int k=1;
          while(fscanf(fptr,"%[^\n]", c))
          {
                ++number_of_lines;
                Team.team_players[k].line = c;
                printf("line %d  is %s  \n" ,k, c);

                k++;
          }

            fclose(fptr);

    }
    }

    Team * initializeTeam(char * name, Player * players)
    {




    }

Team * game(Team * teamA,Team * teamB)
    {

        if (teamA != NULL && teamB != NULL)
        {

        int offense=0,defense=0;
		for(i=0;i<10;i++)
            {
			offense = offense + teamA->team_players[i].offensive ;
			defense = defense + teamB->team_players[i].defensive;
			}

        if(offense > defense)
            {
			teamB->team_players.offensive++;
            }
        else
            {
            teamA->team_players.defensive++;
            }

        if(offense > defense)
            {
			return teamA;
            }
        else
            {
        	return teamB;
            }

        }
        else
        {
            return NULL;
        }
    }


    Team * tournament(Team **, int)
    {

    }

void deleteTeam(Team *team){
	free(team);
}




