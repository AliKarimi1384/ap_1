/*
Advanced programming course
Exercise number 1_3
Ali Karimi
Github account: https://github.com/AliKarimi1384
*/
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
using namespace std;
class myclass
{
public:
    bool compare_result(int num)
    {
        string user_output;
        string output;
        user_output = get_output(num);
        output = read_file(num);
        if (user_output.compare(output) == 0)
        {
            return true;
        }
        return false;
    }

private:
    string path(int num, bool is_in)
    {
        string directory;
        if (is_in)
        {
            directory = "in\\input";
        }
        else
        {
            directory = "out\\output";
        }
        return directory + to_string(num) + ".txt";
    }
    string read_file(int num)
    {
        string res;
        string temp;
        fstream file;
        file.open(path(num, false));
        if (!file.is_open())
        {
            cout << "Error: There was a problem while opening the files. \nMake sure that output and input files and in and out directories are available and try again.";
            exit(0);
        }
        while (!file.eof())
        {
            getline(file, temp);
            res += temp + "\n";
        }
        file.close();
        return res;
    }
    string get_output(int num)
    {
        string result;
        char _result[1000];
        string msg = "user.exe < " + path(num, true);
        FILE *fl = _popen(msg.c_str(), "r");
        if (!fl)
        {
            cout << "Error: There was a problem while running the file.";
            exit(0);
        }
        while (fgets(_result, 128, fl) != NULL)
        {
            result += _result;
        }
        _pclose(fl);
        // I added a \n because the sample outputs have \n in the end
        result += "\n";
        return result;
    }
};
int main()
{
    double count = 0;
    myclass obj;
    // we know that there are 10 files in the directory.
    for (int i = 1; i <= 10; i++)
    {
        if (obj.compare_result(i))
        {
            ++count;
        }
    }
    double percentage = count / 10.0 * 100.0;
    cout << "The final percentage is " << percentage << '%';
    return 0;
}