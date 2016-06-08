/* 
 * File:   LinePlot.cpp
 * Author: hell
 * 
 * Created on 8. červen 2016, 14:10
 */

#include "LinePlot.h"

LinePlot::LinePlot(ifstream& infile): Graph(infile) {
    fill= '*';
    width = 3;
}


LinePlot::~LinePlot() {
}

void LinePlot::print(ofstream& out){
out << cathegoryNames[column] << endl;
    
    /**for every row **/
    for(int i = height; i >= 0; i--){        
        int val = (i * max)/height; /**backtracking the initial value from i - the result is not precise, but faster than getting the value from for cycle*/
        out << val;
        for(int k = digits(val); k < digits(max); k++)
            out << " ";
        out << "| ";
        
        /**for every column **/
        for(size_t j = 0; j < cathegories.size(); j++ ){
            if(cathegories[j].rank == i){
                for(int k = 0; k < width;k++)
                    out << " ";
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
}
