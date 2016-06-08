/* 
 * File:   main.cpp
 * Author: hell
 *
 * Created on 31. květen 2016, 14:36
 */

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
#include "Graph.h"
#include "BarPlot.h"
#include "LinePlot.h"

using namespace std;

int main(int argc, char** argv) {
    
    
    ofstream outfile;
    outfile.open("lineTest",  ios::out);
    if (outfile.fail()){ return false;}
    
    ifstream infile;
    infile.open("sells.csv",  ios::in);
    if (infile.fail()){ cout << "Cannot open file" << endl;}
    
    //BarPlot b(infile);
    //b.print(outfile);
    LinePlot l(infile);
    l.print(outfile);
    
    outfile.close();
    
    return 0;
}

