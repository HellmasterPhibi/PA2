/* 
 * File:   BarPlot.cpp
 * Author: hell
 * 
 * Created on 3. červen 2016, 17:59
 */

#include "BarPlot.h"

BarPlot::BarPlot(ifstream& infile, int col, int col2,  vector<char>& fillWith): Graph(infile,col, col2, fillWith) {
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

void BarPlot::printAxisX(ofstream& out)const{
    for(int k = 0; k < digits(max) + 1; k++)
            out << " ";
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

void BarPlot::print(ofstream& out){
    out << cathegoryNames[column2] << endl;
    
    /**for every row **/
    for(int i = height; i >= 0; i--){        
        printAxisY(i, out);
        
        /**for every column **/
        for(int j = cathegories.size()-1; j >= 0; j-- ){
            if(cathegories[j].rank == i){
                printRow(out, ' ', '_');
            } 
            else if(cathegories[j].rank > i){
                printRow(out, '|', fill[j]);
            } 
            else{
                printRow(out, ' ', ' ');
            }
            out << "  ";
        }
        out << endl;
    }
    printAxisX(out);
    
    out << endl;
}