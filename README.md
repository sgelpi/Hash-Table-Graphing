# Hash Table Graphing

## About
The purpose of this project was to analyze the differences between separate-chaining hash tables and open-addressing hash tables. The speeds of each table are represented by reads, and the total number of reads for each table is incremented every time an item from the dataset is accessed. The dataset chosen for this particular project is the umpiring data for each game played in the 2022 MLB season. Each game is recorded as a seperate item, and within each game there is various data about the umpires effectiveness on that particular day. The data is read from a csv into c++ as a vector, which is then used to add the data into 20 seperate hash tables, with half using separate-chaining and the other half using quadratic probing. For each type of table there were also two hashing keys used based off of different parameters stored in each game object, as well as 5 different table sizes. A python script was used to obtain the reads data from c++ and create graphs for each individual hash table. The results are displayed below.


## Graphs

### Separate-Chaining
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

### Quadratic-Probing
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


## Terminal Commands
Compile command: g++ -std=c++17 main.cpp Game.cpp
Run command: ./a.out
