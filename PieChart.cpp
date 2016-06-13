/* 
 * File:   PieChart.cpp
 * Author: hell
 * 
 * Created on 12. červen 2016, 20:05
 */

#include "PieChart.h"

PieChart::PieChart(ifstream& infile, int col, int col2): Graph(infile,col, col2) {
    setDegrees();
    
    for(int i = 0; i < 25; i ++){
        for(int j = 0; j < 25; j++){
            int v1 = 13 - i;
            int v2 = 13 - j;
            double distance = sqrt(v1 * v1 + v2 * v2);
            if (distance > 12)
                pie[i][j] = ' ';
            else
                pie[i][j] = filling(v1, v2);            
        }
    }

}
void PieChart::setDegrees(){
    int allranks = 0;
    for(size_t i = 0;i < cathegories.size();i++){        
        allranks += cathegories[i].rank;
    }
    double single = 360.0/ allranks;
    
    for(size_t i = 0;i < cathegories.size();i++){        
        degrees.push_back(single * cathegories[i].rank);
    }
    setDegreeBorders();
}

void PieChart::setDegreeBorders(){
    int sum = 0;
    for(size_t i = 0;i < cathegories.size();i++){
        char filling = i + 35;
        double deg = degrees[i] + sum;    
        if(i + 1 == cathegories.size() )
            deg = 360;
        fill. push_back(make_pair(filling, deg));
        sum += degrees[i];        
    }
}

char PieChart::filling(int v1, int v2) const{
    double angle = vectorAngle(v1,v2);
    
    for(size_t i = 0;i < fill.size();i++){
        if(angle < fill[i].second)
            return fill[i].first;
    }
    return ' ';
}

double PieChart::vectorAngle(int v1, int v2)const{
    int u1 = 0;
    int u2 = 13;
    
    double angle = atan2(v1, v2) - atan2(u1, u2);
    angle = angle * 360 / (2*PI);
    
    if (angle < 0)
        angle = angle + 360;
            
    return angle;        
}


void PieChart::printLegend(ofstream& out) const{
    for(size_t i = 0; i < cathegories.size(); i++){
        out << cathegories[i].name << ": ";
        for( int j = 0; j < 2; j ++)
            out << fill[i].first;
        out << "    ";
    }

}

void PieChart::print(ofstream& out){
    printLegend(out);
    out << endl << endl;
    
    for(int i = 0; i < 25; i++){
        for(int j = 0; j < 25; j++){
            out << pie[i][j] << " ";
        }
        out << endl;
    }
}


PieChart::~PieChart() {
}

