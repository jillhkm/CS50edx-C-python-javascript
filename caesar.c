#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    //check for integer input
    if (argc != 2 || shift <= 0) {
        printf("Your shift number was invalid.");
        return 1;
    }

    //getting initial shift number
    int shift = atoi(argv[1]);

    //get message string
    string orgmessage = get_string ("plain text: ");
    int n = strlen(orgmessage);
    char lowercase[n];
    strcpy(lowercase, orgmessage);
    for (int i = 0; i < n; i++) {
        lowercase[i] = tolower(lowercase[i]);
    }

    //encryptstring
    int actshift = shift % 26;
    //check for value above 122 (ascii 'z')
    for (int i = 0; i < n; i++) {
        int chshift = lowercase[i] + actshift;
        if (lowercase[i] > 96 && lowercase[i] < 123){
            if (chshift > 122) {
                chshift -= 26;
                lowercase[i] = (chshift);
            }
            else {
                lowercase[i] = (chshift);

            }
        }
    }

    //change lower back to upper if needed
    for (int i = 0; i < n; i++) {
        if(isupper(orgmessage[i])) {
            lowercase[i] = toupper(lowercase[i]);
        }
    }

    //print encrypted message
    printf("ciphertext: %s\n ", lowercase);
    return 0;

}