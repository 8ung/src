#include "Scoreboard.h"
#include <vector>
#include "Game.h"
#include "Position_class.h"
#include "Worm.h"

using namespace std;

Scoreboard::Scoreboard(vector<Worm> &worm_vector)
{
	players = worm_vector.size();
	position_first_row = new Position_class(800, 300);
	if (Game.team_play)
	{
		min_points = 10;
		spacing = 300;
	}
	else
	{
		min_points = players*10;
		spacing = 100;
	}
}

int Scoreboard::game_finished(vector<Worm> &Worm_vector)
{
	int first_index;
	int first = 0;
	int second = 0;
	int score_compare = 0;
	for(int i = 0; i < players; i++)
	{
		score_compare = Worm_vector[i].score;
		if(score_compare > second)
		{
			second = score_compare;
			if(first < second)
			{
				second = first;
				first = score_compare;
				first_index = i;
			}
		}
	}
	if(first < second + 2)
	{
		return first_index;
	}
	else return 7; //7 = false
}

string Scoreboard::game_finished_team_play(vector<Worm> &Worm_vector)
{
	int teamhot = -1;
	int teamcold = -1;
	int counter = 0;
	while(teamhot == -1 || teamcold == -1)
	{
		if(Worm_vector[i].team == "hot")
		{
			teamhot = Worm_vector[i].score;
		}
		else if(Worm_vector[i].team == "cold")
		{
			teamcold = Worm_vector[i].score;
		}
	}
	if(teamhot >= 10 && teamhot > teamcold + 2)
	{
		return "hot";
	}
	else if(teamcold >= 10 && teamcold > teamhot + 2)
	{
		return "cold";
	}
	else
	{
		return "none";
	}

}

void Scoreboard::update(vector<Worm> &survivor_vector)
{
	for(int i = 0; i < survivor_vector.size(); i++)
		{
			survivor_vector[i].score += 1;
		}
}

void Scoreboard::update_team_play(vector<Worm> &survivor_vector, vector<Worm> &Worm_vector)
{
	string team = "";
	if(!survivor_vector.empty())
	{
		team = survivor_vector[0].team;
		for(int i = 0; i < players; i++)
		{
			if(Worm_vector[i].team == team)
			{
				Worm_vector[i].score += 1;
			}
		}
	}
}
