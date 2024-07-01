#pragma once
#include <string>
#include <vector>

#include "Vertex.hpp"
#include <iostream>
#include <map>


using namespace std;
using namespace ariel;
namespace ariel {
	class Hexagon {
		int id;
		int num;
		string resource;
		vector<Vertex*> vertexs;

	public:
		static int loop;
		Hexagon(int id, int num, string resource, vector<Vertex*> vertexs);
		static string print(vector<Hexagon> hexagons);
		
		vector<Vertex*>& get_vertex() {
			return vertexs;
		}
		int get_num() {
			return num;
		}
		string get_res() {
			return resource;
		}
		
	};
	
}

