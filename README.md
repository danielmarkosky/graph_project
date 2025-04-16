# Graph project

## Idea
The idea for this project is basically: "if we start with some connected graph, and then we edit that graph (removing or/and adding edges) depending on some function, how does the graph behave?". 

## Idea some more
This project aims at showcasing author's coding abilities (yeah). Due to the fact that the sudoku solver is overrated (imo) I - the author - decided to do something different.

## Inspiration
Yuval Noah Harari's book "Nexus" proposes a very interesting idea: Political systems can be looked at as different kinds of information networks. (best popular science book ever btw) For example dictatorship would be a centralized starlike network, while democracy would be a decentralized one. The question is: which is stronger? That's basically the idea for this project (plus some math fun).

## A little bit more accurate
(IN MY OPINION) A good thing to do looking at a political system - graph representation of - is to ask if graph is connected or not. The house divided will not survive (sorry for that) so it is important to keep our society connected. The idea is that every vertex in graph is an entity of voice (What I mean by that is a person, a party, a group of people, a newspaper, a bot on instagram.*) and an edge is some kind of chanel between those entities (For example a person reading a newspaper or a bot learning on text from a reddit thread). Now we have a graph. Let's check which kind of graph will survive the most. Let's do iterations in which edges will appear and disappear depending on some function. The question is - which function would be a pleasant way to decide if an edge should be removed? Welllll let's do it at random with some probability depended on some constant we will call 'strength of connections'. And what about adding edges? Wwweeeelllllllllllll let's do it at random with probability depended on some constant and the shortest path between those two vertices (It kinda make sens. If person A knows person B, and person B knows person C, and person C knows person D, it seems plausible that A and C are going to meet faster than A and D). Let's say that the probability of adding an edge between two verticies is c/(d^2), where c is some constant (how should I know) and d is the shortest path between those two vertices. Why d squared, you may ask. Well, Newton had it squared so why not?

* This is a very interesting topic, read "Nexus", it's amazing.

## Some reflections
I don't believe it's an original idea, and I'm kinda not in the mood to search through scientific papers and reading smart words of smart people. I just thought that it would be a cool way to have something to showcase my coding abilities (or lack of them). Live long and prosper to all the people who are reading this. 

## Technologies
 - C++ 20
 - conan and cmake for building and package management
 - googletest for unit testing
 - boost/graph for graph representation and algorithms
 - copilot for vibes
 - clang-format for code formatting

Common, I write this mostly to show that I can write some :>

## Build (linux supremacy)
In the root directory of the project, run:
```
conan install . --build=missing
conan build .
```
