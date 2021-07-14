#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <typeinfo> 
#include <time.h>

using namespace std;

const int FINISH = 36;                                          // Finish line is at column 36
const int SOLDIER = 60;                                         // Total 60 soldiers

void initialTroop (char[][40], int);                            // Initial troop setting
void printAll (char[][40]);
bool nextRound ();                                              // Whether to next round
void parameters (char&, int&, int&);                            // Determine parameters for Stage 3
void swap(char[][40], int&, int&, int&);                        // Swap soldiers for random march

void steady_march (char[][40], int, int, int);                  // Move soldiers as steady march
void random_march (char[][40], int, int, int);                  // Move soldiers as random march
void runSimulation(char[][40], char, int&, int, int, char);     // Run Simulation


int main(){
    char troop[20][40];
    int row, col;
    char stage, march_type;
    int n_step = 1;                             // Default : move 1 step forward
    int form = 6;                               // Default : 6-rows troop formation
    int round = 1;                              // Starting from Round 1
    bool goNext;
    
    
    // Build the outline (outside box + finish line)
    // Outside Box
    for (row=0; row<20; row++){
        for (col=0; col<40; col++){

            if (col==0 || col==39){
                troop[row][col] = '|';
            }

            else if (row==0 || row==19){
                troop[row][col] = '-';
            }

            else {
                troop[row][col] = ' ';
            }
        }
    }
    
    // Finish Line
    troop[5][36] = '|';
    troop[6][36] = '|';
    troop[7][36] = 'F';
    troop[8][36] = 'I';
    troop[9][36] = 'N';
    troop[10][36] = 'I';
    troop[11][36] = 'S';
    troop[12][36] = 'H';
    troop[13][36] = '|';
    troop[14][36] = '|';


    // Prompt the user to pick the stage.
    do {
        cout << "\n[ Military Training Simulation ]\n\n- Please select the stage.\n(A) Stage 1\t(B) Stage 2\t (C) Stage 3\n";
        cin >> stage;

        if (!(stage == 'A' || stage == 'a' || stage == 'B' || stage == 'b' || stage == 'C' || stage == 'c')){
            do {
                cout << "Invalid input. Please choose from A, B, C." << endl;
                cin >> stage;
            } while (!(stage == 'A' || stage == 'a' || stage == 'B' || stage == 'b' || stage == 'C' || stage == 'c'));
        }

    } while (!(stage == 'A' || stage == 'a' || stage == 'B' || stage == 'b' || stage == 'C' || stage == 'c'));
    // Convert to lowercase for convenience.
    stage = tolower(stage);
    cout << "\n";                            


    // Stage 1
    if (stage == 'a'){
        // Print initiate setting.
        initialTroop(troop, form);                                          
        printAll(troop);                                     
        goNext = nextRound();

        // Run simulation.
        while (goNext) {
            runSimulation(troop, stage, round, n_step, form, march_type);            
            round++;
            goNext = nextRound();                           
        }

        // Exit simulation on the request.
        if (!goNext) {
            cout << "\n-- Simulation discontinued on your request --\n" << endl;
        }
    }


    // Stage 2
    if (stage == 'b'){
        // Print initiate setting.
        initialTroop(troop, form);                                          
        printAll(troop);                                     
        goNext = nextRound();

        // Run simulation.                
        while (goNext) {
            runSimulation(troop, stage, round, n_step, form, march_type);            
            round++;
            goNext = nextRound();                             
        }
        
        // Exit simulation on the request.
        if (!goNext){
            cout << "\n-- Simulation discontinued on your request --\n" << endl;
        }
    }


    // Stage 3
    if (stage == 'c') {
        
        // Set parameters.
        cout << "- Stage 3 requires three parameters: \n" << endl;
        parameters (march_type, form, n_step);
            
        // Print initiate setting tailored to parameters.
        initialTroop(troop, form);                                          
        printAll(troop);                                    
        goNext = nextRound();


        // Run simulation.
        while (goNext) {
            runSimulation(troop, stage, round, n_step, form, march_type);
            round++;
            goNext = nextRound();
        }
        
        // Exit simulation on the request.
        if (!goNext){
            cout << "\n-- Simulation discontinued on your request --\n" << endl;
        }
    }
   
    return 0;
}
void initialTroop(char troop[20][40], int form){
    // troop dimension = (SOLDIER / form) x form = r x form
    // Default troop dimension = 10 x 6
    int row, col;
    int r = SOLDIER / form;
    for (row=5; row<5+r; row++){
        for (col=2; col<2+form; col++){
            troop[row][col] = '>';
        }
    }
}
void printAll(char troop[][40]){
    int row, col;
    for (row=0; row<20; row++){
        for (col=0; col<40; col++){
            cout << troop[row][col];
        }
        cout << "\n";
    }    
}
bool nextRound (){
    // Ask whether to proceed with the next round
    char yesNo;
    do {
        cout << "Go to next round (Y/y)? ";
        cin >> yesNo;

        if (!(yesNo == 'Y' || yesNo == 'y' || yesNo == 'N' || yesNo == 'n')){
            do {
                cout << "Invalid input. Yes for Y/y, No for N/n" << endl;
                cin >> yesNo;
            } while (!(yesNo == 'Y' || yesNo == 'y' || yesNo == 'N' || yesNo == 'n'));
        }
    } while (!(yesNo == 'Y' || yesNo == 'y' || yesNo == 'N' || yesNo == 'n'));

    // Yes = true, No = false
    if (yesNo == 'Y' || yesNo == 'y'){
        return true;
    }
    return false;
}
void parameters(char& march_type, int& form, int& n_step){
    // Param 1 : Type of March
    do {
        cout << "(Parameter 1)  Please select the march type.\n(A) Steady March\t(B) Random March\n";
        cin >> march_type;

        if (!(march_type == 'A' || march_type == 'a' || march_type == 'B' || march_type == 'b')){
            do {
                cout << "Invalid input. Please choose from A and B" << endl;
                cin >> march_type;
            } while (!(march_type == 'A' || march_type == 'a' || march_type == 'B' || march_type == 'b'));
        }

    } while (!(march_type == 'A' || march_type == 'a' || march_type == 'B' || march_type == 'b'));
    // Convert to lowercase for convenience
    march_type = tolower(march_type);


    // Param 2 : # of Rows for the Formation
    char formation;
    do {
        cout << "\n(Parameter 2)  Please select the number of rows for the formation.\n(A) 6 rows\t(B) 10 rows\t (C) 15 rows\n";
        cin >> formation;

        if (!(formation == 'A' || formation == 'a' || formation == 'B' || formation == 'b' || formation == 'C' || formation == 'c')){
            do {
                cout << "Invalid input. Please choose from A, B, C." << endl;
                cin >> formation;
            } while (!(formation == 'A' || formation == 'a' || formation == 'B' || formation == 'b' || formation == 'C' || formation == 'c'));
        }

    } while (!(formation == 'A' || formation == 'a' || formation == 'B' || formation == 'b' || formation == 'C' || formation == 'c'));
    // Convert to lowercase and numeric value for convenience
    formation = tolower(formation);
    (formation == 'a' ? form = 6 : formation == 'b' ? form = 10 : form = 15);


    // Param 3 : (max) # of Steps for Each Round
    bool intError;
    (march_type == 'a' ? cout << "\n(Parameter 3)  Please input the number of steps for each round in STEADY march: " : cout << "\n(Parameter 3)  Please input the maximum number of steps for each round in RANDOM march: ");
    cin >> n_step;

    // input data type validation (Three considerations : scale, non-zero, integer)
    intError = cin.fail();
    cin.clear();
    cin.ignore(INT_MAX, '\n');

    // wrong data type input
    if (intError) {
        cout << "Type Error!. Please enter a non-zero INTEGER : ";
        do {
            cin >> n_step;
            
            intError = cin.fail();
            cin.clear();
            cin.ignore(INT_MAX, '\n');

            // wrong data type again
            if (intError){
                cout << "Type Error! Please enter a non-zero INTEGER: ";
            }
            // out of range or zero input
            else if (n_step+form+2 > FINISH || n_step == 0){
                cout << "Range Error! Please enter a SMALLER and NON-ZERO integer: ";
            }
        } while(n_step+form+2 > FINISH || intError || n_step == 0);
    }

    // correct data type but out of range or zero
    else {
        if (n_step+form+2 > FINISH || n_step == 0){
            cout << "Range Error! Please enter a SMALLER and NON-ZERO integer: ";
            do {
                cin >> n_step;
                intError = cin.fail();
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                // wrong data type
                if (intError) {
                    cout << "Type Error! Please enter a non-zero INTEGER: ";
                }
                // out of range or zero
                else if (n_step+form+2 > FINISH || n_step == 0){
                    cout << "Range Error! Please enter a SMALLER and NON-ZERO integer: ";
                }
            } while (n_step+form+2 > FINISH || intError || n_step == 0);
        }
    }
    cout << "\n";
}
void swap(char troop[][40], int& row, int& col, int& step){
    // Swap the current location and the destination.
    char temp;
    temp = troop[row][col];
    troop[row][col] = troop[row][col+step];
    troop[row][col+step] = temp;
}
void steady_march (char troop[][40], int round, int form, int n_step){
    int row, col, r, c, frontrow;
    
    r = SOLDIER / form;             // row changes by the formation
    c = n_step * round;             // column changes every round by n_step
    frontrow = 2 + form + c;        // frontrow every round
    
    // Initialize every round
    for (row=5; row<5+r; row++){
        for (col=2; col<FINISH; col++){
            troop[row][col] = ' ';
        }
    }

    // When the troop not yet reaches the finish line.
    if (frontrow < FINISH){
        for (row=5; row<5+r; row++){
            for (col=2+c; col<frontrow; col++){
                troop[row][col] = '>';
            }
        }
    }

    // When the troop begins to reach the finish line.
    else {
        for (row=5; row<5+r; row++){
            for (col=2+c; col<FINISH; col++){
                troop[row][col] = '>';
            }
        }
    }

    printAll(troop);
}    
void random_march (char troop[][40], int round, int form, int n_step){
    int row, col;
    int r = SOLDIER / form;
    
    // Initialize only at first
    if (round == 0){
        for (row=5; row<5+r; row++){
            for (col=2; col<2+form; col++){
                troop[row][col] = '>';
            }
        }
    }

    srand(time(0));
    static int step = rand();

    for (row=5; row<15; row++){
        for (col=FINISH-1; col>1; col--){
            
            // Generate the random step for each soldier.
            step = rand()%(n_step) + 1;                                        

            // Not yet reaching the finish line,
            if (col+step < FINISH){                                     
                if (troop[row][col]=='>'){                              
                    
                    // Initial destination is clear, then swap.
                    if (troop[row][col+step]==' '){                     
                        swap(troop, row, col, step);                    
                    }

                    // If not, take the alternative destination.
                    else {
                        for (int i=1; i<step; i++){
                            if (troop[row][col+step-i]==' '){
                                step = step-i;
                                swap(troop, row, col, step);
                            }
                        }
                    }
                }
            }
            
            // Passing the finish line, let it disappear.
            else {
                troop[row][col] = ' ';
            }
        }
    }

    // print outside box, finish line, soldiers
    printAll(troop);
}
void runSimulation(char troop[][40], char stage, int& round, int n_step, int form, char march_type){
    int row, col;
    int r = SOLDIER / form;
    int count = 0;

    // Launch the corresponding march
    if (stage == 'a' || march_type == 'a'){                     // <stage 1> or <stage 3 + steady march>
        steady_march(troop, round, form, n_step);           
    }

    else if (stage == 'b'){                                     // <stage 2>           
        random_march(troop, round, form, 3);
    }

    else {                                                      // <stage 3 + random march> 
        random_march(troop, round, form, n_step);
    }


    // Count how many soldiers remained each round.
    for (row=5; row<5+r; row++){
        for (col=2; col<FINISH; col++){
            if (troop[row][col]=='>'){
                count ++;
            }
        }
    }

    // End simulation if no soldiers remained.
    if (count == 0){
        cout << "Finished!" << endl;
        exit(0);
    }      
}
