#include <iostream>
#include <vector>
using namespace std;


// Check if an array is subset of another array

bool isSubset(vector<int> &x, vector<int> &y){

    int a = x.size(), b = y.size();
    for (int i=0; i<b; i++){
        bool found = false;

        for (int j=0; j<a; j++){
            if (y[i] == x[j]){
                found = true;
                x[j] = -1;
                break;
            }
        }

        if (!found) return false;
    }

    return true;   
}

void displayVector(vector<int> z){
    for (int i=0; i<z.size(); i++){
        cout<<z[i]<<" ";
    }
    cout<<endl;
}


int main(){

    vector<int> x = {15, 3, 8, 9, 19, 10};
    vector<int> y = {3, 9, 10};

    cout<<"x : "; displayVector(x);
    cout<<"y : "; displayVector(y);

    if (isSubset(x,y)) {cout<<"True"<<endl;}
    else {cout<<"False"<<endl;}

    return 0;
}