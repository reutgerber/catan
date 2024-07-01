#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "hexagon.hpp"
#include "Vertex.hpp"
#include "Edge.hpp"
using namespace std;
namespace ariel {
	class Print
	{
	private:
		int num_hexs;
		string start_space;
		bool flag_revers;
		

	public:
		Print() {
			num_hexs = 1;
			start_space = "                                          ";
			flag_revers = false;
		}
		void print_row(vector<Hexagon> hexagons, vector<Vertex> vertexs, vector<Edge> edges) {
			for (int i = 0; i < 3; i++) {
				print2(hexagons, vertexs, edges);
				print3();
				print4(edges);
				print5();

			}
			
			for (int i = 0; i < 2; i++) {
				num_hexs = 2;
				print2_rev(hexagons, vertexs, edges);
				print3_rev();
				print4_rev(edges);
				print5_rev();
				num_hexs = 3;
				print2(hexagons, vertexs, edges);
				print3();
				print4(edges);
				print5();
				start_space = "             ";
			}
			num_hexs = 2;
			print2_rev(hexagons, vertexs, edges);
			print3_rev();
			print4_rev(edges);
			print5_rev();
			num_hexs = 3;
			print2(hexagons, vertexs, edges);
			num_hexs = 1;
			start_space = "                         ";
			print3_rev();
			print4_rev(edges);
			print5_rev();
			num_hexs = 2;
			print2(hexagons, vertexs, edges);
			num_hexs = 0;
			start_space = "                                       ";
			print3_rev();
			print4_rev(edges);
			print5_rev();
			num_hexs = 1;
			start_space = "                                          ";
			print2(hexagons, vertexs, edges);
		

		};

		void print2_rev(vector<Hexagon> hexagons, vector<Vertex> vertexs,vector<Edge> edges) {
			start_space = "          ";
			string ver_print = Vertex::print(vertexs);
			cout << start_space << ver_print;
			string source_board = Hexagon::print(hexagons);
			cout << "    " << source_board << "    ";
			print_ver(vertexs, edges);
			for (int i = 1; i < num_hexs; i++) {
				source_board = Hexagon::print(hexagons);
				cout << "    " << source_board << "    ";
				print_ver(vertexs, edges);
			}
			source_board = Hexagon::print(hexagons);
			
			ver_print = Vertex::print(vertexs);
			cout << "    " << source_board << "    " << ver_print << endl;
			start_space.append(" ");
		}

		void print_ver(vector<Vertex> vertexs, vector<Edge> edges) {
			string ver_print = Vertex::print(vertexs);
			cout << ver_print << "---"<< Edge::print(edges) << "---" << Vertex::print(vertexs);
		}
		
		void print2(vector<Hexagon> hexagons, vector<Vertex> vertexs, vector<Edge> edges) {
			cout << start_space;
			print_ver(vertexs,edges);
			for (int i = 1; i < num_hexs; i++) {
				/*cout << "            ";*/
				string source_board = Hexagon::print(hexagons);
				cout << "    "<< source_board<<"    ";
				print_ver(vertexs, edges);
			}		
			cout << start_space << endl;

			if (num_hexs < 4) {
				start_space.erase(start_space.length() - 1);
			}
			else {
				start_space.append(" ");
			}
		}

		void print_h3rev() {
			cout << "\\" << "               " << "/";
		}
		void print3_rev() {
			/*cout <<start_space<< "\\" << "          ";*/
			cout << start_space;
			print_h3rev();
			for (int i = 1; i < num_hexs+1; i++) {
				/*print_h3();*/
				cout << "           ";
				/*print_h3();*/
				print_h3rev();
			}
			/*cout << "          " << "/" << endl;*/
			cout << start_space << endl;
			start_space.append(" ");
		}

		void print_h3() {
			cout << "/" << "           " << "\\" ;
		}

		void print3() {
			cout << start_space;
			print_h3();
			for (int i = 1; i < num_hexs; i++) {
				cout << "               ";
				print_h3();
			}
			cout << start_space << endl;
			
			if (num_hexs < 4) {
				start_space.erase(start_space.length() - 1);
			}
			else {
				start_space.append(" ");
			}
		}
		void print_h4rev(vector<Edge> edges) {
			string edge_board = Edge::print(edges);
			cout << edge_board << "            " << Edge::print(edges);
		}
		void print4_rev(vector<Edge> edges) {
	
			cout << start_space;
			print_h4rev(edges);
			for (int i = 1; i < num_hexs+1; i++) {
				cout << "            ";
				print_h4rev(edges);
			}

			/*cout << "        " << "e" << endl;*/
			cout << start_space << endl;
			start_space.append(" ");

		}

		void print_h4(vector<Edge> edges) {
			string edge_board = Edge::print(edges);
			cout << edge_board << "            " << Edge::print(edges);
		}
		void print4(vector<Edge> edges) {
			cout << start_space;
			print_h4(edges);
			for (int i = 1; i < num_hexs; i++) {
				cout << "            ";
				print_h4(edges);
			}

			cout << start_space << endl;
			
			if (num_hexs < 4) {
				start_space.erase(start_space.length() - 1);
			}
			else {
				start_space.append(" ");
			}
		}
		void print_h5rev() {
			cout << "\\" << "           " << "/";
		}
		void print5_rev() {
			/*cout<<start_space<<"\\"<< "      ";*/
			cout << start_space;
			print_h5rev();
			for (int i = 1; i < num_hexs+1; i++) {
				cout << "               ";
				print_h5rev();
			}
			cout << start_space << endl;
			start_space.append(" ");
			
		}
		void print_h5() {
			cout << "/" << "               " << "\\";

		}
		void print5() {
			cout << start_space;
			print_h5();
			for (int i = 1; i < num_hexs; i++) {
				cout << "           ";
				print_h5();
			}
			cout << start_space << endl;
			if (num_hexs < 4) {
				start_space.erase(start_space.length() - 11);
				num_hexs++;
			}
			else {
				start_space.append("      ");
				num_hexs--;
			}

		}

	};

}