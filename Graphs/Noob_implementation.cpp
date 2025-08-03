#include<iostream>
#include<vector>
using namespace std;
class vertex{
    public:
    string data;

    vertex(string data){
        this->data=data;
    }
}
class edge{
    public:
    vertex source;
    vertex destination;
    int wt;
    bool direction;
    
    edge(vertex srce,vertex dest){
        source=srce;
        destination=dest;
        wt=0;
        direction=false;
    }
    edge(vertex srce,vertex dest,int wt){
        source=srce;
        destination=dest;
        this->wt=wt;
        direction=false;
    }
    edge(vertex srce,vertex dest,bool direction){
        source=srce;
        destination=dest;
        wt=0;
        this->direction=direction;
    }
    edge(vertex srce,vertex dest,int wt,bool direction){
        source=srce;
        destination=dest;
        this->wt=wt;
        this->direction=direction;
    }
};
class graph{
        public:
        vector<vertex> vertices;
        vector<edge> edges;
};
int main(){
    vertex v1("Balkaran");
    vertex v2("Basant");
    vertex v3("Beer");
    vertex v4("Beauty");
    vertex v5("Bhargav");
    edge e1(v1,v2,true);
    edge e2(v2,v3,true);
    edge e3(v3,v4,true);
    edge e4(v4,v5,true);
    edge e5(v5,v1,true);
    graph g1;
    g1.edges(e1,e2,e3,e4,e5);
    g1.vertices(v1,v2,v3,v4,v5);
    
    return 0;
}