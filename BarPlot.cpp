/* 
 * File:   BarPlot.cpp
 * Author: hell
 * 
 * Created on 3. červen 2016, 17:59
 */

#include "BarPlot.h"

BarPlot::BarPlot(ifstream& infile): Graph(infile) {
    width = 10;
}

BarPlot::~BarPlot() {
}

void BarPlot::printRow(ofstream& out, char sides, char fill)const{
    out << sides;
        for(int k = 0; k < width; k++) 
            out <<  fill;
    out << sides;

}

void BarPlot::print(ofstream& out){
    /**for every row **/
    for(int i = height; i >= 0; i--){  
        
        
        out << i;
        if(i < 10) out << "  ";
        else if(i < 100) out << " ";
        out << "| ";
        
        /**for every column **/
        for(int j = cathegories.size()-1; j >= 0; j-- ){
            if(cathegories[j].rank == i){
                printRow(out, ' ', '_');
            } 
            else if(cathegories[j].rank > i){
                printRow(out, '|', ' ');
            } 
            else{
                printRow(out, ' ', ' ');
            }
            out << "  ";
        }
        out << endl;
    }
    out << "   ";
    int offset = 4;
    for(int j = cathegories.size()-1; j >= 0; j-- ){
        for(int k = 0; k < offset; k++)
            out << " ";
        
        out << cathegories[j].name;
        
        for(int i = cathegories[j].name.size() +  offset ; i < width + 4; i++ )
            out << " ";
    }
         
    out << endl;
    for(int i = (cathegories.size()-1) * (width +7 ) + 3; i > 0; i--)
        out << "_";
    out << endl;
}