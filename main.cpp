// 
// Your previous C++ content is preserved below:
// 
#include <iostream>
#include <cmath>

#define DB 12.70
#define SB 31.80
#define TRIPLE_INNER 198.00
#define TRIPLE_OUTER 214.00
#define DOUBLE_INNER 321.00
#define DOUBLE_OUTER 340.00
using namespace std;


//score class
class Dartboard {
    private:
        int dart_x, dart_y;
        double dart_diameter;
        void generate_dartboard_score();

    public:
        Dartboard(int x, int y);
        int get_dart_x();
        int get_dart_y();
        void calculate_dart_diameter();
        string which_region();
        double calculate_dart_degree();
        int dartboard_score();
        
};

//Dartboard constructory
Dartboard::Dartboard(int x_input, int y_input) {
    this-> dart_x = x_input;
    this-> dart_y = y_input;

    calculate_dart_diameter();
}

//read-only dart_x
int Dartboard::get_dart_x() {
    return dart_x;
}

//read-only dart_y
int Dartboard::get_dart_y() {
    return dart_y;
}

//calculate the diameter of the dart from the center
void Dartboard::calculate_dart_diameter() {
    dart_diameter = sqrt(pow(dart_x, 2) + pow(dart_y, 2));
}

string Dartboard::which_region() {
    if(dart_diameter <= DB) {
        return "DB";
    }
    else if(dart_diameter <= SB) {
        return "SB";
    }  
    else if(dart_diameter <= TRIPLE_OUTER && dart_diameter >= TRIPLE_INNER) {
        return "T";
    }
    else if(dart_diameter <= DOUBLE_OUTER && dart_diameter >= DOUBLE_INNER) {
        return "D";
    }
    else if(dart_diameter > DOUBLE_OUTER) {
        return "X";
    }
    else {
        //is on a normal position on the dartboard
        return "";
    }
}

//gernerate score for dartboard
void Dartboard::generate_dartboard_score() {
    //convert score to 
}

//calculate the dart degree position
double Dartboard::calculate_dart_degree() {
    //atan(dart_y, dart_x);
}

//caculate where on board function is
int Dartboard::dartboard_score() {
    //generate_darboard score base on degree
    //find degree of dart
   //double dart_degree = calculate_dart_degree();
    //match & return dart to dartboard_score


    //temporary in place
    return 0;
}

//print score
void print_score(int x, int y, string score_val) {
    cout << "score(" << x << ", " << y << ") -> \"" << score_val << "\"" << endl;
  return;
}

//wrapper function
void score (int x, int y) {
    //create Dartboard object
    Dartboard player(x,y);
    //find if outlier condition
    string region = player.which_region();
    if(region == "X" || region == "DB" || region =="SB") {
        //output score
        print_score(x, y, region);
    }
    else {
        //find at which angle dart is at using coordinate
        int dartboard_score = player.dartboard_score();
        if (region == "T") {
            //triple score
            int triple_score = 3 * dartboard_score;
            //output score
            print_score(x, y, "T" + triple_score);
        }
        else if (region == "D") {
            //double score
            int double_score = 2 * dartboard_score;
            //output score
            print_score(x, y, "D" + double_score);
        }
        else {
            //output score
            print_score(x, y, to_string(dartboard_score));
        }
    }
}

// To execute C++, please define "int main()"
int main() {
  //get input from user
  
  //call score()
  score(3,4);
  
  //did not finish
  return 0;
}
