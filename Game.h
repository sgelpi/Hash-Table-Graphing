
#ifndef GAME_H
#define GAME_H

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using std::string;

class Game {

private:
    std::string date, umpire, home, away;
    int id, homeTeamRuns, awayTeamRuns, pitchesCalled, incorrectCalls, correctCalls;

public:
    // Constructors
    Game();

    Game(int id,
         string date,
         string umpire,
         string away,
         string home,
         int homeTeamRuns,
         int awayTeamRuns,
         int pitchesCalled,
         int incorrectCalls,
         int correctCalls);

    // Getters
    int getId() const;

    int getHomeTeamRuns() const;

    int getAwayTeamRuns() const;

    int getPitchesCalled() const;

    int getIncorrectCalls() const;

    int getCorrectCalls() const;

    string getDate() const;

    string getUmpire() const;

    string getHome() const;

    string getAway() const;

    // Setters
    void setId(int id);

    void setHomeTeamRuns(int homeTeamRuns);

    void setAwayTeamRuns(int awayTeamRuns);

    void setPitchesCalled(int pitchesCalled);

    void setIncorrectCalls(int incorrectCalls);

    void setCorrectCalls(int correctCalls);

    void setDate(string date);

    void setUmpire(string umpire);

    void setHome(string home);

    void setAway(string away);
};


#endif //GAME_H
