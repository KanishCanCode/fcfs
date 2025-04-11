#include <iostream>
using namespace  std;

class process{
public:
    string PName;
    int BT;
    int WT;
    int AT;
    int TAT;
    int RT;
    int CT;
};

int main(){

int numProcess;
cout<<"enter the number of processes";
cin>>numProcess;
process p[numProcess];
for(int x=0;x<numProcess;x++){
cout<<"enter name of process for "<<x+1<<endl;
cin>>p[x].PName;
cout<<"enter the Arrival time for "<<x+1<<endl;
cin>>p[x].AT;
cout<<"enter the Burst time for "<<x+1<<endl;
cin>>p[x].BT;

}
for(int i=0;i<numProcess-1;i++){
        for(int j=i+1;j<numProcess;j++){
            if(p[j].AT < p[i].AT){
                process temp = p[j];
                p[j] = p[i];
                p[i] = temp;
            }
        }
    }
    int sumRT = 0;
    int sumCT = 0;
    int sumWT = 0;
    int sumTAT = 0;


    int cumulativeSum = 0;
for(int x=0;x<numProcess;x++){
        p[x].WT = cumulativeSum;
        p[x].CT=p[x].AT+p[x].BT;
        if(x == 0){
            p[x].RT = 0;
        }
        else{
            p[x].RT = p[x-1].CT;
        }
        p[x].TAT=p[x].CT-p[x].AT;

 cout << "\nProcess " << p[x].PName << ":\n";
        cout << "Response Time: " << p[x].RT << endl;
        cout << "Completion Time: " << p[x].CT << endl;
        cout << "Waiting Time: " << p[x].WT << endl;
        cout << "Turn Around Time: " << p[x].TAT << endl;


        sumRT += p[x].RT;
        sumCT += p[x].CT;
        sumWT += p[x].WT;
        sumTAT += p[x].TAT;

        cumulativeSum += p[x].BT;

}
}
