#include "player.hpp"
#include "board.hpp"
namespace ariel {
	class Catan {
		Player& p1;
		Player& p2;
		Player& p3;
		vector<Player*> players;

		Board b;
		Deck d;
		
		
		public:

			Catan(Player& p1, Player& p2, Player& p3);
			~Catan() = default;
			void ChooseStartingPlayer();
			
			Deck& getDeck();
			Board &getBoard();
			
			vector<Player*>& get_players() {
				return players;
			}

			void round(int res);
			
			void bring_player_resorese(int vertex, Player& player);
			void printWinner();
			
	};
	
}
