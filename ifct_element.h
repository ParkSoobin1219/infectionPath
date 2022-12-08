//
//  ifct_element.h
//  infection path
//
//  Created by Juyeop Kim on 2022/10/20.
//

#ifndef ifct_element_h
#define ifct_element_h

#define N_PLACE                     40
#define N_HISTORY                   5
#define MAX_PLACENAME               100

void* ifctele_genElement(int index, int age, unsigned int detected_time, int history_place[N_HISTORY]); //?????????????

char* ifctele_getPlaceName(int placeIndex); // 인덱스를 넣으면 도시 이름을 string 으로 뱉어주는 함수 (0)

int ifctele_getHistPlaceIndex(void* obj, int index);

unsigned int ifctele_getinfestedTime(void* obj);

int ifctele_getAge(void* obj);

void ifctele_printElement(void* obj, int i);
#endif /* ifct_element_h */
