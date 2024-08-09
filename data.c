#include<stdio.h>
#include<string.h>
#include"STD_TYPS.h"
#include"definitions.h"
#include"data.h"



Patient patients[MAX_PATIENTS];
Slot slots[MAX_SLOTS];
u8 counter =start;

u8 admin_mode(void)
{
    u16 password;
    u8 attempts = start;

    while (attempts < max_number_of_attempts)
	{
        printf("Enter Admin Password: ");
        scanf("%d",&password);
        if (password == default_admin_password)
		{
            return true;
        }
		else 
		{
        printf("Incorrect password. Try again.\n");
        attempts++;
		}
    }
    return false;
}

void add_patient(void)
{ 
    if (counter >= MAX_PATIENTS)
	{
        printf("Patient list is full.\n");
    }
	
    Patient new_patient;
    printf("Enter Patient ID: ");
    scanf("%d", &new_patient.id);
	
	u8 i = start;
    for (i ; i <counter; i++)
	{
        if (patients[i].id == new_patient.id) 
		{
            printf("ID already exists. Entry rejected.\n");
        }
    }
	
    printf("Enter patient name: ");
    scanf("%s", new_patient.name);
    printf("Enter patient age: ");
    scanf("%d", &new_patient.age);
    printf("Enter patient gender: ");
    scanf("%s", new_patient.gender);

    patients[counter] = new_patient;
	counter++;
    printf("Patient record added.\n");
	
}

void edit_patient(void)
{
    u8 id;
    printf("Enter patient ID to edit: ");
    scanf("%d", &id);
	u8 i=start;
    for (i ; i<counter ; i++)
	{
        if (patients[i].id == id)
		{
            printf("Enter new patient name: ");
            scanf("%s", patients[i].name);
            printf("Enter new patient age: ");
            scanf("%d", &patients[i].age);
            printf("Enter new patient gender: ");
            scanf("%s", patients[i].gender);
            printf("Patient record updated.\n");
			return; 
        }
    }
    printf("Incorrect ID. No record found.\n");
}

void reserve_slot(void)
{
    printf("Available slots:\n");
	u8 i = start;
    for (i; i < MAX_SLOTS; i++)
	{
        if (slots[i].reserved=false)
		{
            printf("%d. %dpm to %d:%d0pm\n", i + true, slots[i].id, slots[i].id,interval);
        }
    }

    u8 slot_choice, patient_id;
    printf("Enter patient ID: ");
    scanf("%d", &patient_id);
    printf("Enter desired slot number: ");
    scanf("%d", &slot_choice);

    if (slot_choice < true || slot_choice > MAX_SLOTS || slots[slot_choice - true].reserved)
	{
        printf("Invalid slot choice.\n");
		return;
    }
    slots[slot_choice - true].reserved = patient_id;
    printf("Slot reserved.\n");
}


void cancel_reservation(void) 
{
    u8 patient_id;
    printf("Enter patient ID to cancel reservation: ");
    scanf("%d", &patient_id);
	u8 i = start;
    for (i; i < MAX_SLOTS; i++)
	{
        if (slots[i].reserved == patient_id)
		{
            slots[i].reserved = Cancel_reservation;
            printf("Reservation cancelled.\n");
			return;
        }
    }
    printf("No reservation found for this ID.\n");
}

void view_patient_record(void) {
    u8 id;
    printf("Enter patient ID: ");
    scanf("%d", &id);
	u8 i=start;
    for (i; i < counter; i++)
	{
        if (patients[i].id == id)
		{
            printf("Patient ID: %d\n", patients[i].id);
            printf("Name: %s\n", patients[i].name);
            printf("Age: %d\n", patients[i].age);
            printf("Gender: %s\n", patients[i].gender);
        }
    }
    printf("No record found for this ID.\n");
}

void view_reservations(void) {
    printf("Today's reservations:\n");
	u8 i = start;
    for (i; i < MAX_SLOTS; i++) {
		int start_hour = start_time + (i / start_time); 
        int start_minute = (i % start_time) * interval; 
        if (slots[i].reserved) {
            printf("%d:%02d pm to %d:%02d pm - Patient ID: %d\n", 
                start_hour, start_minute, 
                start_hour + ((start_minute + interval) / hour), (start_minute + interval) % hour, 
                slots[i].reserved);
        } else {
            printf("%d:%02d pm to %d:%02d pm - Available\n", 
                start_hour, start_minute, 
                start_hour + ((start_minute + interval) / hour), (start_minute +interval) % hour);     }
    }
}


