#include "game.h"

using namespace std;

int main() {
    cout << "--------------------------" << endl;
    cout << "DEVELOPED BY ABHINAV GUPTA" << endl;
    cout << "--------------------------" << endl << endl;
    string username;
    cout << "Enter your username:" << endl;
    cin >> username;
    Game game(username);
    cout << endl << endl;
    while (true) {
        bool playAgain = false;
        game.playGame();
        while (true) {
            cout << "Do you want to play again? [yes/no]" << endl;
            string input;
            cin >> input;
            if (input == "yes") {
                playAgain = true;
                break;
            } else if (input == "no") {
                playAgain = false;
                break;
            } else {
                cout << "Invalid Command" << endl;
            }
        }
        if (playAgain == false) {
            break;
        }
        game.resetGame();
        cout << endl << endl;
    }
    cout << endl;
    cout << "Thank you for playing, " << game.getUsername() << "!" << endl;
}