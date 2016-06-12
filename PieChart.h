/* 
 * File:   PieChart.h
 * Author: hell
 *
 * Created on 12. červen 2016, 20:05
 */

#ifndef PIECHART_H
#define	PIECHART_H

#include "Graph.h"

using namespace std;

class PieChart :  public Graph {
public:
    PieChart(ifstream& infile, int col);
    virtual ~PieChart();
    virtual void print(ofstream& out);
private:

};

#endif	/* PIECHART_H */

