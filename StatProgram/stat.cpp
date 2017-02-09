#include <iostream>
#include <math.h>

float get_mean(int, float*);
float get_variance(int, float*);
float get_stddev(int, float*);
float get_median(int, float*);

int main(){
  int set_size = 12;
  float dataset[12] = {7.6, 8.4, 9.3, 9.5, 9.5, 9.8, 10.5, 11.5, 11.9, 15.2, 16.1, 20.4}; 
  float mean = get_mean(set_size, dataset);
  std::cout << "The mean is " << mean << std::endl;
  float median = get_median(set_size, dataset);
  std::cout << "The median is " << median << std::endl;
  /*
  int set_size = 11;
  int dataset[11] = {42, 61, 52, 68, 42, 45, 27, 24, 56, 83, 34}; 
  float variance = get_variance();
  std::cout << "The variance is " << variance << std::endl;
  float stddev = get_stddev();
  std::cout << "The standard deviation is " << stddev << std::endl;
  */
  return 0;
}

float get_mean(int set_size, float dataset[set_size]){  
  float sum = 0;
  for (int k = 0; k < set_size; k++)
    sum += dataset[k];
  float mean = sum / set_size;
  return mean;

}

float get_variance(int set_size, float dataset[set_size]){
  float mean_sum = 0;
  for (int k = 0; k < set_size; k++)
    mean_sum += dataset[k];
  float mean = mean_sum / set_size;
  
  float var_sum = 0;
  for (int i = 0; i < set_size; i++){
    var_sum += pow((dataset[i] - mean), 2.0);
  }
  float variance = (1.0 / (set_size - 1)) * var_sum;
  return variance;
}

float get_stddev(int set_size, float dataset[set_size]){
  return sqrt(get_variance(set_size, dataset));
}
  
float get_median(int set_size, float dataset[set_size]){
  //assumes ordered-set
  float median;
  //if even-numbered set
  int pivot = set_size / 2;
  if (set_size % 2 == 0)
    median = (dataset[pivot] + dataset[pivot - 1]) / 2.0;
  //if odd-numbered set
  else
    median = dataset[pivot];
  return median;
}
