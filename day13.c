#include <stdio.h>
int main()
{
    int passengers, age, time, i;
    float distance, base_fare, final_fare, total_revenue = 0, highest_fare = 0, lowest_fare = 999999;
    char name[50];
    printf("Enter ths number of passengers = ");
    scanf("%d",&passengers);
    for(i = 1; i <= passengers; i++)
    {
        printf("\n---passengers %d---\n",i);
        printf("Enter the name = ");
        scanf("%s",name);
        printf("Enter the age = ");
        scanf("%d",&age);
        printf("Enter the distance(in Km) = ");
        scanf("%f",&distance);
        printf("Enter the time(in 24hours) = ");
        scanf("%d",&time);
        base_fare = distance * 10;
        if(age < 12)
        {
            final_fare = base_fare * 0.5;
            printf("passenger = %s| Base fare = %.2f| Child Discount Applied",name, base_fare);
        }
        else if(age >= 60)
        {
            final_fare = base_fare * 0.7;
            printf("passenger = %s| base fare = %.2f| senior citizen Discount Applied",name, base_fare);
        }
        else
        {
            final_fare = base_fare; // no discount
            printf("Passenger: %s | Base Fare: %.2f | ", name, base_fare);
        }
        if((time >= 8 && time <= 10) || (time >= 17 && time <= 20))
        {
            final_fare = final_fare * 1.2; // Add 20% surcharge
            printf("Peak Hour Surcharge Applied | ");
        }
        if (final_fare < 20)
        final_fare = 20;
        printf("Final Fare: %.2f\n", final_fare);
        total_revenue += final_fare;
        if (final_fare > highest_fare)
        highest_fare = final_fare;
        if (final_fare < lowest_fare)
        lowest_fare = final_fare;
        
    }
    printf("Total Passengers: %d\n", passengers);
    printf("Total Revenue Collected: %.2f\n", total_revenue);
    printf("Highest Fare: %.2f\n", highest_fare);
    printf("Lowest Fare: %.2f\n", lowest_fare);
    return 0;
}