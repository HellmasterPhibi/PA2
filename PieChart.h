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
    PieChart(ifstream& infile, int col, int col2);
    virtual ~PieChart();
    virtual void print(ofstream& out);
private:
    char pie [25][25];
    double vectorAngle(int v1, int v2)const;
    char filling(int v1, int v2) const;
    vector<pair<char,double> > fill; /**first = fill, second = max degree up to which the fill should be placed*/
    vector<double> degrees;
    void setDegrees();
    void setDegreeBorders();
    void printLegend(ofstream& out) const;
};

#endif	/* PIECHART_H */

