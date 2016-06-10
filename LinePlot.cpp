/* 
 * File:   LinePlot.cpp
 * Author: hell
 * 
 * Created on 8. červen 2016, 14:10
 */

#include "LinePlot.h"

LinePlot::LinePlot(ifstream& infile): Graph(infile) {
    fill= '*';
    width = 6;
   // sort(cathegories.begin(),cathegories.end(),cmpFoo //not working, maybe change chathegories from vector to list?
}

bool LinePlot::cmpFoo (const TCathegory& i,const TCathegory& j)const { 
    return (stoi(i.name) < stoi(j.name)); 
}


LinePlot::~LinePlot() {
}

/**prints only the values that are given in the input file*/
void LinePlot::printAxisX(ofstream& out)const{
    for(int k = 0; k < digits(max) + 2; k++)
            out << " ";
    for(size_t i = 0; i < cathegories.size(); i++  ){
        out << cathegories[i].name;
        for(int j = 0; j < width - digits(stoi(cathegories[i].name)); j++)
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
            else if(i == height){ /**the highest value*/
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
                if(abs((cathegories[j].rank - cathegories[j+1].rank)) < 3 )
                   for(int k = 0; k < width/2 -1 ;k++)
                        out << " -";    
                else
                    for(int k = 0; k < width;k++)
                        out << " ";                
            } 
            else if ( ((cathegories[j].rank < i) && (cathegories[j+1].rank < i)) ||
                      ((cathegories[j].rank > i) && (cathegories[j+1].rank > i))
                    ){
                for(int k = 0; k < width +1;k++)
                    out << " ";   
            }
            else if ((j+1) != cathegories.size() ){
                int spaces = abs(cathegories[j+1].rank - i);
                for(int k = 0; k < width - spaces -1;k++)
                    out << " ";   
                out << "-";
                for(int k = 0; k < spaces ;k++)
                    out << " "; 
                
            }
        }
        out << endl;
    }
    printAxisX(out);
    out << endl;
}
