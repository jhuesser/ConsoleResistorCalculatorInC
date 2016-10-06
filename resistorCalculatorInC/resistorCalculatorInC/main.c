//
//  main.c
//  resistorCalculatorInC
//
//  Created by Jonas Hüsser on 28.09.16.
//  Check LICENCE file for the licence
//
//  For API documentation check https://github.com/jhuesser/ResistorCalculatorAPI
//  This project is aviable at https://github.com/jheusser/ConsoleResistorCalculatorInC
//

#include <stdio.h>
#include <string.h>
#include <curl/curl.h>


/*My error handling function
Used same error numbers like in API*/
int errorHandler(int errNmb, char errMsg[]) {
    
    //prints error number and error message
    printf("Error %i: %s \n", errNmb, errMsg);
    
    //starts program again
    main();
    //returns error number
    return errNmb;
}

//function to list all colors
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

//this function checks the input and assigns the number
char* getColorValues(int colorNmb){
    
    char* colorValue;
    
    //shitty C doesn't has a switch case for chars. OH I HATE IT!!
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
            errorHandler(102, "This color is invalid");
            
            break;
    }
    
    return colorValue;
    
}

// I've used multiple function, so i can do some error handling later.

//get the first color

char* getFirstColor() {
    
    char* firstColor;
    int colorNmb;
    
    printf("Please type the number of the color of the first ring\n");
    listColors();
    scanf("%d",&colorNmb);
    

    
    firstColor = getColorValues(colorNmb);
    
    
    
    return firstColor;
    
}

//get second color

char* getSecondColor() {
    
    char* secondColor;
    int colorNmb;
    
    printf("Please type the number of the color of the second ring\n");
    listColors();
    scanf("%d",&colorNmb);
    
    
    
    secondColor = getColorValues(colorNmb);
    
    
    
    return secondColor;
    
}

//get 3rd color

char* getThirdColor() {
    
    char* thirdColor;
    int colorNmb;
    
    printf("Please type the number of the color of the third ring\n");
    listColors();
    scanf("%d",&colorNmb);
    
    
    
    thirdColor = getColorValues(colorNmb);
    
    
    
    return thirdColor;
    
}

//get 4th color

char* getFourthColor() {
    
    char* fourthColor;
    int colorNmb;
    
    printf("Please type the number of the color of the 4th ring\n");
    listColors();
    scanf("%d",&colorNmb);
    
    
    
    fourthColor = getColorValues(colorNmb);
    
    
    
    return fourthColor;
    
}


//get 5th color

char* getFifthColor() {
    
    char* fifthColor;
    int colorNmb;
    
    printf("Please type the number of the color of the 5th ring\n");
    listColors();
    scanf("%d",&colorNmb);
    
    
    
    fifthColor = getColorValues(colorNmb);
    
    
    
    return fifthColor;
    
    
    
    
    
}

//maybe enable this in the future. but just maybe

/*
void calculateResultViaAPI(char* callURL) {
    
    
    CURL *hnd = curl_easy_init();
    
    curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, "GET");
    curl_easy_setopt(hnd, CURLOPT_URL, callURL);
    
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "postman-token: 0303ff27-260e-52ca-77f4-8a98089355c7");
    headers = curl_slist_append(headers, "cache-control: no-cache");
    headers = curl_slist_append(headers, "as-key: eh3X9PIiWPo5jlFkebMR");
    curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, headers);
    
    CURLcode ret = curl_easy_perform(hnd);
    
}

*/


//the main functions

int main(int argc, const char * argv[]) {
    
    //number of rings a user enters
    int nmbOfRings;
    //request value for API; needs to be char to include in in POST URL.
    int hasFiveRings;
    
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
        //sends en error message.
        errorHandler(103, "Invalid number of rings");
        
    }
        
    //get the colors.
    firstColor = getFirstColor();
    secondColor = getSecondColor();
    thirdColor = getThirdColor();
    fourthColor = getFourthColor();
    if (hasFiveRings == 1) {
        fifthColor = getFifthColor();
    } else {
        firstColor = 0;
        
    }
    
    
    
    //i hate C. I want strings. I WANT STRINGS!!!
    char apiCall[1000];
    
    //the root URL of my API
    char* rootURL = "https://api.widerstandsberechner.ch/api.php?";
    
    //put togheter the call URL
    sprintf(apiCall, "%sfirstcolor=%s&secondcolor=%s&thirdcolor=%s&fourthcolor=%s&fifthcolor=%s&resultInText=1", rootURL, firstColor, secondColor, thirdColor, fourthColor, fifthColor);
    
   
   //maybe enable this too in the future....
    
    //calculateResultViaAPI(apiCall);

    
    // HERE IS WERE THE MAGIC HAPPENS GUYS!
   
    //value for the HTTP request.
    CURL *hnd = curl_easy_init();
    
    //define request type. (API works with GET and POST)
    curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, "POST");
    //set the URL for the HTTP POST request
    curl_easy_setopt(hnd, CURLOPT_URL, apiCall);
    
    //define the HTTP headers
    struct curl_slist *headers = NULL;
    //need no cache
    headers = curl_slist_append(headers, "cache-control: no-cache");
    //headers = curl_slist_append(headers, "as-key: eh3X9PIiWPo5jlFkebMR");
    
    //complete the final request
    curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, headers);
    
    //make the request. ret is the return code, but don't need that.
    CURLcode ret = curl_easy_perform(hnd);
   
    //print new line
    
    printf("\n");
    
    return 0;
}
