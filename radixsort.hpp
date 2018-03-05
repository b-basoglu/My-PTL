#include <iostream>
#include <vector>
using namespace std;

int max(vector<int> &v) {
  int size = v.size();
  int max = v[0];
  for(int i=1; i<size; i++)
    if(v[i] > max)
      max = v[i];
  return max;
}

void countsort(vector<int> &v, int e) {
  int size = v.size();
  vector<int> output(size);
  vector<int> count(10);

  for(int i=0; i<size; i++)
    count[ (v[i] / e) % 10]++;

  for(int i=1; i<10; i++)
    count[i] += count[i-1];

  for(int i=size-1; i>=0; i--) {
    output[count[(v[i]/e)%10]-1] = v[i];
    count[ (v[i] / e) % 10]--;
  }

  for(int i=0; i<size; i++)
    v[i] = output[i];
}

void radixsort(vector<int> &v) {
  int size = v.size();
  int mx = max(v);

  for(int e=1; mx/e>0; e*=10)
    countsort(v,e);
}

void print(vector<int> &v) {
  int size = v.size();
  for(int i=0; i<size; i++)
    cout << v[i] << " ";
  cout << endl;
}


int main(int argc, char const *argv[]) {
  vector<int> v {333,678,466,547,236,121,444,553,667,884,993,002,231,493,105,607,655,722};
  radixsort(v);
  print(v);
  return 0;
}
