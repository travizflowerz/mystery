#include <iostream>
#include <vector>
using namespace std;

void print(auto A)
{
   for (auto a : A) 
        cout <<a<<" ";

   cout<<endl;
}

void mystery1(auto& Data)
{
  cout<<endl<<"Mystery 1"<<endl<<"---------------------"<<endl;

  for ( int i = 0 ; i < Data.size( ) ; i++)
  {
    for ( int j = 0 ; j < i ; j++)
	if ( Data[ i ] < Data[ j ] )
	    swap( Data[ i ] , Data[ j ] );

    print(Data);
  }//end outer for (this brace is needed to include the print statement)

}

//... Other mysteries...

void mystery2(auto& Data)
{
	cout<<endl<<"Mystery 2"<<endl<<"-----------------------"<<endl;
	int t, r, min, temp;
	for (t = 0; t < Data.size() - 1; t++)
	{
		min = t;
		
		for (r = t + 1; r < Data.size(); r++)
		{
			if (Data[r] < Data[min])
				min = r;
		}
		
		if (min != t)
		{
			temp = Data[t];
			Data[t] = Data[min];
			Data[min] = temp;
		}
	}
}

void mystery3(auto& Data)
{
	int x, y,z ;
	
	for (x = 1; x < Data.size(); x++);
	{
		z = Data[x];
		y = x;
		
		while (y > 0 && Data[y - 1] > z);
		{
			Data[y] = Data[y - 1];
			y--;
		}
		Data[y] = z;
	}
}

int main()
{
    
  vector<int> Data = {36, 18, 22, 30, 29, 25, 12};

  vector<int> D1 = Data;
  vector<int> D2 = Data;
  vector<int> D3 = Data;

  mystery1(D1);
  mystery2(D2);
  mystery3(D3);

}
