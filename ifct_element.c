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


// ���� �ѹ��� �´� ���� ��Ʈ���� ������ִ� �Լ�
char* ifctele_getPlaceName(int placeIndex)
{
	return countryName[placeIndex];
};

int ifctele_getPlaceIndex(char arr[]){
	int index; //�Է¹��� ��ҿ� �ش��ϴ� index ������ ���� 
	int i,j; 
	
	//countrtname �� �Է� ���� �迭�� ���� ������ �ε��� ������ ���� 
	for(i=0;i<N_PLACE;i++)
	{
		if(strcmp(countryName[i], arr)==0)
	      index=i;
	}
	
	return index; // ������ �ε����� ��ȯ 
}


//����ü�� �ִ� �������� �����Ͽ� ����Ʈ 
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

//�Է¹��� ��ҿ� �ִ� ȯ���� �ε����� ��ȯ���ִ� �Լ� 
int ifctele_getHistPlaceIndex(void* obj, int index){
	int* ip;
	ip=obj;
	int j; 
	int pIndex; 
	
	//����ü�� ������ ��Ұ� �Է� ���� ������ �ش� ȯ�� �ε����� ���� 
	for(j=0;j<5;j++)
	{
		if(ip[j*8+7]==index)
		 pIndex=j;
	}; 
	
	return pIndex;
}

//ȯ���� ���̰� ���� ���� �����ϸ� element���� ������ִ� �Լ� 
int ifctele_getAge(void* obj, int m, int M){
	int* ip;
	ip=obj;
	int i;
	
	//ȯ�� 5�� ���ؼ� 
	for(i=0;i<5;i++)
	{
		//ȯ�� ������ �ι�° ��Ұ� �ִ� �ּ� �̳��̸� 
		if(ip[i*8+1]>=m && ip[i*8+1]<=M)
		{
		  ifctele_printElement(obj, i); //printelement �Լ��� ȯ�� ���� �������  
		  printf("\n");
		}  
	}
}


 
