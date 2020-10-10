#include <iostream>
using namespace std;

class MinHeap {
    
private:

public:
    int hps[16] = {15, 15, 1, 12, 14, 10, 7, 4, 11, 3, 2, 13, 6, 8, 9, 5};
    int start = hps[0]/2;

    //A function to display the array in the command line that takes no input and returns nothing
    void displayHeap() {
        cout <<  "Array: ";
        for ( int i = 0; i <  size(hps); i++) {
            cout << hps[i] << " ";
        };
        cout << endl;
    }
    
    int getParent(int ind){
        if (ind/2 <=15) {
            return ind/2;
        } else {
            return 0;
        }
    }
    
    int getLchild(int ind){
        if (ind*2 <= 15) {
            return ind*2;
        } else { 
            return 0; 
        };
    }

    int getRchild(int ind){
        if (((ind*2)+1) <= 15) {
            return ind*2+1;
        } else {
            return 0;
        };
    }
    
    void swap(int ind1, int ind2) {
        int tmp1 = hps[ind1];
        int tmp2 = hps[ind2];
        hps[ind1] = tmp2;
        hps[ind2] = tmp1;
    }
    
    int subheapify(int ind){ 
            int p = ind;
            int l = getLchild(ind);
            int r = getRchild(ind);
            if ( r != 0 || l != 0 ) {
                if (hps[p] > hps[l] && hps[l] < hps[r]) {
                    swap(p, l);
                    return 2;
                }       
                if (hps[p] > hps[r] && hps[r] < hps[l]) {
                    swap(p, r);
                    return 1;
                } else {
                    return 0;
                }
            }
            else {
                return 0;
            };
    }
    
    void treeheapify(int ind) {
        while (ind > 0) {
            int check = subheapify(ind);
            if (check == 2) {
                if (getLchild(getLchild(ind)) || getRchild(getLchild(ind))){
                   return treeheapify(getLchild(ind));
                } else {
                    return treeheapify(ind-1); 
                };
            };
            if (check == 1) {
                if (getRchild(getRchild(ind)) || getLchild(getRchild(ind))){
                    return treeheapify(getRchild(ind));
                } else {
                    return treeheapify(ind-1); 
                };
            };
            return treeheapify(ind-1);
        } 
        cout << "Array has been min heapified" << endl;
        displayHeap();
    }
    
    void percolate(int tmp1){
        int p = tmp1;
        int l = getLchild(tmp1);
        int r = getRchild(tmp1);
        
        if(l > 0 && r > 0) {
            if (hps[p] > hps[l] || hps[p] > hps[r]) {
                if (hps[l] < hps[r] && l < hps[0] ) {
                    swap(p, l);
                    return percolate(l);
                }
                if (hps[r] < hps[l] && r < hps[0]) {
                    swap(p, r);
                    return percolate(r);
                };
            }
        }
    };

    void heapsort() {
        while(hps[0] != 0) {
            if (hps[hps[0]] > hps[1]) {
                swap(hps[0], 1);
            };
            hps[0] = hps[0]-1;
            percolate(1);
        };
        cout << "Array has been sorted" << endl;
        displayHeap();
    }
    
};
    
int main(int argc, char **argv) {
    
    MinHeap hps1;
    hps1.displayHeap();
    hps1.treeheapify(hps1.start);
    hps1.heapsort();

    return 0;
}
