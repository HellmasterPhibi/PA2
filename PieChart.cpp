/* 
 * File:   PieChart.cpp
 * Author: hell
 * 
 * Created on 12. červen 2016, 20:05
 */

#include "PieChart.h"

PieChart::PieChart(ifstream& infile, int col): Graph(infile,col) {
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

char PieChart::filling(int v1, int v2) const{
    if(vectorAngle(v1,v2) <= 45)
        return '&';
    else if ((vectorAngle(v1,v2) > 45) && (vectorAngle(v1,v2) <= 90))
        return '#';
    else if ((vectorAngle(v1,v2) > 90) && (vectorAngle(v1,v2) <= 200))
        return '$';
    else        
        return '@';

}

double PieChart::vectorAngle(int v1, int v2)const{
    int u1 = 0;
    int u2 = 13;
    
    //double cosAlpha = (u1*v1 + u2*v2) / (sqrt(u1 * u1 + u2 * u2) * sqrt(v1 * v1 + v2 * v2));
    //double degree = acos(cosAlpha)  * 180.0 / PI;
    double angle = atan2(u1, u2) - atan2(v1, v2);
    angle = angle * 360 / (2*PI);
    if (angle < 0){
    angle = angle + 360;
}
    
    /*
    if((v1 * u2 - v2 * u1) < 0)
        degree += 180;
    */
    //cout << "cos alpha " << cosAlpha << " degrees: " << degree << endl;
    
    return angle;
    
    
}

void PieChart::print(ofstream& out){
    
    for(int i = 0; i < 25; i++){
        for(int j = 0; j < 25; j++){
            out << pie[i][j] << " ";
        }
        out << endl;
    }
}


PieChart::~PieChart() {
}

