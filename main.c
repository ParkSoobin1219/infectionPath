//
//  main.c
//  infestPath
//
//  Created by Juyeop Kim on 2022/10/20.
//

#include <stdio.h>
#include <string.h>
#include "ifct_element.h"
#include "ifct_database.h"

#define MENU_PATIENT        1
#define MENU_PLACE          2
#define MENU_AGE            3
#define MENU_TRACK          4
#define MENU_EXIT           0

#define TIME_HIDE           2


int trackInfester(int patient_no, int *detected_time, int *place);

int main(int argc, const char * argv[]) {
    
    int menu_selection; //button number
    int *ifct_element;
	FILE* fp;
    int pIndex, age, time, placeIndex;
    char investPlace[MAX_PLACENAME];
    int mAge, MAge;
    //int placeHist[N_HISTORY];
    struct patientinfotxt {
		int pIndex, age, time;
		int placeHist[N_HISTORY];
	};
	
	struct patientinfotxt h[5];
    
    
    
    
    
//------------------------------- 1. loading patient info file ------------------------------
    //1-1. FILE pointer open
    if (argc != 2)
    {
        printf("[ERROR] syntax : infestPath (file path).");
        return -1;
    }
    
    fp = fopen(argv[1],"r");
    if (fp == NULL)
    {
        printf("[ERROR] Failed to open database file!! (%s)\n", argv[1]);
        return -1;
    }
    
    
    
	//1-2. loading each patient informations
	int i=0;
    while(!feof(fp))
	{
		fscanf(fp, " %d %d %d", &h[i].pIndex, &h[i].age, &h[i].time);
		int j;
		for(j=0;j<N_HISTORY;j++){
			fscanf(fp, " %d", &h[i].placeHist[j]);
		}
	    
        i++;
        if(feof(fp)) break;
	}
	
	
	
    //1-3. FILE pointer close
    fclose(fp);
	
    
	
	
	
    
//--------------------------------------2.Program 동작---------------------------------------------------- 

    do {
    	printf("\n");
        printf("\n=============== INFECTION PATH MANAGEMENT PROGRAM (No. of patients : %i) =============\n", ifctdb_len());
        printf("1. Print details about a patient.\n");                      //MENU_PATIENT
        printf("2. Print list of patients infected at a place.\n");        //MENU_PLACE
        printf("3. Print list of patients in a range of age.\n");          //MENU_AGE
        printf("4. Track the root of the infection\n");                     //MENU_TRACK
        printf("0. Exit.\n");                                               //MENU_EXIT
        printf("========================================================================================\n\n");
        
        printf("Select a menu :");
        scanf("%d", &menu_selection);
        fflush(stdin);
        
        switch(menu_selection)
        {
        	//종료 문구 출력 
            case MENU_EXIT:
                printf("Exiting the program... Bye bye.\n");
                break;
            
			//patient index를 입력 받고 해당 환자의 정보 출력    
            case MENU_PATIENT:
                printf("Patient index :");
                scanf("%d", &pIndex);
                ifct_element=h;
                ifctele_printElement(ifct_element, pIndex);
                break;
            
			//place 를 입력받아 해당 장소에서 확진된 환자 출력 및 확진 환자 수 출력    
            case MENU_PLACE:
                printf("Place Name :");
                scanf("%s", investPlace); 
                placeIndex=ifctele_getPlaceIndex(investPlace);
                ifct_element=h;
                pIndex=ifctele_getHistPlaceIndex(ifct_element, placeIndex);
                ifctele_printElement(ifct_element, pIndex);
                printf("There is(are) %d patient(s) detected in %s\n", 1, ifctele_getPlaceName(placeIndex));
                break;
            
			//최소,최대 나이 입력 받고 범위 내 나이의 환자 출력    
            case MENU_AGE:
                printf("minimal age :");
                scanf("%d", &mAge);
                printf("maximal age :");
                scanf("%d", &MAge);
                ifct_element=h;
                ifctele_getAge(ifct_element, mAge, MAge);
                break;
            
			//감염 경로 추적    
            case MENU_TRACK:
                printf("Patient index :");
                //scanf("%d", &);    
                break;
                
            default:
                printf("[ERROR Wrong menu selection! (%i), please choose between 0 ~ 4\n", menu_selection);
                break;
        }
    
    } while(menu_selection != 0); // 메뉴 exit을 누르기 전에는 계속 반복 
    
    
    return 0;
}
