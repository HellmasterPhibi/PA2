/* 
 * File:   LinePlot.h
 * Author: hell
 *
 * Created on 8. červen 2016, 14:10
 */

#ifndef LINEPLOT_H
#define	LINEPLOT_H

#include "Graph.h"

using namespace std;

class LinePlot: public Graph  {
public:
    LinePlot(ifstream& infile, int col, int col2,  vector<char>& fillWith);
    virtual ~LinePlot();
    virtual void print(ofstream& out);
private:
    void printAxisX(ofstream& out)const;
    int width;
};

#endif	/* LINEPLOT_H */

