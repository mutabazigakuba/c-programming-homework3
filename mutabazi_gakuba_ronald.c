#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define sizeOfInput 100

// global variables
char *cryptionToUse;
char *cypherToUse;
char *inputFileName;
char *outputFileName;
int repeatProcess = 0;
char alphabets[27];
int offSet;

//methods
void createAlphabets();
void selectCryption();
void selectCypher();
void getInputFile();
void getOutputFile();
void encryptCaesar();
void decryptCaeser();
void encryptRandom();
void decryptRandom();
void chooseToContinue();
void getOffset();
void shuffleAlphabet();

int main(){

    do {
        createAlphabets();
        selectCryption();
        selectCypher();
        getInputFile();
        getOutputFile();
        if ((strcmp(cryptionToUse,"encrypt")==0) && (strcmp(cypherToUse,"caesar")==0)){
            getOffset();
            encryptCaesar();
        } else if((strcmp(cryptionToUse,"encrypt")==0) && (strcmp(cypherToUse,"random")==0)) {
            getOffset();
            encryptRandom();
        } else if ((strcmp(cryptionToUse,"decrypt")==0) && (strcmp(cypherToUse,"caesar")==0)) {
            getOffset();
            decryptCaeser();
        } else if ((strcmp(cryptionToUse,"decrypt")==0) && (strcmp(cypherToUse,"random")==0)) {
            getOffset();
            decryptRandom();
        } else {
            printf("Oops, something went wrong :(\n");
        }
        chooseToContinue();
    } while (repeatProcess < 1);
}

void createAlphabets() {
    int i;
    for(i=0; i<26; i++){
        alphabets[i] = 'a'+i;
    }
    alphabets[i]='\0';
}

void getOffset() {
    int i;
    printf("What is the offset? \n");
    scanf("%d", &i);
    offSet = i;
}

void selectCryption(){
    char input1[sizeOfInput];
    int repeat = 0;
    char enc[] = "encrypt\n";
    char dec[] = "decrypt\n";

    do{
        printf("Would like to encrypt or decrypt?\n");
        fgets(input1, sizeOfInput, stdin);
        char * word;
        word = strtok(input1, " ");

        if (strcmp(word,enc) == 0){
            printf("encrypt was selected\n");
            cryptionToUse = "encrypt";
            repeat++;
        } else if (strcmp(word,dec) == 0){
            printf("decrypt was selected\n");
            cryptionToUse = "decrypt";
            repeat++;
        } else{
            printf("Please type 'encrypt' or 'decrypt'\n");
        }
    } while (repeat < 1);

}

void selectCypher(){
    char input1[sizeOfInput];
    int repeat = 0;
    char cae[] = "caesar\n";
    char ran[] = "random\n";

    do{
        printf("Would like to use caesar or random? \n");
        fgets(input1, sizeOfInput, stdin);
        char * word;
        word = strtok(input1, " ");

        if (strcmp(word,cae) == 0){
            printf("caesar was selected\n");
            cypherToUse = "caesar";
            repeat++;
        } else if (strcmp(word,ran) == 0){
            printf("random was selected\n");
            cypherToUse = "random";
            repeat++;
        } else{
            printf("Please type 'caesar' or 'random'\n");
        }
    } while (repeat < 1);

}

void getInputFile(){
    char fileinput[sizeOfInput];
    printf("What is the input file name?\n");
    scanf("%s", fileinput);
    inputFileName = fileinput;
    printf("Input file name: %s \n", inputFileName);
}

void getOutputFile(){
    char fileoutput[sizeOfInput];
    printf("What is the output file name?\n");
    scanf("%s", fileoutput);
    outputFileName = fileoutput;
    printf("Output file name: %s %s \n", outputFileName, inputFileName);
}

void encryptCaesar(){
    char *filename = outputFileName;
    FILE *file = fopen(filename, "w");
    for (int i=0; i < strlen(alphabets); i++){
        fprintf(file,"%c -> %d\n", alphabets[i], offSet++);
    }
    fclose(file);

    char *inputfile = inputFileName;
    FILE *fileinput = fopen(inputfile, "r");
    //check if file exists
    if (fileinput == NULL) {
        printf("Error: can't find or open file.\n");
        repeatProcess++;
    } else{
        char singleLine[sizeOfInput];
        while (!feof(fileinput)){
            fgets(singleLine, sizeOfInput, fileinput);
            for (int i = 0; i < strlen(singleLine); i++){
                if (isalpha(singleLine[i]) == 0){
                    printf("%c is not an alphabet. \n", singleLine[i]);
                } else {
                    for (int j = 0; j < strlen(alphabets); j++){
                        if (tolower(singleLine[i]) == alphabets[j]){
                            int position  = (j + offSet) % 26;
                            printf("%c is %c \n",singleLine[i], alphabets[position]);
                            fprintf(fileinput,"%c \n", alphabets[position]);
                        }
                    }                
                }
            }
        }
    }
    fclose(fileinput);
    printf("encrypt using caesar done!\n");
}

void decryptCaeser(){
    char *filename = outputFileName;
    FILE *file = fopen(filename, "w");
    for (int i=0; i < strlen(alphabets); i++){
        fprintf(file,"%c -> %d\n", alphabets[i], offSet++);
    }

    fclose(file);

    FILE *fileinput = fopen(inputFileName, "r");
    if (fileinput == NULL) {
        printf("Error: can't find or open file.\n");
        repeatProcess++;
    } else{
        char singleLine[sizeOfInput];
        while (!feof(fileinput)){
            fgets(singleLine, sizeOfInput, fileinput);
            // puts(singleLine); // display on cmd
            for (int i = 0; i < strlen(singleLine); i++){
                if (isalpha(singleLine[i]) == 0){
                    printf("%c is not an alphabet. \n", singleLine[i]);
                } else {
                    for (int j = 0; j < strlen(alphabets); j++){
                        if (tolower(singleLine[i]) == alphabets[j]){
                            int position  = (abs(j - offSet)) % 26;
                            printf("%c is %c \n",singleLine[i], alphabets[position]);
                            fprintf(fileinput,"%c \n", alphabets[position]);
                            return;
                        }
                    }                
                }                
            }                
        }
    }
    fclose(fileinput);
    printf("decrypt using caesar done!\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void encryptRandom(){
    char *filename = outputFileName;
    FILE *file = fopen(filename, "w");

    // begin shuffle
    int arr[26];
    int n = 26;
    char shuffledLetters[26];

    for (int i = 0; i < 26; i++){
        arr[i] = i;
    }
    
    char *letters[] = {
        "a", "b", "c", "d", "e", "f", "g", "h", "i", "j","k","l","m",
        "n","o","p","q","r","s","t","u","v","w","x","y","z"
    };

    srand(time(NULL));
    for(int i = n-1; i > 0; i--) {
        int j = rand() % (i+1);
        swap(&arr[i], &arr[j]);
    }

    for(int i=0; i<n; i++) {
        int index1 = arr[i];
        // shuffledLetters = letters[index1]; // find a way to store randomised
        for (int j = 0; j < 26; j++) {
            if((letters[index1]) == (letters[j])) {
                int position = (j+offSet) % 26;
                fprintf(file,"%s \n", letters[position]);
            }
        }
    }
    // end shuffle
    fclose(file);
    
    FILE *fileinput = fopen(inputFileName, "r");
    char singleLine[sizeOfInput];
    while (!feof(fileinput)){
        fgets(singleLine, sizeOfInput, fileinput);
        for (int i = 0; i < strlen(singleLine); i++){
            if (isalpha(singleLine[i]) == 0){
                printf("%c is not an alphabet. \n", singleLine[i]);
            } else {
                for (int j = 0; j < 26; j++){
                    if (i == j){
                        fprintf(fileinput,"%s \n", letters[j]);
                        return;
                    }
                }                
            }
        }
    }
    fclose(fileinput);
    printf("encrypt and random compute done!\n");
}

void decryptRandom() {
    // get randomized letters and 
    // substract the offset from the first line of input file
    char *letters[] = {
        "a", "b", "c", "d", "e", "f", "g", "h", "i", "j","k","l","m",
        "n","o","p","q","r","s","t","u","v","w","x","y","z"
    };

    FILE *fileinput = fopen(inputFileName, "r");
    char singleLine[sizeOfInput];
    while (!feof(fileinput)){
        fgets(singleLine, sizeOfInput, fileinput);
        for (int i = 0; i < strlen(singleLine); i++){
            if (isalpha(singleLine[i]) == 0){
                printf("%c is not an alphabet. \n", singleLine[i]);
            } else {
                int position = (abs(i - 2)) % 26;
                printf("%s \n", letters[position]);   // store this in an array         
            }
        }
    }
    fclose(fileinput);

    // compute the text as you read thru the rest of the file
    FILE *file = fopen(outputFileName, "r");
    FILE *filename = fopen(outputFileName, "r");
    char singleLine2[sizeOfInput];
    while (!feof(file)){
        fgets(singleLine2, sizeOfInput, file);
        for (int i = 0; i < strlen(singleLine2); i++){
            if (isalpha(singleLine2[i]) == 0){
                printf("%c is not an alphabet. \n", singleLine2[i]);
            } else {
                for (int j = 0; j < 26; j++){
                    if (i == j){
                        fprintf(filename,"%s \n", letters[j]);
                        return;
                    }
                }                
            }
        }
    }
    fclose(filename);
    fclose(file);
    printf("decrypt and random compute done!\n");
}

void chooseToContinue() {
    printf("Would like to continue? Type 'N' or 'NO' or 'n' or 'no' to stop \n");
    char input1[sizeOfInput];
    fgets(input1, sizeOfInput,stdin);
    char * word;
    word = strtok(input1, " ");
    if ((strcmp(word,"N\n") == 0) || (strcmp(word,"NO\n") == 0) || (strcmp(word,"no\n") == 0) || (strcmp(word,"n\n") == 0)) {
        repeatProcess++;
    }
}