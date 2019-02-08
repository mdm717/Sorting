#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void sort(char *words[], int len){
        char *temp; 
        int x, y;
        for(x=0; x<len; x++)
        {
                for(y=x+1; y<len; y++)
                {
                        if(strcmp(words[x], words[y]) > 0)        
                        {
                                temp = words[y];    
                                words[y] = words[x];
                                words[x] = temp;
                        }
                }         
        }
}

int main(int argc, char* argv[]){
        if(argc < 2 || argc > 2)
        {
                printf("error.\n");
                return 0;
        }

	int i;
  	int j = 0;
        char *argString = (char*)malloc((argc)*sizeof(char));
	argString = argv[1];

        //replaces any non alphabetical characters with spaces
        for(i=0; i<strlen(argString); i++)
        {
                if(!isalpha(argString[i]))
                {
                        argString[i] = ' ';
                }
        }
	
        //tokenizes the character array of tempString
        char *newString[strlen(argString)];
        char *token = strtok(argString, " ");
        while(token)
        {
                newString[j] = token;   //takes full words from tempString and makes them a single object in newString
                token = strtok(NULL, " ");
                j++;
        }
	
	//sorts array newString in alphabetical order	
	sort(newString, j);
	
        for(i=0; i<j; i++)
	{
	        printf("%s\n", newString[i]);
        }
        return 0;
}


