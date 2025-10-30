

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