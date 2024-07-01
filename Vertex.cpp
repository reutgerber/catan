#include "Vertex.hpp"

#include <stdexcept>
#include <time.h>
using namespace ariel;
int Vertex::loop = 0;

Vertex::Vertex(int id) {
	this->id = id;
	available = to_string(id);
	points = 0;
	num_player = -1;

}
void Vertex::set_available(string available, int num_player) {
	if (available == "v")
		this->points = 1;
	else
		this->points = 2;
	this->available = available + to_string(num_player);
	this->num_player = num_player;


}

string Vertex::print(vector<Vertex> vertexs) {
	string available_cpy = vertexs[loop].available;
	if (available_cpy.length() == 1)
		available_cpy.append(" ");
	loop++;
	return available_cpy;
}