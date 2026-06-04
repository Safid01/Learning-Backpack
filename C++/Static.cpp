#include <iostream>
using namespace std;

class S {
private:
    string SName;
    int SId;
public:
    static int nextSId;
    S() {
    nextSId+=10;
    SId = nextSId;
    cout<<"New Service: " <<SId<<std::endl;
}
    S(string n) {
    SName = n;
    nextSId+=5;
    SId = nextSId;
    cout<<SName<<" Service ID: " <<SId<<std::endl;
}
~S() {
    cout<<"S-"<<SId<<": "<<SName<<endl;
}
void setS(string n) {
    SName = n;
}
};
int S::nextSId = 0;
int main() {
    S s1;
    S s2("Reading"),s3;
    s3.setS("Speaking");
    s1.setS("Writing");
    return 0;
}