/*----------------------------------------------------------
 *				HTBLA-Leonding / Class
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			deletable_primes.c
 * Author:			P. Bauer
 * Due Date:		October 16, 2012
 * ----------------------------------------------------------
 * Description:
 * Implementation of deletable_primes.h.
 * ----------------------------------------------------------
 */
 #include "deletable_primes.h"
 #include "math.h"


bool is_prime(unsigned long num)
{
   if (num == 1)return false;
   else if (num == 2)
   {
      return true;
   }
   else if ( num % 2 == 0 )
   {
      return false;
   }
   unsigned long sqroot = sqrt(num);
   for (unsigned long i = 3; i <= sqroot; i += 2 )
   {
      if (!(num % i))
      {
         return false;
      }
   }
   return true;
}

unsigned long remove_digit(int index, unsigned long num)
{
  unsigned long leftNum = 0;
  unsigned long rightNum = 0;
  unsigned long removedNum = 0;

  if (index == 0)
  {
    return num / 10;
  }
  leftNum = num / pow(10 , index + 1);
  rightNum = num % (unsigned long)pow(10 , index);
  removedNum = leftNum * pow(10 , index) + rightNum;

  return removedNum;
}

int count(unsigned long num)
{
 int counter = 0;
  while (num > 0)
  {
     counter++;
     num /= 10;
  }

  return counter;
}

 int get_ways(unsigned long num)
 {
   int length = 0;
   for (int i = 0; i < count(num); i++)
   {
     if (count(num) == 1)
     {
       if (is_prime(num))
       {
         return 1;
       }
       return 0;
     }
     else if (is_prime(remove_digit(i,num)) )
     {
       length += get_ways(remove_digit(i,num));
      }

    }
   return length;
 }
