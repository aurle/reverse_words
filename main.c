#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ReverseWords(char *, const size_t);
void ReverseString(char *, int start, int end);
void Usage();

int main(int argc, char * argv[])
{
    char *test_string = argv[1];
    if (argc < 2)
    {
        Usage();
    }

    printf("Test String: %s\n", test_string);
    ReverseWords(test_string, strlen(test_string));
    printf("Reversed: %s\n", test_string);
}

/** \brief Display usage on the command line
 */
void Usage(void) 
{
    printf("Reverse the words in a string\n");
    printf("reverse \"The quick brown fox jumped over the lazy dog\"\n");
    exit(0);
}

/** \brief reverse words in a string
 *  \param text contains a string with words
 *  \param length the length of the string
 */
void ReverseWords(char *text, const size_t length)
{
    ReverseString(text, 0, length);
    
    int wordstart = 0;
    int wordend = 0;
    while (wordend < length)
    {
        while(text[wordend++] != ' ' && wordend <= length);
        wordend -= 1;
        ReverseString(text, wordstart, wordend);
        wordstart = wordend;
        while (wordstart++ == ' ' && wordstart < length); // skip until the first character of the next word is found
        wordend = wordstart; //start of next word
    } 
}

/** \brief reverse a section of string
 *  \param text contains the string to be reversed
 *  \param start the beginning of that area to be reversed
 *  \param end the end of the area to be reversed
 */
void ReverseString(char *text, int start, int end)
{
    int halfway = (end-start)/2;
    for(int index = 0; index < halfway; index++)
    {
        char temp = text[start + index];
        text[start + index] = text[end - index - 1];
        text[end - index - 1] = temp;
    }	
}