#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person{
    private:
        string name;
        int age;
    public:
        Person(string& name, int& age){
            this->name = name;
            this->age = age;
        }
        Person(){
            
        }
        string getName(){
            return this->name;
        }
        int getAge(){
            return this->age;
        }
        void setName(string& name){
            this->name = name;
        }
        void setAge(int& age){
            this->age = age;
        }
        virtual void getdata(){
            string name;
            int age;
            cin>>name>>age;
            this->setName(name);
            this->setAge(age);
        }
        virtual void putdata(){
            cout<<this->name<<" "<<this->age<<endl;
        }
};

class Professor : public Person{
    private:
        int publications;
        int cur_id;
        static int num;
    public:
        Professor(string& name, int& age, int& publications, int& cur_id): Person(name,age){
            num++;
            this->publications = publications;
            this->cur_id = num;
        }
        Professor() : Person(){
            num ++;
            this->cur_id= num;
        }
        
        void setCur(int& cur){
            this->cur_id = cur;
        }
        
        void setPublications(int& publications){
            this->publications = publications;
        }
        void getdata(){
            string name;
            int age;
            int publications;
            cin>> name >> age >> publications;
            setName(name);
            setAge(age);
            setPublications(publications);
            
        }
        void putdata(){
            cout<< this->getName() <<" "<< this->getAge()<<" "<< this->publications << " "<<this->cur_id<<endl;
        }
}; 

class Student : public Person{
    private:
        int marks[6];
        int cur_id;
        static int num;
    public:
        Student() : Person(){
            num++;
            this->cur_id = num;
        }
        Student(string& name,int& age,int (&marks)[6],int& cur_id) : Person(name,age ){
            for(int i=0; i<6 ; i++){
                this->marks[i]= marks[i];
            }
            num++;
            this->cur_id = num;
            
        }
        
        void setCur(int& cur){
            this->cur_id = cur;
        }
        
        void setMarks(int (&marks)[6]){
            for(int i=0; i<6 ; i++){
                this->marks[i]= marks[i];
            }
        }
        int sumMarks(){
            int sum=0;
            for(int i=0;i<6;i++){
                sum = sum +this->marks[i];
            }
            return sum;
        }
        void getdata(){
            string name;
            int age;
            int marks[6];
            cin>>name>>age;
            for(int i = 0; i<6;i++){
                cin>>marks[i];
            }
            this->setName(name);
            this->setAge(age);
            this->setMarks(marks);
            
        }
        void putdata(){
            cout<<getName()<<" "<<getAge()<<" "<< sumMarks() <<" "<< this->cur_id<<endl;
        }
};

int Professor::num = 0;
int Student::num=0;


int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}