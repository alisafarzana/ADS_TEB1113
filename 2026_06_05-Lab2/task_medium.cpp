#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    //Median in row wise sorted matrix
    
    vector<vector<int>> mat = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };

    vector<int> elements;

    //Matrix to one vector
    for (int i=0; i<mat.size(); i++){
        for (int j=0; j<mat[i].size(); j++){
            elements.push_back(mat[i][j]);
        }
    }

    // sort in ascending order
    sort(elements.begin(), elements.end());

    //output
    cout<<"Matrix: "<<endl;
    for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < mat[i].size(); j++) {
        cout << mat[i][j] << "\t";
        }
    cout << endl;
    }

    cout << "Elements in sorted order: ";
    for (int i = 0; i < elements.size(); i++) {
        cout << elements[i] << " ";
    }

    int median = elements.size() / 2;
    cout<<endl<<"Median : "<<elements[median];


    return 0;
}