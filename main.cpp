#include <iostream>
#include <vector>
#include <cmath>



template <typename T>
void CoutVector(std::vector<T> vec) {
  std::cout << "[ ";

  for (auto& i : vec) {
    std::cout << i << ", ";
  }

  std::cout << "]" << std::endl;
}


namespace task1 {

  std::vector<int>  VecSize13From25ToNegative11() {
    std::vector<int> nums = { 25, 22, 19, 16, 13, 10, 7, 4, 1, -2, -5, -8, -11 };
    return nums;
  }

  std::vector<int> CreateVector(int start, int step, int stop) {
    std::vector<int> new_vector;

    if (step < 0) {
      for (int i = start; i > stop; i += step) {
        new_vector.push_back(i);
      }
    }
    else {
      for (int i = start; i < stop; i += step) {
        new_vector.push_back(i);
      }
    }

    return new_vector;
  }


  void ExecuteTask() {
    CoutVector(VecSize13From25ToNegative11());
    CoutVector(CreateVector(25, -3, -12));
    CoutVector(CreateVector(-15, 4, 0));


  }

};

namespace task2 {
  unsigned long long int Product(int start, int step, int stop) {
    unsigned long long int product = 1;
    stop = abs(stop);
    std::vector<int> numbers = task1::CreateVector(start, step, stop);

    for (int& i : numbers) {
      product *= i;
    }

    return product;
  }


  void ExecuteTask() {
    int n;
    std::cin >> n;
    std::cout << Product(-15, 4, n) << std::endl;
  }

}

namespace task3 {
  void CoutDivisibleBy6From12To61() {
    std::vector<int> nums = task1::CreateVector(12, 1, 62);

    std::cout << "< ";

    for (auto& i : nums) {
      if (i % 6 == 0) {
        std::cout << i << ", ";
      }

    }

    std::cout << ">" << std::endl;
  }

  void CoutDivisibleBy6From12To61Clever() {
    std::vector<int> nums = task1::CreateVector(12, 6, 62);
    CoutVector(nums);
  }

  void ExecuteTask() {
    CoutDivisibleBy6From12To61();
    CoutDivisibleBy6From12To61Clever();
  }
}

namespace task4 {
  double AddingFractions(double n, double mul) {
    double sum_ = 0;

    for (double i = 1; i <= n; i++) {
      sum_ += 1 / (i * mul);
    }

    return sum_;
  }


  void ExecuteTask() {
    double n;
    double mul = 7;
    std::cin >> n;

    std::cout << AddingFractions(n, mul) << std::endl;
  }
}


namespace task5 {
  double Factorial(double n) {
    double product = 1;

    for (int i = 2; i <= n; i++) {
      product *= i;
    }

    return product;
  }


  double AddingFractions(float n) {
    double sum_ = 0;

    for (float i = 1; i <= n; i++) {
      sum_ += 1 / (i * 7);
    }

    return sum_;
  }

  double DoIt(double n) {
    double up = 1;
    double symbol = 1;

    for (int i = 1; i <= n; i++) {
      up *= n / Factorial(n);
      up *= symbol;
      symbol *= -1;
    }

    double three = 3;
    return up / task4::AddingFractions(n, three);
  }


  void ExecuteTask() {
    double n;
    std::cin >> n;

    std::cout << DoIt(n) << std::endl;
  }
}


int main()
{
  task1::ExecuteTask();
  task2::ExecuteTask();
  task3::ExecuteTask();
  task4::ExecuteTask();
  task5::ExecuteTask();

  return 0;
}