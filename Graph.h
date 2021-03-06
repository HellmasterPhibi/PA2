/* 
 * File:   Graph.h
 * Author: hell
 *
 * Created on 31. květen 2016, 17:20
 */

#ifndef GRAPH_H
#define	GRAPH_H

#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <climits>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <stdint.h>

using namespace std;
class Graph {
public:
    Graph();
    Graph(const Graph& orig);
    virtual ~Graph();
    virtual void print(ofstream&) = 0;
    struct TCathegory{
        TCathegory(string na, int nu):name(na),rank(nu){};
        string name;
        int rank;
    };
protected:
    vector<TCathegory> cathegories;
};

#endif	/* GRAPH_H */

