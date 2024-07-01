#include <gtest/gtest.h>
#include "player.hpp"
#include "board.hpp"
#include "develope_card.hpp"
#include "catan.hpp"

using namespace ariel;

// בדיקת יצירת שחקן
TEST(PlayerTest, CreatePlayer) {
    cout<<"test1";
    Player p("Amit");
    EXPECT_EQ(p.get_name(), "Amit");
    EXPECT_EQ(p.get_points(), 0);
    EXPECT_EQ(p.get_source_card().at("wheat"), 2);
    EXPECT_EQ(p.get_source_card().at("wood"), 4);
    EXPECT_EQ(p.get_source_card().at("brick"), 4);
    EXPECT_EQ(p.get_source_card().at("stone"), 0);
    EXPECT_EQ(p.get_source_card().at("sheep"), 2);
}

//two building in same edge
TEST(PlayerTest, Build) {
    cout<<"test2";
    Player p("Amit");
    Board board;
    EXPECT_NO_THROW(p.placeSettelemnt(1,board));
    EXPECT_THROW(p.placeSettelemnt(0,board),std::runtime_error);
}

//not enoph money
TEST(PlayerTest, Buydevelop){
    Player p("Amit");
    Board board;
    Deck deck;
    EXPECT_THROW(p.buyDevelopmentCard(deck),std::runtime_error);
}

TEST(PlayerTest, Trade_ValidTurnValidTrade) {
  Player p1("Reut");
  Player p2("Moshe");
  p1.set_turn(true);

  // Perform the trade
  p1.trade(p2, "wheat", "sheep", 1, 2);  // Reut trades 1 wheat for 2 sheep

  // Verify resource changes
  EXPECT_EQ(p1.get_source_card().at("wheat"), 1);
  EXPECT_EQ(p1.get_source_card().at("sheep"), 4);
  EXPECT_EQ(p2.get_source_card().at("wheat"), 3);
  EXPECT_EQ(p2.get_source_card().at("sheep"), 0);
}

//after build in first time player should get res
TEST(PlayerTest, build_res){
    Player p1("Amit");
	Player p2("Yossi");
	Player p3("Dana");
	Catan catan(p1, p2, p3);
	Board& board = catan.getBoard();
    catan.ChooseStartingPlayer();
    p1.placeSettelemnt(5, board);
	p1.placeRoad(8, board); 
	catan.bring_player_resorese(5,p1);
	p1.placeSettelemnt(11, board);
	p1.placeRoad(11, board);
	catan.bring_player_resorese(11, p1);
    EXPECT_EQ(p1.get_source_card().at("wheat"), 1);
    EXPECT_EQ(p1.get_source_card().at("wood"), 0);
    EXPECT_EQ(p1.get_source_card().at("brick"), 0);
    EXPECT_EQ(p1.get_source_card().at("stone"), 1);
    EXPECT_EQ(p1.get_source_card().at("sheep"), 0);
}

//get res after roll
TEST(PlayerTest, roll){
    Player p1("Amit");
	Player p2("Yossi");
	Player p3("Dana");
	Catan catan(p1, p2, p3);
	Board& board = catan.getBoard();
    catan.ChooseStartingPlayer();
    p1.placeSettelemnt(5, board);
	p1.placeRoad(8, board); 
	catan.bring_player_resorese(5,p1);
	p1.placeSettelemnt(11, board);
	p1.placeRoad(11, board);
	catan.bring_player_resorese(11, p1);
    //assume the cubes 12
    catan.round(12);
    EXPECT_EQ(p1.get_source_card().at("wheat"), 2);
    EXPECT_EQ(p1.get_source_card().at("wood"), 0);
    EXPECT_EQ(p1.get_source_card().at("brick"), 0);
    EXPECT_EQ(p1.get_source_card().at("stone"), 1);
    EXPECT_EQ(p1.get_source_card().at("sheep"), 0);
}

//get res after roll if player have city
TEST(player, roll2) {
  Player p1("Amit");
  Player p2("Yossi");
  Player p3("Dana");
  Catan catan(p1, p2, p3);
  Board& board = catan.getBoard();
  catan.ChooseStartingPlayer();
  p1.placeSettelemnt(5, board);
  p1.placeRoad(8, board); 
  catan.bring_player_resorese(5,p1);
  p1.placeSettelemnt(11, board);
  p1.placeRoad(11, board);
  catan.bring_player_resorese(11, p1);
  p1.inc_map("stone");
  p1.inc_map("stone");
  p1.inc_map("stone");
  p1.inc_map("wheat");
  p1.inc_map("wheat");
  p1.placeCity(5,board);
  //assume the cubes 12
    catan.round(12);
    EXPECT_EQ(p1.get_source_card().at("wheat"), 3);
    EXPECT_EQ(p1.get_source_card().at("wood"), 0);
    EXPECT_EQ(p1.get_source_card().at("brick"), 0);
    EXPECT_EQ(p1.get_source_card().at("stone"), 1);
    EXPECT_EQ(p1.get_source_card().at("sheep"), 0);
}



//player try to play not his turn
TEST(PlayerTest, turn){
    Player p1("Amit");
	Player p2("Yossi");
	Player p3("Dana");
	Catan catan(p1, p2, p3);
	Board& board = catan.getBoard();
    catan.ChooseStartingPlayer();
    EXPECT_THROW(p2.placeSettelemnt(1,board),std::runtime_error);
}

//player try to play in his turn
TEST(PlayerTest, turn2){
    Player p1("Amit");
	Player p2("Yossi");
	Player p3("Dana");
	Catan catan(p1, p2, p3);
	Board& board = catan.getBoard();
    catan.ChooseStartingPlayer();
    p1.endTurn();
    EXPECT_NO_THROW(p2.placeSettelemnt(1,board));
}

//check there are 3 knights and 4 victorypoint in the deck
TEST(DeckTest, ThreeKnights) {
  Deck deck;

  // Count the number of KnightCards in the deck
  int knight_count = 0;
  int victory_count =0;
  for(int i=0;i<37;i++){
        DevelopCard* card= deck.drawCard();
        if (card->getType()=="Knight") {
            knight_count++;
        }
        else if(card->getType()=="VictoryPoint"){
             victory_count++;
        }
  }

  EXPECT_EQ(knight_count, 3);
  EXPECT_EQ(victory_count, 4);
}


TEST(Develop, VictoryPointCard) {
  Player p1("mr.test");
  Board board;
  std::vector<Player*> players;
  players.push_back(&p1);

  VictoryPointCard card;
  card.use(p1, players, board);
  EXPECT_EQ(p1.get_points(), 1);
}

//if there are 3 knights 2 points 
TEST(Develop, knights) {
  Player p1("mr.test");
  Board board;
  std::vector<Player*> players;
  players.push_back(&p1);
  KnightCard card1;
  card1.use(p1, players, board);
  KnightCard card2;
  card2.use(p1, players, board);
  KnightCard card3;
  card3.use(p1, players, board);
  EXPECT_EQ(p1.get_points(), 2);
}

//check if upgarte to city bring 2 points
TEST(player, cityPoints) {
  Player p1("Amit");
  Player p2("Yossi");
  Player p3("Dana");
  Catan catan(p1, p2, p3);
  Board& board = catan.getBoard();
  catan.ChooseStartingPlayer();
  p1.placeSettelemnt(0,board);
  EXPECT_EQ(p1.get_points(), 1);
  p1.inc_map("stone");
  p1.inc_map("stone");
  p1.inc_map("stone");
  p1.inc_map("wheat");
  p1.inc_map("wheat");
  p1.placeCity(0,board);
  EXPECT_EQ(p1.get_points(), 2);
}


int main1(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}