  #include <iostream>
  
   int main(void) {
       int val1;
       int val2;
  
       std::cout<<"�� ���� ���� �Է�: ";
       std::cin>>val1>>val2;
       int result = 0;
      for(int i = val1; i < val2; i++) {
          result += i;
      }
      std::cout<<"�� �� ������ ���� ��:"<<result;
 
 
  }
