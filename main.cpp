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
#include "PieChart.h"

using namespace std;

int main(int argc, char** argv) {
    ofstream outfile;
    outfile.open("pieTest",  ios::out);
    if (outfile.fail()){ return false;}
    
    ifstream infile;
    infile.open("grades.csv",  ios::in);
    if (infile.fail()){ cout << "Cannot open file" << endl;
    return -1;
    }
    
    PieChart p(infile,0,1);
    p.print(outfile);
    
    //Histogram h(infile,12);
    //h.print(outfile);
    
    //LinePlot l(infile,1, 2);
    //l.print(outfile);
    
    //BarPlot b(infile,0,1);
   // b.print(outfile);
    
    infile.close();
    outfile.close();
    
    return 0;
}

