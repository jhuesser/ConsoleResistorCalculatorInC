//
//  main.c
//  resistorCalculatorInC
//
//  Created by Jonas Hüsser on 28.09.16.
//  Check LICENCE file for the licence
//

#include <stdio.h>
#include <string.h>

int errorHandler(int errNmb, char errMsg[]) {
    
    printf("Error %i: %s \n", errNmb, errMsg);
    
    main();
    return 0;
}

char* getFirstColor() {
    
     char firstColor;
    int isErrorOccured;
    printf("Please write the color of your first ring in english: \n");
    scanf("%s",&firstColor);
    
    //why C, oh why my dear C you don't have a switch for strings / chars...? I hate you.
    
    if (strcmp(&firstColor, "brown") == 0) {
        isErrorOccured = 0;
    } else if (strcmp(&firstColor, "red") == 0) {
        isErrorOccured = 0;
    } else if (strcmp(&firstColor, "orange") == 0) {
        isErrorOccured = 0;
    } else if (strcmp(&firstColor, "yellow") == 0) {
        isErrorOccured = 0;
    } else if (strcmp(&firstColor, "green") == 0) {
        isErrorOccured = 0;
    } else if (strcmp(&firstColor, "blue") == 0) {
        isErrorOccured = 0;
    } else if (strcmp(&firstColor, "purple") == 0) {
        isErrorOccured = 0;
    } else if (strcmp(&firstColor, "grey") == 0) {
        isErrorOccured = 0;
    } else if (strcmp(&firstColor, "white") == 0) {
        isErrorOccured = 0;
    } else {
        
        isErrorOccured = 1;
    }
    
    
    if (isErrorOccured == 1) {
        errorHandler(101, "This color can't be at this position");
    }
    
    
    return &firstColor;
}




int main(int argc, const char * argv[]) {
    
    //number of rings a user enters
    int nmbOfRings;
    //request value for API; needs to be char to include in in POST URL.
    int hasFiveRings;
     //char firstColorName;
    
    //welcome text
    printf("Welcome to Jonas Hüsser's resistor calculator \n");
    //seperator
    printf("----------------------------------------------\n");
    //asks the user how much rings the resistor has; accepted values: 4 or 5
    printf("Please enter if your resistor has 4 or 5 rings [4/5]\n");
    //saves the input
    scanf("%d",&nmbOfRings);
   
    //checks the input and sets the value for POSTing
    //for 4 rings
    if (nmbOfRings == 4) {
        //hasFiveRings = false
        hasFiveRings = 0;
        
        
    } else if (nmbOfRings == 5) {
        //if it has 5 rings
        hasFiveRings = 1;
    } else {
        
        errorHandler(102, "Invalid number of rings");
        
    }
        
    char firstColorName = *getFirstColor();
    
    
    
    printf("%c", firstColorName);
    
    
    
    
    return 0;
}
