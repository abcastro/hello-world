#include <iostream>
#include <sstream>

// rotate an array by d positions

void print_arr(char *a, int n) {
  for (int i = 0; i < n; i++) {
    std::cout << a[i] << " ";
  }
}


int main(int argc, char *argv[]) {
  char arr[13] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm' };
  int n = 13;
  int d;
  char tmp;
  char aux;

  std::stringstream(argv[1]) >> d;

  std::cout << "rodar " << d << std::endl;

  aux = arr[0];
  for (int i = 0; i < n; i++) {
    tmp = arr[(i * d + d) % n];
    arr[(i * d + d) % n] = aux;
    aux = tmp;

    // print_arr(arr, n);
    // std::cout << "(" << aux << ")" << std::endl;
  }

  print_arr(arr, n);
  std::cout << std::endl;

  return 0;
}
