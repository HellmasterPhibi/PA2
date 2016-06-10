/* 
 * File:   Histogram.h
 * Author: hell
 *
 * Created on 9. červen 2016, 14:26
 */

#ifndef HISTOGRAM_H
#define	HISTOGRAM_H

#include "Graph.h"

using namespace std;

class Histogram : public Graph  {
public:
    Histogram(ifstream& infile);
    virtual ~Histogram();
private:

};

#endif	/* HISTOGRAM_H */

