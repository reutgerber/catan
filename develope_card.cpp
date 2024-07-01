#include "develope_card.hpp"
#include "player.hpp"
#include "board.hpp"
#include <random>
#include <algorithm>


void KnightCard::use(Player& player, std::vector<Player*>& players, Board& board) {
    std::cout << "Knight card used by player " << player.get_name() << std::endl;
    player.increase_num_knights();
    
}


void VictoryPointCard::use(Player& player, std::vector<Player*>& players, Board& board) {
    std::cout << "Victory Point card used by player " << player.get_name() << std::endl;
    player.increase_points(1);
}


void MonopolyCard::use(Player& player, std::vector<Player*>& players, Board& board) {
    std::cout << "choose resource to monopol: wheat/wood/brick/stone/sheep" << endl;
    std::string res;
    std::cin >> res;
    if (res != "wheat" && res != "wood" && res != "brick" && res != "stone" && res != "sheep")
        throw runtime_error("invalid input");
    int num_dec = 0;
    for (Player* player: players) {
            //decerse from all the players the res and count it
            num_dec+=player->dec_map(res);
     
    }
    //inc by the count
    for (int i = 0; i < num_dec; i++) {
        player.inc_map(res);
    }
}

 
void RoadBuildingCard::use(Player& player, std::vector<Player*>& players, Board& board) {
    //inc resorces for road
    player.inc_map("wood");
    player.inc_map("wood");
    player.inc_map("brick");
    player.inc_map("brick");
    int road_num;
    std::cout << "choose first road_num" << endl;
    cin >> road_num;
    player.placeRoad(road_num,board);
    std::cout << "choose second road_num" << endl;
    cin >> road_num;
    player.placeRoad(road_num, board);
    
}

// Definitions for YearOfPlentyCard
void YearOfPlentyCard::use(Player& player, std::vector<Player*>& players, Board& board) {
    std::cout << "choose resource wheat/wood/brick/stone/sheep" << endl;
    std::string chosen_resource;
    std::cin >> chosen_resource;
    if (chosen_resource != "wheat" && chosen_resource != "wood" && chosen_resource != "brick" && chosen_resource != "stone" && chosen_resource != "sheep")
        throw runtime_error("invalid input");
    player.inc_map(chosen_resource);
    std::cout << "choose another resource wheat/wood/brick/stone/sheep" << endl;
    std::string chosen;
    std::cin >> chosen;
    if (chosen != "wheat" && chosen != "wood" && chosen != "brick" && chosen != "stone" && chosen != "sheep")
        throw runtime_error("invalid input");
    player.inc_map(chosen);
 
}

Deck::Deck() {
    // Adding cards to the deck
    for (int i = 0; i < knightCardCount; ++i) {
        deck.push_back(new KnightCard());
    }
    for (int i = 0; i < 4; ++i) {
        deck.push_back(new VictoryPointCard());
    }
    for (int i = 0; i < 10; ++i) {
        deck.push_back(new MonopolyCard());
        deck.push_back(new RoadBuildingCard());
        deck.push_back(new YearOfPlentyCard());
    }

    // Shuffling the deck
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(deck.begin(), deck.end(), gen);
}
Deck::~Deck() {
                // Clean up allocated memory
    for (auto card : deck) {
        delete card;
    }
}

DevelopCard* Deck::drawCard() {
    //if (deck.empty()) {
    //    return nullptr;
    //}

    DevelopCard* drawnCard = deck.back();
    deck.pop_back();
    return drawnCard;
}