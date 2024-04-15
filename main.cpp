
#include "OpenAddressing.h"
#include "SeparateChaining.h"
#include "Game.h"
#include <ostream>
using namespace std;

string getGameId(Game g) {
    return to_string(g.getId());
}

string getHomeTeamId(Game g) {
    return g.getHome() + to_string(g.getId());
}

void getDataFromFile(std::vector<Game> &games) {
    //Read in file
    std::ifstream inFile;
    inFile.open("mlb-umpire-scorecard.csv");
    std::string header;

    //get rid of header
    if (inFile) {
        getline(inFile, header);
    }

    //Reads file and sets up vector
    while (inFile && inFile.peek() != EOF) {
        std::string date = "n/a", umpire = "n/a", home = "n/a", away = "n/a", nothing;
        int id = -1, homeTeamRuns = -2, awayTeamRuns = -3, pitchesCalled = -4;
        int incorrectCalls = -5, correctCalls = -6;
        char comma = ',';

        // id
        inFile >> id;
        inFile >> comma;

        // date
        getline(inFile, date, comma);

        // umpire
        getline(inFile, umpire, comma);

        // away
        getline(inFile, away, comma);

        // home
        getline(inFile, home, comma);

        // homeTeamRuns
        inFile >> homeTeamRuns;
        inFile >> comma;

        // awayTeamRuns
        inFile >> awayTeamRuns;
        inFile >> comma;

        // pitchesCalled
        if(inFile.peek() == 'N'){
            pitchesCalled = 0;
        }
        else{
            inFile >> pitchesCalled;
            inFile >> comma;
        }

        //incorrect calls
        if(inFile.peek() == 'N'){
            incorrectCalls = 0;
        }
        else{
            inFile >> incorrectCalls;
            inFile >> comma;
        }

        //correct calls
        if(inFile.peek() == 'N'){
            correctCalls = 0;
        }
        else{
            inFile >> correctCalls;
        }

        //reads through end of the line
        getline(inFile, nothing);

        // puts data from line into the vector
        games.push_back(Game(id, date, umpire, away, home, homeTeamRuns, awayTeamRuns,
                             pitchesCalled, incorrectCalls, correctCalls));
    }
    inFile.close();
}

int main() {
    vector<Game> games;
    vector<QuadraticProbing<Game>> qp;
    vector<SeparateChaining<Game>> sc;
    int qPreads1 = 0, qPreads2 = 0, qPreads3 = 0, qPreads4 = 0, qPreads5 = 0,
            qPreads6 = 0, qPreads7 = 0, qPreads8 = 0, qPreads9 = 0, qPreads10 = 0,
            sCreads1 = 0, sCreads2 = 0, sCreads3 = 0, sCreads4 = 0, sCreads5 = 0,
            sCreads6 = 0, sCreads7 = 0, sCreads8 = 0, sCreads9 = 0, sCreads10 = 0;

    vector<int> reads;
    reads.push_back(qPreads1);
    reads.push_back(qPreads2);
    reads.push_back(qPreads3);
    reads.push_back(qPreads4);
    reads.push_back(qPreads5);
    reads.push_back(qPreads6);
    reads.push_back(qPreads7);
    reads.push_back(qPreads8);
    reads.push_back(qPreads9);
    reads.push_back(qPreads10);
    reads.push_back(sCreads1);
    reads.push_back(sCreads2);
    reads.push_back(sCreads3);
    reads.push_back(sCreads4);
    reads.push_back(sCreads5);
    reads.push_back(sCreads6);
    reads.push_back(sCreads7);
    reads.push_back(sCreads8);
    reads.push_back(sCreads9);
    reads.push_back(sCreads10);


    vector<int> sizes{2500, 3500, 4500, 5500, 6500};
    getDataFromFile(games);
    ofstream outFile;
    outFile.open("data/read_data.csv");


    //Populate with Quadratic Probing tables
    for (int i = 0; i < 5; i++) {
        QuadraticProbing<Game> temp(sizes[i], getGameId);
        qp.push_back(temp);
    }

    for (int i = 0; i < 5; i++) {
        QuadraticProbing<Game> temp(sizes[i], getHomeTeamId);
        qp.push_back(temp);
    }

    //Populate with Separate Chaining tables
    for (int i = 0; i < 5; i++) {
        SeparateChaining<Game> temp(sizes[i], getGameId);
        sc.push_back(temp);
    }

    for (int i = 0; i < 5; i++) {
        SeparateChaining<Game> temp(sizes[i], getHomeTeamId);
        sc.push_back(temp);
    }


    //Iterates through data vector
    for(int i = 0; i < games.size(); i++){
        outFile << i;
        outFile << ",";
        //insert the game object into each qp table
        for(int j = 0; j < 10; j++) {
            qp[j].insert(games[i], reads[j]);
        }
        //insert the game object into each sc table
        for(int j = 0; j < 10; j++) {
            sc[j].insert(games[i], reads[j + 10]);
        }
        //prints to csv file
        for(int j = 0; j < reads.size(); j++){
            //will start a new line at the end of each row
            if(j == 19) {
                outFile << reads[j] << endl;
            }
            else{
                outFile << reads[j];
                outFile << ",";
            }
        }
    }

    outFile.close();

    string command = "python3 graph.py";
    system(command.c_str());

    return 0;
}

