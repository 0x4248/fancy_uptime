// Fancy uptime for linux systems

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <unistd.h>

#include "./lib/colour.h"

using namespace std;

int main(int argc, char *argv[])
{
    ascii_colours::normal normal;
    ascii_colours::bold bold;

    string uptime = "";
    FILE *in;
    char buff[512];
    if(!(in = popen("uptime -p", "r")))
    {
        return 1;
    }
    while(fgets(buff, sizeof(buff), in)!=NULL)
    {
        uptime += buff;
    }
    pclose(in);
    uptime.replace(uptime.find("up"), 2, bold.green+"The system has been up for:"+bold.reset+"\n");
    if(uptime.find("years") != string::npos)
    {
        uptime.replace(uptime.find("years"), 5, normal.cyan+"years"+normal.reset+"\n");
    }
    if(uptime.find("months") != string::npos)
    {
        uptime.replace(uptime.find("months"), 6, normal.cyan+"months"+normal.reset+"\n");
    }
    if(uptime.find("weeks") != string::npos)
    {
        uptime.replace(uptime.find("weeks"), 5, normal.cyan+"weeks"+normal.reset+"\n");
    }
    if(uptime.find("days") != string::npos)
    {
        uptime.replace(uptime.find("days"), 4, normal.cyan+"days"+normal.reset+"\n");
    }
    if(uptime.find("hours") != string::npos)
    {
        uptime.replace(uptime.find("hours"), 5, normal.cyan+"hours"+normal.reset+"\n");
    }
    if(uptime.find("minutes") != string::npos)
    {
        uptime.replace(uptime.find("minutes"), 7, normal.cyan+"minutes"+normal.reset+"\n");
    }
    if(uptime.find("seconds") != string::npos)
    {
        uptime.replace(uptime.find("seconds"), 6, normal.cyan+"seconds"+normal.reset+"\n");
    }
    if(uptime.find("year") != string::npos)
    {
        uptime.replace(uptime.find("year"), 5, normal.cyan+"years"+normal.reset+"\n");
    }
    if(uptime.find("month") != string::npos)
    {
        uptime.replace(uptime.find("month"), 6, normal.cyan+"months"+normal.reset+"\n");
    }
    if(uptime.find("week") != string::npos)
    {
        uptime.replace(uptime.find("week"), 5, normal.cyan+"weeks"+normal.reset+"\n");
    }
    if(uptime.find("day") != string::npos)
    {
        uptime.replace(uptime.find("day"), 4, normal.cyan+"days"+normal.reset+"\n");
    }
    if(uptime.find("hour") != string::npos)
    {
        uptime.replace(uptime.find("hour"), 5, normal.cyan+"hours"+normal.reset+"\n");
    }
    if(uptime.find("minute") != string::npos)
    {
        uptime.replace(uptime.find("minute"), 7, normal.cyan+"minutes"+normal.reset+"\n");
    }
    if(uptime.find("second") != string::npos)
    {
        uptime.replace(uptime.find("second"), 6, normal.cyan+"seconds"+normal.reset+"\n");
    }
    if(uptime.find(" 0") != string::npos)
    {
        uptime.replace(uptime.find(" 0"), 2, "0");
    }
    if(uptime.find(" 1") != string::npos)
    {
        uptime.replace(uptime.find(" 1"), 2, "1");
    }
    if(uptime.find(" 2") != string::npos)
    {
        uptime.replace(uptime.find(" 2"), 2, "2");
    }
    if(uptime.find(" 3") != string::npos)
    {
        uptime.replace(uptime.find(" 3"), 2, "3");
    }
    if(uptime.find(" 4") != string::npos)
    {
        uptime.replace(uptime.find(" 4"), 2, "4");
    }
    if(uptime.find(" 5") != string::npos)
    {
        uptime.replace(uptime.find(" 5"), 2, "5");
    }
    if(uptime.find(" 6") != string::npos)
    {
        uptime.replace(uptime.find(" 6"), 2, "6");
    }
    if(uptime.find(" 7") != string::npos)
    {
        uptime.replace(uptime.find(" 7"), 2, "7");
    }
    if(uptime.find(" 8") != string::npos)
    {
        uptime.replace(uptime.find(" 8"), 2, "8");
    }
    if(uptime.find(" 9") != string::npos)
    {
        uptime.replace(uptime.find(" 9"), 2, "9");
    }
    uptime.erase(uptime.find_last_not_of("\n")+1);
    uptime.erase(uptime.find_last_not_of(" ")+1);
    ofstream myfile;
    myfile.open("uptime.txt");
    myfile << uptime;
    myfile.close();

    cout << uptime << endl;
}
