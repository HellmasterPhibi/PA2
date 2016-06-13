/* 
 * File:   LinePlot.cpp
 * Author: hell
 * 
 * Created on 8. červen 2016, 14:10
 */

#include "LinePlot.h"

using namespace std;

LinePlot::LinePlot(ifstream& infile, int col, int col2,  vector<char>& fillWith): Graph(infile,col, col2, fillWith) {
    width = 6;
    sort(cathegories.begin(),cathegories.end(),[](const TCathegory& i,const TCathegory& j) { 
    return (stoi(i.name) < stoi(j.name)); 
} );
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
    out << endl;

}



void LinePlot::print(ofstream& out){
out << cathegoryNames[column2] << endl;
    /**for every row **/
    for(int i = height; i >= 0; i--){        
        printAxisY(i, out);
        
        /**for every value **/
        for(size_t j = 0; j < cathegories.size(); j++ ){
            if(cathegories[j].rank == i){
                out << fill[0];
                if(abs((cathegories[j].rank - cathegories[j+1].rank)) < 3 )
                   for(int k = 0; k < width -1 ;k++){
                       if(k % 2)
                        out << fill[0];    
                       else
                           out << " ";
                   }
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
                out << fill[0];
                for(int k = 0; k < spaces ;k++)
                    out << " "; 
                
            }
        }
        out << endl;
    }
    printAxisX(out);
    out << endl;
}
