#pragma once
#include <vector>
#include <string>


using namespace std;

namespace ariel {
	class Vertex
	{
	private:
		//player own this vertex
		int num_player;
		//city or village 1/2 points
		int points;

		string available;
		int id;		
		vector<Vertex*> neigbors;
		//by int to prevent from cycle
		vector<int> edge_nei;
	public:
		static int loop;
		Vertex(int id);
		
		~Vertex() {};
		void add_neibours(vector<Vertex*> neigbors) {
			this->neigbors = neigbors;
		}
		void add_edge_nei(int my_edge_nei) {
			edge_nei.push_back(my_edge_nei);
		}

		vector<int> get_edge_nei() {
			return edge_nei;
		}
		int get_id() {
			return id;
		}

		void set_available(string available, int num_player); 
		

		string get_available(){
			return available;
		}
		int get_num_player() {
			return num_player;
		}
		static string print(vector<Vertex> vertexs);
		

		vector<Vertex*> get_neighbors() {
			return neigbors;
		}

		int get_points() {
			return points;
		}

	};
}

