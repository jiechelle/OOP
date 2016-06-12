#include <iostream>
#include <fstream>
using namespace std;

class PolyTerm{
    
    int coe;
    int deg;
    
    
public:
    PolyTerm(int coefficient, int degree){
        this->coe = coefficient;
        this->deg = degree;
    }
    
    void canonicalize(){
        
    }
    
    int getDeg(){
        return deg;
    }
    
    int getCoe(){
        return coe;
    }
    
};





class PolyNode{
    
public:
    PolyNode * next;
    int coe;
    int deg;
    
    PolyNode(){
        coe = 0;
        deg = 0;
        next = NULL;
    }
    
    
    PolyNode(int c, int d){
        this->coe = c;
        this->deg = d;
        next = NULL;
    }
    
    
};



class PolyList{
    PolyNode *listHead;
    PolyNode *current;
    int length;
    
public:
    
    PolyList(){//constructor
        listHead = new PolyNode(0, 0);
        current = listHead;
        length = 0;
    }
    
    
    void append(PolyNode *NodeParam){
    
        NodeParam->next = current->next;
        current->next = NodeParam;
        cout<<NodeParam->coe<<" --- " << NodeParam->deg<<" | ";
        length++;
        
        
    }

    
    void printList(){
        PolyNode * temp = listHead;
        cout<<"\nPrinting List: \n";
        while(temp->next!=NULL){
            cout<<"Coe:" <<temp->coe<< " Deg:" << temp->deg<< " --> ";
            temp = temp->next;
        }
        //cout<<"temp.Coef: "<<temp->coe<< " "<<endl;
        cout<<"\nlist length: "<<length<<endl;
    }
    
    
    
};





int main(int argc, char* argv[]) {
    
//    PolyList eq0 = *new PolyList();    
//    eq1.append(*new PolyNode(2, 3));
    
    PolyList * eq1 = new PolyList();
    
    PolyNode *node1 = new PolyNode(2,5);
    PolyNode *node2 = new PolyNode(2,4);
    
    PolyNode *node3;
    node3 = new PolyNode(8, 2);

    eq1->append(node1);
    eq1->append(node2);
    eq1->append(node3);
    
    eq1->printList();
    
    
    
    
    
    
    
    return 0; };








