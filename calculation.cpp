//https://www.cse.msu.edu/~cse232/Labs/lab03.html TA solution code

#include<iostream>
using std::cout; using std::cin; using std::endl; using std::fixed;
#include<iomanip>
using std::setprecision;
#include<cmath>
using std::sin; using std::acos; using std::abs; using std::pow;

const long double pi = acos(static_cast<long double>(-1));
 
double fn(double x){
  return -6*(x*x) + 5*x + 3;
}
double integral(double x){
    return -2*pow(x,3)+5/2.0*pow(x,2) + 3*x;
}
 
double trap(double a, double b, long N){
  double interval = (b-a)/N;
  double result = fn(a);
  for(double i=a+interval;i<b;i+=interval){
    result += 2*fn(i);
  }
  result += fn(b);
  result = (result * interval)/2.0;
  return result;
}

int main(){
  double b = 1.0, a = 0.0;
  cout << "Lower Range:" << endl;
  cin >> a;
  cout << "Upper Range:" << endl;
  cin >> b;
  double true_val;
  double result;
  double tolerance;
  long traps;

  cout << fixed << setprecision(4);

  true_val = integral(b) - integral(a);
  cout << "Tolerance:" << endl;
  cin >> tolerance;
  cout << "Initial trapezoid count:" << endl;
  cin >> traps;
  result = trap(a,b,traps);
  while (abs(true_val - result) > tolerance){
    cout << "Intermediate Result:" << result << ", traps:" << traps
         << ", diff:" << abs(true_val - result) << endl;
    traps *= 2;
    result = trap(a,b,traps);
  }
  cout << "Trap count:" << traps << ", estimate:" << result
       << ", exact:" << true_val << ", tolerance:" << tolerance << endl;
  }
