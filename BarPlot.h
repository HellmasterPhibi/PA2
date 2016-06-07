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
    BarPlot();
    BarPlot(const BarPlot& orig);
    virtual ~BarPlot();
    virtual void print(ofstream& out);
private:

};

#endif	/* BARPLOT_H */

