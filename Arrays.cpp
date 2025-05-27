#include <iostream>
using namespace std;

int main() { 
  int arr[10]; //define an array of 10 elements
  int sum= 0;
 
  cout<< "Enter 10 integers(By putting a space in between): "<<endl;
  for (int i = 0; i < 10; ++i){
    cin>>arr[i];}
  
  cout<<"Array elements: ";
  for (int i = 0; i < 10; ++i){
    cout<<arr[i]; //display the array elements
    if(i<9)
      cout<<" , ";} //put commas between elements
  cout<<endl;

  int max= arr[0];
  int min= arr[0];
  for (int i = 0; i < 10; ++i){
    sum+= arr[i];  //sum of all elements
    if (arr[i] > max){
      max= arr[i];  //find maximum element
    }
    if (arr[i] < min){
      min= arr[i];  //find minimum element
    }
  }
  
  double average = double(sum) / 10; // calculating the average of all the elements
  cout << "The sum of the array elements: " << sum << endl;
  cout << "Average of the array elements: " << average << endl;

  cout << "The maximum element: " << max << endl;
  cout << "The minimum element: " << min << endl;

  int* start = arr;
  int* end = arr + 9;
  while(start < end){
    int temp= *start;
    *start= *end;
    *end= temp;
    start++;
    end--;} // using pointers to reverse the elements of the array

  cout<< "Reversed order array elements: ";
  for (int i = 0; i <10; ++i){
    cout<<arr[i];
    if (i <9) 
      cout<< " , ";} // display the array elements, again
  cout<<endl;

  return 0;}