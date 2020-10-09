#include <iostream>
using namespace std;

class MinHeap {
private:
    int hps[16];
public:
    MinHeap() : hps {15,8,2,10,3,1,14,9,4,5,6,7,11,15,13,12} {};
    
    void displayHeap() {
        cout <<  "Array: ";
        for ( int i = 0; i <  size(hps); i++) {
            cout << hps[i] << " ";
        };
        cout << endl;
    }
    
    int getParent(int ind){
        return ind/2;
    }
    
    int getLchild(int ind){
        return ind*2;
    }
    
    int getRchild(int ind){
        return (ind*2)+1;
    }
};



int main(int argc, char **argv) {
    
    MinHeap hps1;
    hps1.displayHeap();
    int p = hps1.getParent(2);
    int l = hps1.getLchild(2);
    int r = hps1.getRchild(2);
    cout << "Parent of 2: " << p << endl;
    cout << "LChild of 2: " << l << endl;
    cout << "Rchild of 2: " << r << endl;
    return 0;
}
