# Prince of Persia series puzzle simulators
These are simulations of various puzzles among PoP series, mainly created for the purpose of finding the optimal solutions of them through bruteforce.
The code I have put here are just the simulation part itself, the loop part is not that hard to implement, its just a bunch of nested 'for' loops.

# How to use:
## T2T King's statue puzzle:
- You have to input one of the 4 moves - FW, BW, CW, AW.
- FW stands for "forward", which tries to move the statue forward. Equivalent of doing this in the game: ![image](https://user-images.githubusercontent.com/54983451/109641694-04197000-7b78-11eb-873b-8a39a9f35c32.png)

- BW stands for "backward", which tries to move the statue backward. Equivalent of doing this in the game: ![image](https://user-images.githubusercontent.com/54983451/109642078-8a35b680-7b78-11eb-920c-ee63bbf71e45.png)

- CW stands for "clockwise", which tries to move the statue clockwise. Equivalent of doing this in the game: ![image](https://user-images.githubusercontent.com/54983451/109642540-1ea01900-7b79-11eb-82b1-84a026a0b649.png)

- AW stands for "anti-clockwise", which tries to move the statue anti-clockwise. Equivalent of doing this in the game: ![image](https://user-images.githubusercontent.com/54983451/109642858-7fc7ec80-7b79-11eb-99a0-67fdc9a3a0a8.png)

- You beat the puzzle when you can input a FW when in translation position 5 and the statue is facing front.
- When you beat the puzzle, the list of moves will be displayed.
- Most optimal solution known (99% sure its the most optimal) - FW CW CW FW FW CW BW CW FW CW FW AW FW
## TFS 3rd Water Pillar puzzle:
- You have to input one of the 4 moves - FC, NC, FA, NA.
- FC stands for "Freeze-Clockwise. Its equivalent to moving the lever clockwise in-game while freezing.
- NC stands for "Normal-Clockwise. Its equivalent to moving the lever clockwise in-game while **not** freezing.
- FA stands for "Freeze-AntiClockwise. Its equivalent to moving the lever anti-clockwise in-game while freezing.
- NA stands for "Mormal-AntiClockwise. Its equivalent to moving the lever anti-clockwise in-game while **not** freezing.
- You win all the pieces get to position 4 (You dont get a indication for it)
- You input "ex" to exit the program.
- Most optimal solution - FA NC FA NA (Shoutouts to @Vynneve - https://youtu.be/HDytFR8tcSU)
## TFS-Wii Forge of the Gods puzzle:
- You have to input one of the 4 moves - LA, LC, RA, RC.
- LA stands for "Left-AntiClockwise. Its equivalent to turning the circle to the left anti-clockwise in the game: ![image](https://user-images.githubusercontent.com/54983451/109646459-3a59ee00-7b7e-11eb-872b-b9f4592a025f.png)

- LC stands for "Left-Clockwise. Its equivalent to turning the circle to the left clockwise in the game: ![image](https://user-images.githubusercontent.com/54983451/109646753-82791080-7b7e-11eb-9579-0f1bcfdd71f9.png)

- RA stands for "Right-Anticlockwise. Its equivalent to turning the circle to the right anti-clockwise in the game: ![image](https://user-images.githubusercontent.com/54983451/109647015-dab01280-7b7e-11eb-9986-c3c62ff37d54.png)

- RC stands for "Right-Clockwise. Its equivalent to turning the circle to the right clockwise in the game: ![image](https://user-images.githubusercontent.com/54983451/109647272-18ad3680-7b7f-11eb-80b7-cd12a6ac3a33.png)

- You win when all 4 colours get solved atleast once.
- You can input "re" to reset the puzzle or "ex" to exit the program.
- Most optimal solutions known:
  1. RA (yellow) LA RA (green) RA LA RC RC LC RC LC RC LC (purple) LC RC (orange)
  2. RA (yellow) LA RA (green) RA LC RC RC LA RC LC RC LC (purple) LC RC (orange)
  3. RA (yellow) LA RA (green) RC RC LC RA LC LC RC (orange) LA LA RC LC (purple)
- Shoutouts to toca and Samabam for helping me with this.
