#include <iostream>

using namespace std;

void FCFS(int arr[], int head)

{

int seek_count = 0;

int distance, cur_track;

for (int i = 0; i < size; i++)

{

cur_track = arr[i];

distance = abs(cur_track - head);

seek_count += distance;

head = cur_track;

}

cout << "Total number of seek operations = " << seek_count << endl;

cout << "Seek Sequence is" << endl;

for (int i = 0; i < size; i++)

cout << arr[i] << endl;

}

int main()

{

int size = 0 ;

cout<<"Enter the total number of requests.\n";

cin>>size;

int arr[size] ;

cout<<"Enter the all disk track numbers to be accessed.\n";

for( int i = 0 ; i<size ; i++ )

cin>>size[i];

int head;

cout<<"Enter the track number where head is present currently.\n";

cin>>head;

FCFS(arr, head);

return 0;

}
