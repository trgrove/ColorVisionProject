#include <iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include <string>

using namespace std;

struct rgb{
  int r, g ,b;
};

bool visibleWithin(int red, int green, int blue, const string& type);//checking if a color is too dark to see
bool colorSimilarity(const rgb& color1, const rgb& color2, double lowestVal = 30.0);//compares how close two colors are to each other
void saveFinalEvaluation(const vector<rgb>& colorPalette, const string& colorBlindnessType);//using void to get color pallette input and then to outpu wether its too close in color or not and whethter its visible

int main (){

  string typesToEvaluateFor[3] = {"protanopia, tritanopia, deuteranopia"};
  vector<rgb> colorPalette;  //using struct to declare palette under rgb data type
  string colorBlindnessType;
  int colorMax = 3;         //sets the max amount of colors to be compared in a palette at 3

  cout << "Hello! Please enter type of colorblindness below:\n (protanopia, deuteranopia, tritanopia)" << endl;
  cin >> colorBlindnessType;
    while(colorBlindnessType != "protanopia" && colorBlindnessType !="deuteranopia" && colorBlindnessType != "tritanopia"){
      cout << "it's not that hard to spell bruh lock in..." << endl;
      cin >> colorBlindnessType;
    }

    

  cout << "Evaluating color palette visibility for " << colorBlindnessType << endl;

  cout << "Pick three colors in a color palette." << endl;

    for(int i = 0; i < colorMax; i++){     //gets color palette from user
      rgb hold;

      cout << "Please enter color " << (i + 1) << " keeping the values within rgb range, 0-255:" << endl; //displays color 1,2,3 rather than 0,1,2 by starting at i+1
      cin >> hold.r >> hold.g >> hold.b;    //keeps three colors entered then evaluates if theyre within valid rgb range

      if(hold.r >= 0 && hold.r <=255 && hold.g >= 0 && hold.g <=255 && hold.b >= 0 && hold.b <=255){ //checks that colors are in proper rgb range
        cout << "Color within range. storing in color palette.." << endl;
        colorPalette.push_back(hold);
      } else {    //will go back to the color entered incorrectly for the user to re-enter
        cout << "Colors out of range...re-enter please." << endl;
        i--;
      }
      

      
    }

    ofstream outFile("color_palette.txt");//stores the entered colors in a file then pulls from the file later to compare colors to each other
    outFile << "You chose: " << colorBlindnessType << "\n\n";

      saveFinalEvaluation(colorPalette, colorBlindnessType); //saves color evaluation for a type of colorblindness

    return 0;
}

bool visibleWithin(int red, int green, int blue, const string& type){   //checking if a color is too dark to see
  if(type == "protanopia"){
        return red >= 30 && blue >= 5 && green >= 5;    //returns whether bool is true or false
    }
  if (type == "deuteranopia"){                          //if any types spelled wrong then all colors appear "not vsibile" ie..tooo dark even if that snot true
        return red >= 15 && blue >= 5 && green >= 15;
    }
  if(type == "tritanopia"){
        return red >= 20 && blue >= 20 && green >= 10;
    }
    
    return false;     //if any above conditions are not true the bool returns false
}

bool colorSimilarity(const rgb& color1, const rgb& color2, double lowestVal){//compares how close two colors are to each other
  int rDiff = color1.r - color2.r;
  int gDiff = color1.g - color2.g;
  int bDiff = color1.b - color2.b;

    //use squared euclidian distance--I wasn't sure how to use standard in c++ so I used gemini to ask how I could impement the equation into my code
  int euclidianSquaredDistance = 2 * rDiff * rDiff + 4 * gDiff * gDiff + 3 * bDiff * bDiff;
    //compares against the lowest value that rgb can be from each other
  return euclidianSquaredDistance < (lowestVal * lowestVal);
}

void saveFinalEvaluation(const vector<rgb>& colorPalette, const string& colorBlindnessType) {//using void to get color pallette input and then to outpu wether its too close in color or not and whethter its visible
    ofstream outFile("color_palette.txt");
    outFile << "You chose: " << colorBlindnessType << "\n\n";

      for(size_t i = 0; i < colorPalette.size(); i++){
        bool isVisible = visibleWithin(colorPalette[i].r, colorPalette[i].g, colorPalette[i].b, colorBlindnessType);
        string status;

        if(isVisible){
          status = "Visible";
        } else {
          status = "Not visible";
        }
            cout << "Color " << i + 1 << ": " << status << endl;
            outFile << "Color " << (i + 1) << " (" << colorPalette[i].r << ", " << colorPalette[i].g << ", " << colorPalette[i].b << "): " << status << "\n";
      }
        bool colorsTooSimilar = false;

  for (size_t i = 0; i < colorPalette.size(); i++){//to evaluate two colors I have to use two different indexs'--i for color "1" j fpr color "2"--colors arent actually one and two but the fisrt and second to be compared
      for(size_t j = i + 1; j < colorPalette.size(); j++){
        if(colorSimilarity(colorPalette[i], colorPalette[j])){

          cout << "Color " << (i + 1) << " and color " << (j + 1) << " are too close in color for someone with " << colorBlindnessType << " to distinct between." << endl;
          outFile << "Color " << (i + 1) << " and color " << (j + 1) << " are too close in color for someone with " << colorBlindnessType << " to distinct between.\n\n";
          
          colorsTooSimilar = true;
      } else{
        cout << "Color " << (i + 1) << " and color " << (j + 1) << " are visible and not too close in color." << endl;
        outFile << "Color " << (i + 1) << " and color " << (j + 1) << " are visible and not too close in color.\n";
      }

    } 
  }

   if (!colorsTooSimilar){
        cout << "Colors are all visible to somone with " << colorBlindnessType << endl;
        outFile << "Colors are all visible to somone with" << colorBlindnessType << "\n\n";
    }
    outFile.close();
}


       
    
    
       



