/* 
 * File:   LinePlot.cpp
 * Author: hell
 * 
 * Created on 8. červen 2016, 14:10
 */

#include "LinePlot.h"

LinePlot::LinePlot(ifstream& infile): Graph(infile) {
    fill= '*';
    width = 4;
}


LinePlot::~LinePlot() {
}

void LinePlot::printAxisX(ofstream& out)const{
    for(int k = 0; k < digits(max) + 2; k++)
            out << " ";
    for(size_t i = 0; i < cathegories.size(); i++  ){
        out << cathegories[i].name;
        for(int j = 0; j < width+1; j++)
            out << " ";
    }

}

void LinePlot::printAxisY(int i,ofstream& out)const{
    int val = -1;
        for(size_t k = 0; k < cathegories.size(); k++){
            if(cathegories[k].rank == i){
                val = cathegories[k].count;
                out << val;
                break;
            }
            else if(i == height){
                val = max;
                out << val;
                break;
            }
        }
        for(int k = digits(val); k < digits(max); k++)
            out << " ";
        out << "| ";
}


void LinePlot::print(ofstream& out){
out << cathegoryNames[column] << endl;
    /**for every row **/
    for(int i = height; i >= 0; i--){        
        printAxisY(i, out);
        
        /**for every value **/
        for(size_t j = 0; j < cathegories.size(); j++ ){
            if(cathegories[j].rank == i){
                out << fill;
                for(int k = 0; k < width;k++)
                    out << " ";                
            } 
            else{
                for(int k = 0; k < width *2 +1;k++)
                    out << " ";   
            }
        }
        out << endl;
    }
    printAxisX(out);
    out << endl;
}
