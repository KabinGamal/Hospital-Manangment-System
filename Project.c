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
void addPatient() {
    system("cls || clear");
    printHeader("ADD NEW PATIENT");
    
    if(patientCount >= 100) {
        printf("\nMaximum number of patients reached. Cannot add more.\n");
        pressAnyKeyToContinue();
        return;
    }
    
    Patient p;
    p.id = 2000 + patientCount + 1;
    
    printf("\nPatient ID will be automatically assigned as: %d", p.id);
    
    printf("\n\nEnter Patient's Name: ");
    fgets(p.name, sizeof(p.name), stdin);
    p.name[strcspn(p.name, "\n")] = '\0';
    
    printf("Enter Age: ");
    scanf("%d", &p.age);
    clearInputBuffer();
    
    printf("Enter Gender (M/F/O): ");
    scanf("%c", &p.gender);
    clearInputBuffer();
    p.gender = toupper(p.gender);
    
    printf("Enter Address: ");
    fgets(p.address, sizeof(p.address), stdin);
    p.address[strcspn(p.address, "\n")] = '\0';
    
    printf("Enter Contact Number: ");
    fgets(p.contact, sizeof(p.contact), stdin);
    p.contact[strcspn(p.contact, "\n")] = '\0';
    
    printf("Enter Blood Type: ");
    fgets(p.bloodType, sizeof(p.bloodType), stdin);
    p.bloodType[strcspn(p.bloodType, "\n")] = '\0';
    
    printf("Enter Medical History (if any): ");
    fgets(p.medicalHistory, sizeof(p.medicalHistory), stdin);
    p.medicalHistory[strcspn(p.medicalHistory, "\n")] = '\0';
    
    patients[patientCount++] = p;
    
    printf("\nPatient added successfully!\n");
    displayPatientCard(p.id);
    
    saveData();
    pressAnyKeyToContinue();
}
void viewPatients() {
    system("cls || clear");
    printHeader("ALL PATIENTS");
    
    if(patientCount == 0) {
        printf("\nNo patients found in the system.\n");
        pressAnyKeyToContinue();
        return;
    }
    
    printf("\n%-8s %-25s %-5s %-5s %-15s %-10s\n", "ID", "Name", "Age", "Gender", "Contact", "Blood Type");
    printf("-----------------------------------------------------------------\n");
    
    for(int i = 0; i < patientCount; i++) {
        printf("%-8d %-25s %-5d %-5c %-15s %-10s\n", 
               patients[i].id, 
               patients[i].name, 
               patients[i].age, 
               patients[i].gender,
               patients[i].contact,
               patients[i].bloodType);
    }
    
    pressAnyKeyToContinue();
}

void searchPatient() {
    system("cls || clear");
    printHeader("SEARCH PATIENT");
    
    if(patientCount == 0) {
        printf("\nNo patients found in the system.\n");
        pressAnyKeyToContinue();
        return;
    }
    
    int choice;
    printf("\nSearch by:\n1. ID\n2. Name\n3. Blood Type\n4. Return\n\nEnter your choice: ");
    scanf("%d", &choice);
    clearInputBuffer();
    
    if(choice == 4) return;
    
    char searchTerm[50];
    int found = 0;
    
    printf("\n%-8s %-25s %-5s %-5s %-15s %-10s\n", "ID", "Name", "Age", "Gender", "Contact", "Blood Type");
    printf("-----------------------------------------------------------------\n");
    
    switch(choice) {
        case 1: {
            int id;
            printf("\nEnter Patient ID to search: ");
            scanf("%d", &id);
            clearInputBuffer();
            for(int i = 0; i < patientCount; i++) {
                if(patients[i].id == id) {
                    printf("%-8d %-25s %-5d %-5c %-15s %-10s\n", patients[i].id, patients[i].name, patients[i].age, patients[i].gender, patients[i].contact, patients[i].bloodType);
                    found = 1;
                    break;
                }
            }
            break;
        }
        case 2:
            printf("\nEnter Patient Name to search: ");
            fgets(searchTerm, sizeof(searchTerm), stdin);
            searchTerm[strcspn(searchTerm, "\n")] = '\0';
            for(int i = 0; i < patientCount; i++) {
                if(strstr(patients[i].name, searchTerm) != NULL) {
                    printf("%-8d %-25s %-5d %-5c %-15s %-10s\n", patients[i].id, patients[i].name, patients[i].age, patients[i].gender, patients[i].contact, patients[i].bloodType);
                    found = 1;
                }
            }
            break;
        case 3:
            printf("\nEnter Blood Type to search: ");
            fgets(searchTerm, sizeof(searchTerm), stdin);
            searchTerm[strcspn(searchTerm, "\n")] = '\0';
            for(int i = 0; i < patientCount; i++) {
                if(strstr(patients[i].bloodType, searchTerm) != NULL) {
                    printf("%-8d %-25s %-5d %-5c %-15s %-10s\n", patients[i].id, patients[i].name, patients[i].age, patients[i].gender, patients[i].contact, patients[i].bloodType);
                    found = 1;
                }
            }
            break;
        default:
            printf("\nInvalid choice.\n");
            pressAnyKeyToContinue();
            return;
    }
    
    if(!found) printf("\nNo matching patients found.\n");
    pressAnyKeyToContinue();
}
void updatePatient() {
    system("cls || clear");
    printHeader("UPDATE PATIENT INFORMATION");
    
    if(patientCount == 0) {
        printf("\nNo patients found in the system.\n");
        pressAnyKeyToContinue();
        return;
    }
    
    int id;
    printf("\nEnter Patient ID to update: ");
    scanf("%d", &id);
    clearInputBuffer();
    
    int index = -1;
    for(int i = 0; i < patientCount; i++) {
        if(patients[i].id == id) {
            index = i;
            break;
        }
    }
    
    if(index == -1) {
        printf("\nPatient with ID %d not found.\n", id);
        pressAnyKeyToContinue();
        return;
    }
    
    char input[200];
    char charInput;
    
    printf("\nName (%s): ", patients[index].name);
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    if(strlen(input) > 0) strcpy(patients[index].name, input);
    
    printf("Age (%d): ", patients[index].age);
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    if(strlen(input) > 0) patients[index].age = atoi(input);
    
    printf("Gender (%c): ", patients[index].gender);
    charInput = getchar();
    clearInputBuffer();
    if(charInput != '\n') patients[index].gender = toupper(charInput);
    
    printf("Address (%s): ", patients[index].address);
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    if(strlen(input) > 0) strcpy(patients[index].address, input);
    
    printf("Contact (%s): ", patients[index].contact);
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    if(strlen(input) > 0) strcpy(patients[index].contact, input);
    
    printf("Blood Type (%s): ", patients[index].bloodType);
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    if(strlen(input) > 0) strcpy(patients[index].bloodType, input);
    
    printf("Medical History (%s): ", patients[index].medicalHistory);
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    if(strlen(input) > 0) strcpy(patients[index].medicalHistory, input);
    
    printf("\nPatient information updated successfully!\n");
    saveData();
    pressAnyKeyToContinue();
}
void displayPatientCard(int patientId) {
    int index = -1;
    for(int i = 0; i < patientCount; i++) {
        if(patients[i].id == patientId) {
            index = i;
            break;
        }
    }
    
    if(index == -1) {
        printf("\nPatient with ID %d not found.\n", patientId);
        return;
    }
    
    printf("\n================================================================\n");
    printf("                      PATIENT MEDICAL CARD                      \n");
    printf("================================================================\n");
    printf("  %-58s \n", patients[index].name);
    printf("----------------------------------------------------------------\n");
    printf("  ID: %-53d \n", patients[index].id);
    printf("  Age: %-2d                                Gender: %-14c \n", patients[index].age, patients[index].gender);
    printf("  Blood Type: %-45s \n", patients[index].bloodType);
    printf("  Contact: %-48s \n", patients[index].contact);
    printf("  Address: %-48s \n", patients[index].address);
    printf("----------------------------------------------------------------\n");
    printf("  MEDICAL HISTORY:                                              \n");
    printf("  %-58s \n", patients[index].medicalHistory);
    printf("================================================================\n");
}
void displayPatientCard(int patientId) {
    int index = -1;
    for(int i = 0; i < patientCount; i++) {
        if(patients[i].id == patientId) {
            index = i;
            break;
        }
    }
    
    if(index == -1) {
        printf("\nPatient with ID %d not found.\n", patientId);
        return;
    }
    
    printf("\n================================================================\n");
    printf("                      PATIENT MEDICAL CARD                      \n");
    printf("================================================================\n");
    printf("  %-58s \n", patients[index].name);
    printf("----------------------------------------------------------------\n");
    printf("  ID: %-53d \n", patients[index].id);
    printf("  Age: %-2d                                Gender: %-14c \n", patients[index].age, patients[index].gender);
    printf("  Blood Type: %-45s \n", patients[index].bloodType);
    printf("  Contact: %-48s \n", patients[index].contact);
    printf("  Address: %-48s \n", patients[index].address);
    printf("----------------------------------------------------------------\n");
    printf("  MEDICAL HISTORY:                                              \n");
    printf("  %-58s \n", patients[index].medicalHistory);
    printf("================================================================\n");
}
void scheduleAppointment() {
    system("cls || clear");
    printHeader("SCHEDULE NEW APPOINTMENT");
    
    if(doctorCount == 0 || patientCount == 0) {
        printf("\nCannot schedule appointment. Need at least one doctor and one patient.\n");
        pressAnyKeyToContinue();
        return;
    }
    
    if(appointmentCount >= 200) {
        printf("\nMaximum number of appointments reached.\n");
        pressAnyKeyToContinue();
        return;
    }
    
    Appointment a;
    a.id = 3000 + appointmentCount + 1;
    a.completed = 0;
    
    printf("\nAppointment ID will be automatically assigned as: %d", a.id);
    
    printf("\nEnter Patient ID: ");
    scanf("%d", &a.patientId);
    clearInputBuffer();
    
    int patientIndex = -1;
    for(int i = 0; i < patientCount; i++) {
        if(patients[i].id == a.patientId) { patientIndex = i; break; }
    }
    
    if(patientIndex == -1) {
        printf("\nInvalid Patient ID.\n");
        pressAnyKeyToContinue();
        return;
    }
    
    printf("Enter Doctor ID: ");
    scanf("%d", &a.doctorId);
    clearInputBuffer();
    
    int doctorIndex = -1;
    for(int i = 0; i < doctorCount; i++) {
        if(doctors[i].id == a.doctorId) { doctorIndex = i; break; }
    }
    
    if(doctorIndex == -1 || !doctors[doctorIndex].available) {
        printf("\nInvalid Doctor ID or Doctor is not available.\n");
        pressAnyKeyToContinue();
        return;
    }
    
    do {
        printf("Enter Date (YYYY-MM-DD): ");
        fgets(a.date, sizeof(a.date), stdin);
        a.date[strcspn(a.date, "\n")] = '\0';
    } while(!validateDate(a.date));
    
    do {
        printf("Enter Time (HH:MM): ");
        fgets(a.time, sizeof(a.time), stdin);
        a.time[strcspn(a.time, "\n")] = '\0';
    } while(!validateTime(a.time));
    
    printf("Enter Purpose: ");
    fgets(a.purpose, sizeof(a.purpose), stdin);
    a.purpose[strcspn(a.purpose, "\n")] = '\0';
    
    appointments[appointmentCount++] = a;
    
    printf("\nAppointment scheduled successfully!\n");
    saveData();
    pressAnyKeyToContinue();
}


