#include <iostream>
#include <fstream>
using namespace std;
ofstream output;
ifstream input;

class PolyNode;
class PolyList;

class PolyTerm{
    
    int coe;
    int deg;
    
public:
    PolyTerm(int coefficient, int degree){
        this->coe = coefficient;
        this->deg = degree;
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
    
    
    PolyNode * findspot(PolyNode *item){
        PolyNode * spot = listHead;
        
        while((spot->next!=NULL) && (spot->next->deg>= item->deg)){
            
            if(spot->next->deg == item->deg){
                int coe=(spot->next->coe)+(item->coe);
                //int deg=(spot->next->deg)+(item->deg);
                PolyNode * combo = new PolyNode(coe,spot->next->deg);
                cout<<"SPOTis"<<spot->coe<<" : "<<spot->deg<<" ";
                
                combo->next = spot->next->next;
                spot->next = combo;
                cout<<"There is a COMBO!: ("<<combo->coe<<":"<<combo->deg<<") \n";
                printList();
                
                break;
            }//if same degree
            else{
                spot = spot->next;
            }
            
        }//while
    
        return spot;
    }
    
    
    
    void canonicalize(PolyNode* item){
        cout<<"\nCanonicalizing "<<item->coe<<":"<<item->deg<<endl;
        PolyNode * spot = findspot(item);
    
        item->next = spot->next;
        spot->next = item;
        length++;
        
//        cout<<" Inserted "<<item->coe<<":"<<item->deg<<" ";
        
     
        
        
    }

    
    void printList(){
        PolyNode * temp = listHead->next;
        //        cout<<"\nLINKED LIST: \n";
        while(temp!=NULL){
            if(temp->next==NULL){
                cout<<" " <<temp->coe<< "x^" << temp->deg<< "\n";
            }else{
                cout<<" " <<temp->coe<< "x^" << temp->deg<< " + ";
                
            }
            temp = temp->next;
        }
        //cout<<"temp.Coef: "<<temp->coe<< " "<<endl;
        cout<<"list length: "<<length<<endl;
    }


    
    
};





int main(int argc, char* argv[]) {

    int coefficient;
    int degree;
    input.open(argv[1]);
    output.open(argv[2]);
    

    
    PolyList * eq1 = new PolyList();
    
    
    cout<<"File data\n";
    while(input>>coefficient>>degree){
        eq1->printList();
        PolyNode *node = new PolyNode(coefficient,degree);
        eq1->canonicalize(node);
        
    }
    cout<<endl;
    

    eq1->printList();
    
    
    
    
    
    
    
    input.close();
    output.close();
    
    return 0; };








