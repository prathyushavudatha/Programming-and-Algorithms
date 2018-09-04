

struct Player
{
    int offensive;
    int defensive;
    int number;
    int team;
    char* first;
    char* last;
}Player;

struct Team
{
    Player team_players[];
    char* Team_name;
}Team;


Player* draftPlayers(char*,int,int);
Team* initializeTeam(char*, Player*);
Team* game(Team*,Team*);
Team* tournament(Team**,int);
void deleteTeam(Team*);
