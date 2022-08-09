#include <iostream>


int place_value(int n) {
   int p = 0;
   while (n != 0) {
      int l = n % 10;
      n /= 10;
      
      p++;
   } 
   
   return (p);
}


int get_part (int num) {
      int n;
 
    switch( place_value(num) ) {
       case 2:
       n = num % 10;
       break;
       case 3:
       n = num % 100;
       break;
       case 7:
       n = num % 1000000;
       break;
       default:
       n = num % 1000;
    }
     
    return (n);
 
}


void d1(int n); //ones
void d2 (int n); //tens
void d3 (int n);  //hundreds
void d4 (int n); //thousands
void d5 (int n); //ten thousand
void d6 (int n); //hundred thousand
void d7 (int n); //million

int main() { 
   int digit, n;
   
   std::cout<<"Enter number to convert to words within the ranges of (0 to 9999999)\n\n";
   
   std::cin >> digit;
   
   n = place_value(digit);
   
   switch (n) {
     case 0:
     std::cout<<"zero";
     case 1: 
     d1(digit);
     break;
     case 2:
     d2(digit);
     break;
     case 3:
     d3(digit);
     break;
     case 4:
     d4(digit);
     break;
     case 5: 
     d5(digit);
     break;
     case 6:
     d6(digit);
     break;
     case 7:
     d7(digit);
     break;
     default:
     std::cout<<"You exceeded the range!";
} 


   return 0; 
}

void d1(int n) {

     switch(n) {
        case 1:
        std::cout<<"one";
        break;
        case 2:
        std::cout<<"two";
        break;
        case 3:
        std::cout<<"three";
        break;
        case 4:
        std::cout<<"four";
        break;
        case 5:
        std::cout<<"five";
        break;
        case 6:
        std::cout<<"six";
        break;
        case 7:
        std::cout<<"seven";
        break;
        case 8:
        std::cout<<"eight";
        break;
        case 9:
        std::cout<<"nine";
        break;
     }
}

void d2 (int n) {
   int fnum = n / 10; //first digit
   int lnum = get_part(n); //last digit
   
   if(fnum == 1) {
   
      if(lnum == 0 || lnum == 1 || lnum == 2 || lnum == 3 || lnum == 5 || lnum == 8) {
         switch (lnum) {
             case 0:
             std::cout<<"ten";
             break;
             case 1:
             std::cout<<"eleven";
             break;
             case 2:
             std::cout<<"twelve";
             break;
             case 3:
             std::cout<<"thirteen";
             break;
             case 5:
             std::cout<<"fifteen";
             break;
             case 8:
             std::cout<<"eighteen";
             break;
         }
      }
      
      else  {
         d1(lnum); 
         std::cout<<"teen";
      }
   }
   
   else {
      switch (fnum) {
         case 2:
         std::cout<<"twenty";
         if(lnum != 0) {
          std::cout<<" ";
         }
         break;
         
         case 3:
         std::cout<<"thirty";
         if(lnum != 0) {
            std::cout<<" ";
         }
         break;
         
         case 4:
         std::cout<<"forty";
         if(lnum != 0) {
            std::cout<<" ";
         }
         break;
         
         case 5:
         std::cout<<"fifty";
         if(lnum != 0) {
            std::cout<<" ";
         }
         break;
         
         case 6:
         std::cout<<"sixty";
         if(lnum != 0) {
            std::cout<<" ";
         }
         break;
         
         case 7:
         std::cout<<"seventy";
         if(lnum != 0) {
            std::cout<<" ";
         }
         break;
         
         case 8:
         std::cout<<"eighty";
         if(lnum != 0) {
            std::cout<<" ";
         }
         break;
         
         case 9:
         std::cout<<"ninety";
         if(lnum != 0) {
            std::cout<<" ";
         }
         break;
         
      } 
      d1(lnum);    
   }
  
}

void d3(int n) {
   int fnum = n / 100; //first digit
   int lnum = get_part(n); //last two digit
   
     int pv = place_value(lnum);
    
   
   d1(fnum); std::cout<<" hundred";
   if(pv == 1) {
      std::cout<<" and ";
      d1(lnum);
   }
   else if(pv == 2) {
       std::cout<<" and ";
       d2(lnum);
   }
}
 
 void d4(int n) {
    int fnum = n / 1000;
    int lnum = get_part(n);
    
    int pv = place_value(lnum);
    
    d1(fnum); std::cout<<" thousand";
    
    if(pv == 1) {
      std::cout<<" and ";
      d1(lnum);
   }
   else if(pv == 2) {
      std::cout<<" and ";
      d2(lnum);
   }
   else if(pv == 3) {
      std::cout<<" ";
      d3(lnum);
   }
 
 }
 
 void d5(int n) {
    int fnum = n / 1000;
    int lnum = get_part(n);
    
    int pv = place_value(lnum);
    
    d2(fnum); std::cout<<" thousand";
    
       if(pv == 1) {
      std::cout<<" and ";
      d1(lnum);
   }
   else if(pv == 2) {
      std::cout<<" and ";
      d2(lnum);
   }
   else if(pv == 3) {
      std::cout<<" ";
      d3(lnum);
   }
  
  
 }
 
 void d6(int n) {
  int fnum = n / 1000;
    int lnum = get_part(n);
    
    int pv = place_value(lnum);
    
    d3(fnum); std::cout<<" thousand";
    
       if(pv == 1) {
      std::cout<<" and ";
      d1(lnum);
   }
   else if(pv == 2) {
      std::cout<<" and ";
      d2(lnum);
   }
   else if(pv == 3) {
      std::cout<<" ";
      d3(lnum);
   }

 
 }


void d7(int n) {
  int fnum = n / 1000000;
    int lnum = get_part(n);
    
    int pv = place_value(lnum);
    
    d1(fnum); std::cout<<" million";
    
       if(pv == 1) {
      std::cout<<" and ";
      d1(lnum);
   }
   else if(pv == 2) {
      std::cout<<" and ";
      d2(lnum);
   }
   else if(pv == 3) {
      std::cout<<" ";
      d3(lnum);
   }
   else if(pv == 4) {
      std::cout<<" ";
      d4(lnum); 
     }
   else if(pv == 5) {
      std::cout<<" ";
      d5(lnum);
   }
   else if(pv == 6) {
      std::cout<<" ";
      d6(lnum);
   }
   
}

