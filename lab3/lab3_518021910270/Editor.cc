#include <iostream>
#include <sstream>
#include<algorithm>
#include "Editor.h"

using namespace std;

Editor::Editor()
{
   buffer = new ListBuffer();
}
Editor::~Editor()
{
    delete buffer;
}

void Editor::run()
{
    string cmd;
    while (true)
    {
        cout << "cmd> ";
        cout.flush();
        getline(cin, cmd);
        if (cmd == "Q")
            break;
        try {
            dispatchCmd(cmd);
        } catch (const char *e) {
            cout << "? " << e << endl;
        } catch (const out_of_range &oor) {
            cout << "? " << oor.what() << endl;
        } catch (const range_error &re) {
            cout << "? " << re.what() << endl;
        }
    }
}

void Editor::dispatchCmd(const string &cmd)
{
   if(cmd[0]>='0'&&cmd[0]<='9')
   {
        int linenumber;
        string text;
        stringstream ss(cmd);
        ss>>linenumber>>text;
        buffer->insertLine(linenumber,text);
        return;
   }
   if(cmd[0]=='d')
   {
        int linenumber;
        string type;
        stringstream ss(cmd);
        ss>>type>>linenumber;
        buffer->deleteLine(linenumber);
        return;
   }
   if(cmd[0]=='s'&&cmd[1]=='a'&&cmd[2]=='v'&&cmd[3]=='e')
   {
        stringstream ss(cmd);
        string filename;
        filename=ss.str();
        buffer->writeToFile(filename.substr(5));
        return;
   }  
   string CMD=cmd;
   transform(CMD.begin(),CMD.end(),CMD.begin(),::toupper);
   if(CMD=="LIST")
   {
      buffer->showLines();
      return;
   }
     return;
}