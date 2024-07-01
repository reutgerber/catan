#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "hexagon.hpp"
#include "Vertex.hpp"
#include "Edge.hpp"
#include "print.hpp"
using namespace std;
namespace ariel {
    class Board {
        vector<Hexagon> hexagons;
        vector<Vertex> vertexs;
        vector<Edge> edges;
       
     
    public:
       static const int num_ver = 54;
       static const int num_edge = 72;
       Board();

       void print_board() {
           Print p;
           p.print_row(hexagons,vertexs,edges);  
       }
        
       vector<Vertex>& get_vertexs() {
           return vertexs;
        }
       vector<Hexagon>& get_hexagons() {
           return hexagons;
       }
       vector<Edge>& get_edges() {
           return edges;
       }

    };

}



