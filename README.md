# Graph project

## Idea
The idea for this project is basically: "if we start with some connected graph, and then we edit that graph (removing or/and adding edges) depending on some function, how does the graph behave?". 

## Description
The project uses adjacency matrix representation of a graph 

## Technologies
 - c++ 11<=
 - conan and cmake for building and package management
 - googletest for unit testing
 - boost/graph for graph representation and algorithms
 - copilot for vibes
 - TODO!

Common, I write this mostly to show that I can write some :>

## Build (linux supremacy)
In the root directory of the project, run:
```
conan install . --build=missing
conan build .
```
Then to run the application, do:
```
./Release/DuckDuck
```
To run tests:
```
./Release/DuckDuck_units
```