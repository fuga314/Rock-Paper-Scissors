#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/Main.hpp>
#include<iostream>
#include<string>
//#include<ctime>

const int weight = 1000;
const int height = 900;

using namespace sf;
enum game {
	paper, rock, sci
};

int game_logic() {
	int q1 = rand() % 3;
	int q2 = rand() % 3;
	if (q1 == q2)return 0;
	if ((q1 + 1) % 3 == q2)return 1;
	return 2;

}

int main() {
	srand(100);
	int n;
	std::cin >> n;
	int won = 0;
	int lose = 0;
	int draw = 0;
	for (int i = 0; i != n; ++i) {
		switch (game_logic())
		{
		case 0:
			++draw;
			break;
		case 1:
			++won;
			break;
		case 2:
			++lose;
			break;
		}	
	}
	std::cout << won << " " << lose << " " << draw << std::endl;

	RenderWindow window(VideoMode(weight, height), "Rock-Paper-scissors");

	RectangleShape q1,q2,q3;
	q1.setFillColor(Color::Color(135, 206, 250));
	q1.setSize(Vector2f(250, won*2));
	q1.setPosition(Vector2f(75, height-won*2));
	q1.setOutlineColor(Color::Black);
	q1.setOutlineThickness(2.f);

	q2.setFillColor(Color::Color(255, 69, 0));
	q2.setSize(Vector2f(250, lose*2));
	q2.setPosition(Vector2f(350, height-lose*2));
	q2.setOutlineColor(Color::Black);
	q2.setOutlineThickness(2.f);

	q3.setFillColor(Color::Color(153, 50, 204));
	q3.setSize(Vector2f(250, draw*2));
	q3.setPosition(Vector2f(625, height - draw*2));
	q3.setOutlineColor(Color::Black);
	q3.setOutlineThickness(2.f);


	Font won_t;
	won_t.loadFromFile("Arialn.ttf");
	Text text_win,win_score,text_lose,lose_score,text_draw,draw_score;
	text_win.setFont(won_t);
	text_win.setString("won");
	text_win.setPosition(170, height - 50);

	text_lose.setFont(won_t);
	text_lose.setString("lose");
	text_lose.setPosition(455, height - 50);

	text_draw.setFont(won_t);
	text_draw.setString("draw");
	text_draw.setPosition(730, height - 50);

	std::string str = std::to_string(won);
	win_score.setFont(won_t);
	win_score.setString(str);
	win_score.setPosition(170, height - won * 2 - 50);

	str = std::to_string(lose);
	lose_score.setFont(won_t);
	lose_score.setString(str);
	lose_score.setPosition(455, height - lose * 2 - 50);

	str = std::to_string(draw);
	draw_score.setFont(won_t);
	draw_score.setString(str);
	draw_score.setPosition(730, height - draw * 2 - 50);
	

	



	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)window.close();
		}
		window.clear(Color::Color(47, 79, 79));
		window.draw(q1);
		window.draw(q2);
		window.draw(q3);
		window.draw(text_win);
		window.draw(text_lose);
		window.draw(text_draw);
		window.draw(win_score);
		window.draw(lose_score);
		window.draw(draw_score);
		window.display();
	}



	return 0;
}