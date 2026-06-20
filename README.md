# Real-Time Gaming Leaderboard System

## Overview
A high-performance, real-time leaderboard management system built in C++. This system tracks, updates, and retrieves player rankings dynamically, designed to simulate the backend architecture of competitive multiplayer games.

## Data Structures Used
To ensure the system scales without severe performance bottlenecks, it avoids standard array sorting ($O(n \log n)$) and instead utilizes:
*   **`std::unordered_map` (Hash Map):** Used to map `PlayerID` to `Score`. This ensures constant time **$O(1)$** lookups when checking if a player exists or retrieving their current score.
*   **`std::set` (Balanced Binary Search Tree):** Used to store pairs of `(Score, PlayerID)`. C++ sets automatically sort elements upon insertion. This ensures that inserting a new score or updating an existing one only takes **$O(\log n)$** time, while keeping the leaderboard continuously sorted.

## Features
1. **Add/Update Score:** Dynamically adds a new player or increments an existing player's score.
2. **Top K Retrieval:** Instantly fetches the current top *K* players without needing to trigger a massive sorting operation.
3. **Player Reset:** Deletes a player's record from both the hash map and the tree in $O(\log n)$ time.

## How to Run
1. Ensure you have a C++ compiler installed (e.g., GCC).
2. Compile the source file:
   ```bash
   g++ main.cpp -o leaderboard
   ```
3. Run the executable:
   ```bash
   ./leaderboard
   ``` 
