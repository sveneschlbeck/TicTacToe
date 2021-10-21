// TicTacToe.cpp

#include <iostream>
#include <string>
#include <array>
#include <list>

using namespace std;


int getWinner(const array<array<int, 3>, 3> &field) {

    // Check for winner horizontally
    for (int i = 0; i <= 2; i++) {
        if ((field[i][0] != 0) && (field[i][0] == field[i][1]) && (field[i][1] == field[i][2])) {
            return field[i][0];
        }
    }

    // Check for winner vertically    
    for (int i = 0; i <= 2; i++) {
        if ((field[0][i] != 0) && (field[0][i] == field[1][i]) && (field[1][i] == field[2][i])) {
            return field[0][i];
        }
    }

    // Check for winner diagonally
    if ((field[0][0] != 0) && (field[0][0] == field[1][1]) && (field[1][1] == field[2][2])) {
                return field[0][0];
    } 
    else if ((field[0][2] != 0) && (field[0][2] == field[1][1]) && (field[1][1] == field[2][0])) {
                return field[0][2];
    }

    return 0;
}


void updateField(const array<array<int, 3>, 3> &field) {

    cout << "    " << endl;
    cout << "   New field situation: " << endl;
    cout << "    " << endl;

    cout << "   " << field[0][0] << " | " << field[0][1] << " | " << field[0][2] << endl;
    cout << "   " << field[1][0] << " | " << field[1][1] << " | " << field[1][2] << endl;
    cout << "   " << field[2][0] << " | " << field[2][1] << " | " << field[2][2] << endl;
    cout << "    " << endl;

    cout << "    " << endl;
}


void printOpeningMessage() {

    cout << "   WELCOME TO... " << endl;
    cout << "    " << endl;
    cout << "    _______   _______   _______" << endl;
    cout << "   |__   __| |__   __| |__   __|" << endl;
    cout << "      | |       | |       | |" << endl;
    cout << "      |_|ic     |_|ac     |_|oe" << endl;
    cout << "    " << endl;
    cout << "    " << endl;
}


void printIndices() {

    cout << "   Those are the indices of the field positions: " << endl;
    cout << "    " << endl;
    cout << "   " << 1 << " | " << 2 << " | " << 3 << endl;
    cout << "   " << 4 << " | " << 5 << " | " << 6 << endl;
    cout << "   " << 7 << " | " << 8 << " | " << 9 << endl;
    cout << "    " << endl;
}


int main()
{

    // Print game opening message
    printOpeningMessage();


    // Print message and field at the beginning
    printIndices();


    // Enter names
    cout << "   Player 1, please enter your name." << endl;
    cout << "    " << endl;

    string player1;
    cin >> player1;
    cout << "\n   Good luck, " + player1 + "!" << endl;
    cout << "   =======================   " << endl;
    cout << "    " << endl;

    cout << "   Player 2, please enter your name." << endl;
    cout << "    " << endl;

    string player2;
    cin >> player2;
    cout << "\n   Good luck, " + player2 + "!" << endl;
    cout << "   =======================   " << endl;
    cout << "    " << endl;


    // Define field
    array<array<int, 3>, 3> field;
    field = { { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} } };


    // Game loop
    bool gameOn = true; // Flag indicating if game is on or off
    list<int> indexList; // Creating empty list; later to be filled with indices already used

    while ((gameOn == true) && (indexList.size() < 9)) {

    again1: // Inloop point 1

        cout << "   " + player1 + ", where would you like to place a chip? Enter the index (1 - 9).\n" << endl;
        int index1; // Initializing index 1
        cin >> index1; // Writing input of player 1 into index 1

        bool found1 = (find(indexList.begin(), indexList.end(), index1) != indexList.end()); // Search indexList for entered index 1
        if (found1 == true) {
            cout << "    " << endl;
            cout << "   Index already used in this game. Choose different index." << endl;
            cout << "    " << endl;
            goto again1;
        }
        else {
            indexList.push_back(index1); // Add index 1 to the indexList

            switch (index1) {
            case 1:
                field[0][0] = 1;
                break;
            case 2:
                field[0][1] = 1;
                break;
            case 3:
                field[0][2] = 1;
                break;
            case 4:
                field[1][0] = 1;
                break;
            case 5:
                field[1][1] = 1;
                break;
            case 6:
                field[1][2] = 1;
                break;
            case 7:
                field[2][0] = 1;
                break;
            case 8:
                field[2][1] = 1;
                break;
            case 9:
                field[2][2] = 1;
                break;
            default:
                cout << "    " << endl;
                cout << "   Invalid input. Try again." << endl;
                goto again1;
            }

            if (gameOn == true) {
                // Update field
                updateField(field);
            }

            if ((indexList.size() == 9) && (gameOn == true)) {
                cout << "   Tie. Congratualtions to both!" << endl;
                cout << "   Game finished." << endl;
                gameOn = false;
                break;
            }


            if ((gameOn == true) && (indexList.size() < 9)) {

            again2: // Inloop point 2

                cout << "   " + player2 + ", where would you like to place a chip? Enter the index (1 - 9).\n" << endl;
                int index2; // Initializing index 2
                cin >> index2; // Writing input of player 2 into index 2

                bool found2 = (find(indexList.begin(), indexList.end(), index2) != indexList.end()); // Search indexList for entered index 2
                if (found2 == true) {
                    cout << "    " << endl;
                    cout << "   Index already used in this game. Choose different index." << endl;
                    cout << "    " << endl;
                    goto again2;
                }
                else {
                    indexList.push_back(index2); // Add index 2 to the indexList

                    switch (index2) {
                    case 1:
                        field[0][0] = 2;
                        break;
                    case 2:
                        field[0][1] = 2;
                        break;
                    case 3:
                        field[0][2] = 2;
                        break;
                    case 4:
                        field[1][0] = 2;
                        break;
                    case 5:
                        field[1][1] = 2;
                        break;
                    case 6:
                        field[1][2] = 2;
                        break;
                    case 7:
                        field[2][0] = 2;
                        break;
                    case 8:
                        field[2][1] = 2;
                        break;
                    case 9:
                        field[2][2] = 2;
                        break;
                    default:
                        cout << "    " << endl;
                        cout << "   Invalid input. Try again." << endl;
                        goto again2;
                    }

                    if (gameOn == true) {
                        // Update field
                        updateField(field);
                    }
                }


                // Get Winner or Result
                int winner;
                winner = getWinner(field);

                if (winner == 1) {
                    cout << "   " + player1 + " won. Congratulations!" << endl;
                    cout << "    " << endl;
                    cout << "   Game finished." << endl;
                    gameOn = false;
                    break;
                }
                else if (winner == 2) {
                    cout << "   " + player2 + " won. Congratulations!" << endl;
                    cout << "    " << endl;
                    cout << "   Game finished." << endl;
                    gameOn = false;
                    break;
                }
                else if ((indexList.size() == 9) && (gameOn == true)) {
                    cout << "   Tie. Congratualtions to both!" << endl;
                    cout << "   Game finished." << endl;
                    gameOn = false;
                    break;
                }
            }
        }
    }
}