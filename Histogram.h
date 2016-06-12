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
    Histogram(ifstream& infile, int col);
    virtual ~Histogram();
    virtual void print(ofstream& out);
private:
    struct THisto{
        THisto(){
            localMin = INT_MAX;
            localMax = 0;
            count = 0;
        };
        int localMin;
        int count;
        int localMax;
    };
    void printRow(ofstream& out, char sides, char fill)const;
    vector<THisto> histoRanks;
    void initialize(int colNum);
    int width;
    void printAxisY(int i,ofstream& out)const;
    void printAxisX(ofstream& out)const;
    int maxCount;
    int range;

};

#endif	/* HISTOGRAM_H */

