#include "player.hpp"
#include "catan.hpp"
#include <random>
#include <ctime>
#include <iostream>

using namespace ariel;
int Player::num_player = 0;
Player::Player(string name) {
	points = 0;
	source_cards["wheat"] = 2;
	source_cards["wood"] = 4;
	source_cards["brick"] = 4;
	source_cards["stone"] = 0;
	source_cards["sheep"] = 2;
	this->name = name;
	this->age = 10;
	my_num = num_player;
	num_knights = 0;
	num_player++;

}
int Player::rollTwoDice(Board& board) {
	if (is_turn == false) {
		throw runtime_error("not your turn");
	}
	// Seed the random number generator (call only once)
	static std::default_random_engine generator(std::time(0));

	// Define a uniform distribution for numbers 1 to 6
	std::uniform_int_distribution<int> distribution(1, 6);

	int res = distribution(generator) + distribution(generator);
	

	return res;
}
void Player::use_card(Catan& catan,Board& board) {
			if (is_turn == false) {
				throw runtime_error("not your turn");
			}
			if (develope_cards.size() != 0) {
				DevelopCard* card=develope_cards.back();
				card->use(*this, catan.get_players(),board);
				develope_cards.pop_back();
				delete card;
			}
			else {
				throw runtime_error("No development cards left");
			}
			this->endTurn();
}

void Player::placeCity(int placeNum, Board& board) {
	if (is_turn == false) {
		throw runtime_error("not your turn");
	}
	Vertex& vplace = board.get_vertexs()[placeNum];
	if (vplace.get_num_player() == my_num) {
		pay(city_cost);
		vplace.set_available("c", this->my_num);
		increase_points(1);
	}
}

void Player::placeSettelemnt(int placesNum, Board& board) {
	if (is_turn == false) {
		throw runtime_error("not your turn");
	}
	Vertex& vplace = board.get_vertexs()[placesNum];
	/*vector<int> edge_id = vplace.get_edge_nei();
	for */
	//if ver empty&& first build or 
	if ((vplace.get_available() == to_string(placesNum)) && (points <= 1 || check_two_roads(vplace, board)) && check_one_road(vplace, board))
	{
		pay(village_cost);
		vplace.set_available("v", this->my_num);
		increase_points(1);

	}
	else {
		throw runtime_error("Vertex not available");
	}

}

bool Player::check_one_road(Vertex& vplace, Board& board) {
	bool flag = true;
	for (int edge_id : vplace.get_edge_nei()) {
		Edge& nei_edge = board.get_edges()[edge_id];
		if (check_nei_ver(nei_edge, 1) || check_nei_ver(nei_edge, 2) || check_nei_ver(nei_edge, 0)) {
			flag = false;
		}
	}
	return flag;
}

bool Player::check_two_roads(Vertex& vplace, Board& board) {
	bool flag = false;
	for (int edge_id : vplace.get_edge_nei()) {
		Edge& nei_edge = board.get_edges()[edge_id];
		//if there is nei that belong to current player && ver on edge empty
		if (nei_edge.get_num_player() == my_num && check_nei_ver(nei_edge, -1)) {
			//check also the next edge
			flag = check_nei_edge(nei_edge);
		}
	}
	return flag;
}

void Player::placeRoad(int roadNum, Board& board) {
	if (is_turn == false) {
		throw runtime_error("not your turn");
	}
	Edge& eroad = board.get_edges()[roadNum];
	//check if the edge is empty(��� ���� ���) &&  
	if ((eroad.get_num_player() == -1) && (check_nei_edge(eroad) || check_nei_ver(eroad, my_num))) {
		pay(road_cost);
		eroad.set_available("e", this->my_num);
	}
	else {
		throw runtime_error("Edge is not available or no neighbouring edge with the player's road.");
	}
}

bool Player::check_nei_edge(Edge& roadnum) {
	bool flag = false;
	for (Edge* nei : roadnum.get_neibours())
		if (nei->get_num_player() == my_num)
			flag = true;
	return flag;
}

bool Player::check_nei_ver(Edge& roadnum, int num_check) {
	bool flag = false;
	for (Vertex* nei : roadnum.get_ver_nei()) {
		if (nei->get_num_player() == num_check)
			flag = true;
	}
	return flag;
}

void Player::pay(const map<const string, int>& resources) {

	for (const auto& resource : resources) {
		const string& key = resource.first;
		int amount = resource.second;

		if (source_cards[key] < amount) {
			throw runtime_error("Not enough " + key + " resources to pay.");
		}
		source_cards[key] -= amount;
	}
}

void Player::print_player() {
	cout << "player " << my_num << endl;
	for (const auto& pair : source_cards) {
		cout << pair.first << ": " << pair.second << endl;
	}
	cout << "points: " << points << endl;
	cout << "knights: " << num_knights << endl;
	cout << endl;
}
void Player::trade(Player& other, const string& my_card, const string& other_card, int my_amount, int other_amount) {
	if (is_turn == false) {
		throw runtime_error("not your turn");
	}
	// Check if both players have enough resources to trade
	if (source_cards[my_card] < my_amount) {
		throw runtime_error("Not enough " + my_card + " resources to trade.");
	}
	if (other.source_cards[other_card] < other_amount) {
		throw runtime_error("Other player doesn't have enough " + other_card + " resources to trade.");
	}
	cout << "trade success" << endl;
	// Perform the trade
	source_cards[my_card] -= my_amount;
	other.source_cards[my_card] += my_amount;

	other.source_cards[other_card] -= other_amount;
	source_cards[other_card] += other_amount;
}

void Player::buyDevelopmentCard(Deck& deck) {
	if (is_turn == false) {
		throw runtime_error("not your turn");
	}
	pay(develop_cost);
	DevelopCard* newCard = deck.drawCard();
	if (newCard != nullptr) {
		develope_cards.push_back(newCard);
		cout << "Bought a development card of type: " << newCard->getType() << endl;
	}
	else {
		throw runtime_error("No development cards left in the deck.");
	}

}

void Player::endTurn() {
	if (is_turn == false) {
		throw runtime_error("not your turn");
	}
	next_player->set_turn(true);
	is_turn = false;
	cout << name << " end his turn" << endl;
	cout << next_player->get_name() << " now playing" << endl;
}
void Player::reduce_half_resources() {

	int total_resources = 0;
	for (const auto& resource : source_cards) {
		total_resources += resource.second;
	}

	if (total_resources > 7) {
		cout << "player " << this->my_num << " need to remove" << endl;
		int resources_to_remove = total_resources / 2;
		cout << "You need to remove " << resources_to_remove << " resources." << endl;

		while (resources_to_remove > 0) {
			cout << "Current resources:" << endl;
			for (const auto& resource : source_cards) {
				cout << resource.first << ": " << resource.second << endl;
			}

			string resource_to_remove;
			int amount_to_remove;
			cout << "Enter resource to remove: ";
			cin >> resource_to_remove;
			cout << "Enter amount to remove: ";
			cin >> amount_to_remove;

			if (source_cards[resource_to_remove] >= amount_to_remove) {
				source_cards[resource_to_remove] -= amount_to_remove;
				resources_to_remove -= amount_to_remove;
			}
			else {
				throw runtime_error("Not enough resource to remove");
			}
		}

	}
}