#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>


int check_Key(int argc, string key);
char encryptLowerCase(char letter, string key);
char encryptUpperCase(char letter , string key);

int main(int argc, string argv[])
{
    //Step 1: Get and check key given by user
    string key = argv[1];
    int isKeyVaild = check_Key(argc, key);
    if(isKeyVaild != 0)
    {
        return isKeyVaild;
    };

    //Step 2: Start substituting
    char cipherText[200] = "";
    //Promnt user for plaintext
    string plaintext = get_string("plaintext: ");

    //Loop through plaintext and check if letter islowercase
    for(int i = 0, x = strlen(plaintext); i < x ; i++)
    {
        //The above loop should decide whether to call the encryptUppercase function or encryptlowerCase funtion
        if(islower(plaintext[i]))
        {
            char encryptLower = encryptLowerCase(plaintext[i],key);
            char convertedLowerChar[2] = "\0";
            convertedLowerChar[0] = encryptLower;
            strcat(cipherText,convertedLowerChar);


        }else if(isupper(plaintext[i]))
        {
            char encryptUpper = encryptUpperCase(plaintext[i],key);
            char convertedUpperChar[2] = "\0";
            convertedUpperChar[0] = encryptUpper;
            strcat(cipherText,convertedUpperChar);
        }else
        {
            char convertedChar[2] = "\0";
            convertedChar[0] = plaintext[i];
            strcat(cipherText,convertedChar);
        };
    };

    printf("ciphertext: %s\n",cipherText);

    return 0;
}

int check_Key(int argc, string key)
{
    if(argc != 2)
    {
        printf("Usage: ./substitution key \n");
        return 1;
    }else if(strlen(key) != 26)
    {
        printf("Key must contain 26 characters. \n");
        return 1;
    };

    for(int i = 0, x = strlen(key); i < x ; i++)
    {
        //perform duplicate check on letters

        char caseKey = toupper(key[i]);

        for(int z = 0, count = 0, y = strlen(key); z <= y ; z++)
        {
            char upperKey = toupper(key[z]);

            if(count == 2)
            {
                printf("Duplicate letter found \n");
                return 1;

            }else if(upperKey == caseKey)
            {
                count++;
            };
        };

        if(isalpha(key[i]))
        {

            continue;

        }else
        {
            printf("key contains non alphabatical letter \n");
            return 1;
        };

    };

    return 0;

};

//Funtion loops through alphabetical order string and checks if character matches current plaintext character
char encryptLowerCase(char letter , string key)
{
    string originalAlphabet = "abcdefghijklmnopqrstuvwxyz";

    for(int i = 0,  x = strlen(originalAlphabet); i < x; i++)
    {
        if(originalAlphabet[i] == letter)
        {
            //Once match is found , loop through key as many times and then return subtitute character
            for(int z = 0, y = strlen(key) ; z <= i && z < y; z++)
            {
                if( z == i)
                {

                    char casedKey = tolower(key[z]);
                    return casedKey;
                };
            };
        };
    };

    return '1';
};

//Funtion loops through alphabetical order string and checks if character matches current plaintext character
char encryptUpperCase(char letter , string key)
{
    string originalAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for(int i = 0,  x = strlen(originalAlphabet); i < x; i++)
    {
        if(originalAlphabet[i] == letter)
        {
            //Once match is found , loop through key as many times and then return subtitute character
            for(int z = 0, y = strlen(key) ; z <= i && z < y; z++)
            {
                if( z == i)
                {
                    char casedKey = toupper(key[z]);
                    return casedKey;
                };
            };
        };
    };

    return '1';
};