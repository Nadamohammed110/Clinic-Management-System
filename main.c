#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include"STD_TYPS.h"
#include"definitions.h"
#include"data.h"

int main ()
{
	u8 mode;
	printf(" Choose Your Mode :\n 1.Admin Mode \n 2. User Mode\n");
	scanf("%d", &mode);
	
    if (mode == admin) 
	{		
	 if (!admin_mode()) 
		{
            printf("Too many incorrect attempts. System closing.\n");
			return false;
        }	
	while (true) 
	{ 	u8 choice;
		printf(" Admin Menu:\n 1. Add new patient record\n 2. Edit patient record\n 3. Reserve a slot with the doctor\n 4. Cancel reservation\n 5. Exit\n ");
		printf(" Enter choice: ُ");
            scanf("%d",&choice);
			
            switch (choice)
			{
                case Add_patient:
                    add_patient();
                    break;
                case Edit_patient:
                    edit_patient();
                    break;
                case Reserve_slot:
                    reserve_slot();
                    break;
                case Cancel_reserve:
                    cancel_reservation();
                    break;
                case Exit_admin_mode:
                    printf("Exiting admin mode.\n");
                    return false;
                default:
                    printf("Invalid choice. Try again.\n");
            }
	} 
    } 
	
	else if (mode == user)
	{

       while (true)
	   {	u8 choice;
            printf(" User Menu:\n 1. View patient record\n 2. View today's reservations\n 3. Exit\n ");
            printf(" Enter choice: ُ");
			scanf("%d", &choice);

            switch (choice)
			{
                case View_patient_record:
                    view_patient_record();
                    break;
                case View_reservations:
                    view_reservations();
                    break;
                case Exit_user_mode:
                    printf("Exiting user mode.\n");
                    return false;
                default:
                    printf("Invalid choice. Try again.\n");
            }
        } 
    }
	else
		{
        printf("Invalid mode. System closing.\n");
        }
	    return false;
}

