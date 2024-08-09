#ifndef  DEFINITIONS_H
#define  DEFINITIONS_H

#define true 1
#define false 0

#define admin 1
#define user 2

#define start 0
#define start_time 2
#define hour 60

#define default_admin_password 1234
#define max_number_of_attempts 3

//features of admin mode
#define Cancel_reservation 0
#define interval 30

#define Admin_mode 1

#define Add_patient 1 
#define Edit_patient 2
#define Reserve_slot 3
#define Cancel_reserve 4
#define Exit_admin_mode 5

#define View_patient_record 1
#define View_reservations 2
#define Exit_user_mode 3

//definition of functions 
u8 admin_mode(void);
void add_patient(void);
void edit_patient(void);
void reserve_slot(void);
void cancel_reservation(void);
void view_patient_record(void);
void view_reservations(void);



#endif