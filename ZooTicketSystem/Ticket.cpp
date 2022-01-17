/* Name: Gary Tsang
   Description: This program is designed for zoo visitors to be able to
                purchase tickets
   Input: Number of adults, seniors, children, infants, and young adults
          as well as yes/no, and discount codes
   Output: Number of adults, seniors, children, infants, and young adults
           and total amount for all the visitors and any discounts
           applied
*/

/* Algorithm for program
   1. Greet user with welcome screen
   2. Display the prices for each group along with discount offers
   3. Prompt user to enter quantity of visitors in each age group
   4. Apply any discounts, if possible, with the given quantity
      information, if no discount then show total
   5. Show the overall receipt with all age groups present, quantity of
      visitors, price per person, total price in each age group,
      subtotal, discount (if applicable), and overall total
*/

//libraries used in program
#include <iostream>
#include <iomanip>

int main()
{
   //variables for types of people
   double At = 0.0, Chil = 0.0, YA = 0.0, Inf = 0.0, Sr = 0.0;

   //variables for prices and discounts
   const double AdTi = 34.99, ChTi = 9.99, SeTi = 24.99, YaTi = 19.99,
                Zm = .30, Gd = .15, C = .10;
   double SubTot = 0.0, total = 0.0, DisPric = 0.0, TotalPeople = 0.0;
   int DiscountCode = 0;
   const int ZM = 30, GD = 15, Co = 10, free = 0;
   char response = 0;

   //welcome message greeting user
   std::cout << "*******************************\n";
   std::cout << "Welcome to the Zoo Ticket Kiosk\n";
   std::cout << "Ticket Purchase Menu\n";

   //price chart for each age group
   std::cout << "Adults: $" << AdTi << "\n";
   std::cout << "Seniors: $" << SeTi << "\n";
   std::cout << "Young adults: $" << YaTi << "\n";
   std::cout << "Children: $" << ChTi << "\n";
   std::cout << "Infants: Free\n";

   //discount listings
   std::cout << "\nDiscounts\n";
   std::cout << "Zoo member: " << ZM << "%\n";
   std::cout << "Coupon: " << Co << "%\n";

   //prompts user to enter number of visitors
   std::cout << "How many adults: ";
   std::cin >> At;
   std::cout << "How many seniors: ";
   std::cin >> Sr;
   std::cout << "How many young adults: ";
   std::cin >> YA;
   std::cout << "How many children: ";
   std::cin >> Chil;
   std::cout << "How many infants: ";
   std::cin >> Inf;

   //formula for calculating subtotal
   SubTot = (At * AdTi) + (Sr * SeTi) + (YA * YaTi) + (Chil * ChTi) +
            (Inf * free);
   TotalPeople = At + Sr + YA + Chil; //calculate quantity of visitors

   //asks user if they have a discount code
   std::cout << "\nDo you have a discount code? (y/n):";
   std::cin >> response;

   //application for the discount code depending on situation
   bool DiscountCodeEntered = false;
   //switch statement so the answer can ONLY be Y/y/N/n
   switch (response)
   {
          case 'y': case 'Y':
          std::cout << "Please enter your discount code: ";
          std::cin >> DiscountCode;
          DiscountCodeEntered = true;
          if (DiscountCodeEntered)
          {
                if (DiscountCode == 0)
                {
                      std::cout << "\nError - Invalid discount code\n";
                      //if user enters discount code of "0", outputs
                      //error message
                }
                else //if not "0", goes through discount code options
                {
                     if (DiscountCode % 3 == 0)
                     {
                             DisPric = SubTot * Zm;
                     }
                     else if (TotalPeople >= 10)
                     {
                             DisPric = SubTot * Gd;
                     }
                     else if (DiscountCode % 4 == 0)
                     {
                             DisPric = SubTot * C;
                     }
                }
         }
              break;

              //if no, but total >= 10 people, then case will be executed
              case 'N': case 'n':
              if (TotalPeople >= 10)
              {
                      DisPric = SubTot * Gd;
                      std::cout << "No discount code\n";
              }
              else
              {
                      std::cout << "No discount code\n";
              }
              break;

              default: //invalid entry is entered, the following appears
              std::cout << "Invalid entry - " << response << "\n";
              std::cout << "Would you like to start over? (y/n):\n";
              std::cin >> response;
              if (response == 'Y'|| response == 'y')
              {
                      std::cout << "Exiting ticket sales\n";
                      return 0;
              }
              if ((response == 'N'|| response == 'n') &&
                   TotalPeople >= 10)
              {
                     DisPric = SubTot * Gd;
                     std::cout << "Continuing with no discount\n";
              }
              else
              {
                     std::cout << "Continuing with no discount\n";
              }
       }

   total = SubTot - DisPric;  //calculates total after applying discount

   //string variables for laying out the receipt
   std::string a = "Adults:", s = "Seniors:", ya = "Young Adults:",
          c = "Children:", i = "Infants:";

   //lists the visitors, quantity, price per each person, price total
   //per group.
   std::cout << "\nReceipt\n";

   //If the quantity is above 0 then the age group appears
   if (At > 0)
   {
        std::cout << a << std::setw(9) << At << " @  " << std::setw(5)
             << AdTi << " ea = " << std::setw(6) << At * AdTi << "\n";
   }
   if (Sr > 0)
   {
        std::cout << s << std::setw(8) << Sr << " @  " << std::setw(5)
             << SeTi << " ea = " << std::setw(6) << Sr * SeTi << "\n";
   }
   if (YA > 0)
   {
        std::cout << ya << std::setw(3) << YA << " @  " << std::setw(5)
             << YaTi << " ea = " << std::setw(6) << YA * YaTi << "\n";
   }
   if (Chil > 0)
   {
        std::cout << c << std::setw(7) << Chil << " @  " << std::setw(5)
             << ChTi << " ea = " << std::setw(6) << Chil * ChTi << "\n";
   }
   if (Inf > 0)
   {
        std::cout << i << std::setw(8) << Inf << std::setw(22)
             << "free\n";
   }

   //subtotal
   std::cout << "\n" << std::fixed << std::setprecision(2)
        << std::setw(23) << "Subtotal" << std::setw(8) << "$"
        << SubTot << "\n";

   //outputs statement depending on whether discount of used
   if ((response == 'N' || response == 'n') && TotalPeople < 10)
   {
           std::cout << "No discounts apply\n";
   }
   else //depending on discount used, message will be outputted
   {
        if (DiscountCode % 3 == 0 && DiscountCode != 0)
        {
                std::cout << "\nZoo member discount of " << ZM * 1.00
                    << "% applied\n";
        }
        else if (TotalPeople >= 10)
        {
                std::cout << "\nGroup discount of " << GD * 1.00
                    << "% applied\n";
        }
        else if (DiscountCode % 4 == 0 && DiscountCode != 0)
        {
                std::cout << "\nCoupon discount of " << Co * 1.00
                    << "% applied\n";
        }
        else
        {
               std::cout << "No discounts apply\n";
        }

        //if >= 1 people then the discount price will be outputted
        if (TotalPeople >= 1)
        {
                std::cout << "\n" << std::fixed << std::setprecision(2)
                    << std::setw(23) << "Discount" << std::setw(8)
                    << "$-" << DisPric << "\n";
        }
        else //if 0 total people, no discounts
        {
                std::cout << "No discounts apply\n";
        }
   }

   //overall total of the zoo visit
   std::cout << "\n" << std::fixed << std::setprecision(2)
        << std::setw(23) << "Total" << std::setw(8) << "$"
        << total << "\n";

   return 0;

}
