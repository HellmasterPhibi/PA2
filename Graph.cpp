/* 
 * File:   Graph.cpp
 * Author: hell
 * 
 * Created on 31. květen 2016, 17:20
 */

#include "Graph.h"


Graph::Graph(ifstream& infile) {
     height = 30;
     column = 3;
     string line, tmp;
     if (infile.is_open()){
         getline (infile,line);
         stringstream names(line);
            while(getline(names, tmp,','))
                cathegoryNames.push_back(tmp);
         
        while ( getline (infile,line) ){
            stringstream ss(line);
            vector<string> tmpVec;
            while(getline(ss, tmp,','))
                tmpVec.push_back(tmp);
            
            TCathegory cath(tmpVec[0],stoi(tmpVec[column]));
            cathegories.push_back(cath);
        }
         setRanks();
        infile.close();
    }
}

void Graph::setRanks(){
    int max = 0;
    for(auto i: cathegories){
        if (max < i.count)
            max = i.count;
    }
    for(size_t i = 0;i < cathegories.size();i++){
        cathegories[i].rank = (cathegories[i].count * height) / max;
    }
    
    
    
}
Graph::Graph(const Graph& orig) {
}

Graph::~Graph() {
}

