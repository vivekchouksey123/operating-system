#include<iostream>
using namespace std;

class MemoryAllocation
{
	public:
	int amtProcess , amtBlocks ;
	int *blockSize , *processSize , *allocation , *flag ;
	void input() ;
	void First_Fit() ;
	void Best_Fit() ;
	void Worst_Fit() ;
	void output() ;
};

void MemoryAllocation :: input()
{
	cout<<"Enter the number of memory blocks available :" ;
	cin>>amtBlocks;
	
	blockSize = new int [amtBlocks] ;
	flag = new int[amtBlocks] ;
	
	cout<<"\nEnter the size of each block.";
	for(int i = 0 ; i<amtBlocks ; i++)
	{
		cin>>blockSize[i];
		flag[i] = 0 ; //no process allocated
	}
	
	cout<<"\nEnter the number of processes : ";
	cin>>amtProcess;
	
	processSize = new int [amtBlocks] ;
	allocation = new int [amtProcess] ;
	
	cout<<"\nEnter the size of each process.\n";
	for( int i=0 ; i<amtProcess ; i++ )
	{
		cin>>processSize[i];
		allocation[i] = -1 ; //not allocated memory
	}
}

void MemoryAllocation :: First_Fit()
{
	for( int i=0 ; i<amtProcess ; i++)
		for(int j = 0 ; j<amtBlocks ; j++)
		{
			if( processSize[i] <= blockSize[j] && flag[j] == 0  )
			{
				allocation[i] = j ;
				flag[j] = 1;
				break; // ith process is allocated to jth memory block
			}
		}
}

void MemoryAllocation :: Best_Fit()
{
	
	for( int i=0 ; i<amtProcess ; i++)
	{
		int min = INT_MAX ;
		for( int j=0 ; j<amtBlocks ; j++  )
		{
			if( min > blockSize[j] - processSize[i] && blockSize[j] >= processSize[i] && flag[j] == 0 )
			{
				min = blockSize[j] - processSize[i] ;
				allocation[i] = j ;
				flag[j] = 1;
				 // ith process is allocated to jth memory block
			}
		}
	}
}

void MemoryAllocation :: Worst_Fit()
{
	
	for( int i=0 ; i<amtProcess ; i++)
	{
		int max = 0 , tempflag = -1;
		for( int j=0 ; j<amtBlocks ; j++  )
		{
			if( max <= ( blockSize[j] - processSize[i] )  && ( blockSize[j] >= processSize[i] ) && ( flag[j] == 0) )
			{
				max = blockSize[j] - processSize[i] ;
				allocation[i] = j ;
				tempflag = j;
				// ith process is allocated to jth memory block
			}
		}
		if( tempflag != -1 )
			flag[tempflag] = 1;
	}
}

void MemoryAllocation :: output()
{
	cout<<"Process no.\tProcess size\tMemory Block\tMemory Size\n";
	for( int i=0 ; i<amtProcess ; i++ )
	{
		cout<<i<<"\t\t"<<processSize[i]<<"\t\t";
		if( flag[allocation[i]] == 1 )
		{
			cout<<allocation[i]<<"\t\t"<<blockSize[allocation[i]]<<"\n";
		}
		else cout<<"NOT Allocated.\n";
	}
}

int main()
{
	MemoryAllocation ff, bf , wf;
	int choice;
	cout<<"Enter '1' for First Fit.\n'2' for Best Fit.\n'3' for Worst Fit.\n";
	cin>>choice;
	
	switch(choice)
	{
		case 1: ff.input();
				ff.First_Fit();
				ff.output();
				//break;
		case 2: bf.input();
				bf.Best_Fit();
				bf.output();
				//break;
		case 3: wf.input();
				wf.Worst_Fit();
				wf.output();
				break;
		default : cout<<"Wrong Choice.\n";
			break;
	}
	
}
