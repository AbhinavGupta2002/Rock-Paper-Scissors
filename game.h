#ifndef GAME_H_
#define GAME_H_
#include <iostream>
#include <vector>
#include <map>
 
 class Game {
     private:
     const std::string username; // stores the player's username
     int computerPoints; // stores the number of rounds that the computer has won
     int playerPoints; // stores the number of rounds that the player has won
     int round; // stores the current round number
     int winningAmount; // stores the required number of rounds to win
     std::vector<std::string> listTypes = {"rock", "paper", "scissors"}; // used for randomly choosing a type

     std::string getComputerChoice(); // provides the computer's choice
     int getRoundWinner(std::string player, std::string computer); // gives the round winner [or tie]
     int getMatchWinner(); // gives the match winner [or tie]

     bool checkRoundWinner(std::string player, std::string computer); // checks if someone won the round or is a tie
     bool checkMatchWinner(); // checks if someone won the match

     public:
     Game(std::string username); // constructor
     ~Game(); // destructor
     
     void playGame(); // the game begins
     std::string getUsername(); // the username of the player is provided
     void resetGame(); // the game resets
 };

#endif