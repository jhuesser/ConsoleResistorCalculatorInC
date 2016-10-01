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


void listColors() {
    
    printf("[1] no color\n");
    printf("[2] silver\n");
    printf("[3] gold\n");
    printf("[4] black\n");
    printf("[5] brown\n");
    printf("[6] red\n");
    printf("[7] orange\n");
    printf("[8] yellow\n");
    printf("[9] green\n");
    printf("[10] blue\n");
    printf("[11] purple\n");
    printf("[12] grey\n");
    printf("[13] white\n");
    
    
    
    
}

char* getColorValues(int colorNmb){
    
    char* colorValue;
    
    switch (colorNmb) {
        case 1:
            colorValue = "no-color";
            break;
        case 2:
            colorValue = "silver";
            break;
        case 3:
            colorValue = "gold";
            break;
        case 4:
            colorValue = "black";
            break;
        case 5:
            colorValue = "brown";
            break;
        case 6:
            colorValue = "red";
            break;
        case 7:
            colorValue = "orange";
            break;
        case 8:
            colorValue = "yellow";
            break;
        case 9:
           colorValue = "green";
            break;
        case 10:
            colorValue = "blue";
            break;
        case 11:
            colorValue = "purple";
            break;
        case 12:
            colorValue = "grey";
            break;
        case 13:
            colorValue = "white";
            break;
        default:
            printf("This color is invalid");
            
            break;
    }
    
    return colorValue;
    
}


char* getFirstColor() {
    
    char* firstColor;
    int colorNmb;
    
    printf("Please type the number of the color of the first ring\n");
    listColors();
    scanf("%d",&colorNmb);
    

    
    firstColor = getColorValues(colorNmb);
    
    
    
    return firstColor;
    
}


char* getSecondColor() {
    
    char* secondColor;
    int colorNmb;
    
    printf("Please type the number of the color of the second ring\n");
    listColors();
    scanf("%d",&colorNmb);
    
    
    
    secondColor = getColorValues(colorNmb);
    
    
    
    return secondColor;
    
}


char* getThirdColor() {
    
    char* thirdColor;
    int colorNmb;
    
    printf("Please type the number of the color of the third ring\n");
    listColors();
    scanf("%d",&colorNmb);
    
    
    
    thirdColor = getColorValues(colorNmb);
    
    
    
    return thirdColor;
    
}


char* getFourthColor() {
    
    char* fourthColor;
    int colorNmb;
    
    printf("Please type the number of the color of the 4th ring\n");
    listColors();
    scanf("%d",&colorNmb);
    
    
    
    fourthColor = getColorValues(colorNmb);
    
    
    
    return fourthColor;
    
}


char* getFifthColor() {
    
    char* fifthColor;
    int colorNmb;
    
    printf("Please type the number of the color of the 5th ring\n");
    listColors();
    scanf("%d",&colorNmb);
    
    
    
    fifthColor = getColorValues(colorNmb);
    
    
    
    return fifthColor;
    
}

char* setupAPIcall(const char *color1, const char *color2, const char *color3, const char *color4, const char *color5) {
    
    char *callURL;
    char* rootURL = "https://api.widerstandsberechner.ch/api.php?";
    
    strcpy(callURL, rootURL);
    
    
    return callURL;
}


int main(int argc, const char * argv[]) {
    
    //number of rings a user enters
    int nmbOfRings;
    //request value for API; needs to be char to include in in POST URL.
    int hasFiveRings;
     //char firstColorName;
    char* firstColor;
    char* secondColor;
    char* thirdColor;
    char* fourthColor;
    char* fifthColor;
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
        
    
    firstColor = getFirstColor();
    secondColor = getSecondColor();
    thirdColor = getThirdColor();
    fourthColor = getFourthColor();
    if (hasFiveRings == 1) {
        fifthColor = getFifthColor();
    } else {
        firstColor = 0;
        
    }
    
    
    
    
    char* apiCall;
    
    apiCall = setupAPIcall(firstColor, secondColor, thirdColor, fourthColor, firstColor);
    
    printf("%s", apiCall);
    
    
   
    
    
   
    
   
    
    
    
    
    return 0;
}
