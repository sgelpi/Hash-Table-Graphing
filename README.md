James Davenport
Sam Gelpi

Compile command: g++ -std=c++17 main.cpp Game.cpp

Run command: ./a.out

About: This data set was found on kaggle, and it is a list of every umpire scorecard from the MLB 2022 season. The data contains the attributes id, date, umpire, away, home, away_runs_score, home_runs_scored, total_pitches, correct_calls, and incorrect_calls. The umpire attribute is the name of the umpire, away and home represent the away and home teams, and correct and incorrect calls represent the number of correct and incorrect calls the umpire made during the game. I chose this dataset because the MLB is interested in removing umpires and using an automated strike zone, so I think it would be interesting to look at how bad the current umpires actually are. The rows are ordered as they came in the csv file (in the order listed above). I know the functions are working correctly because they were tested in the main.cpp file. I chose the calculation I chose because I was curious to see the total number of pitches that get thrown by all the teams in an entire season of baseball.

![Seperate Chaining using Key1, Size: 2500](images/graph1.png)

![Seperate Chaining using Key1, Size: 3500](images/graph2.png)

![Seperate Chaining using Key1, Size: 4500](images/graph3.png)

![Seperate Chaining using Key1, Size: 5500](images/graph4.png)

![Seperate Chaining using Key1, Size: 6500](images/graph5.png)

![Seperate Chaining using Key1, Size: 2500](images/graph6.png)

![Seperate Chaining using Key1, Size: 3500](images/graph7.png)

![Seperate Chaining using Key1, Size: 4500](images/graph8.png)

![Seperate Chaining using Key1, Size: 5500](images/graph9.png)

![Seperate Chaining using Key1, Size: 6500](images/graph10.png)

![Quadratic Probing using Key2, Size: 2500](images/graph11.png)

![Quadratic Probing using Key2, Size: 3500](images/graph12.png)

![Quadratic Probing using Key2, Size: 4500](images/graph13.png)

![Quadratic Probing using Key2, Size: 5500](images/graph14.png)

![Quadratic Probing using Key2, Size: 6500](images/graph15.png)

![Quadratic Probing using Key2, Size: 2500](images/graph16.png)

![Quadratic Probing using Key2, Size: 3500](images/graph17.png)

![Quadratic Probing using Key2, Size: 4500](images/graph18.png)

![Quadratic Probing using Key2, Size: 5500](images/graph19.png)

![Quadratic Probing using Key2, Size: 6500](images/graph20.png)

For the quadratic probing graphs the number of reads steadily increased as the algorithm determined new indexes for the inserted items. The sharp increase which occurred in the first three sizes was caused by a rehash, which means all the current items in the table were reread and reentered into the table. There was no rehash for the largest two sizes because the algorithm was able to find an index for every item that was inserted. For the Seperate Chaining graphs the reads for key 1 were much less smooth because the first key was smaller. This is because the key was smaller so more items were being chained together than being placed in new indexes. Because of this the number of reads was lower making the first key an overall more efficient key to use for this dataset. The collision detection method that was most efficient for this dataset was seperate chaining, as the cumulative number of reads was significantly lower for both keys. It is worth noting that one of the other probing algorithms could have been more efficient, but between these two algorithms the seperate chaining is more efficient.
