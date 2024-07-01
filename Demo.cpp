/**
 * Demo file for Ex3.
 *
 */
#include <iostream>
#include <stdexcept>
#include <vector>
#include "catan.hpp"
#include "player.hpp"
#include "board.hpp"
#include "hexagon.hpp"
#include "print.hpp"
using namespace std;
using namespace ariel;

int main()
{   
	Player p1("Amit");
	Player p2("Yossi");
	Player p3("Dana");
	Catan catan(p1, p2, p3);
	Board& board = catan.getBoard();
	Deck& deck = catan.getDeck();
	catan.ChooseStartingPlayer();
	//p1 set
	try {
			 p1.placeSettelemnt(5, board);
		     p1.placeRoad(8, board); 
			 catan.bring_player_resorese(5,p1);
		     p1.placeSettelemnt(11, board);
			 p1.placeRoad(11, board);
			 catan.bring_player_resorese(11, p1);
			 p1.endTurn();
	}
	catch (const std::exception& e)
	{
		    cout << e.what() << endl;
	}
	//p2 set
	try {
		p2.placeSettelemnt(40, board);
		p2.placeRoad(53, board);
		catan.bring_player_resorese(40, p2);
		p2.placeSettelemnt(15, board);
		p2.placeRoad(15, board);
		catan.bring_player_resorese(15, p2);
		p2.endTurn();
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
	//p3 set
	try {
		p3.placeSettelemnt(30, board);
		p3.placeRoad(46, board);
		catan.bring_player_resorese(30, p3);
		p3.placeSettelemnt(44, board);
		p3.placeRoad(56, board);
		catan.bring_player_resorese(44, p3);
		p3.endTurn();
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
	//print
    board.print_board();
	p1.print_player();
	p2.print_player();
	p3.print_player();

	//p1 p2 p3 roll dices
	try {
		int res=p1.rollTwoDice(board);
		cout << "cubes: " << res << endl;
		catan.round(res);
		p1.endTurn();
		res = p2.rollTwoDice(board);
		cout << "cubes: " << res << endl;
		catan.round(res);
		p2.endTurn();
		res=p3.rollTwoDice(board);
		cout << "cubes: " << res << endl;
		p3.endTurn();
		
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
	try {
		int res = p1.rollTwoDice(board);
		cout << "cubes: " << res << endl;
		catan.round(res);
		p1.endTurn();
		res = p2.rollTwoDice(board);
		cout << "cubes: " << res << endl;
		catan.round(res);
		p2.endTurn();
		res = p3.rollTwoDice(board);
		cout << "cubes: " << res << endl;
		p3.endTurn();

	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
		
	
	//print
	cout << "print players after rolls" << endl;
	cout << endl;
	p1.print_player();
	p2.print_player();
	p3.print_player();

	//p1 trade
	try {
		int res = p1.rollTwoDice(board);
		cout << "cubes: " << res << endl;
		catan.round(res);
		cout << "p1 trades 1 stone for 1 sheep with p2." << endl;
		p1.trade(p2, "stone", "sheep", 1, 1); 
		p1.print_player();
		p2.print_player();
		p3.print_player();
		p1.endTurn();
		res = p2.rollTwoDice(board);
		cout << "cubes: " << res << endl;
		catan.round(res);
		p2.endTurn();
		res = p3.rollTwoDice(board);
		cout << "cubes: " << res << endl;
		catan.round(res);
		p3.buyDevelopmentCard(deck);

		p1.print_player();
		p2.print_player();
		p3.print_player();

		p3.use_card(catan, board);
		/*p3.endTurn();*/

	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
	/*board.print_board();*/
	p1.print_player();
	p2.print_player();
	p3.print_player();
	catan.printWinner();
	
	/*try {
		int res = p2.rollTwoDice(board);
		cout << "cubes: " << res << endl;
		catan.round(res);
		p2.placeRoad(49, board);
		p2.placeSettelemnt(33,board);
		p2.print_player();
		board.print_board();
		p2.endTurn();

	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}*/

	
   // Player p1("Amit");
   // Player p2("Yossi");
   // Player p3("Dana");
   // Catan catan(p1, p2, p3);
   // // Starting of the game. Every player places two settlements and two roads.
   // catan.ChooseStartingPlayer();   // should print the name of the starting player, assume it is Amit.
  
   // Board& board = catan.getBoard(); // get the board of the game.
   ///* board.print_board();*/

   // /*p1.print_player();*/
   // /*p1.print_player();*/
   // try {
   //     p1.placeSettelemnt(5, board);
   // }
   // catch (const std::exception& e)
   // {
   //    cout << e.what() << endl;
   // }
   // /*p1.print_player();*/
   // try {
   //     p1.placeRoad(8, board);
   //     /*p1.print_player();*/
   //     p1.placeRoad(11, board);
   //     /*p1.print_player();*/
   //     p1.placeSettelemnt(11, board);
   //     p1.print_player();
   //     p1.rollTwoDice(board);
   //     catan.round();
   //     p1.print_player();
   // }
   // catch (const std::exception& e)
   // {
   //     cout << e.what() << endl;
   // }
   // board.print_board();
   // //vector<string> places = { "Agricultural Land", "Desert" };
   // //vector<int> placesNum = { 3, 4 };
   // //p1.placeSettelemnt(places, placesNum, board);
   // //p1.placeRoad(places, placesNum, board); // p1 chooses Forest, hills, Agricultural Land, Desert with numbers 5, 6, 3, 4.

   // //vector<string> places = { "Mountains", "Pasture Land" };
   // //vector<int> placesNum = { 4, 9 };
   // //p2.placeSettelemnt(places, placesNum, board);
   // //p2.placeRoad(places, placesNum, board);
   // //try
   // //{
   // //    p3.placeSettelemnt(places, placesNum, board); // p3 tries to place a settlement in the same location as p2.
   // //}
   // //catch (const std::exception& e)
   // //{
   // //    cout << e.what() << endl;
   // //}
   // //vector<string> places = { "Forest", "Pasture Land" };
   // //vector<int> placesNum = { 5, 9 };
   // //p2.placeSettelemnt(places, placesNum, board);
   // //p2.placeRoad(places, placesNum, board); // p2 chooses Mountains, Pasture Land, and Forest with numbers 4, 9, 5.

   // //vector<string> places = { "Mountains", "Pasture Land" };
   // //vector<int> placesNum = { 3, 8 };
   // //p3.placeSettelemnt(places, placesNum, board);
   // //p3.placeRoad(places, placesNum, board);
   // //vector<string> places = { "Agricultural Land", "Pasture Land" };
   // //vector<int> placesNum = { 3, 9 };
   // //p3.placeSettelemnt(places, placesNum, board);
   // //p3.placeRoad(places, placesNum, board); // p3 chooses Mountains, Pasture Land, Agricultural Land, Pasture Land with numbers 3, 8, 3, 9.

   // //// p1 has wood,bricks, and wheat, p2 has wood, ore, and wool, p3 has ore, wool, wheat.
   // int dice = p1.rollTwoDice(board);
   // cout << dice;
   // // Lets say it's print 4. Then, p2 gets ore from the mountations.
   // //p1.placeRoad({ "Forest", "Hills" }, { 5, 6 }, board); // p1 continues to build a road.
   // p1.endTurn();                                     // p1 ends his turn.

   // //p2.rollDice(); // Lets say it's print 9. Then, p3 gets wool from the Pasture Land, p2 gets wool from the Pasture Land.
   // //p2.endTurn();  // p2 ends his turn.

   // //p3.rollDice(); // Lets say it's print 3. Then, p3 gets wheat from the Agricultural Land and Ore from the Mountains, p1 gets wheat from the Agricultural Land.
   // //p3.endTurn();  // p3 ends his turn.

   // //try
   // //{
   // //    p2.rollDice(); // p2 tries to roll the dice again, but it's not his turn.
   // //}
   // //catch (const std::exception& e)
   // //{
   // //    cout << e.what() << endl;
   // //}

   // //p1.rollDice();   
   // 
   // // Lets say it's print 6. Then, p1 gets bricks from the hills.
   // cout << "before trade" << endl;
   // p1.print_player();
   // cout << endl;
   // p2.print_player();
   // try {
   //     p1.trade(p2, "stone", "sheep", 1, 1); // p1 trades 1 wood for 1 brick with p2.
   // }
   // catch (const std::exception& e)
   // {
   //     cout << e.what() << endl;
   // }
   // cout << "after" << endl;
   // p1.print_player();
   // cout << endl;
   // p2.print_player();

   // //p1.endTurn();                        // p1 ends his turn.

   // //p2.rollDice();
   // // Lets say it's print 9. Then, p3 gets wool from the Pasture Land, p2 gets wool from the Pasture Land.
   // Deck& deck = catan.getDeck();
   // p2.buyDevelopmentCard(deck); // p2 buys a development card. Lets say it is a bonus points card.
   // p2.use_card(catan,board);
   // //p2.endTurn();            // p2 ends his turn.

   // //p1.printPoints(); // p1 has 2 points because it has two settelments.
   // //p2.printPoints(); // p2 has 3 points because it has two settelments and a bonus points card.
   // //p3.printPoints(); // p3 has 2 points because it has two settelments.

   // // // Should print None because no player reached 10 points.
   return 0;
}