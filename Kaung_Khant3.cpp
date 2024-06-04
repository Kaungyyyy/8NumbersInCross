#include <iostream>
#include <cmath>
using namespace std;

bool test(int cross[], int curr_box) {
    static int checkList[8][5] = {
            //lists of box numbers and which boxes they are adjacent with
            {-1},
            {0, -1},
            {1, -1},
            {0, 1, 2, -1},
            {1, 2, 3, -1},
            {2, 4, -1},
            {0, 3, 4, -1},
            {3, 4, 5, 6, -1},
    };

    for(int i = 0; i < curr_box; i++) {
        if(cross[curr_box] == cross[i]) { //checks to see if there are any duplicates
            return false;
        }
    }
    for(int i = 0; checkList[curr_box][i] != -1; i++) {
       if(abs(cross[curr_box] - cross[checkList[curr_box][i]]) == 1) { //checks neighboring boxes to see if there are any consecutive numbers
           return false;
       }
    }
    return true;
}



void print(int cross[]) {
    static int count = 0; // count will not rest to 0 since it is static
    cout << "Solution #: " << ++count << endl;
    cout << " " << cross[1] << cross[2] << endl;
    cout << cross[0] << cross[3] << cross[4] << cross[5] << endl;
    cout << " " << cross[6] << cross[7] << endl;

}
int main() {
    int cross[8] = {0}, c = 0; // initializing the array
    cross[c] = 1; // starting at first box
    c++; //moving to next box

    while (c >= 0) {
        if (c > 7) { // print cross and backtrack if last box is passed
            print(cross);
            c--;
        } else {
            cross[c] = 0;
        }
        while(c >= 0) {
            cross[c]++; //move to next box
            if(cross[c] > 8) { // if passed end of box, backtrack
                c--;
            }
            else {
                if(test(cross, c)) { // if ok function returns true, break
                    c++;
                    break;
                }
            }
        }
    }
    return 0;
}
