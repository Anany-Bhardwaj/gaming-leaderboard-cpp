#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

class Leaderboard {
private:
    // Maps PlayerID to their current Score for O(1) lookup
    unordered_map<int, int> playerScores;
    
    // Automatically sorts pairs of {Score, PlayerID} in O(log n) time
    set<pair<int, int>> sortedRankings; 

public:
    Leaderboard() {}

    // Adds or updates a player's score
    void addScore(int playerId, int score) {
        // If player already exists, remove their old score from the set
        if (playerScores.find(playerId) != playerScores.end()) {
            int oldScore = playerScores[playerId];
            sortedRankings.erase({oldScore, playerId});
            playerScores[playerId] += score; // Add to existing score
        } else {
            playerScores[playerId] = score; // New player
        }
        
        // Insert the updated score into the set
        sortedRankings.insert({playerScores[playerId], playerId});
        cout << "> Player " << playerId << " score updated to " << playerScores[playerId] << ".\n";
    }

    // Retrieves the top K players
    void getTopK(int K) {
        cout << "\n--- TOP " << K << " LEADERBOARD ---\n";
        int count = 0;
        
        // Iterate backwards through the set (since it sorts ascending by default)
        for (auto it = sortedRankings.rbegin(); it != sortedRankings.rend() && count < K; ++it) {
            cout << count + 1 << ". Player " << it->second << " | Score: " << it->first << "\n";
            count++;
        }
        
        if (count == 0) cout << "Leaderboard is currently empty.\n";
        cout << "---------------------------\n";
    }

    // Removes a player from the system entirely
    void resetPlayer(int playerId) {
        if (playerScores.find(playerId) != playerScores.end()) {
            int oldScore = playerScores[playerId];
            sortedRankings.erase({oldScore, playerId});
            playerScores.erase(playerId);
            cout << "> Player " << playerId << " has been removed/reset.\n";
        } else {
            cout << "> Error: Player " << playerId << " not found.\n";
        }
    }
};

int main() {
    Leaderboard gameBoard;
    int choice, playerId, score, k;

    cout << "Welcome to the Real-Time Gaming Leaderboard System!\n";

    while (true) {
        cout << "\n1. Add/Update Player Score\n2. View Top K Players\n3. Reset Player\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Player ID: ";
            cin >> playerId;
            cout << "Enter Score to Add: ";
            cin >> score;
            gameBoard.addScore(playerId, score);
        } else if (choice == 2) {
            cout << "How many top players to display? (Enter K): ";
            cin >> k;
            gameBoard.getTopK(k);
        } else if (choice == 3) {
            cout << "Enter Player ID to reset: ";
            cin >> playerId;
            gameBoard.resetPlayer(playerId);
        } else if (choice == 4) {
            cout << "Exiting system. Goodbye!\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
