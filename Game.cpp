
#include "Game.h"
#include <string>
using namespace std;


Game::Game() {
}

Game::Game(int id,
     string date,
     string umpire,
     string away,
     string home,
     int homeTeamRuns,
     int awayTeamRuns,
     int pitchesCalled,
     int incorrectCalls,
     int correctCalls) {
    this->date = date;
    this->umpire = umpire;
    this->home = home;
    this->away = away;
    this->id = id;
    this->homeTeamRuns = homeTeamRuns;
    this->awayTeamRuns = awayTeamRuns;
    this->pitchesCalled = pitchesCalled;
    this->incorrectCalls = incorrectCalls;
    this->correctCalls = correctCalls;
}

int Game::getId() const {
    return id;
}

int Game::getHomeTeamRuns() const {
    return homeTeamRuns;
}

int Game::getAwayTeamRuns() const {
    return awayTeamRuns;
}

int Game::getPitchesCalled() const {
    return pitchesCalled;
}

int Game::getIncorrectCalls() const {
    return incorrectCalls;
}

int Game::getCorrectCalls() const {
    return correctCalls;
}

string Game::getDate() const {
    return date;
}

string Game::getUmpire() const {
    return umpire;
}

string Game::getHome() const {
    return home;
}

string Game::getAway() const {
    return away;
}

void Game::setId(int id) {
    this->id = id;
}

void Game::setHomeTeamRuns(int homeTeamRuns) {
    this->homeTeamRuns = homeTeamRuns;
}

void Game::setAwayTeamRuns(int awayTeamRuns) {
    this->awayTeamRuns = awayTeamRuns;
}

void Game::setPitchesCalled(int pitchesCalled) {
    this->pitchesCalled = pitchesCalled;
}

void Game::setIncorrectCalls(int incorrectCalls) {
    this->incorrectCalls = incorrectCalls;
}

void Game::setCorrectCalls(int correctCalls) {
    this->correctCalls = correctCalls;
}

void Game::setDate(string date) {
    this->date = date;
}

void Game::setUmpire(string umpire) {
    this->umpire = umpire;
}

void Game::setHome(string home) {
    this->home = home;
}

void Game::setAway(string away) {
    this->away = away;
}

// void getDataFromFile(std::vector<Game> &games) {
//     //Read in file
//     std::ifstream inFile;
//     inFile.open("../mlb-umpire-scorecard.csv");
//     std::string header;

//     //get rid of header
//     if (inFile) {
//         getline(inFile, header);
//     }

//     //Reads file and sets up vector
//     while (inFile && inFile.peek() != EOF) {
//         std::string date = "n/a", umpire = "n/a", home = "n/a", away = "n/a", nothing;
//         int id = -1, homeTeamRuns = -2, awayTeamRuns = -3, pitchesCalled = -4;
//         int incorrectCalls = -5, correctCalls = -6;
//         char comma = ',';

//         // id
//         inFile >> id;
//         inFile >> comma;

//         // date
//         getline(inFile, date, comma);

//         // umpire
//         getline(inFile, umpire, comma);

//         // away
//         getline(inFile, away, comma);

//         // home
//         getline(inFile, home, comma);

//         // homeTeamRuns
//         inFile >> homeTeamRuns;
//         inFile >> comma;

//         // awayTeamRuns
//         inFile >> awayTeamRuns;
//         inFile >> comma;

//         // pitchesCalled
//         if(inFile.peek() == 'N'){
//             pitchesCalled = 0;
//         }
//         else{
//             inFile >> pitchesCalled;
//             inFile >> comma;
//         }

//         //incorrect calls
//         if(inFile.peek() == 'N'){
//             incorrectCalls = 0;
//         }
//         else{
//             inFile >> incorrectCalls;
//             inFile >> comma;
//         }

//         //correct calls
//         if(inFile.peek() == 'N'){
//             correctCalls = 0;
//         }
//         else{
//             inFile >> correctCalls;
//         }

//         //reads through end of the line
//         getline(inFile, nothing);

//         // puts data from line into the vector
//         games.push_back(Game(id, date, umpire, away, home, homeTeamRuns, awayTeamRuns,
//                              pitchesCalled, incorrectCalls, correctCalls));
//     }
//     inFile.close();
// }
