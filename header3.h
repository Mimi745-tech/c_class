#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flats.h"
#ifndef header3_h
#define  header3_h
void write_to_file(struct Flat* flats,int n){
    FILE *fpnt = fopen("Flats.txt","a");
    if(fpnt == NULL){
        printf("File wasn't created");
        return;
    } for (int i=0;i<n;i++){
        fprintf(fpnt,"%d;%d;%s;%d;%s;%s;%2.f\n",
            flats[i].number,
            flats[i].rooms,
            flats[i].name,
            flats[i].owner,
            flats[i].booked ? "Yes": "No",
            flats[i].street,
            flats[i].rent, 
);
    }    
        fclose(fpnt);
    }

void read_from_file(struct Flat *flats,int n){
   FILE *fpnt= fopen("Flats.txt","r");
    if(fpnt == NULL){
      printf("File wasn't created");
      return;
    }
   char line[100];
   int i=0;

if (fpnt != NULL){
while (fgets(line, 100, fpnt)&& i<n)
        {
            char *token;
            token = strtok(line, ";");
            int flag=1;
            while( token != NULL )
            { 
        
                if(flag==1){
                    flats[i].number=atoi(token);}
                else if(flag==2){
                    flats[i].rooms=atoi(token);
                }
                else if(flag==3){
                    strcpy(flats[i].name,token);
                }
                else if(flag==4){
                    strcpy(flats[i].owner,token);
                }
                else if(flag==5){
                    flats[i].booked=(strcmp(token,"Yes")==0);
                }
                else if(flag==6){
                    strcpy(flats[i].street,token);
                }
                else{
                    if(token[strlen(token)-1]=='\n'){
                        token[strlen(token)-1]='\0';
                    }
                        flats[i].rent= atof(token);
                }
                token = strtok(NULL, ";");
                flag++;
              
        
 
            if(flag>7){
                flag=1;
            }
    }
       i++;

}
    fclose(fpnt);

}

#endif
