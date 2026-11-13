#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;
class Time {
    int seconds;
public:
    explicit Time(int s=0):seconds(s) { if(s<0) throw invalid_argument("Negative time"); }
    Time& operator++() { ++seconds; return *this; }
    Time operator++(int) { Time old=*this; ++seconds; return old; }
    bool operator==(const Time& x) const { return seconds==x.seconds; }
    bool operator<(const Time& x) const { return seconds<x.seconds; }
    friend ostream& operator<<(ostream& os,const Time& t) { return os<<t.seconds/3600<<":"<<(t.seconds/60)%60<<":"<<t.seconds%60; }
};
class Playlist {
    vector<string> tracks;
public:
    Playlist(initializer_list<string> t):tracks(t){}
    string& operator[](size_t i) { if(i>=tracks.size()) throw out_of_range("Playlist index out of range"); return tracks[i]; }
    const string& operator[](size_t i) const { if(i>=tracks.size()) throw out_of_range("Playlist index out of range"); return tracks[i]; }
    size_t size() const { return tracks.size(); }
};
int main() {
    Time t(5); Time a=t++; Time b=++t;
    cout << "a=" << a << " b=" << b << " t=" << t << '\n';
    Playlist p{"Track One","Track Two","Track Three"};
    for(size_t i=0;i<p.size();++i) cout<<i<<": "<<p[i]<<'\n';
    try { cout<<p[static_cast<size_t>(-1)]<<'\n'; } catch(const out_of_range& e){ cout<<e.what()<<'\n'; }
    Time rollover(3599); ++rollover; cout << "Rollover: " << rollover << '\n';
}
