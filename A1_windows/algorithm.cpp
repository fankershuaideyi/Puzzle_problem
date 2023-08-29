

#include <queue>
#include <unordered_set>
#include "algorithm.h"

using namespace std;


//用来判断hashfunction
struct PuzzleHash{
    size_t operator()(const Puzzle &puzzle) const {
        return puzzle.hashFunction();
    }
};

///////////////////////////////////////////////////////////////////////////////////////////
//
// Search Algorithm:  UC with Strict Expanded List
//
// Move Generator:  
//
////////////////////////////////////////////////////////////////////////////////////////////
string uc_explist(string const initialState, string const goalState, int& pathLength, int &numOfStateExpansions, int& maxQLength,
                               float &actualRunningTime, int &numOfDeletionsFromMiddleOfHeap, int &numOfLocalLoopsAvoided, int &numOfAttemptedNodeReExpansions){
											 
   string path;
   clock_t startTime;
   numOfDeletionsFromMiddleOfHeap=0;
   numOfLocalLoopsAvoided=0;
   numOfAttemptedNodeReExpansions=0;

    cout << "------------------------------" << endl;
    cout << "<<uc_explist>>" << endl;
    cout << "------------------------------" << endl;
	actualRunningTime=0.0;	
	startTime = clock();
	srand(time(NULL)); //RANDOM NUMBER GENERATOR - ONLY FOR THIS DEMO.  YOU REALLY DON'T NEED THIS! DISABLE THIS STATEMENT.
	maxQLength= rand() % 200; //AT THE MOMENT, THIS IS JUST GENERATING SOME DUMMY VALUE.  YOUR ALGORITHM IMPLEMENTATION SHOULD COMPUTE THIS PROPERLY.
	numOfStateExpansions = rand() % 200; //AT THE MOMENT, THIS IS JUST GENERATING SOME DUMMY VALUE.  YOUR ALGORITHM IMPLEMENTATION SHOULD COMPUTE THIS PROPERLY
    Puzzle *p = new Puzzle(initialState,goalState);
    std::queue<Puzzle> q;
    unordered_set<Puzzle,PuzzleHash> visited;
    q.push(*p);
    visited.insert(*p);
    while (!q.empty()){
        Puzzle currentState = q.front();
        q.pop();
        if(currentState.goalMatch()){
            path = currentState.getPath();
            break;
        } else{
           bool L = currentState.canMoveLeft();
           bool U = currentState.canMoveUp();
           bool R = currentState.canMoveRight();
           bool D = currentState.canMoveDown();
           if(L){
               Puzzle nextState = *currentState.moveLeft();
               if(visited.find(nextState)==visited.end()){
                   q.push(nextState);
                   visited.insert(nextState);
               }
           }
           if(U){
               Puzzle nextState = *currentState.moveUp();
               if(visited.find(nextState)==visited.end()){
                   q.push(nextState);
                   visited.insert(nextState);
               }
           }
           if(R){
               Puzzle nextState = *currentState.moveRight();
               if(visited.find(nextState)==visited.end()){
                   q.push(nextState);
                   visited.insert(nextState);
               }
           }
           if(D){
               Puzzle nextState =*currentState.moveDown();
               if(visited.find(nextState)==visited.end()){
                   q.push(nextState);
                   visited.insert(nextState);
               }
           }
        }
    }
//***********************************************************************************************************
	actualRunningTime = ((float)(clock() - startTime)/CLOCKS_PER_SEC);
	//this is just a dummy path for testing the function
	pathLength = path.size();
	return path;
}




///////////////////////////////////////////////////////////////////////////////////////////
//
// Search Algorithm:  A* with the Strict Expanded List
//
// Move Generator:  
//
////////////////////////////////////////////////////////////////////////////////////////////
string aStar_ExpandedList(string const initialState, string const goalState, int& pathLength, int &numOfStateExpansions, int& maxQLength,
                               float &actualRunningTime, int &numOfDeletionsFromMiddleOfHeap, int &numOfLocalLoopsAvoided, int &numOfAttemptedNodeReExpansions, heuristicFunction heuristic){
											 
   string path;
   clock_t startTime;
   
   numOfDeletionsFromMiddleOfHeap=0;
   numOfLocalLoopsAvoided=0;
   numOfAttemptedNodeReExpansions=0;


     cout << "------------------------------" << endl;
     cout << "<<aStar_ExpandedList>>" << endl;
     cout << "------------------------------" << endl;
	actualRunningTime=0.0;	
	startTime = clock();
	srand(time(NULL)); //RANDOM NUMBER GENERATOR - ONLY FOR THIS DEMO.  YOU REALLY DON'T NEED THIS! DISABLE THIS STATEMENT.
	maxQLength= rand() % 200; //AT THE MOMENT, THIS IS JUST GENERATING SOME DUMMY VALUE.  YOUR ALGORITHM IMPLEMENTATION SHOULD COMPUTE THIS PROPERLY.
	numOfStateExpansions = rand() % 200; //AT THE MOMENT, THIS IS JUST GENERATING SOME DUMMY VALUE.  YOUR ALGORITHM IMPLEMENTATION SHOULD COMPUTE THIS PROPERLY
    Puzzle *p = new Puzzle(initialState,goalState);
    unordered_set<Puzzle,PuzzleHash>visited;
    priority_queue<Puzzle> puzzle;
    puzzle.push(*p);
    visited.insert(*p);
    while(!puzzle.empty()){
        Puzzle currentState = puzzle.top();
        puzzle.pop();
        if(currentState.goalMatch()){
            path = currentState.getPath();
            break;
        }else{
            bool L = currentState.canMoveLeft();
            bool U = currentState.canMoveUp();
            bool R = currentState.canMoveRight();
            bool D = currentState.canMoveDown();
            if(L){
                Puzzle nextState = *currentState.moveLeft();
                nextState.updateHCost(heuristic);
                nextState.updateFCost();
                if(visited.find(nextState) == visited.end()){
                    puzzle.push(nextState);
                    visited.insert(nextState);
                }
            }
            if(U){
                Puzzle nextState = *currentState.moveUp();
                nextState.updateHCost(heuristic);
                nextState.updateFCost();
                if(visited.find(nextState) == visited.end()){
                    puzzle.push(nextState);
                    visited.insert(nextState);
                }
            }
            if(R){
                Puzzle nextState = *currentState.moveRight();
                nextState.updateHCost(heuristic);
                nextState.updateFCost();
                if(visited.find(nextState) == visited.end()){
                    puzzle.push(nextState);
                    visited.insert(nextState);
                }
            }
            if(D){
                Puzzle nextState = *currentState.moveDown();
                nextState.updateHCost(heuristic);
                nextState.updateFCost();
                if(visited.find(nextState) == visited.end()){
                    puzzle.push(nextState);
                    visited.insert(nextState);
                }
            }
        }
    }
//***********************************************************************************************************
	actualRunningTime = ((float)(clock() - startTime)/CLOCKS_PER_SEC);//this is just a dummy path for testing the function
	pathLength = path.size();
	return path;		
		
}

