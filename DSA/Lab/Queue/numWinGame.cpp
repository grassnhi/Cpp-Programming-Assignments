/*
A group of N students in HCMUT are playing a funny game. They gather around a circle and number themselves from 1 to N clockwise. After a step of the game, a person is removed from the circle. The last person to stay in the circle is the winner.

The game's rule is as follows:

1. The game start at the person numbered 1.
2. From the current person, count k people clockwise (including the person you started at). The counting may wraps around the circle.
3. The last counted one is remove from the circle.
4. If the circle still has more than one people, the game continues from the person immediately clockwise of the person who just lost the game. Then repeat step 2
5. The last person in the game will win.

Toan really wants to win the game to impress their friends. Given the number of players, N, and an integer, k. Help Toan win the game by determine the number in which he has to be standing to certainly win the game.

Hint: You can use a queue to simulate the process of the game.

Constraint:
1 <= k <= N <= 10^4

Example:
Input:
n = 5, k = 2
Output
3

Explanation: The game proceeds as follows
*/

int numberOfTheWinner(int N, int k) {
    queue<int> players;
    for (int i = 1; i <= N; i++) {
        players.push(i);
    }
    while (players.size() > 1) {
        for (int i = 1; i < k; i++) {
            players.push(players.front());
            players.pop();
        }
        players.pop();
    }
    return players.front();
}


/*
Test	Input	Result
    int N;
    int k;
    cin >> N >> k;
    cout << numberOfTheWinner(N, k);
5
2
3
    int N;
    int k;
    cin >> N >> k;
    cout << numberOfTheWinner(N, k);
6
5
1
*/