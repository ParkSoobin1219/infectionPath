//
//  ifs_element.c
//  InfestPath
//
//  Created by Juyeop Kim on 2020/10/20.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ifct_element.h"

typedef enum place {
    Seoul,          //0
    Jeju,           //1
    Tokyo,          //2
    LosAngeles,     //3
    NewYork,        //4
    Texas,          //5
    Toronto,        //6
    Paris,          //7
    Nice,           //8
    Rome,           //9
    Milan,          //10
    London,         //11
    Manchester,     //12
    Basel,          //13
    Luzern,         //14
    Munich,         //15
    Frankfurt,      //16
    Berlin,         //17
    Barcelona,      //18
    Madrid,         //19
    Amsterdam,      //20
    Stockholm,      //21
    Oslo,           //22
    Hanoi,          //23
    Bangkok,        //24
    KualaLumpur,    //25
    Singapore,      //26
    Sydney,         //27
    SaoPaulo,       //28
    Cairo,          //29
    Beijing,        //30
    Nairobi,        //31
    Cancun,         //32
    BuenosAires,    //33
    Reykjavik,      //34
    Glasgow,        //35
    Warsow,         //36
    Istanbul,       //37
    Dubai,          //38
    CapeTown        //39
} place_t;

char countryName[N_PLACE+1][MAX_PLACENAME] =
{   "Seoul",
    "Jeju",
    "Tokyo",
    "LosAngeles",
    "NewYork",
    "Texas",
    "Toronto",
    "Paris",
    "Nice",
    "Rome",
    "Milan",
    "London",
    "Manchester",
    "Basel",
    "Luzern",
    "Munich",
    "Frankfurt",
    "Berlin",
    "Barcelona",
    "Madrid",
    "Amsterdam",
    "Stockholm",
    "Oslo",
    "Hanoi",
    "Bangkok",
    "KualaLumpur",
    "Singapore",
    "Sydney",
    "SaoPaulo",
    "Cairo",
    "Beijing",
    "Nairobi",
    "Cancun",
    "BuenosAires",
    "Reykjavik",
    "Glasgow",
    "Warsow",
    "Istanbul",
    "Dubai",
    "CapeTown",
    "Unrecognized"
};


// 도시 넘버에 맞는 도시 스트링을 출력해주는 함수
char* ifctele_getPlaceName(int placeIndex)
{
	return countryName[placeIndex];
};

int ifctele_getPlaceIndex(char arr[]){
	int index; //입력받은 장소에 해당하는 index 저장할 변수 
	int i,j; 
	
	//countrtname 과 입력 받은 배열을 비교해 같으면 인덱스 변수에 저장 
	for(i=0;i<N_PLACE;i++)
	{
		if(strcmp(countryName[i], arr)==0)
	      index=i;
	}
	
	return index; // 저장한 인덱스를 반환 
}


//구조체에 있는 정보들을 정렬하여 프린트 
void ifctele_printElement(void* obj, int i) 
{
	int* ip;
	ip=obj;
	int j;
	
	printf("-----------------------------------------------------------------------------------\n");
	printf("Patient index : %d\n", ip[0+i*8]);
	printf("Patient age : %d\n", ip[1+i*8]);
	printf("Detected time : %dth\n", ip[2+i*8]);
	printf("Path History :");
	for(j=3;j<3+N_HISTORY;j++)
	{
		printf("%s(%dth)  ", ifctele_getPlaceName(ip[j+i*8]),ip[i*8+2]-7+j);

	}
	printf("\n");
	printf("-----------------------------------------------------------------------------------\n");
	
}

//입력받은 장소에 있는 환자의 인덱스를 반환해주는 함수 
int ifctele_getHistPlaceIndex(void* obj, int index){
	int* ip;
	ip=obj;
	int j; 
	int pIndex; 
	
	//구조체의 마지막 요소가 입력 값과 같으면 해당 환자 인덱스를 저장 
	for(j=0;j<5;j++)
	{
		if(ip[j*8+7]==index)
		 pIndex=j;
	}; 
	
	return pIndex;
}

//환자의 나이가 범위 내에 존재하면 element들을 출력해주는 함수 
int ifctele_getAge(void* obj, int m, int M){
	int* ip;
	ip=obj;
	int i;
	
	//환자 5명에 대해서 
	for(i=0;i<5;i++)
	{
		//환자 정보의 두번째 요소가 최대 최소 이내이면 
		if(ip[i*8+1]>=m && ip[i*8+1]<=M)
		{
		  ifctele_printElement(obj, i); //printelement 함수로 환자 정보 출력해줌  
		  printf("\n");
		}  
	}
}


 
