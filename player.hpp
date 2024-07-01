#pragma once
#include <string>
#include <vector>
#include "board.hpp"
#include "develope_card.hpp"

using namespace std;

namespace ariel {
	class Catan;
	
	class Player {
		string name;
		int my_num;
		int age;
		int points;
		int num_knights;
		bool is_turn;
		Player* next_player;
		map<const string, int> source_cards;
		vector<DevelopCard*> develope_cards;

	public:

		const map<const string, int> village_cost = { {"wheat", 1}, {"wood", 1}, {"brick", 1}, {"sheep", 1} };
		const map<const string, int> road_cost = { {"wood", 1}, {"brick", 1} };
		const map<const string, int> develop_cost = { {"wheat", 1},{"stone", 1},{"sheep", 1} };
		const map<const string, int> city_cost = { {"wheat", 2},{"stone", 3} };
		static int num_player;
		
		Player(string name);

		
		int get_points() {
			return points;
		}
		void increase_num_knights() {
			num_knights++;
			if (num_knights == 3)
				increase_points(2);
		}
		void increase_points(int inc) {
			points += inc;
			if (points >= 10) {
				cout << name << " wins!!" << endl;
				exit(0);
			}
		}

		
		int get_age() {
			return age;
		}
		string get_name() {
			return name;
		}


		void inc_map(string key) {
			source_cards[key] += 1;
		}
		int dec_map(string key) {
			int num_dec = 0;
			while (source_cards[key] != 0) {
				source_cards[key] --;
				num_dec++;
			}
			return num_dec;
		}

		void set_turn(bool turn) {
			is_turn = turn;
		}

		void set_next_player(Player* player) {
			next_player = player;
		}

		void placeCity(int placeNum, Board& board);
		
		void placeSettelemnt(int placesNum, Board& board);
		
		bool check_one_road(Vertex& vplace, Board& board);

		bool check_two_roads(Vertex& vplace, Board& board);
		void placeRoad(int roadNum, Board& board);
		bool check_nei_edge(Edge& roadnum);
		bool check_nei_ver(Edge& roadnum, int num_check);
		void pay(const map<const string, int>& resources);
		void print_player();

		
		void add_res_player(string res, int points) {
			source_cards[res] += points;
		}
		int rollTwoDice(Board& board);

		int get_num() {
			return my_num;
		}
		void trade(Player& other, const string& my_card, const string& other_card, int my_amount, int other_amount);
		void buyDevelopmentCard(Deck& deck);

		
		void use_card(Catan& catan,Board& board);
		

		map<const string, int> get_source_card() {
			return source_cards;
		}

		void endTurn();
		void reduce_half_resources();
		
	};
}