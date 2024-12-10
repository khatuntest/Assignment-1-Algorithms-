
#include "SkipList.h"

using namespace std;
class Game{
private:
    SkipList scoreList;
    map<int,int>playerScore;
public:
    // Function to add a new player or update the score of an existing player
    void updateScore(int PlayerID,int NewScore){
        if(playerScore.find(PlayerID)!=playerScore.end()){
            scoreList.Delete(PlayerID);
        }
        playerScore[PlayerID]=NewScore;
        scoreList.insert(PlayerID);

    }
    void getLeaderboard(int topN){
        Node* curr=scoreList.header->forward[0];
        int count = 0;

        cout << "Leaderboard (Top " << topN << " Players):" << endl;
        while (curr!= nullptr&&count<topN){
            int playerID=curr->key;
            cout << "Player ID: " << playerID << ", Score: " << playerScore[playerID] << endl;
            curr=curr->forward[0];
            count++;
        }
        if (count == 0) {
            cout << "No players available in the leaderboard." << endl;
        }
    }
    void joinGame(int playerID, int initialScore = 0) {};
    void leaveGame(int playerID) {};
    void viewScore(int playerID) {};

};