#ifndef  DATA_H
#define  DATA_H

#define MAX_PATIENTS 100
#define MAX_SLOTS 5
#define Name 50
#define Gender 2


typedef struct {
	u8 id;
    u8 name[Name];
    u8 age;
    u8 gender[Gender];
    
}Patient;

typedef struct {
    u8 id;
    u8 reserved;
}Slot;





#endif