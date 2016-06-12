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
#include <sstream>
#include <queue>
#include <stdint.h>

using namespace std;
class Graph {
public:
    Graph( ifstream& infile, int col);
    virtual ~Graph();
    virtual void print(ofstream&) = 0;
    void setRanks();
    struct TCathegory{
        TCathegory(string na, int nu):name(na),count(nu){};
        string name;
        int count;
        int rank;
    };
protected:
    void printAxisY(int i,ofstream& out)const;
    vector<TCathegory> cathegories;
    vector<string> cathegoryNames;
    int height;
    int column;
    int max;
    int min;
    int digits(int) const;
    double round(double d);
};

#endif	/* GRAPH_H */

