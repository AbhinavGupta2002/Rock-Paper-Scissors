#include <algorithm>
#include <random>
#include <chrono>
#include <limits>
#include "game.h"

using namespace std;

Game::Game(string username): username{username}, computerPoints{0}, playerPoints{0}, round{0}, winningAmount{1} {}

Game::~Game() {
    listTypes.clear();
}

void Game::playGame() {
    cout << "-----------------------------------------" << endl;
    cout << "Welcome to the Rock, Paper, Scissors Game" << endl;
    cout << "   You will play against the computer" << endl;
    cout << "-----------------------------------------" << endl;
    while (true) { // loop ensures that a valid winning number has been accepted
        cout << endl;
        cout << "Enter the winning number of points: [1,2,3,...]" << endl;
        cin >> winningAmount;
        if (cin.fail() || winningAmount <= 0) {
        cout << "Invalid Input" << endl;
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue; 
        }
        break;
    }
    cout << endl;
    while (checkMatchWinner() == false) {
        string playerChoice;
        ++round;
        cout << "-----------------------------------------" << endl;
        cout << "                 ROUND " << round << endl;
        cout << "-----------------------------------------" << endl << endl;
        while (true) { // loop ensures that a valid type has been accepted
            cout << "Enter your choice: [rock/paper/scissors]" << endl;
            cin >> playerChoice;
            if (playerChoice == "rock" || playerChoice == "paper" || playerChoice == "scissors") {
                break;
            }
            cout << "Invalid Choice" << endl;
        }
        string computerChoice;
        computerChoice = getComputerChoice();
        cout << endl;
        cout << "The computer's choice: " << computerChoice << endl << endl;
        if (checkRoundWinner(playerChoice, computerChoice)) { // case where someobody has won the round
            if (getRoundWinner(playerChoice, computerChoice) == 1) { // player won the round
                ++playerPoints;
                cout << username << " has won this round!" << endl;
            } else { // computer won the round
                ++computerPoints;
                cout << "The computer has won this round!" << endl;
            }
        } else { // nobody won the round
            cout << "This round is a tie!" << endl;
        }
        cout << endl;
        cout << "-----------" << endl;
        cout << "SCORE BOARD" << endl;
        cout << "-----------" << endl;
        cout << username << " has " << playerPoints << " point";
        if (playerPoints != 1) {
            cout << "s";
        }
        cout << endl;
        cout << "The computer has " << computerPoints << " point";
        if (computerPoints != 1) {
            cout << "s";
        }
        cout << endl << endl;
    }
    cout << "The winner of the game is ";
    if (getMatchWinner() == 1) { // player won the match
        cout << username;
    } else { // computer won the match
        cout << "the computer";
    }
    cout << "!" << endl;
    cout << endl;
}

string Game::getUsername() {
    return username;
}

string Game::getComputerChoice() {
    vector<string> list = listTypes;
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle (list.begin(), list.end(), default_random_engine(seed)); // shuffles the list of types
    return list[0];
}

// returns 0: round is a tie; returns 1: player wins the round; returns 2: computer wins the round
int Game::getRoundWinner(string player, string computer) {
    if (player == computer) {
        return 0; // round is a tie
    }
    if (player == "rock") {
        if (computer == "scissors") {
            return 1; // player wins the round
        }
        return 2; // computer wins the round
    } else if (player == "paper") {
        if (computer == "rock") {
            return 1; // player wins the round
        }
        return 2; // computer wins the round
    } else {
        if (computer == "paper") {
            return 1; // player wins the round
        }
        return 2; // computer wins the round
    }
}

// returns 0: nobody wins the match yet; returns 1: player wins the match; returns 2: computer wins the match
int Game::getMatchWinner() {
    if (playerPoints == winningAmount) {
        return 1; // player wins the match
    }
    if (computerPoints == winningAmount) {
        return 2; // computer wins the match
    }
    return 0; // nobody has won the match yet
}

bool Game::checkRoundWinner(string player, string computer) {
    if (getRoundWinner(player, computer) != 0) { // case where someobody has won the round
        return true;
    }
    return false; // case where nobody has won the round [tie]
}

bool Game::checkMatchWinner() {
    if (getMatchWinner() != 0) { // case where someobody has won the match
        return true;
    }
    return false; // case where nobody has won the match yet
}

void Game::resetGame() {
    computerPoints = 0;
    playerPoints = 0;
    round = 0;
}