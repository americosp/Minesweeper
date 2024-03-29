#include "pch.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
using namespace std;
using namespace sf;
int main() {

	int board[25][16];
	int underBoard[25][16];
	int open[25][16];
	int hasflag[25][16];
	int debugger[25][16];
	int debugboard[25][16];
	int startingBoard[25][16];
	int boardMines[25][16];
	int mines = 0;
	int width = 32;
	int bombs = 50;
	int flags = 50;
	int tilecount;
	bool debuggerActive = false;
	bool gamewin = false;
	bool gamelose = false;

	for (int i = 0; i < 25; i++)			// Sets the boards
		for (int j = 0; j < 15; j++) {
			debugger[i][j] = 1;
		}
	for (int i = 0; i < 25; i++)
		for (int j = 0; j < 15; j++) {
			hasflag[i][j] = 1;
		}
	for (int i = 0; i < 25; i++)
		for (int j = 0; j < 15; j++) {
			open[i][j] = 1;
		}

	RenderWindow window(sf::VideoMode(800, 600), "Minesweeper");

	Texture one;
	one.loadFromFile("images/number_1.png");
	Sprite uno(one);

	Texture two;
	two.loadFromFile("images/number_2.png");
	Sprite dos(two);

	Texture three;
	three.loadFromFile("images/number_3.png");
	Sprite tres(three);

	Texture four;
	four.loadFromFile("images/number_4.png");
	Sprite quatro(four);

	Texture five;
	five.loadFromFile("images/number_5.png");
	Sprite cinco(five);

	Texture six;
	six.loadFromFile("images/number_6.png");
	Sprite sies(six);

	Texture seven;
	seven.loadFromFile("images/number_7.png");
	Sprite siete(seven);

	Texture eight;
	eight.loadFromFile("images/number_8.png");
	Sprite ocho(eight);

	Texture hidden;
	hidden.loadFromFile("images/tile_hidden.png");
	Sprite hide(hidden);

	Texture revealed;
	revealed.loadFromFile("images/tile_revealed.png");
	Sprite reveale(revealed);
	Sprite reveale1(revealed);
	Sprite reveale2(revealed);
	Sprite reveale3(revealed);
	Sprite reveale4(revealed);
	Sprite reveale5(revealed);
	Sprite reveale6(revealed);
	Sprite reveale7(revealed);
	Sprite reveale8(revealed);

	Texture mine;
	mine.loadFromFile("images/mine.png");
	Sprite minez(mine);

	Texture flag;
	flag.loadFromFile("images/flag.png");
	Sprite flagz(flag);

	Texture happy;
	happy.loadFromFile("images/face_happy.png");
	Sprite happyface(happy);

	Texture testone;
	testone.loadFromFile("images/test_1.png");
	Sprite testuno(testone);

	Texture testtwo;
	testtwo.loadFromFile("images/test_2.png");
	Sprite testdos(testtwo);

	Texture debug;
	debug.loadFromFile("images/debug.png");
	Sprite debugz(debug);

	Texture digits;
	digits.loadFromFile("images/digits.png");
	Sprite digitz(digits);

	Sprite digitz2(digits);

	Texture sad;
	sad.loadFromFile("images/face_lose.png");
	Sprite sadface(sad);

	Texture cool;
	cool.loadFromFile("images/face_win.png");

	Sprite removedFlag(hidden);

	for (int i = 0; i <= 24; i++)				// Creates the rest of the boards
		for (int j = 0; j <= 15; j++) {
			underBoard[i][j] = 10;
			if (rand() % 6 == 0 && bombs > 0) {
				board[i][j] = 9;
				bombs = bombs - 1;
			}
			else {
				board[i][j] = 0;
			}
			if (board[i][j] == 9) {
				mines = mines + 1;
			}
		}
	for (int i = 0; i < 1; i++)
		for (int j = 0; j < 1; j++) {
			int n = 0;
			if (board[i][j] == 9) continue;
			if (board[i + 1][j] == 9) n++;
			if (board[i][j + 1] == 9) n++;
			if (board[i + 1][j + 1] == 9) n++;
			board[i][j] = n;
		}
	for (int i = 24; i < 25; i++)
		for (int j = 0; j < 1; j++) {
			int n = 0;
			if (board[i][j] == 9) continue;
			if (board[i][j + 1] == 9) n++;
			if (board[i - 1][j + 1] == 9) n++;
			if (board[i - 1][j] == 9) n++;
			board[i][j] = n;
		}
	for (int i = 0; i < 1; i++)
		for (int j = 15; j < 16; j++) {
			int n = 0;
			if (board[i][j] == 9) continue;
			if (board[i][j - 1] == 9) n++;
			if (board[i + 1][j - 1] == 9) n++;
			if (board[i + 1][j] == 9) n++;
			board[i][j] = n;
		}
	for (int i = 24; i < 25; i++)
		for (int j = 15; j < 16; j++) {
			int n = 0;
			if (board[i][j] == 9) continue;
			if (board[i - 1][j] == 9) n++;
			if (board[i][j - 1] == 9) n++;
			if (board[i - 1][j - 1] == 9) n++;
			board[i][j] = n;
		}
	for (int j = 0; j < 1; j++)
		for (int i = 1; i < 23; i++) {
			int n = 0;
			if (board[i][j] == 9) continue;
			if (board[i + 1][j] == 9) n++;
			if (board[i][j + 1] == 9) n++;
			if (board[i - 1][j] == 9) n++;
			if (board[i - 1][j + 1] == 9) n++;
			if (board[i + 1][j + 1] == 9) n++;
			board[i][j] = n;
		}
	for (int j = 15; j < 16; j++)
		for (int i = 1; i < 25; i++) {
			int n = 0;
			if (board[i][j] == 9) continue;
			if (board[i][j - 1] == 9) n++;
			if (board[i + 1][j] == 9) n++;
			if (board[i - 1][j] == 9) n++;
			if (board[i - 1][j - 1] == 9) n++;
			if (board[i + 1][j - 1] == 9) n++;
			board[i][j] = n;
		}
	for (int i = 0; i < 1; i++)
		for (int j = 1; j < 15; j++) {
			int n = 0;
			if (board[i][j] == 9) continue;
			if (board[i + 1][j] == 9) n++;
			if (board[i][j - 1] == 9) n++;
			if (board[i][j + 1] == 9) n++;
			if (board[i + 1][j + 1] == 9) n++;
			if (board[i + 1][j - 1] == 9) n++;
			board[i][j] = n;
		}
	for (int i = 24; i < 25; i++)
		for (int j = 1; j < 15; j++) {
			int n = 0;
			if (board[i][j] == 9) continue;
			if (board[i][j + 1] == 9) n++;
			if (board[i][j - 1] == 9) n++;
			if (board[i - 1][j] == 9) n++;
			if (board[i - 1][j + 1] == 9) n++;
			if (board[i - 1][j - 1] == 9) n++;
			board[i][j] = n;
		}
	for (int i = 1; i <= 23; i++)
		for (int j = 1; j <= 14; j++) {
			int n = 0;
			if (board[i][j] == 9) continue;
			if (board[i + 1][j] == 9) n++;
			if (board[i][j + 1] == 9) n++;
			if (board[i - 1][j] == 9) n++;
			if (board[i][j - 1] == 9) n++;
			if (board[i + 1][j + 1] == 9) n++;
			if (board[i - 1][j - 1] == 9) n++;
			if (board[i - 1][j + 1] == 9) n++;
			if (board[i + 1][j - 1] == 9) n++;
			board[i][j] = n;
		}
	for (int i = 0; i < 25; i++)
		for (int j = 0; j < 16; j++) {
			if (board[i][j] == 9)
				boardMines[i][j] = 69;
		}

	// Now to the real business!!

	while (window.isOpen()) {
		Vector2i pixelPos = Mouse::getPosition(window);
		int x = pixelPos.x / width;
		int y = pixelPos.y / width;

		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();

			if (event.type == Event::MouseButtonPressed)
				if (event.key.code == Mouse::Right) {
					if (hasflag[x][y] == 2 && gamelose == false && gamewin == false) {
						underBoard[x][y] = 15;
						flags = flags + 1;
						hasflag[x][y] = 1;
						break;
					}

					if (open[x][y] != 2 && gamelose == false && gamewin == false) {
						underBoard[x][y] = 11;
						flags = flags - 1;
					}
				}
				else if (event.key.code == Mouse::Left) {

					if (debugz.getGlobalBounds().contains(x * width, y * width) && debuggerActive == false && gamelose == false && gamewin == false) {
						for (int i = 0; i < 25; i++)
							for (int j = 0; j < 16; j++) {
								if (board[i][j] == 9) {
									underBoard[i][j] = boardMines[i][j];
								}
							}
						gamelose == false;
						debuggerActive = true;

					}
					else if (debugz.getGlobalBounds().contains(x * width, y * width) && debuggerActive == true && gamelose == false && gamewin == false) {

						for (int i = 0; i < 25; i++)
							for (int j = 0; j < 16; j++) {
								debugboard[i][j] = 15;
							}

						for (int i = 0; i < 25; i++)
							for (int j = 0; j < 16; j++) {
								debugger[i][j] = 2;
							}
						for (int i = 0; i <= 24; i++)
							for (int j = 0; j <= 15; j++) {
								if (debugger[i][j] == 2) {
									for (int i = 0; i < 25; i++)
										for (int j = 0; j < 16; j++) {
											if (open[i][j] == 2) {
												underBoard[i][j] = board[i][j];
											}
											else if (underBoard[i][j] == 11) {
												underBoard[i][j] = 11;
											}
											else {
												underBoard[i][j] = debugboard[i][j];
											}
										}
									gamelose == false;
									debuggerActive = false;
								}

							}
					}
					if (debugz.getGlobalBounds().contains(x * width, y * width)) {
						underBoard[x][y] = underBoard[x][y];
					}
					else if (testuno.getGlobalBounds().contains(x * width, y * width)) {
						underBoard[x][y] = underBoard[x][y];
					}
					else if (testdos.getGlobalBounds().contains(x * width, y * width)) {
						underBoard[x][y] = underBoard[x][y];
					}
					else if (underBoard[x][y] == 11) {
						underBoard[x][y] = 11;
					}
					
					else {
						underBoard[x][y] = board[x][y];
					}
					
					if (happyface.getGlobalBounds().contains(x * width, y * width)) {
						bombs = 50;
						mines = 0;
						gamelose = false;
						gamewin = false;
						flags = 50;
						happyface.setTexture(happy);
						window.draw(happyface);
						for (int i = 0; i <= 24; i++)
							for (int j = 0; j <= 15; j++) {
								underBoard[i][j] = 10;
								if (rand() % 6 == 0 && bombs > 0) {
									board[i][j] = 9;
									bombs = bombs - 1;
								}
								else {
									board[i][j] = 0;
								}
								if (board[i][j] == 9) {
									mines = mines + 1;
								}
							}

						tilecount = 400 - mines;

						for (int i = 0; i < 1; i++)
							for (int j = 0; j < 1; j++) {
								int n = 0;
								if (board[i][j] == 9) continue;
								if (board[i + 1][j] == 9) n++;
								if (board[i][j + 1] == 9) n++;
								if (board[i + 1][j + 1] == 9) n++;
								board[i][j] = n;
							}
						for (int i = 24; i < 25; i++)
							for (int j = 0; j < 1; j++) {
								int n = 0;
								if (board[i][j] == 9) continue;
								if (board[i][j + 1] == 9) n++;
								if (board[i - 1][j + 1] == 9) n++;
								if (board[i - 1][j] == 9) n++;
								board[i][j] = n;
							}
						for (int i = 0; i < 1; i++)
							for (int j = 15; j < 16; j++) {
								int n = 0;
								if (board[i][j] == 9) continue;
								if (board[i][j - 1] == 9) n++;
								if (board[i + 1][j - 1] == 9) n++;
								if (board[i + 1][j] == 9) n++;
								board[i][j] = n;
							}
						for (int i = 24; i < 25; i++)
							for (int j = 15; j < 16; j++) {
								int n = 0;
								if (board[i][j] == 9) continue;
								if (board[i - 1][j] == 9) n++;
								if (board[i][j - 1] == 9) n++;
								if (board[i - 1][j - 1] == 9) n++;
								board[i][j] = n;
							}
						for (int j = 0; j < 1; j++)
							for (int i = 1; i < 23; i++) {
								int n = 0;
								if (board[i][j] == 9) continue;
								if (board[i + 1][j] == 9) n++;
								if (board[i][j + 1] == 9) n++;
								if (board[i - 1][j] == 9) n++;
								if (board[i - 1][j + 1] == 9) n++;
								if (board[i + 1][j + 1] == 9) n++;
								board[i][j] = n;
							}
						for (int j = 15; j < 16; j++)
							for (int i = 1; i < 25; i++) {
								int n = 0;
								if (board[i][j] == 9) continue;
								if (board[i][j - 1] == 9) n++;
								if (board[i + 1][j] == 9) n++;
								if (board[i - 1][j] == 9) n++;
								if (board[i - 1][j - 1] == 9) n++;
								if (board[i + 1][j - 1] == 9) n++;
								board[i][j] = n;
							}
						for (int i = 0; i < 1; i++)
							for (int j = 1; j < 15; j++) {
								int n = 0;
								if (board[i][j] == 9) continue;
								if (board[i + 1][j] == 9) n++;
								if (board[i][j - 1] == 9) n++;
								if (board[i][j + 1] == 9) n++;
								if (board[i + 1][j + 1] == 9) n++;
								if (board[i + 1][j - 1] == 9) n++;
								board[i][j] = n;
							}
						for (int i = 24; i < 25; i++)
							for (int j = 1; j < 15; j++) {
								int n = 0;
								if (board[i][j] == 9) continue;
								if (board[i][j + 1] == 9) n++;
								if (board[i][j - 1] == 9) n++;
								if (board[i - 1][j] == 9) n++;
								if (board[i - 1][j + 1] == 9) n++;
								if (board[i - 1][j - 1] == 9) n++;
								board[i][j] = n;
							}
						for (int i = 1; i <= 23; i++)
							for (int j = 1; j <= 14; j++) {
								int n = 0;
								if (board[i][j] == 9) continue;
								if (board[i + 1][j] == 9) n++;
								if (board[i][j + 1] == 9) n++;
								if (board[i - 1][j] == 9) n++;
								if (board[i][j - 1] == 9) n++;
								if (board[i + 1][j + 1] == 9) n++;
								if (board[i - 1][j - 1] == 9) n++;
								if (board[i - 1][j + 1] == 9) n++;
								if (board[i + 1][j - 1] == 9) n++;
								board[i][j] = n;
							}
						for (int i = 0; i < 25; i++)
							for (int j = 0; j < 15; j++) {
								hasflag[i][j] = 1;
							}
						for (int i = 0; i < 25; i++)
							for (int j = 0; j < 15; j++) {
								open[i][j] = 1;
							}
						for (int i = 0; i < 25; i++)
							for (int j = 0; j < 16; j++) {
								if (board[i][j] == 9)
									boardMines[i][j] = 69;
							}
					}
					if (testuno.getGlobalBounds().contains(x * width, y * width) && gamelose == false && gamewin == false) {
						ifstream inputFile;
						inputFile.open("boards/testboard.brd", ios::in);
						string line1;
						int count = 0;
						if (inputFile.is_open()) {
							getline(inputFile, line1);
							while (getline(inputFile, line1))
							{
								count++;
							}
							inputFile.close();
						}
						count = count + 0;
						inputFile.open("boards/testboard.brd", ios::in);
						string line2;
						int lineCount = count;
						if (inputFile.is_open()) {
							for (int i = 0; i <= lineCount; ++i) {
								getline(inputFile, line2);
								char * tab2 = new char[line2.length() + 1];
								strcpy(tab2, line2.c_str());
								for (int j = 0; j < 25; ++j) {
									if (tab2[j] == '1') {
										board[j][i] = 9;
									}
									else {
										board[j][i] = 0;
									}
								}
							}
						}

						bombs = 50;
						mines = 0;
						gamelose = false;
						gamewin = false;

						for (int i = 0; i < 25; i++)
							for (int j = 0; j < 16; j++) {
								underBoard[i][j] = 10;
								if (board[i][j] == 9) {
									mines = mines + 1;
								}
							}
						happyface.setTexture(happy);
						window.draw(happyface);
				        tilecount = 400 - mines;
						flags = mines;

						for (int i = 0; i < 1; i++)
							for (int j = 0; j < 1; j++) {
								int n = 0;
								if (board[i][j] == 9) continue;
								if (board[i + 1][j] == 9) n++;
								if (board[i][j + 1] == 9) n++;
								if (board[i + 1][j + 1] == 9) n++;
								board[i][j] = n;
							}
						for (int i = 24; i < 25; i++)
							for (int j = 0; j < 1; j++) {
								int n = 0;
								if (board[i][j] == 9) continue;
								if (board[i][j + 1] == 9) n++;
								if (board[i - 1][j + 1] == 9) n++;
								if (board[i - 1][j] == 9) n++;
								board[i][j] = n;
							}
						for (int i = 0; i < 1; i++)
							for (int j = 15; j < 16; j++) {
								int n = 0;
								if (board[i][j] == 9) continue;
								if (board[i][j - 1] == 9) n++;
								if (board[i + 1][j - 1] == 9) n++;
								if (board[i + 1][j] == 9) n++;
								board[i][j] = n;
							}
						for (int i = 24; i < 25; i++)
							for (int j = 15; j < 16; j++) {
								int n = 0;
								if (board[i][j] == 9) continue;
								if (board[i - 1][j] == 9) n++;
								if (board[i][j - 1] == 9) n++;
								if (board[i - 1][j - 1] == 9) n++;
								board[i][j] = n;
							}
						for (int j = 0; j < 1; j++)
							for (int i = 1; i < 23; i++) {
								int n = 0;
								if (board[i][j] == 9) continue;
								if (board[i + 1][j] == 9) n++;
								if (board[i][j + 1] == 9) n++;
								if (board[i - 1][j] == 9) n++;
								if (board[i - 1][j + 1] == 9) n++;
								if (board[i + 1][j + 1] == 9) n++;
								board[i][j] = n;
							}
						for (int j = 15; j < 16; j++)
							for (int i = 1; i < 25; i++) {
								int n = 0;
								if (board[i][j] == 9) continue;
								if (board[i][j - 1] == 9) n++;
								if (board[i + 1][j] == 9) n++;
								if (board[i - 1][j] == 9) n++;
								if (board[i - 1][j - 1] == 9) n++;
								if (board[i + 1][j - 1] == 9) n++;
								board[i][j] = n;
							}
						for (int i = 0; i < 1; i++)
							for (int j = 1; j < 15; j++) {
								int n = 0;
								if (board[i][j] == 9) continue;
								if (board[i + 1][j] == 9) n++;
								if (board[i][j - 1] == 9) n++;
								if (board[i][j + 1] == 9) n++;
								if (board[i + 1][j + 1] == 9) n++;
								if (board[i + 1][j - 1] == 9) n++;
								board[i][j] = n;
							}
						for (int i = 24; i < 25; i++)
							for (int j = 1; j < 15; j++) {
								int n = 0;
								if (board[i][j] == 9) continue;
								if (board[i][j + 1] == 9) n++;
								if (board[i][j - 1] == 9) n++;
								if (board[i - 1][j] == 9) n++;
								if (board[i - 1][j + 1] == 9) n++;
								if (board[i - 1][j - 1] == 9) n++;
								board[i][j] = n;
							}
						for (int i = 1; i <= 23; i++)
							for (int j = 1; j <= 14; j++) {
								int n = 0;
								if (board[i][j] == 9) continue;
								if (board[i + 1][j] == 9) n++;
								if (board[i][j + 1] == 9) n++;
								if (board[i - 1][j] == 9) n++;
								if (board[i][j - 1] == 9) n++;
								if (board[i + 1][j + 1] == 9) n++;
								if (board[i - 1][j - 1] == 9) n++;
								if (board[i - 1][j + 1] == 9) n++;
								if (board[i + 1][j - 1] == 9) n++;
								board[i][j] = n;
							}
						for (int i = 0; i < 25; i++)
							for (int j = 0; j < 15; j++) {
								hasflag[i][j] = 1;
							}
						for (int i = 0; i < 25; i++)
							for (int j = 0; j < 15; j++) {
								open[i][j] = 1;
							}
						for (int i = 0; i < 25; i++)
							for (int j = 0; j < 16; j++) {
								if (board[i][j] == 9)
									boardMines[i][j] = 69;
							}
					}
					if (testdos.getGlobalBounds().contains(x * width, y * width) && gamelose == false && gamewin == false) {
						ifstream newFile;
						newFile.open("boards/testboard2.brd", ios::in);
						string line;
						int count = 0;
						if (newFile.is_open()) {
							getline(newFile, line);
							while (getline(newFile, line))
							{
								count++;
							}
							newFile.close();
						}
						count = count + 0;
						newFile.open("boards/testboard2.brd", ios::in);
						string lines;
						int numberOfLines = count;
						if (newFile.is_open()) {
							for (int i = 0; i <= numberOfLines; ++i) {
								getline(newFile, lines);
								char * tab2 = new char[lines.length() + 1];
								strcpy(tab2, lines.c_str());
								for (int j = 0; j < 25; ++j) {
									if (tab2[j] == '1') {
										board[j][i] = 9;
									}
									else {
										board[j][i] = 0;
									}
								}
							}
						}
						bombs = 50;
						mines = 0;
						gamelose = false;
						gamewin = false;

						for (int i = 0; i < 25; i++)
							for (int j = 0; j < 16; j++) {
								underBoard[i][j] = 10;
								if (board[i][j] == 9) {
									mines = mines + 1;
								}
							}
						happyface.setTexture(happy);
						window.draw(happyface);
						tilecount = 400 - mines;
						flags = mines;

						for (int i = 0; i < 1; i++)
							for (int j = 0; j < 1; j++) {
								int n = 0;
								if (board[i][j] == 9) continue;
								if (board[i + 1][j] == 9) n++;
								if (board[i][j + 1] == 9) n++;
								if (board[i + 1][j + 1] == 9) n++;
								board[i][j] = n;
							}
						for (int i = 24; i < 25; i++)
							for (int j = 0; j < 1; j++) {
								int n = 0;
								if (board[i][j] == 9) continue;
								if (board[i][j + 1] == 9) n++;
								if (board[i - 1][j + 1] == 9) n++;
								if (board[i - 1][j] == 9) n++;
								board[i][j] = n;
							}
						for (int i = 0; i < 1; i++)
							for (int j = 15; j < 16; j++) {
								int n = 0;
								if (board[i][j] == 9) continue;
								if (board[i][j - 1] == 9) n++;
								if (board[i + 1][j - 1] == 9) n++;
								if (board[i + 1][j] == 9) n++;
								board[i][j] = n;
							}
						for (int i = 24; i < 25; i++)
							for (int j = 15; j < 16; j++) {
								int n = 0;
								if (board[i][j] == 9) continue;
								if (board[i - 1][j] == 9) n++;
								if (board[i][j - 1] == 9) n++;
								if (board[i - 1][j - 1] == 9) n++;
								board[i][j] = n;
							}
						for (int j = 0; j < 1; j++)
							for (int i = 1; i < 23; i++) {
								int n = 0;
								if (board[i][j] == 9) continue;
								if (board[i + 1][j] == 9) n++;
								if (board[i][j + 1] == 9) n++;
								if (board[i - 1][j] == 9) n++;
								if (board[i - 1][j + 1] == 9) n++;
								if (board[i + 1][j + 1] == 9) n++;
								board[i][j] = n;
							}
						for (int j = 15; j < 16; j++)
							for (int i = 1; i < 25; i++) {
								int n = 0;
								if (board[i][j] == 9) continue;
								if (board[i][j - 1] == 9) n++;
								if (board[i + 1][j] == 9) n++;
								if (board[i - 1][j] == 9) n++;
								if (board[i - 1][j - 1] == 9) n++;
								if (board[i + 1][j - 1] == 9) n++;
								board[i][j] = n;
							}
						for (int i = 0; i < 1; i++)
							for (int j = 1; j < 15; j++) {
								int n = 0;
								if (board[i][j] == 9) continue;
								if (board[i + 1][j] == 9) n++;
								if (board[i][j - 1] == 9) n++;
								if (board[i][j + 1] == 9) n++;
								if (board[i + 1][j + 1] == 9) n++;
								if (board[i + 1][j - 1] == 9) n++;
								board[i][j] = n;
							}
						for (int i = 24; i < 25; i++)
							for (int j = 1; j < 15; j++) {
								int n = 0;
								if (board[i][j] == 9) continue;
								if (board[i][j + 1] == 9) n++;
								if (board[i][j - 1] == 9) n++;
								if (board[i - 1][j] == 9) n++;
								if (board[i - 1][j + 1] == 9) n++;
								if (board[i - 1][j - 1] == 9) n++;
								board[i][j] = n;
							}
						for (int i = 1; i <= 23; i++)
							for (int j = 1; j <= 14; j++) {
								int n = 0;
								if (board[i][j] == 9) continue;
								if (board[i + 1][j] == 9) n++;
								if (board[i][j + 1] == 9) n++;
								if (board[i - 1][j] == 9) n++;
								if (board[i][j - 1] == 9) n++;
								if (board[i + 1][j + 1] == 9) n++;
								if (board[i - 1][j - 1] == 9) n++;
								if (board[i - 1][j + 1] == 9) n++;
								if (board[i + 1][j - 1] == 9) n++;
								board[i][j] = n;
							}
						for (int i = 0; i < 25; i++)
							for (int j = 0; j < 15; j++) {
								hasflag[i][j] = 1;
							}
						for (int i = 0; i < 25; i++)
							for (int j = 0; j < 15; j++) {
								open[i][j] = 1;
							}
						for (int i = 0; i < 25; i++)
							for (int j = 0; j < 16; j++) {
								if (board[i][j] == 9)
									boardMines[i][j] = 69;
							}
					}
				}
		}

		window.clear(Color::White);
		tilecount = 400 - mines;
		for (int i = 0; i <= 24; i++)
			for (int j = 0; j <= 15; j++) {
				hide.setPosition(i * width, j * width);
				window.draw(hide);
			}

		testuno.setPosition(18 * width, 16 * width);
		window.draw(testuno);

		testdos.setPosition(20 * width, 16 * width);
		window.draw(testdos);

		debugz.setPosition(16 * width, 16 * width);
		window.draw(debugz);

		digitz2.setPosition(21, 16 * width);
		digitz2.setTextureRect(IntRect(21 * ((flags % 10)), 0, 21 * 1, width));
		digitz.setTextureRect(IntRect(21 * ((flags / 10)), 0, 21 * 1, width));
		digitz.setPosition(0, 16 * width);
		window.draw(digitz2);
		window.draw(digitz);

		happyface.setPosition(10 * width, 16 * width);
		window.draw(happyface);

		if (gamelose == false) {
			for (int i = 0; i <= 24; i++)
				for (int j = 0; j <= 15; j++) {

					if (underBoard[i][j] == 9) {
						open[i][j] = 3;
						minez.setPosition(i * width, j * width);
						window.draw(minez);
						happyface.setTexture(sad);
						window.draw(happyface);
						for (int i = 0; i <= 24; i++)
							for (int j = 0; j <= 15; j++) {
								if (board[i][j] == 9) {
									underBoard[i][j] = board[i][j];
								}
							}
						gamelose = true;
					}
					else if (underBoard[i][j] == 0) {
						open[i][j] = 2;
						tilecount = tilecount - 1;
						reveale.setPosition(i * width, j * width);
						window.draw(reveale);

					}
					else if (underBoard[i][j] == 11) {
						hasflag[i][j] = 2;
						flagz.setPosition(i * width, j * width);
						window.draw(flagz);
					}
					else if (underBoard[i][j] == 1) {
						open[i][j] = 2;
						tilecount = tilecount - 1;
						reveale.setPosition(i * width, j * width);
						window.draw(reveale);
						uno.setPosition(i * width, j * width);
						window.draw(uno);
					}
					else if (underBoard[i][j] == 2) {
						open[i][j] = 2;
						tilecount = tilecount - 1;
						reveale.setPosition(i * width, j * width);
						window.draw(reveale);
						dos.setPosition(i * width, j * width);
						window.draw(dos);
					}
					else if (underBoard[i][j] == 3) {
						open[i][j] = 2;
						tilecount = tilecount - 1;
						reveale.setPosition(i * width, j * width);
						window.draw(reveale);
						tres.setPosition(i * width, j * width);
						window.draw(tres);
					}
					else if (underBoard[i][j] == 4) {
						open[i][j] = 2;
						tilecount = tilecount - 1;
						reveale.setPosition(i * width, j * width);
						window.draw(reveale);
						quatro.setPosition(i * width, j * width);
						window.draw(quatro);
					}
					else if (underBoard[i][j] == 5) {
						open[i][j] = 2;
						tilecount = tilecount - 1;
						reveale.setPosition(i * width, j * width);
						window.draw(reveale);
						cinco.setPosition(i * width, j * width);
						window.draw(cinco);
					}
					else if (underBoard[i][j] == 6) {
						open[i][j] = 2;
						tilecount = tilecount - 1;
						reveale.setPosition(i * width, j * width);
						window.draw(reveale);
						sies.setPosition(i * width, j * width);
						window.draw(sies);
					}
					else if (underBoard[i][j] == 7) {
						open[i][j] = 2;
						tilecount = tilecount - 1;
						reveale.setPosition(i * width, j * width);
						window.draw(reveale);
						siete.setPosition(i * width, j * width);
						window.draw(siete);
					}
					else if (underBoard[i][j] == 8) {
						open[i][j] = 2;
						tilecount = tilecount - 1;
						reveale.setPosition(i * width, j * width);
						window.draw(reveale);
						ocho.setPosition(i * width, j * width);
						window.draw(ocho);
					}
					else if (underBoard[i][j] == 15) {
						hide.setPosition(i * width, j * width);
						window.draw(hide);
					}
					else if (underBoard[i][j] == 69) {
						minez.setPosition(i * width, j * width);
						window.draw(minez);
					}
				}
			if (tilecount == 0) {
				for (int i = 0; i <= 24; i++)
					for (int j = 0; j <= 15; j++) {
						if (board[i][j] == 9) {
							underBoard[i][j] = 11;
						}
					}
				happyface.setTexture(cool);
				flags = 0;
				window.draw(happyface);
				gamewin = true;
			}
		}
		else if (gamelose == true) {
			for (int i = 0; i <= 24; i++)
				for (int j = 0; j <= 15; j++) {
					if (board[i][j] == 9) {
						underBoard[i][j] = board[i][j];
						minez.setPosition(i * width, j * width);
						window.draw(minez);
						happyface.setTexture(sad);
						window.draw(happyface);
					}
					if (open[i][j] == 2 || hasflag[i][j] == 2) {
						if (underBoard[i][j] == 0) {
							reveale.setPosition(i * width, j * width);
							window.draw(reveale);
						}
						else if (underBoard[i][j] == 11) {
							flagz.setPosition(i * width, j * width);
							window.draw(flagz);
						}
						else if (underBoard[i][j] == 1) {
							reveale.setPosition(i * width, j * width);
							window.draw(reveale);
							uno.setPosition(i * width, j * width);
							window.draw(uno);
						}
						else if (underBoard[i][j] == 2) {
							reveale.setPosition(i * width, j * width);
							window.draw(reveale);
							dos.setPosition(i * width, j * width);
							window.draw(dos);
						}
						else if (underBoard[i][j] == 3) {
							reveale.setPosition(i * width, j * width);
							window.draw(reveale);
							tres.setPosition(i * width, j * width);
							window.draw(tres);
						}
						else if (underBoard[i][j] == 4) {
							reveale.setPosition(i * width, j * width);
							window.draw(reveale);
							quatro.setPosition(i * width, j * width);
							window.draw(quatro);
						}
						else if (underBoard[i][j] == 5) {
							reveale.setPosition(i * width, j * width);
							window.draw(reveale);
							cinco.setPosition(i * width, j * width);
							window.draw(cinco);
						}
						else if (underBoard[i][j] == 6) {
							reveale.setPosition(i * width, j * width);
							window.draw(reveale);
							sies.setPosition(i * width, j * width);
							window.draw(sies);
						}
						else if (underBoard[i][j] == 7) {
							reveale.setPosition(i * width, j * width);
							window.draw(reveale);
							siete.setPosition(i * width, j * width);
							window.draw(siete);
						}
						else if (underBoard[i][j] == 8) {
							reveale.setPosition(i * width, j * width);
							window.draw(reveale);
							ocho.setPosition(i * width, j * width);
							window.draw(ocho);
						}
						else if (underBoard[i][j] == 15) {
							hide.setPosition(i * width, j * width);
							window.draw(hide);
						}
						else if (underBoard[i][j] == 69) {
							minez.setPosition(i * width, j * width);
							window.draw(minez);
						}
					}
				}
		}
		window.display();
	}
}

