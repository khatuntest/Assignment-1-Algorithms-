
#include "SkipList.h"

using namespace std;
class Game {
private:
    SkipList scoreList;
    map<int, int> playerScore;
    map<int, int> keyMap;

public:

    void updateScore(int playerID, int newScore) {
        if (playerScore.find(playerID) != playerScore.end()) {
            scoreList.Delete(keyMap[playerID]);
        }
        playerScore[playerID] = newScore;
        int invertedKey = -newScore;
        keyMap[playerID] = invertedKey;
        scoreList.insert(invertedKey);
    }

    void getLeaderboard(int topN) {
        Node* curr = scoreList.header->forward[0];
        int count = 0;

        cout << "Leaderboard (Top " << topN << " Players):" << endl;
        while (curr != nullptr && count < topN) {
            int invertedKey = curr->key;
            for (auto& pair : keyMap) {  // Find the playerID matching this inverted key
                if (pair.second == invertedKey) {
                    int playerID = pair.first;
                    cout << "Player ID: " << playerID << ", Score: " << playerScore[playerID] << endl;
                    break;
                }
            }
            curr = curr->forward[0];
            count++;
        }
        if (count == 0) {
            cout << "No players available in the leaderboard." << endl;
        }
    }

    void joinGame(int playerID, int initialScore = 0) {
        if (playerScore.find(playerID) == playerScore.end()) {
            playerScore[playerID] = initialScore;
            int invertedKey = -initialScore;
            keyMap[playerID] = invertedKey;
            scoreList.insert(invertedKey);
            cout << "Player " << playerID << " joined the game with score " << initialScore << endl;
        } else {
            cout << "Player " << playerID << " already exists." << endl;
        }
    }

    void leaveGame(int playerID) {
        if (playerScore.find(playerID) != playerScore.end()) {
            scoreList.Delete(keyMap[playerID]);  // Remove inverted key from SkipList
            playerScore.erase(playerID);
            keyMap.erase(playerID);
            cout << "Player " << playerID << " has left the game." << endl;
        } else {
            cout << "Player " << playerID << " does not exist." << endl;
        }
    }

    void viewScore(int playerID) {
        if (playerScore.find(playerID) != playerScore.end()) {
            cout << "Player " << playerID << "'s score: " << playerScore[playerID] << endl;
        } else {
            cout << "Player " << playerID << " does not exist." << endl;
        }
    }
};

int main() {
    Game myGame;
    // Players join the game
    myGame.joinGame(1, 100);
    myGame.joinGame(2, 200);
    myGame.joinGame(3, 150);
    // Display the leaderboard
    myGame.getLeaderboard(3);
    // Update player scores
    myGame.updateScore(1, 250);
    myGame.updateScore(2, 300);
    // View individual player scores
    myGame.viewScore(1);
    myGame.viewScore(2);
    // Display updated leaderboard
    myGame.getLeaderboard(3);
    // Add a new player and update the leaderboard
    myGame.joinGame(4, 500);
    myGame.getLeaderboard(3);
    // A player leaves the game
    myGame.leaveGame(3);
    // Try viewing a score of a player who left
    myGame.viewScore(3);
    // Display final leaderboard
    myGame.getLeaderboard(3);

    return 0;
}