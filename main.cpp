/* 
 * File:   main.cpp
 * Author: hell
 *
 * Created on 31. květen 2016, 14:36
 */

#include "Graph.h"
#include "BarPlot.h"
#include "LinePlot.h"
#include "Histogram.h"

using namespace std;

int main(int argc, char** argv) {
    ofstream outfile;
    outfile.open("histoTest",  ios::out);
    if (outfile.fail()){ return false;}
    
    ifstream infile;
    infile.open("kus.csv",  ios::in);
    if (infile.fail()){ cout << "Cannot open file" << endl;}
    
    Histogram h(infile,2);
    h.print(outfile);
    
    //LinePlot l(infile,1);
    //l.print(outfile);
    
    //BarPlot b(infile,1);
    //b.print(outfile);
    
    infile.close();
    outfile.close();
    
    return 0;
}

