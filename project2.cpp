/*
 * CSC-301
 * project2.cpp
 * Fall 2022
 *
 * Partner 1: Liam Walsh
 * Partner 2:
 * Date:
 */

#include "project2.hpp"
#include <iostream>

using namespace std;

/*
 * Depth First Search
 */
vector<int> DFS(vector<Vertex> &adjList, Vertex &start, Vertex &exit) {
    //cout << exit.printVertex();
    // initalize all values 
    // set all prev values to none 
    // set all other viisred values to false
    int i =0;
    while(i<adjList.size()){
        adjList[i].visited= false;
        adjList[i].previous = -1;
        i++;
    }
    // create an empty stack of type vector 
    stack<Vertex> visitedValues;

    // mark the start vertex as viisted and push that vertex onto the stack. 
    start.visited= true;
    visitedValues.push(adjList[start.label]);
    // while the stack is not empty then we are going to do stuff
    while(!visitedValues.empty()){
        //going to set current to equal the resuult of stack.pop()
        Vertex curent = visitedValues.top();
        visitedValues.pop();
        // check if current equals exit. If it does equal exit then we stop 
        if (curent.label == exit.label){
            vector<int>returnPathList;
            Vertex pathCurent = curent;
            cout << pathCurent.printVertex();
            while(pathCurent.previous != -1){
                returnPathList.insert(returnPathList.begin(),pathCurent.label);
                pathCurent=  adjList[pathCurent.previous];
                pathCurent.printVertex();
            }
             returnPathList.insert(returnPathList.begin(),start.label);
           // reverse(returnPathList.begin(),returnPathList.end());
           return returnPathList;
        }
            // then we have to reverse through the prev node while 
                // make a vector of int 
                //  nodeREv = current.prev 
                //  while curent.prev is not null then keep going 
                //  push all results onto vector
            // return reversed vector 

        //for each of currents neighbors then itterate in for loop and enque on the stack
        vector<int> curentNeighbors = curent.neighbors;
        for(int i =0; i <curentNeighbors.size(); i++){
            if(!adjList[curentNeighbors[i]].visited){
                adjList[curentNeighbors[i]].visited = true; 
                adjList[curentNeighbors[i]].previous = curent.label; 
                visitedValues.push(adjList[curentNeighbors[i]]);
            }
        }
    }
    return adjList[start.label].neighbors;
}

/*
 * Breadth First Search
 TODO add code for bredth first search.
 */
vector<int> BFS(vector<Vertex> &adjList, Vertex &start, Vertex &exit) {
    //cout << exit.printVertex();
    // initalize all values 
    // set all prev values to none 
    // set all other viisred values to false
    int i =0;
    while(i<adjList.size()){
        adjList[i].visited= false;
        adjList[i].previous = -1;
        i++;
    }
    // create an empty stack of type vector 
    queue<Vertex> visitedValues;
    // mark the start vertex as viisted and push that vertex onto the stack. 
    start.visited= true;
    visitedValues.push(adjList[start.label]);
    // while the stack is not empty then we are going to do stuff
    while(!visitedValues.empty()){
        //going to set current to equal the resuult of stack.pop()
        Vertex curent = visitedValues.front();
        visitedValues.pop();
        // check if current equals exit. If it does equal exit then we stop 
        if (curent.label == exit.label){
            vector<int>returnPathList;
            Vertex pathCurent = curent;
            cout << pathCurent.printVertex();
            while(pathCurent.previous != -1){
                returnPathList.insert(returnPathList.begin(),pathCurent.label);
                pathCurent=  adjList[pathCurent.previous];
                pathCurent.printVertex();
            }
             returnPathList.insert(returnPathList.begin(),start.label);
           // reverse(returnPathList.begin(),returnPathList.end());
           return returnPathList;
        }
            // then we have to reverse through the prev node while 
                // make a vector of int 
                //  nodeREv = current.prev 
                //  while curent.prev is not null then keep going 
                //  push all results onto vector
            // return reversed vector 

        //for each of currents neighbors then itterate in for loop and enque on the stack
        vector<int> curentNeighbors = curent.neighbors;
        for(int i =0; i <curentNeighbors.size(); i++){
            if(!adjList[curentNeighbors[i]].visited){
                adjList[curentNeighbors[i]].visited = true; 
                adjList[curentNeighbors[i]].previous = curent.label; 
                visitedValues.push(adjList[curentNeighbors[i]]);
            }
        }
    }
    return adjList[start.label].neighbors;
}