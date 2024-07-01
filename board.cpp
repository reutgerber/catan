#include "board.hpp"
#include "hexagon.hpp"
#include <iostream>
using namespace std;
using namespace ariel;

Board::Board() {

    for (int i = 0; i < num_edge; i++) {
        edges.push_back(Edge(i));
    }

    for (int i = 0; i < num_ver; i++) {
        vertexs.push_back(Vertex(i));
    }

    edges[0].add_neighbours({ &edges[1], &edges[2] }, &vertexs[0], &vertexs[1]);
    edges[1].add_neighbours({ &edges[3], &edges[6] }, &vertexs[0], &vertexs[3]);
    edges[2].add_neighbours({ &edges[4], &edges[7] }, &vertexs[1], &vertexs[4]);
    edges[3].add_neighbours({ &edges[5], &edges[6] }, &vertexs[2], &vertexs[3]);
    edges[4].add_neighbours({ &edges[7], &edges[8] }, &vertexs[4], &vertexs[5]);
    edges[5].add_neighbours({ &edges[9], &edges[13] }, &vertexs[2], &vertexs[7]);
    edges[6].add_neighbours({ &edges[14], &edges[10] }, &vertexs[3], &vertexs[8]);
    edges[7].add_neighbours({ &edges[10], &edges[15] }, &vertexs[4], &vertexs[9]);
    edges[8].add_neighbours({ &edges[16], &edges[11] }, &vertexs[5], &vertexs[10]);
    edges[9].add_neighbours({ &edges[12], &edges[13] }, &vertexs[6], &vertexs[7]);
    edges[10].add_neighbours({ &edges[14],&edges[15] }, &vertexs[8], &vertexs[9]);
    edges[11].add_neighbours({ &edges[16], &edges[17] }, &vertexs[10], &vertexs[11]);
    edges[12].add_neighbours({ &edges[20] }, &vertexs[6], &vertexs[12]);
    edges[13].add_neighbours({ &edges[21], &edges[18] }, &vertexs[7], &vertexs[13]);
    edges[14].add_neighbours({ &edges[18], &edges[22] }, &vertexs[8], &vertexs[14]);
    edges[15].add_neighbours({ &edges[13], &edges[19] }, &vertexs[9], &vertexs[15]);
    edges[16].add_neighbours({ &edges[19], &edges[24] }, &vertexs[10], &vertexs[16]);
    edges[17].add_neighbours({ &edges[25] }, &vertexs[11], &vertexs[17]);
    edges[18].add_neighbours({ &edges[21], &edges[22] }, &vertexs[13], &vertexs[14]);
    edges[19].add_neighbours({ &edges[23], &edges[24] }, &vertexs[15], &vertexs[16]);
    edges[20].add_neighbours({ &edges[29], &edges[26] }, &vertexs[12], &vertexs[18]);
    edges[21].add_neighbours({ &edges[26], &edges[30] }, &vertexs[13], &vertexs[19]);
    edges[22].add_neighbours({ &edges[31], &edges[27] }, &vertexs[14], &vertexs[20]);
    edges[23].add_neighbours({ &edges[27], &edges[32] }, &vertexs[15], &vertexs[21]);
    edges[24].add_neighbours({ &edges[28], &edges[33] }, &vertexs[16], &vertexs[22]);
    edges[25].add_neighbours({ &edges[28], &edges[34] }, &vertexs[17], &vertexs[23]);
    edges[26].add_neighbours({ &edges[29], &edges[30] }, &vertexs[18], &vertexs[19]);
    edges[27].add_neighbours({ &edges[31], &edges[32] }, &vertexs[20], &vertexs[21]);
    edges[28].add_neighbours({ &edges[33], &edges[34] }, &vertexs[22], &vertexs[23]);
    edges[29].add_neighbours({ &edges[37] }, &vertexs[18], &vertexs[24]);
    edges[30].add_neighbours({ &edges[38], &edges[35] }, &vertexs[19], &vertexs[25]);
    edges[31].add_neighbours({ &edges[35], &edges[39] }, &vertexs[20], &vertexs[26]);
    edges[32].add_neighbours({ &edges[40], &edges[36] }, &vertexs[21], &vertexs[27]);
    edges[33].add_neighbours({ &edges[36], &edges[41] }, &vertexs[22], &vertexs[28]);
    edges[34].add_neighbours({ &edges[42] }, &vertexs[23], &vertexs[29]);
    edges[35].add_neighbours({ &edges[38], &edges[39] }, &vertexs[25], &vertexs[26]);
    edges[36].add_neighbours({ &edges[40], &edges[41] }, &vertexs[27], &vertexs[28]);
    edges[37].add_neighbours({ &edges[43], &edges[46] }, &vertexs[24], &vertexs[30]);
    edges[38].add_neighbours({ &edges[43], &edges[47] }, &vertexs[25], &vertexs[31]);
    edges[39].add_neighbours({ &edges[44], &edges[48] }, &vertexs[26], &vertexs[32]);
    edges[40].add_neighbours({ &edges[44], &edges[49] }, &vertexs[27], &vertexs[33]);
    edges[41].add_neighbours({ &edges[50], &edges[45] }, &vertexs[28], &vertexs[34]);
    edges[42].add_neighbours({ &edges[45], &edges[51] }, &vertexs[29], &vertexs[35]);
    edges[43].add_neighbours({ &edges[46], &edges[47] }, &vertexs[30], &vertexs[31]);
    edges[44].add_neighbours({ &edges[48], &edges[49] }, &vertexs[32], &vertexs[33]);
    edges[45].add_neighbours({ &edges[50], &edges[51] }, &vertexs[34], &vertexs[35]);
    edges[46].add_neighbours({ &edges[54] }, &vertexs[30], &vertexs[36]);
    edges[47].add_neighbours({ &edges[55], &edges[52] }, &vertexs[31], &vertexs[37]);
    edges[48].add_neighbours({ &edges[52], &edges[56] }, &vertexs[32], &vertexs[38]);
    edges[49].add_neighbours({ &edges[57], &edges[53] }, &vertexs[33], &vertexs[39]);
    edges[50].add_neighbours({ &edges[53], &edges[58] }, &vertexs[34], &vertexs[40]);
    edges[51].add_neighbours({ &edges[59] }, &vertexs[35], &vertexs[41]);
    edges[52].add_neighbours({ &edges[55], &edges[56] }, &vertexs[37], &vertexs[38]);
    edges[53].add_neighbours({ &edges[57], &edges[58] }, &vertexs[39], &vertexs[40]);
    edges[54].add_neighbours({ &edges[60] }, &vertexs[36], &vertexs[42]);
    edges[55].add_neighbours({ &edges[60], &edges[63] }, &vertexs[37], &vertexs[43]);
    edges[56].add_neighbours({ &edges[64], &edges[61] }, &vertexs[38], &vertexs[44]);
    edges[57].add_neighbours({ &edges[61], &edges[65] }, &vertexs[39], &vertexs[45]);
    edges[58].add_neighbours({ &edges[66], &edges[62] }, &vertexs[40], &vertexs[46]);
    edges[59].add_neighbours({ &edges[62] }, &vertexs[41], &vertexs[47]);
    edges[60].add_neighbours({ &edges[63] }, &vertexs[42], &vertexs[43]);
    edges[61].add_neighbours({ &edges[64], &edges[65] }, &vertexs[44], &vertexs[45]);
    edges[62].add_neighbours({ &edges[66] }, &vertexs[46], &vertexs[47]);
    edges[63].add_neighbours({ &edges[67] }, &vertexs[43], &vertexs[48]);
    edges[64].add_neighbours({ &edges[67], &edges[69] }, &vertexs[44], &vertexs[49]);
    edges[65].add_neighbours({ &edges[68], &edges[70] }, &vertexs[45], &vertexs[50]);
    edges[66].add_neighbours({ &edges[68] }, &vertexs[46], &vertexs[51]);
    edges[67].add_neighbours({ &edges[69] }, &vertexs[48], &vertexs[49]);
    edges[68].add_neighbours({ &edges[70] }, &vertexs[50], &vertexs[51]);
    edges[69].add_neighbours({ &edges[71] }, &vertexs[49], &vertexs[52]);
    edges[70].add_neighbours({ &edges[71] }, &vertexs[50], &vertexs[53]);
    edges[71].add_neighbours({ &edges[69], &edges[70] }, &vertexs[52], &vertexs[53]);




    vertexs[0].add_neibours({ &vertexs[1], &vertexs[3] });
    vertexs[1].add_neibours({ &vertexs[0], &vertexs[4] });
    vertexs[2].add_neibours({ &vertexs[3], &vertexs[7] });
    vertexs[3].add_neibours({ &vertexs[0], &vertexs[2], &vertexs[8] });
    vertexs[4].add_neibours({ &vertexs[1], &vertexs[5], &vertexs[9] });
    vertexs[5].add_neibours({ &vertexs[4], &vertexs[10] });
    vertexs[6].add_neibours({ &vertexs[7], &vertexs[12] });
    vertexs[7].add_neibours({ &vertexs[2], &vertexs[6], &vertexs[13] });
    vertexs[8].add_neibours({ &vertexs[3], &vertexs[9], &vertexs[14] });
    vertexs[9].add_neibours({ &vertexs[4], &vertexs[8], &vertexs[15] });
    vertexs[10].add_neibours({ &vertexs[5], &vertexs[11], &vertexs[16] });
    vertexs[11].add_neibours({ &vertexs[10], &vertexs[17] });
    vertexs[12].add_neibours({ &vertexs[6], &vertexs[18] });
    vertexs[13].add_neibours({ &vertexs[7], &vertexs[14], &vertexs[19] });
    vertexs[14].add_neibours({ &vertexs[8], &vertexs[13], &vertexs[20] });
    vertexs[15].add_neibours({ &vertexs[9], &vertexs[16], &vertexs[21] });
    vertexs[16].add_neibours({ &vertexs[15], &vertexs[10], &vertexs[22] });
    vertexs[17].add_neibours({ &vertexs[11], &vertexs[23] });
    vertexs[18].add_neibours({ &vertexs[12], &vertexs[19], &vertexs[24] });
    vertexs[19].add_neibours({ &vertexs[13], &vertexs[18], &vertexs[25] });
    vertexs[20].add_neibours({ &vertexs[14], &vertexs[21], &vertexs[26] });
    vertexs[21].add_neibours({ &vertexs[15], &vertexs[20], &vertexs[27] });
    vertexs[22].add_neibours({ &vertexs[16], &vertexs[23], &vertexs[28] });
    vertexs[23].add_neibours({ &vertexs[22], &vertexs[17], &vertexs[29] });
    vertexs[24].add_neibours({ &vertexs[18], &vertexs[30] });
    vertexs[25].add_neibours({ &vertexs[19], &vertexs[26], &vertexs[31] });
    vertexs[26].add_neibours({ &vertexs[20], &vertexs[25], &vertexs[32] });
    vertexs[27].add_neibours({ &vertexs[21], &vertexs[28], &vertexs[33] });
    vertexs[28].add_neibours({ &vertexs[27], &vertexs[22], &vertexs[34] });
    vertexs[29].add_neibours({ &vertexs[23], &vertexs[35] });
    vertexs[30].add_neibours({ &vertexs[24], &vertexs[31], &vertexs[36] });
    vertexs[31].add_neibours({ &vertexs[25], &vertexs[30], &vertexs[37] });
    vertexs[32].add_neibours({ &vertexs[26], &vertexs[33], &vertexs[38] });
    vertexs[33].add_neibours({ &vertexs[27], &vertexs[32], &vertexs[39] });
    vertexs[34].add_neibours({ &vertexs[28], &vertexs[35], &vertexs[40] });
    vertexs[35].add_neibours({ &vertexs[34], &vertexs[29], &vertexs[41] });
    vertexs[36].add_neibours({ &vertexs[30], &vertexs[42] });
    vertexs[37].add_neibours({ &vertexs[31], &vertexs[38], &vertexs[43] });
    vertexs[38].add_neibours({ &vertexs[32], &vertexs[37], &vertexs[44] });
    vertexs[39].add_neibours({ &vertexs[33], &vertexs[40], &vertexs[45] });
    vertexs[40].add_neibours({ &vertexs[39], &vertexs[34], &vertexs[46] });
    vertexs[41].add_neibours({ &vertexs[35], &vertexs[47] });
    vertexs[42].add_neibours({ &vertexs[36], &vertexs[43] });
    vertexs[43].add_neibours({ &vertexs[42], &vertexs[37], &vertexs[48] });
    vertexs[44].add_neibours({ &vertexs[38], &vertexs[45], &vertexs[49] });
    vertexs[45].add_neibours({ &vertexs[44], &vertexs[39], &vertexs[50] });
    vertexs[46].add_neibours({ &vertexs[40], &vertexs[47], &vertexs[51] });
    vertexs[47].add_neibours({ &vertexs[46], &vertexs[41] });
    vertexs[48].add_neibours({ &vertexs[43], &vertexs[49] });
    vertexs[49].add_neibours({ &vertexs[48], &vertexs[44], &vertexs[52] });
    vertexs[50].add_neibours({ &vertexs[45], &vertexs[51], &vertexs[53] });
    vertexs[51].add_neibours({ &vertexs[50], &vertexs[46] });
    vertexs[52].add_neibours({ &vertexs[49], &vertexs[53] });
    vertexs[53].add_neibours({ &vertexs[52], &vertexs[50] });



    hexagons.push_back(Hexagon(0, 9, "wheat", { &vertexs[0],&vertexs[1],&vertexs[3],&vertexs[4],&vertexs[8],&vertexs[9] }));
    hexagons.push_back(Hexagon(1, 8, "wood", { &vertexs[2],&vertexs[3],&vertexs[7],&vertexs[8],&vertexs[13],&vertexs[14] }));
    hexagons.push_back(Hexagon(2, 12, "wheat", { &vertexs[4],&vertexs[5],&vertexs[9],&vertexs[10],&vertexs[15],&vertexs[16] }));
    hexagons.push_back(Hexagon(3, 5, "brick", { &vertexs[6],&vertexs[7],&vertexs[12],&vertexs[13],&vertexs[18],&vertexs[19] }));
    hexagons.push_back(Hexagon(4, 11, "wood", { &vertexs[8],&vertexs[9],&vertexs[14],&vertexs[15],&vertexs[20],&vertexs[21] }));
    hexagons.push_back(Hexagon(5, 10, "stone", { &vertexs[10],&vertexs[11],&vertexs[16],&vertexs[17],&vertexs[22],&vertexs[23] }));
    hexagons.push_back(Hexagon(6, 3, "stone", { &vertexs[13],&vertexs[14],&vertexs[19],&vertexs[20],&vertexs[25],&vertexs[26] }));
    hexagons.push_back(Hexagon(7, 6, "brick", { &vertexs[15],&vertexs[16],&vertexs[21],&vertexs[22],&vertexs[27],&vertexs[28] }));
    hexagons.push_back(Hexagon(8, 6, "wheat", { &vertexs[18],&vertexs[19],&vertexs[24],&vertexs[25],&vertexs[30],&vertexs[31] }));
    hexagons.push_back(Hexagon(9, 7, "desert", { &vertexs[20],&vertexs[21],&vertexs[26],&vertexs[27],&vertexs[32],&vertexs[33] }));
    hexagons.push_back(Hexagon(10, 2, "sheep", { &vertexs[22],&vertexs[23],&vertexs[28],&vertexs[29],&vertexs[34],&vertexs[35] }));
    hexagons.push_back(Hexagon(11, 4, "wheat", { &vertexs[25],&vertexs[26],&vertexs[31],&vertexs[32],&vertexs[37],&vertexs[38] }));
    hexagons.push_back(Hexagon(12, 4, "sheep", { &vertexs[27],&vertexs[28],&vertexs[33],&vertexs[34],&vertexs[39],&vertexs[40] }));
    hexagons.push_back(Hexagon(13, 11, "sheep", { &vertexs[30],&vertexs[31],&vertexs[36],&vertexs[37],&vertexs[42],&vertexs[43] }));
    hexagons.push_back(Hexagon(14, 3, "wood", { &vertexs[32],&vertexs[33],&vertexs[38],&vertexs[39],&vertexs[44],&vertexs[45] }));
    hexagons.push_back(Hexagon(15, 9, "wood", { &vertexs[34],&vertexs[35],&vertexs[40],&vertexs[41],&vertexs[46],&vertexs[47] }));
    hexagons.push_back(Hexagon(16, 5, "sheep", { &vertexs[37],&vertexs[38],&vertexs[43],&vertexs[44],&vertexs[48],&vertexs[49] }));
    hexagons.push_back(Hexagon(17, 10, "brick", { &vertexs[39],&vertexs[40],&vertexs[45],&vertexs[46],&vertexs[50],&vertexs[51] }));
    hexagons.push_back(Hexagon(18, 8, "stone", { &vertexs[44],&vertexs[45],&vertexs[49],&vertexs[50],&vertexs[52],&vertexs[53] }));

}

    