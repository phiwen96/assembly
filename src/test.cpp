#include "assembly.hpp"

namespace ph::assembly {

int test ()
{
      return 0;
      cout << passing_four_parameters (1, 2, 3, 4) << endl;

      cout << passing_three_parameters (1, 2, 3) << endl;

      cout << passing_two_parameters (11, 12) << endl;

      cout << passing_one_parameter (10) << endl;
      cout << myloop () << endl;
      
      
      cout << someFunction() << endl;
      double test[] = {
            1, 2, 3
      };
      cout << sum(test, 3) << endl;
      
      []{
            char temp;
            char rslt1, rslt2;
            char one = 'o', two = 't';
            int integer;
            //switch to assembly
            asm
            {
                  mov al, one
                  
                  xchg al, two
                  mov bl, 'A'
                  mov bh, 'B'
                  xchg bl, bh //swap bytes
                  mov temp, bl
                  mov rslt1, bh
                  mov bh, temp
                  mov rslt2, bh
            }
            cout << one << " " << two << endl;
            //print result
            printf ("BL = %c, BH = %c\n", rslt1, rslt2);
      };
      return 0;
}


}

