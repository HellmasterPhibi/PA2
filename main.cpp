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

using namespace std;

int main(int argc, char** argv) {
    
    
    ofstream outfile;
    outfile.open("newTest",  ios::out);
    if (outfile.fail()){ return false;}
    
    BarPlot b;
    b.print(outfile);
    
    return 0;
}

