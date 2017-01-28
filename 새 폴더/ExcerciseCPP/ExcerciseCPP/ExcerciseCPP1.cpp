  #include <iostream>
  
   int main(void) {
       int val1;
       int val2;
  
       std::cout<<"두 개의 숫자 입력: ";
       std::cin>>val1>>val2;
       int result = 0;
      for(int i = val1; i < val2; i++) {
          result += i;
      }
      std::cout<<"두 수 사이의 정수 합:"<<result;
 
 
  }
