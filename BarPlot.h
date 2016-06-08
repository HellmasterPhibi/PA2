/* 
 * File:   BarPlot.h
 * Author: hell
 *
 * Created on 3. červen 2016, 17:59
 */

#ifndef BARPLOT_H
#define	BARPLOT_H


#include "Graph.h"

using namespace std;

class BarPlot: public Graph {
public:
    BarPlot(ifstream& infile);
    virtual ~BarPlot();
    virtual void print(ofstream& out);
private:
    int width;
    void printRow(ofstream& out, char sides, char fill)const;
    void printAxisX(ofstream& out)const;

};

#endif	/* BARPLOT_H */

