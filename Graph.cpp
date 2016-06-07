/* 
 * File:   Graph.cpp
 * Author: hell
 * 
 * Created on 31. květen 2016, 17:20
 */

#include "Graph.h"


Graph::Graph(ifstream& infile) {
     string line, tmp;
     if (infile.is_open()){
         getline (infile,line);
        while ( getline (infile,line) ){
            stringstream ss(line);
            vector<string> tmpVec;
            while(getline(ss, tmp,','))
                tmpVec.push_back(tmp);
            
            TCathegory cath(tmpVec[0],stoi(tmpVec[3]));
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
    cout << "max = " << max <<endl;
    for(auto i: cathegories){
        i.rank = (i.count * 10) / max;
        cout << i.name << " ma rank " << i.rank << endl;
    }
    
    
    
}
Graph::Graph(const Graph& orig) {
}

Graph::~Graph() {
}

