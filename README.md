NAVY GAME
--------------------------------------------------------------------------------------
This is a terminal version of the game BattleShip. 
The two players are ONLY allowed to comunicate using the signals SIGUSER1 and SIGUSER2. 
The map size is 8x8. 
On each turn, you must display your positions, and then your enemy’s positions. 
At the end of the game (when all the ships of a player have been hit), you must display whether “I won” (and return 0) or “Enemy won” (and return 1).

Usage:

./navy [first_player_pid] navy_positions

first_player_pid: only for the 2nd player. pid of the first player. navy_positions: file representing the positions of the ships

![image](https://github.com/magdalenamartinez/NAVY_GAME/assets/146070152/970af53a-49c9-41f4-b395-54d5eeeb8ac8)

