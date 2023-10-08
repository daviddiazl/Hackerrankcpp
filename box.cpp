#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

class Box{
    private:
        int l;
        int b;
        int h;
    public:
        Box(){
            this->l = 0;
            this->b = 0;
            this->h = 0;
        }
        Box(int l,int b,int h){
            this->l = l;
            this->b = b;
            this->h = h;
        }
        Box(Box& bx){
            this->l = bx.l;
            this->b = bx.b;
            this->h = bx.h;
        }
        int getLength(){
            return this->l;
        }
        int getBreadth(){
            return this->b;
        }
        int getHeight(){
            return this->h;
        }
        long long CalculateVolume(){
            //long long volume;
            //volume = l*b*h;
            return  static_cast<long long>(this->l)* static_cast<long long>(this->b)*static_cast<long long>(this->h); //La clave para que no de problemas de desbordamiento
                                                                                                                      //es la conversion estatica 
            
        }
        bool operator<(const Box& bx){
            bool result = false;
            if(this->l< bx.l){
                result = true;
            }else if(this->l== bx.l && this->b< bx.b){
                result = true;
            }else if(this->l == bx.l && this->b == bx.b && this->h< bx.h){
                result = true;
            }else{
                
            }
            return result;
        }
        //friend ostream& operator<<(ostream& os,const Box& bx){
            //os<< bx.l << " "<< bx.b << " "<< bx.h;
            //return os;
        //}
        
};
    ostream& operator<<(ostream& os,Box& bx){
            os<< bx.getLength() << " "<< bx.getBreadth() << " "<< bx.getHeight();
            return os;
        }



void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}