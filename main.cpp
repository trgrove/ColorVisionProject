#include <iostream>
using namespace std;
#include <string>


    int main() {

        string x;
        int cip = 5;
        char type;
        cout << "input type of colorblindess: Tritanopia A, Protanopia B or Deuteranopia C." << endl;
        cin >> type;

        switch (type){
        case 'A':
            cout << "Tritanopia" << endl;
            break;
        case 'B':
            cout << "Protanopia" << endl;
            break;
        case 'C':
            cout << "Deuteranopia" << endl;
            break;
        default: 
            cout << "Not an option please pick A, B or C" << endl;
            return 1;
        }
            cout << "enter number of colors in your palette: " << endl; 
            cin >> cip;

        if (cip > 5 || cip <= 0) {
            cout << "unavailable number of colors in palette." << endl;
            return 1;
        }

        int R[5], G[5], B[5];

        for (int i = 0; i < cip; ++i){
        
            cout << "enter color " << (i+1) << " in RGB number form" << endl;//i=0 starts at 0-4 for 5 cases
            cin >> R[i] >> G[i] >> B[i];

        if (R[i] >= 0 && R[i] <= 255 && G[i] >= 0 && G[i] <= 255 && B[i] >= 0 && B[i] <= 255) {  //making sure the rgb values are between 0 and 255 for each color
            bool red = (R[i] > G[i] && R[i] > B[i] && R[i] > 50);
            bool blue = (B[i] > G[i] && B[i] > R[i] && B[i] >50);
            bool green = (G[i] > R[i] && G[i] > B[i] && G[i] > 50);
       
        if (type == 'A'){ //Tri--blue blind
            if (red || green) {
            cout << "color " << (i+1) << " is visible to people with Tritanopia!" << endl;

            }else if (blue)     
            cout << "color " << (i+1) << " is not visible to people with Tritanopia!" << endl;  
             else {
                    cout << "color " << (i+1) << " is neutral(grey/black/white)";
            } 
        }                   

        if (type == 'B'){ //Pro--Red blind
            if (blue || green) {
            cout << "color " << (i+1) << " is visible to people with Protanopia!" << endl;

            }else if (red) {    
            cout << "color " << (i+1) << " is not visible to people with Protanopia!" << endl;             
            }else {
                    cout << "color " << (i+1) << " is neutral(grey/black/white)";

            }
        }
        if (type == 'C'){ //Deu--green blind
            if (blue || red) {
            cout << "color " << (i+1) << " is visible to people with Deuteranopia!" << endl;

            }else if (green){ 
            cout << "color " << (i+1) << " is not visible to people with Deuteranopia!" << endl;             
            }else {
                    cout << "color " << (i+1) << " is neutral(grey/black/white)";
            }
        }

     
        }
            else{
            cout << "invalid color selection. Number above 255 or below 0." << endl;
            return 1;
              }
    
    }
        return 0;
}



       
    
    
       



