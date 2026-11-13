#include <iostream>
#include <cstring>
using namespace std;
class Text {
    char* data;
public:
    Text(const char* s="") { data=new char[strlen(s)+1]; strcpy(data,s); }
    Text(const Text& other) { data=new char[strlen(other.data)+1]; strcpy(data,other.data); cout<<"[copy] "; }
    Text& operator=(const Text& other) { if(this!=&other){ char* fresh=new char[strlen(other.data)+1]; strcpy(fresh,other.data); delete[] data; data=fresh; } return *this; }
    ~Text(){ delete[] data; }
    Text& operator+=(const Text& other) { size_t n=strlen(data)+strlen(other.data)+1; char* fresh=new char[n]; strcpy(fresh,data); strcat(fresh,other.data); delete[] data; data=fresh; return *this; }
    friend Text operator+(Text left,const Text& right) { left+=right; return left; }
    bool operator==(const Text& x) const { return strcmp(data,x.data)==0; }
    bool operator!=(const Text& x) const { return !(*this==x); }
    friend ostream& operator<<(ostream& os,const Text& t){ return os<<t.data; }
};
int main(){ Text a("Hello "),b("World"),c("!"); Text result=a+b+c; cout<<"\nCombined: "<<result<<'\n'; Text empty; Text longText("A longer SMS message for testing."); empty=longText; empty=empty; cout<<"Assigned: "<<empty<<'\n'; cout<<boolalpha<<(a!=b)<<'\n'; }
