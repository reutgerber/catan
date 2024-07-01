#include "catan.hpp"
#include "player.hpp"
//#include "board.hpp"
#include <iostream>
using namespace std;
using namespace ariel;

Catan::Catan(Player& player1, Player& player2, Player& player3) :p1(player1), p2(player2), p3(player3), players{ &p1, &p2, &p3 }{

}

void Catan::ChooseStartingPlayer() {
	p1.set_turn(true);
	p2.set_turn(false);
	p3.set_turn(false);

	p1.set_next_player(&p2);
	p2.set_next_player(&p3);
	p3.set_next_player(&p1);

	cout << p1.get_name() << " is starting" << endl;
}

//after rolling the function over every hex and bring the player his resorces
void Catan::round(int res) {

	//if the cubes res 7 the player it calls reduce_half_resources
	if (res == 7) {
		for (Player* player : players) {
			player->reduce_half_resources();
		}
	}
	else {
		vector<Hexagon>& hexagons = b.get_hexagons();
		//over any hex
		for (int i = 0; i < hexagons.size(); i++) {
			if (hexagons[i].get_num() == res) {
				//over any ver of the hex
				for (Vertex* ver_hex : hexagons[i].get_vertex()) {
					//over any player
					for (Player* player : players) {
						//if the ver belong to the player he gets the resorce
						if (player->get_num() == ver_hex->get_num_player()) {
							player->add_res_player(hexagons[i].get_res(), ver_hex->get_points());
						}
					}

				}
			}
		}
	}

}
//before rolling, after first setteles
void Catan::bring_player_resorese(int vertex, Player& player) {
	vector<Hexagon>& hexagons = b.get_hexagons();
	//over any hex
	for (int i = 0; i < hexagons.size(); i++) {
		//over any ver of the hex
		for (Vertex* v : hexagons[i].get_vertex()) {
			//if resorce not dessert
			if ((v->get_id() == vertex) && i != 9) {
				player.inc_map(hexagons[i].get_res());
			}
		}
	}
}
Board& Catan::getBoard() {
    return b;
}
Deck& Catan::getDeck() {
	return d;
}
void Catan::printWinner() {
	Player* winner = nullptr;
	for (Player* player : players) {
		if (player->get_points() >= 10) {
			if (winner == nullptr || player->get_points() > winner->get_points()) {
				winner = player;
			}
		}
	}
	if (winner != nullptr) {
		cout << "The winner is: " << winner->get_name() << " with " << winner->get_points() << " points!" << endl;
	}
	else {
		cout << "None" << endl;
	}
}
