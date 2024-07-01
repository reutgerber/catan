#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Vertex.hpp"
using namespace std;
namespace ariel {
	class Edge
	{
	private:
		//player own this vertex
		int num_player;
		
		string available;
		int id;
		
		vector<Edge*> neighbors;
		vector<Vertex*> ver_nei;
		
	public:
		static int loop;

		Edge(int _id) {
			id = _id;
			available = to_string(id);
			num_player = -1;
			/*num_player = -1;*/
			/*cout << id << endl;*/
		}
		~Edge() {
		/*for (Vertex* v:ver_nei){
			delete(v);*/
		};
		
		void add_neighbours(vector<Edge*> neighbors, Vertex* v1, Vertex* v2);

		


		int get_id() {
			return id;
		}
		void set_available(string available, int num_player) {
			this->available = available + to_string(num_player);
			this->num_player = num_player;
			

		}
		string get_available() {
			return available;
		}

		static string print(vector<Edge> edges) {
			string available_cpy = edges[loop].available;
			if (available_cpy.length() == 1)
				available_cpy.append(" ");
			loop++;
			return available_cpy;
		}
		int get_num_player() {
			return num_player;
		}

		vector<Edge*>& get_neibours() {
			return neighbors;
		}
		vector<Vertex*>& get_ver_nei() {
			return ver_nei;
		}

	};
}
