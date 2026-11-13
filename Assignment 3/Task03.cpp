#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Event {
    string name; int rows, seats; vector<vector<char>> map;
public:
    Event(string n, int r, int s) : name(move(n)), rows(r), seats(s), map(r, vector<char>(s, 'O')) {
        cout << "Created " << name << " (" << rows << "x" << seats << ")\n";
    }
    bool book(int r,int s) { if(r<0||r>=rows||s<0||s>=seats||map[r][s]=='X') return false; map[r][s]='X'; return true; }
    bool cancel(int r,int s) { if(r<0||r>=rows||s<0||s>=seats||map[r][s]=='O') return false; map[r][s]='O'; return true; }
    void show() const { for(auto& row:map){ for(char c:row) cout<<c<<' '; cout<<'\n'; } }
    ~Event() { int booked=0; for(auto& row:map) for(char c:row) booked += (c=='X'); cout << "Closed " << name << "; booked seats: " << booked << '\n'; }
};
int main() {
    Event morning("Morning Show",2,3); morning.book(0,1); morning.book(1,2); morning.cancel(0,1); morning.show();
    { Event afternoon("Afternoon Show",1,2); afternoon.book(0,0); }
    Event* night = new Event("Night Show",2,2); night->book(1,1); delete night;
    Event zero("Empty Event",0,5); zero.show();
}
