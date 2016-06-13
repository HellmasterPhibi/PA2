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
#include <math.h>

#define PI 3.14159265

using namespace std;
class Graph {
public:
    Graph( ifstream& infile, int col, int col2,  vector<char>& filling);
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
    void setFillings();
    void printAxisY(int i,ofstream& out)const;
    vector<TCathegory> cathegories;
    vector<string> cathegoryNames;
    int height;
    int column1;
    int column2;
    int max;
    int min;
    int maxRank;
    int digits(int) const;
    double round(double d);
    int roundInt(int input) const;
    vector<char> fill;
};

#endif	/* GRAPH_H */

