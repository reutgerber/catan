#include "Edge.hpp"
using namespace ariel;
int Edge::loop = 0;
void Edge::add_neighbours(vector<Edge*> neighbors, Vertex* v1, Vertex* v2) {
	this->neighbors = neighbors;
	//���� ���� ���� ��� ����� �� ����
	for (Edge* neighbor : neighbors) {
		neighbor->neighbors.push_back(this);
	}
	this->ver_nei.push_back(v1);
	this->ver_nei.push_back(v2);
	
	//���� ���� �� ��������� ���������� ����� �� ����
	v1->add_edge_nei(this->id);
	v2->add_edge_nei(this->id);
}