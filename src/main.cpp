/* Fancy uptime (main.c)
 * A fancy uptime reader that makes a nicer output than the uptime command. 
 * Made by: awesomelewis2007
 * Github: https://www.github.com/awesomelewis2007/fancy_uptime
 * License: GNU General Public License v3.0
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <unistd.h>

#include "colour.h"

using namespace std;
#define VERSION "1.0.0"

ascii_colours::normal normal;
ascii_colours::bold bold;

/**
 * format_uptime - formats the uptime string
 * @uptime: the uptime string
 * @return: the formatted uptime string
*/
std::string format_uptime(std::string uptime){
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
    return uptime;
}

int main(int argc, char *argv[])
{
    for(int i = 1; i < argc; i++)
    {
        if(strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0)
        {
            cout << bold.green << "Fancy uptime for linux systems" << bold.reset << endl;
            cout << bold.green << "Usage: " << bold.reset << "uptime [OPTION]" << endl;
            cout << bold.green << "Options:" << bold.reset << endl;
            cout << bold.green << "  -h, --help" << bold.reset << "     Show this help" << endl;
            cout << bold.green << "  -v, --version" << bold.reset << "  Show version" << endl;
            cout << bold.green << "  -nc, --no-colour" << bold.reset << "  No colour" << endl;
            return 0;
        }
        else if(strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--version") == 0)
        {
            cout << bold.green << "Fancy uptime for linux systems" << bold.reset << endl;
            cout << bold.green << "Version: " << bold.reset << VERSION << endl;
            return 0;
        }
        else if(strcmp(argv[i], "-nc") == 0 || strcmp(argv[i], "--no-colour") == 0)
        {
            normal.reset = "";
            bold.reset = "";
            normal.red = "";
            normal.green = "";
            normal.yellow = "";
            normal.blue = "";
            normal.magenta = "";
            normal.cyan = "";
            normal.white = "";
            bold.red = "";
            bold.green = "";
            bold.yellow = "";
            bold.blue = "";
            bold.magenta = "";
            bold.cyan = "";
            bold.white = "";
        }
    }
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
    uptime = format_uptime(uptime);
    cout << uptime << endl;
}
