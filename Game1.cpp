#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <vector>
#define BOARD_SIZE 3
#define CELL_SIZE 150
using namespace std;

char board[BOARD_SIZE][BOARD_SIZE];

void ResetBoard() {
	for (int i = 0; i < BOARD_SIZE; ++i) {
		for (int j = 0; j < BOARD_SIZE; ++j) {
			board[i][j] = ' ';
		}
	}
}

bool IsFull() {
	for (int i = 0; i < BOARD_SIZE; ++i) {
		for (int j = 0; j < BOARD_SIZE; ++j) {
			if (board[i][j] == ' ') return false;
		}
	}
	return true;
}

char Winner(vector<pair<pair<int, int>, pair<int, int>>>& coordinate) {
	for (int i = 0; i < BOARD_SIZE; ++i) {
		if (board[i][0] != ' ' &&
			board[i][0] == board[i][1] &&
			board[i][1] == board[i][2]) {
			coordinate.push_back({ {i, 0}, {i, 2} });
			return board[i][0];
		}

		if (board[0][i] != ' ' &&
			board[0][i] == board[1][i] &&
			board[1][i] == board[2][i]) {
			coordinate.push_back({ {0, i}, {2, i} });
			return board[0][i];
		}
	}

	if (board[0][0] != ' ' &&
		board[0][0] == board[1][1] &&
		board[1][1] == board[2][2]) {
		coordinate.push_back({ {0, 0}, {2, 2} });
		return board[0][0];
	}

	if (board[0][2] != ' ' &&
		board[0][2] == board[1][1] &&
		board[1][1] == board[2][0]) {
		coordinate.push_back({ {0, 2}, {2, 0} });
		return board[0][2];
	}

	return ' ';
}

void DrawX(sf::RenderWindow& window, int col, int row) {
	float margin = 30.f;
	sf::Vector2f p1(col * CELL_SIZE + margin, row * CELL_SIZE + margin);
	sf::Vector2f p2((col + 1) * CELL_SIZE - margin, (row + 1) * CELL_SIZE - margin);
	sf::Vector2f p3((col + 1) * CELL_SIZE - margin, row * CELL_SIZE + margin);
	sf::Vector2f p4(col * CELL_SIZE + margin, (row + 1) * CELL_SIZE - margin);

	sf::RectangleShape line1(p2 - p1);
	line1.setFillColor(sf::Color::Black);
	line1.setPosition(p1);
	line1.setSize(sf::Vector2f(sqrt(2) * (CELL_SIZE - 2 * margin), 10));
	line1.setRotation(45);

	sf::RectangleShape line2(p3 - p4);
	line2.setFillColor(sf::Color::Black);
	line2.setPosition(p4);
	line2.setSize(sf::Vector2f(sqrt(2) * (CELL_SIZE - 2 * margin), 10));
	line2.setRotation(-45);

	window.draw(line1);
	window.draw(line2);
}

void DrawO(sf::RenderWindow& window, int col, int row) {
	float radius = (CELL_SIZE - 2 * 30) / 2;
	sf::CircleShape circle(radius);
	circle.setFillColor(sf::Color::Transparent);
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(10);
	circle.setPosition(col * CELL_SIZE + 30, row * CELL_SIZE + 30);
	window.draw(circle);
}

int main() {
	sf::RenderWindow window(sf::VideoMode(BOARD_SIZE * CELL_SIZE, BOARD_SIZE * CELL_SIZE, 32), "Tic-Tac-Toe");
	ResetBoard();
	char CurrentPlayer = 'X';
	char winner = ' ';
	vector<pair<pair<int, int>, pair<int, int>>> coordinate;
	bool GameOver = false;
	bool JustFinished = false;
	sf::Clock GameClock;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			if (!GameOver && event.type == sf::Event::MouseButtonPressed) {
				int row = event.mouseButton.y / CELL_SIZE;
				int col = event.mouseButton.x / CELL_SIZE;

				if (row < BOARD_SIZE && col < BOARD_SIZE && board[row][col] == ' ') {
					board[row][col] = CurrentPlayer;
					coordinate.clear();
					winner = Winner(coordinate);
					if (winner != ' ') {
						GameOver = true;
						JustFinished = true;
						GameClock.restart();
					}

					else if (IsFull()) {
						GameOver = true;
						JustFinished = true;
						GameClock.restart();
						winner = 'D';
					}
					else {
						CurrentPlayer = (CurrentPlayer == 'X') ? 'O' : 'X';
					}
				}
			}
		}
		if (GameOver && JustFinished && GameClock.getElapsedTime().asSeconds() > 1.0f) {
			ResetBoard();
			CurrentPlayer = 'X';
			GameOver = false;
			JustFinished = false;
			winner = ' ';
		}

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R) {
			ResetBoard();
			CurrentPlayer = 'X';
			GameOver = false;
			JustFinished = false;
			winner = ' ';
		}
		window.clear(sf::Color::White);

		for (int i = 0; i < BOARD_SIZE; ++i) {
			sf::RectangleShape hline(sf::Vector2f(CELL_SIZE * BOARD_SIZE, 6));
			hline.setFillColor(sf::Color::Black);
			hline.setPosition(0, i * CELL_SIZE);
			window.draw(hline);

			sf::RectangleShape vline(sf::Vector2f(6, CELL_SIZE * BOARD_SIZE));
			vline.setFillColor(sf::Color::Black);
			vline.setPosition(i * CELL_SIZE, 0);
			window.draw(vline);
		}

		for (int i = 0; i < BOARD_SIZE; ++i) {
			for (int j = 0; j < BOARD_SIZE; ++j) {
				if (board[i][j] == 'X') DrawX(window, j, i);
				else if (board[i][j] == 'O') DrawO(window, j, i);
			}
		}

		if (winner != ' ' && !coordinate.empty()) {
			int row1 = coordinate[0].first.first;
			int col1 = coordinate[0].first.second;
			int row2 = coordinate[0].second.first;
			int col2 = coordinate[0].second.second;

			sf::Vector2f p1(col1 * CELL_SIZE + CELL_SIZE / 2.f, row1 * CELL_SIZE + CELL_SIZE / 2.f);
			sf::Vector2f p2(col2 * CELL_SIZE + CELL_SIZE / 2.f, row2 * CELL_SIZE + CELL_SIZE / 2.f);

			sf::Vector2f direction = p2 - p1;
			float length = sqrt(direction.x * direction.x + direction.y * direction.y);

			sf::Vector2f unitDir = direction / length;

			float extend = 40.f;
			sf::Vector2f new1 = p1 - unitDir * extend;
			sf::Vector2f new2 = p2 + unitDir * extend;
			
			sf::Vector2f newDir = new2 - new1;
			float newLength = sqrt(newDir.x * newDir.x + newDir.y * newDir.y);

			sf::RectangleShape nline(sf::Vector2f(newLength, 7));
			nline.setFillColor(sf::Color::Magenta);
			nline.setOrigin(0, 5);
			nline.setPosition(new1);
			nline.setRotation(atan2(newDir.y, newDir.x) * 180.f / 3.14159f);
			window.draw(nline);
		}

		if (GameOver && JustFinished) {
			sf::RectangleShape overlay(sf::Vector2f(CELL_SIZE * BOARD_SIZE, 150));
			overlay.setFillColor(sf::Color(50, 50, 50, 180));
			overlay.setOrigin(overlay.getSize().x / 2, overlay.getSize().y / 2);
			overlay.setPosition(CELL_SIZE * BOARD_SIZE / 2, CELL_SIZE * BOARD_SIZE / 2);
			window.draw(overlay);

			sf::Font font;
			if (!font.loadFromFile("Open_Sans/static/OpenSans-Regular.ttf")) {
				return -1;
			}
			else {
				sf::Text msg;
				msg.setFont(font);
				msg.setFillColor(sf::Color::White);
				msg.setCharacterSize(32);
				msg.setOutlineColor(sf::Color::Black);
				msg.setOutlineThickness(4);
				msg.setStyle(sf::Text::Bold);

				if (winner == 'D') msg.setString("DRAW");
				else msg.setString("PLAYER  " + string(1, winner) + "  WINS!!!");

				sf::FloatRect bounds = msg.getLocalBounds();
				msg.setOrigin(bounds.left + bounds.width / 2, bounds.top + bounds.height / 2);
				msg.setPosition(CELL_SIZE * BOARD_SIZE / 2, CELL_SIZE * BOARD_SIZE / 2);
				window.draw(msg);
			}
		}
		window.display();
	}
	return 0;
}