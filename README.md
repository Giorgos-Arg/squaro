# squaro

This C program implements the [SquarO](http://wikibin.org/articles/squaro.html) game, a puzzle game invented by Marc 
Lebel. 

## Description

The game consists of a grid of N x N squares. At the corners of each square there are circles which can be colored 
black(X) or white(o). There is a number between 0-4 indicated in each square. The goal is to color in black a subset of 
circles so that the number of black circles at the corners of each square matches the number written in the square.

## Usage

```bash
gcc -o squaro squaro.c
```

Run:

```bash
./squaro <squaro_grid_file>
```
Where <squaro_grid_file> is a text file containing the grid of the game as an NxN array of integers between 0 and 4.

Example:
```bash
2 2 2 2 1 
1 3 3 3 2
3 3 1 1 1 
3 1 1 1 0
2 0 1 1 1
```

## Example

```bash
./squaro data/squaroGrid1.txt

Welcome to the Squaro Game!

Enter your commands in the following format:
 i,j: for changing the color of the circle at (i,j).
 -1,-1 for ending the game.
 Notice: i,j numbering is from the range [0, 5].


o---o---o---o---o---o
| 2 | 2 | 2 | 2 | 1 |
o---o---o---o---o---o
| 1 | 3 | 3 | 3 | 2 |
o---o---o---o---o---o
| 3 | 3 | 1 | 1 | 1 |
o---o---o---o---o---o
| 3 | 1 | 1 | 1 | 0 |
o---o---o---o---o---o
| 2 | 0 | 1 | 1 | 1 |
o---o---o---o---o---o
>0,0

X---o---o---o---o---o
| 2 | 2 | 2 | 2 | 1 |
o---o---o---o---o---o
| 1 | 3 | 3 | 3 | 2 |
o---o---o---o---o---o
| 3 | 3 | 1 | 1 | 1 |
o---o---o---o---o---o
| 3 | 1 | 1 | 1 | 0 |
o---o---o---o---o---o
| 2 | 0 | 1 | 1 | 1 |
o---o---o---o---o---o
>0,1

X---X---o---o---o---o
| 2 | 2 | 2 | 2 | 1 |
o---o---o---o---o---o
| 1 | 3 | 3 | 3 | 2 |
o---o---o---o---o---o
| 3 | 3 | 1 | 1 | 1 |
o---o---o---o---o---o
| 3 | 1 | 1 | 1 | 0 |
o---o---o---o---o---o
| 2 | 0 | 1 | 1 | 1 |
o---o---o---o---o---o
>1,2

X---X---o---o---o---o
| 2 | 2 | 2 | 2 | 1 |
o---o---X---o---o---o
| 1 | 3 | 3 | 3 | 2 |
o---o---o---o---o---o
| 3 | 3 | 1 | 1 | 1 |
o---o---o---o---o---o
| 3 | 1 | 1 | 1 | 0 |
o---o---o---o---o---o
| 2 | 0 | 1 | 1 | 1 |
o---o---o---o---o---o
>1,3

X---X---o---o---o---o
| 2 | 2 | 2 | 2 | 1 |
o---o---X---X---o---o
| 1 | 3 | 3 | 3 | 2 |
o---o---o---o---o---o
| 3 | 3 | 1 | 1 | 1 |
o---o---o---o---o---o
| 3 | 1 | 1 | 1 | 0 |
o---o---o---o---o---o
| 2 | 0 | 1 | 1 | 1 |
o---o---o---o---o---o
>1,4

X---X---o---o---o---o
| 2 | 2 | 2 | 2 | 1 |
o---o---X---X---X---o
| 1 | 3 | 3 | 3 | 2 |
o---o---o---o---o---o
| 3 | 3 | 1 | 1 | 1 |
o---o---o---o---o---o
| 3 | 1 | 1 | 1 | 0 |
o---o---o---o---o---o
| 2 | 0 | 1 | 1 | 1 |
o---o---o---o---o---o
>2,1

X---X---o---o---o---o
| 2 | 2 | 2 | 2 | 1 |
o---o---X---X---X---o
| 1 | 3 | 3 | 3 | 2 |
o---X---o---o---o---o
| 3 | 3 | 1 | 1 | 1 |
o---o---o---o---o---o
| 3 | 1 | 1 | 1 | 0 |
o---o---o---o---o---o
| 2 | 0 | 1 | 1 | 1 |
o---o---o---o---o---o
>2,2

X---X---o---o---o---o
| 2 | 2 | 2 | 2 | 1 |
o---o---X---X---X---o
| 1 | 3 | 3 | 3 | 2 |
o---X---X---o---o---o
| 3 | 3 | 1 | 1 | 1 |
o---o---o---o---o---o
| 3 | 1 | 1 | 1 | 0 |
o---o---o---o---o---o
| 2 | 0 | 1 | 1 | 1 |
o---o---o---o---o---o
>2,4

X---X---o---o---o---o
| 2 | 2 | 2 | 2 | 1 |
o---o---X---X---X---o
| 1 | 3 | 3 | 3 | 2 |
o---X---X---o---X---o
| 3 | 3 | 1 | 1 | 1 |
o---o---o---o---o---o
| 3 | 1 | 1 | 1 | 0 |
o---o---o---o---o---o
| 2 | 0 | 1 | 1 | 1 |
o---o---o---o---o---o
>3,0

X---X---o---o---o---o
| 2 | 2 | 2 | 2 | 1 |
o---o---X---X---X---o
| 1 | 3 | 3 | 3 | 2 |
o---X---X---o---X---o
| 3 | 3 | 1 | 1 | 1 |
X---o---o---o---o---o
| 3 | 1 | 1 | 1 | 0 |
o---o---o---o---o---o
| 2 | 0 | 1 | 1 | 1 |
o---o---o---o---o---o
>3,1

X---X---o---o---o---o
| 2 | 2 | 2 | 2 | 1 |
o---o---X---X---X---o
| 1 | 3 | 3 | 3 | 2 |
o---X---X---o---X---o
| 3 | 3 | 1 | 1 | 1 |
X---X---o---o---o---o
| 3 | 1 | 1 | 1 | 0 |
o---o---o---o---o---o
| 2 | 0 | 1 | 1 | 1 |
o---o---o---o---o---o
>4,0

X---X---o---o---o---o
| 2 | 2 | 2 | 2 | 1 |
o---o---X---X---X---o
| 1 | 3 | 3 | 3 | 2 |
o---X---X---o---X---o
| 3 | 3 | 1 | 1 | 1 |
X---X---o---o---o---o
| 3 | 1 | 1 | 1 | 0 |
X---o---o---o---o---o
| 2 | 0 | 1 | 1 | 1 |
o---o---o---o---o---o
>4,3

X---X---o---o---o---o
| 2 | 2 | 2 | 2 | 1 |
o---o---X---X---X---o
| 1 | 3 | 3 | 3 | 2 |
o---X---X---o---X---o
| 3 | 3 | 1 | 1 | 1 |
X---X---o---o---o---o
| 3 | 1 | 1 | 1 | 0 |
X---o---o---X---o---o
| 2 | 0 | 1 | 1 | 1 |
o---o---o---o---o---o
>5,0

X---X---o---o---o---o
| 2 | 2 | 2 | 2 | 1 |
o---o---X---X---X---o
| 1 | 3 | 3 | 3 | 2 |
o---X---X---o---X---o
| 3 | 3 | 1 | 1 | 1 |
X---X---o---o---o---o
| 3 | 1 | 1 | 1 | 0 |
X---o---o---X---o---o
| 2 | 0 | 1 | 1 | 1 |
X---o---o---o---o---o
>5,5

X---X---o---o---o---o
| 2 | 2 | 2 | 2 | 1 |
o---o---X---X---X---o
| 1 | 3 | 3 | 3 | 2 |
o---X---X---o---X---o
| 3 | 3 | 1 | 1 | 1 |
X---X---o---o---o---o
| 3 | 1 | 1 | 1 | 0 |
X---o---o---X---o---o
| 2 | 0 | 1 | 1 | 1 |
X---o---o---o---o---X

Congratulations!!! Game completed!
```

## Author

Giorgos Argyrides (g.aryrides@outlook.com)
