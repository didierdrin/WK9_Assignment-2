#include <stdio.h>

// Function to calculate tax
float calculateTax(float *grossSalary) {
    float tax = 0.0;
    
    if (*grossSalary > 300) {
        tax = *grossSalary * 0.28;
    } else if (*grossSalary > 100) {
        tax = *grossSalary * 0.20;
    }
    // Else tax remains 0 for salary <= 100
    
    return tax;
}

// Function to calculate medication insurance
float calculateMedication(float *grossSalary) {
    return *grossSalary * 0.05;
}

// Function to calculate maternity leave
float calculateMaternity(float *grossSalary) {
    return *grossSalary * 0.003;
}

// Function to calculate social security
float calculateSocialSecurity(float *grossSalary) {
    return *grossSalary * 0.03;
}

// Function to calculate net salary
float calculateNetSalary(float *grossSalary) {
    float tax = calculateTax(grossSalary);
    float medication = calculateMedication(grossSalary);
    float maternity = calculateMaternity(grossSalary);
    float socialSecurity = calculateSocialSecurity(grossSalary);
    
    float totalDeductions = tax + medication + maternity + socialSecurity;
    return *grossSalary - totalDeductions;
}

int main() {
    float grossSalary;
    
    printf("Enter gross salary: $");
    scanf("%f", &grossSalary);
    
    float netSalary = calculateNetSalary(&grossSalary);
    
    printf("\nSalary Breakdown:\n");
    printf("Gross Salary: $%.2f\n", grossSalary);
    printf("Tax: $%.2f\n", calculateTax(&grossSalary));
    printf("Medication Insurance: $%.2f\n", calculateMedication(&grossSalary));
    printf("Maternity Leave: $%.2f\n", calculateMaternity(&grossSalary));
    printf("Social Security: $%.2f\n", calculateSocialSecurity(&grossSalary));
    printf("Net Salary: $%.2f\n", netSalary);
    
    return 0;
}
