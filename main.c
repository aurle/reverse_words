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
    printf("   Reversed: %s\n", test_string);
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
    ReverseString(text, 0, length - 1);
    
    int wordstart = 0;
    int wordend = 0;
    while (wordend < length)
    {
        while(text[++wordend] != ' ' && wordend < length); // This is going to go one byte past the end
        wordend -= 1; // the previous byte is the actual end position
        ReverseString(text, wordstart, wordend);
        wordstart = wordend + 1; //start search for next word at end of this word
        while (text[++wordstart] == ' ' && wordstart < length); // skip to next character or end of string
        wordend = wordstart; //start of next word
    } 
}

/** \brief reverse a section of string
 *  \param text contains the string to be reversed
 *  \param first the first position of the area to be reversed
 *  \param last the last position of the area to be reversed
 */
void ReverseString(char *text, int first, int last)
{
    int halfway = (last-first+1)/2;
    char *begin_ptr = text + first;
    char *end_ptr = begin_ptr + last;
    for(int index = 0; index < halfway; index++, begin_ptr++, end_ptr--)
    {
        char *temp = begin_ptr;
        begin_ptr = end_ptr;
        end_ptr = temp;
    }	
}