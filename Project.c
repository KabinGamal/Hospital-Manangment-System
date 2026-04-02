#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

typedef struct {
    int id;
    char name[50];
    char specialization[50];
    char contact[15];
    int available; 
} Doctor;

typedef struct {
    int id;
    char name[50];
    int age;
    char gender;
    char address[100];
    char contact[15];
    char bloodType[5];
    char medicalHistory[200];
} Patient;

typedef struct {
    int id;
    int patientId;
    int doctorId;
    char date[11]; 
    char time[6];  
    char purpose[100];
    int completed; 
} Appointment;

Doctor doctors[100];
Patient patients[100];
Appointment appointments[200];
int doctorCount = 0;
int patientCount = 0;
int appointmentCount = 0;

void displayMainMenu();
void manageDoctors();
void managePatients();
void manageAppointments();
void displayHospitalStats();
void loadData();
void saveData();
void addDoctor();
void viewDoctors();
void searchDoctor();
void updateDoctor();
void addPatient();
void viewPatients();
void searchPatient();
void updatePatient();
void scheduleAppointment();
void viewAppointments();
void completeAppointment();
void cancelAppointment();
void displayPatientCard(int patientId);
void displayDoctorSchedule(int doctorId);
void displayUpcomingAppointments();
void displayEmergencyContacts();
void getCurrentDateTime(char *date, char *time);
void clearInputBuffer();
void printHeader(const char *title);
void pressAnyKeyToContinue();
int validateDate(const char *date);
int validateTime(const char *time);
int main() {
    loadData();
    
    int choice;
    do {
        displayMainMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();
        
        switch(choice) {
            case 1:
                manageDoctors();
                break;
            case 2:
                managePatients();
                break;
            case 3:
                manageAppointments();
                break;
            case 4:
                displayHospitalStats();
                break;
            case 5:
                displayEmergencyContacts();
                break;
            case 6:
                printf("\nSaving data and exiting system...\n");
                saveData();
                printf("Thank you for using the Hospital Management System.\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                pressAnyKeyToContinue();
        }
    } while(choice != 6);
    
    return 0;
}
void displayMainMenu() {
    system("cls || clear"); 
    printHeader("MAIN MENU");
    printf("\n1. Manage Doctors");
    printf("\n2. Manage Patients");
    printf("\n3. Manage Appointments");
    printf("\n4. View Hospital Statistics");
    printf("\n5. Emergency Contacts");
    printf("\n6. Exit System\n");
    printf("\nWelcome to our Hospital Management System");
    printf("\nPlease select an option to continue...");
}

void manageDoctors() {
    int choice;
    do {
        system("cls || clear");
        printHeader("DOCTOR MANAGEMENT");
        printf("\n1. Add New Doctor");
        printf("\n2. View All Doctors");
        printf("\n3. Search Doctor");
        printf("\n4. Update Doctor Information");
        printf("\n5. Return to Main Menu");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();
        
        switch(choice) {
            case 1: addDoctor(); break;
            case 2: viewDoctors(); break;
            case 3: searchDoctor(); break;
            case 4: updateDoctor(); break;
            case 5: break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                pressAnyKeyToContinue();
        }
    } while(choice != 5);
}

void managePatients() {
    int choice;
    do {
        system("cls || clear");
        printHeader("PATIENT MANAGEMENT");
        printf("\n1. Add New Patient");
        printf("\n2. View All Patients");
        printf("\n3. Search Patient");
        printf("\n4. Update Patient Information");
        printf("\n5. Return to Main Menu");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();
        
        switch(choice) {
            case 1: addPatient(); break;
            case 2: viewPatients(); break;
            case 3: searchPatient(); break;
            case 4: updatePatient(); break;
            case 5: break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                pressAnyKeyToContinue();
        }
    } while(choice != 5);
}
void manageAppointments() {
    int choice;
    do {
        system("cls || clear");
        printHeader("APPOINTMENT MANAGEMENT");
        printf("\n1. Schedule New Appointment");
        printf("\n2. View All Appointments");
        printf("\n3. View Upcoming Appointments");
        printf("\n4. Complete Appointment");
        printf("\n5. Cancel Appointment");
        printf("\n6. Return to Main Menu");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();
        
        switch(choice) {
            case 1: scheduleAppointment(); break;
            case 2: viewAppointments(); break;
            case 3: displayUpcomingAppointments(); break;
            case 4: completeAppointment(); break;
            case 5: cancelAppointment(); break;
            case 6: break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                pressAnyKeyToContinue();
        }
    } while(choice != 6);
}
void addDoctor() {
    system("cls || clear");
    printHeader("ADD NEW DOCTOR");
    
    if(doctorCount >= 100) {
        printf("\nMaximum number of doctors reached. Cannot add more.\n");
        pressAnyKeyToContinue();
        return;
    }
    
    Doctor d;
    d.id = 1000 + doctorCount + 1;
    
    printf("\nDoctor ID will be automatically assigned as: %d", d.id);
    
    printf("\n\nEnter Doctor's Name: ");
    fgets(d.name, sizeof(d.name), stdin);
    d.name[strcspn(d.name, "\n")] = '\0'; 
    
    printf("Enter Specialization: ");
    fgets(d.specialization, sizeof(d.specialization), stdin);
    d.specialization[strcspn(d.specialization, "\n")] = '\0';
    
    printf("Enter Contact Number: ");
    fgets(d.contact, sizeof(d.contact), stdin);
    d.contact[strcspn(d.contact, "\n")] = '\0';
    
    d.available = 1;
    
    doctors[doctorCount++] = d;
    
    printf("\nDoctor added successfully!\n");
    saveData();
    pressAnyKeyToContinue();
}
void viewDoctors() {
    system("cls || clear");
    printHeader("ALL DOCTORS");
    
    if(doctorCount == 0) {
        printf("\nNo doctors found in the system.\n");
        pressAnyKeyToContinue();
        return;
    }
    
    printf("\n%-8s %-25s %-20s %-15s %s\n", "ID", "Name", "Specialization", "Contact", "Status");
    printf("-----------------------------------------------------------------\n");
    
    for(int i = 0; i < doctorCount; i++) {
        printf("%-8d %-25s %-20s %-15s %s\n", 
               doctors[i].id, 
               doctors[i].name, 
               doctors[i].specialization, 
               doctors[i].contact,
               doctors[i].available ? "Available" : "Not Available");
    }
    
    pressAnyKeyToContinue();
}
void searchDoctor() {
    system("cls || clear");
    printHeader("SEARCH DOCTOR");
    
    if(doctorCount == 0) {
        printf("\nNo doctors found in the system.\n");
        pressAnyKeyToContinue();
        return;
    }
    
    int choice;
    printf("\nSearch by:\n1. ID\n2. Name\n3. Specialization\n4. Return\n\nEnter your choice: ");
    scanf("%d", &choice);
    clearInputBuffer();
    
    if(choice == 4) return;
    
    char searchTerm[50];
    int found = 0;
    
    printf("\n%-8s %-25s %-20s %-15s %s\n", "ID", "Name", "Specialization", "Contact", "Status");
    printf("-----------------------------------------------------------------\n");
    
    switch(choice) {
        case 1: {
            int id;
            printf("\nEnter Doctor ID to search: ");
            scanf("%d", &id);
            clearInputBuffer();
            for(int i = 0; i < doctorCount; i++) {
                if(doctors[i].id == id) {
                    printf("%-8d %-25s %-20s %-15s %s\n", doctors[i].id, doctors[i].name, doctors[i].specialization, doctors[i].contact, doctors[i].available ? "Available" : "Not Available");
                    found = 1;
                    break;
                }
            }
            break;
        }
        case 2:
            printf("\nEnter Doctor Name to search: ");
            fgets(searchTerm, sizeof(searchTerm), stdin);
            searchTerm[strcspn(searchTerm, "\n")] = '\0';
            for(int i = 0; i < doctorCount; i++) {
                if(strstr(doctors[i].name, searchTerm) != NULL) {
                    printf("%-8d %-25s %-20s %-15s %s\n", doctors[i].id, doctors[i].name, doctors[i].specialization, doctors[i].contact, doctors[i].available ? "Available" : "Not Available");
                    found = 1;
                }
            }
            break;
        case 3:
            printf("\nEnter Specialization to search: ");
            fgets(searchTerm, sizeof(searchTerm), stdin);
            searchTerm[strcspn(searchTerm, "\n")] = '\0';
            for(int i = 0; i < doctorCount; i++) {
                if(strstr(doctors[i].specialization, searchTerm) != NULL) {
                    printf("%-8d %-25s %-20s %-15s %s\n", doctors[i].id, doctors[i].name, doctors[i].specialization, doctors[i].contact, doctors[i].available ? "Available" : "Not Available");
                    found = 1;
                }
            }
            break;
        default:
            printf("\nInvalid choice.\n");
            pressAnyKeyToContinue();
            return;
    }
    
    if(!found) printf("\nNo matching doctors found.\n");
    pressAnyKeyToContinue();
}

void updateDoctor() {
    system("cls || clear");
    printHeader("UPDATE DOCTOR INFORMATION");
    
    if(doctorCount == 0) {
        printf("\nNo doctors found in the system.\n");
        pressAnyKeyToContinue();
        return;
    }
    
    int id;
    printf("\nEnter Doctor ID to update: ");
    scanf("%d", &id);
    clearInputBuffer();
    
    int index = -1;
    for(int i = 0; i < doctorCount; i++) {
        if(doctors[i].id == id) {
            index = i;
            break;
        }
    }
    
    if(index == -1) {
        printf("\nDoctor with ID %d not found.\n", id);
        pressAnyKeyToContinue();
        return;
    }
    
    char input[100];
    
    printf("\nName (%s): ", doctors[index].name);
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    if(strlen(input) > 0) strcpy(doctors[index].name, input);
    
    printf("Specialization (%s): ", doctors[index].specialization);
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    if(strlen(input) > 0) strcpy(doctors[index].specialization, input);
    
    printf("Contact (%s): ", doctors[index].contact);
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    if(strlen(input) > 0) strcpy(doctors[index].contact, input);
    
    printf("Availability (1 for Available, 0 for Not Available) (%d): ", doctors[index].available);
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    if(strlen(input) > 0) doctors[index].available = atoi(input);
    
    printf("\nDoctor information updated successfully!\n");
    saveData();
    pressAnyKeyToContinue();
}
