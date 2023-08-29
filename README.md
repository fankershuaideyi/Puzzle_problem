# Puzzle_problem
This is some of C++ algorithms to solve the 3*3 Puzzle game.

## Introduction:

This project will solve the 8-puzzle problem using a selection of search algorithms, and their variants to solve the 8-word puzzle problem to find the shortest path, and a BGI animated simulation is provided. This provides two methods :Uniform Cost-BFS algorithm and A* algorithm and a number of data for testing. It can be compiled by GCC to run as search.exe file, and the run command is shown in the makefile.



## How to run Search.exe:

###### Using the following command:

```cmd
./search.exe  "single_run" "astar_explist_manhattan" "608435127" "123456780"
```

**Type of run** = "batch_run" or "single_run“ or “animate_run"

**batch_run**: this type will run all the data from the template.xlsx.

**Algorithm name**: “uc_explist" or "astar_explist_manhattan"or"astar_explist_misplacedtiles"

**“uc_explist"**: UniformCost with Strict Expanded List algorithm.

**astar_explist_manhattan**: Calculating fcost using Manhattan Distance.

**astar_explist_misplacedtiles**: Calculating fcost using the number of puzzles in misplaced.

**"608435127"**:  initialState

**"123456780"**:  goalState



## Others:

Some data like: maxQlength, numberOfStateExpansion, runtime are used just for performance testing.



Fanker 

Version 1.0.0