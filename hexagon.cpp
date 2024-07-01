#include "hexagon.hpp"
#include <stdexcept>
#include <time.h>
using namespace ariel;
int Hexagon::loop = 0;

Hexagon::Hexagon(int id, int num, string resource, vector<Vertex*> vertexs) {
	this->id = id;
	this->num = num;
	this->resource = resource;
	this->vertexs = vertexs;

}
string Hexagon::print(vector<Hexagon> hexagons) {
	string source = hexagons[loop].resource;
	string num_str = to_string(hexagons[loop].num);
	if (num_str.length() == 1)
		num_str.append(" ");
	if (source.length() == 4)
		source.append(" ");
	loop++;
	return source + " " + num_str;
}