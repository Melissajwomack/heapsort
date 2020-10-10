#include <iostream>
using namespace std;

class MinHeap {
public:
    //The hard coded array, where the index[0] is the number of members in the array from index[1] to index[n]
    //index[0] will be used in the sorting method to separate the array into two parts: one is unsorted and one is sorted
    int hps[16] = {15, 15, 1, 12, 14, 10, 7, 4, 11, 3, 2, 13, 6, 8, 9, 5};
    
    //This variable gives the index of the first parent in the array
    int heapstart = hps[0]/2;

    //A function to display the array in the command line that takes no input and returns nothing
    void displayHeap() {
        cout <<  "Array: ";
        for ( int i = 0; i <  size(hps); i++) {
            cout << hps[i] << " ";
        };
        cout << "\n" << endl;
    }
    
    //A function to retrive the left child of the index of interest
    //Takes the index of interest as a parameter
    //Returns the index of the left child of the index of interest
    int getLchild(int ind){
        if (ind*2 <= 15) {
            return ind*2;
        } else { 
            return 0; 
        };
    }

    //A function to retrive the right child of the index of interest
    //Takes the index of interest as a parameter
    //Returns the index of the right child of the index of interest
    int getRchild(int ind){
        if (((ind*2)+1) <= 15) {
            return ind*2+1;
        } else {
            return 0;
        };
    }
    
    //A function that swaps the values at the indicated indices
    // Takes two indices as parameters and returns nothing
    void swap(int ind1, int ind2) {
        int tmp1 = hps[ind1];
        int tmp2 = hps[ind2];
        hps[ind1] = tmp2;
        hps[ind2] = tmp1;
    }
    
    //A function that checks the left and right child of the indicated index and turns the subtree into a min heap
    //The function takes the index of the parent of the subtree
    //The functions returns a 0 if no swap occured
    //The fucntion returns a 1 if the parent and right child swapped
    //The fucntion returns a 2 if the parent and left child swapped
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
    
    //A recursive function that turns the entire array into a min heap
    //The function uses the subheapify method output to control the flow
    //The function takes the index of the first parent in the tree as a parameter
    //The function returns nothing
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
    
    //A recursice function to percolate the indicated index down the tree if it is greater than the values below it in the tree
    //This function takes the index of the value in the array that needs to be percolated and returns nothing
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

    //A function that uses Floyd's method to sort a min heap in an array
    //The function has no parameters and returns nothing
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
    hps1.treeheapify(hps1.heapstart);
    hps1.heapsort();

    return 0;
}
